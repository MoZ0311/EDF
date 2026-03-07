// GameScene class

#pragma once

# include "../player/CameraController.hpp"
# include "../core/Config.hpp"

class GameScene : public SceneSettings::Manager::Scene
{
public:

	// コンストラクタ
	GameScene(const InitData& init);

	// 更新処理
	void update() override;

	// 描画処理
	void draw() const override;

private:

	const Texture uvChecker{ U"example/texture/uv.png", TextureDesc::MippedSRGB };

	// マルチサンプリング対応のレンダーテクスチャ
	const MSRenderTexture m_renderTexture;

	// 3D空間用のカメラ
	BasicCamera3D m_camera;

	// カメラ操作クラス
	CameraController m_cameraController;

	// スカイボックスの描画エンジン
	const Sky m_skyRenderer;
};
