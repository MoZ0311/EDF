// GameScene class

# include "GameScene.hpp"

using namespace SceneSettings;
GameScene::GameScene(const InitData& init)
	: IScene{ init }
	, m_renderTexture{ Scene::Size(), TextureFormat::R8G8B8A8_Unorm_SRGB, HasDepth::Yes }
	, m_camera{ m_renderTexture.size(), 60_deg, Vec3{ 10, 16, 32 } }
{

}

void GameScene::update()
{
	// debug
	if (KeyEnter.down())
	{
		changeScene(State::Title, TransitionDuration);
	}
}

void GameScene::draw() const
{
	Cursor::RequestStyle(CursorStyle::Hidden);

	// 3Dシーンにカメラを設定
	Graphics3D::SetCameraTransform(m_camera);

	// 3D描画
	{
		const ScopedRenderTarget3D target{ m_renderTexture.clear(Palette::Firebrick.removeSRGBCurve()) };
		const ScopedRenderStates3D blend{ BlendState::OpaqueAlphaToCoverage };

		// 床を描画
		Plane{ 64 }.draw(uvChecker);

		// ボックスを描画
		Box{ -8,2,0,4 }.draw(ColorF{ 0.8, 0.6, 0.4 }.removeSRGBCurve());

		// 球を描画
		Sphere{ 0,2,0,2 }.draw(ColorF{ 0.4, 0.8, 0.6 }.removeSRGBCurve());

		// 円柱を描画
		Cylinder{ 8, 2, 0, 2, 4 }.draw(ColorF{ 0.6, 0.4, 0.8 }.removeSRGBCurve());

	}

	// 2Dに転送
	{
		Graphics3D::Flush();
		m_renderTexture.resolve();
		Shader::LinearToScreen(m_renderTexture);
	}
}
