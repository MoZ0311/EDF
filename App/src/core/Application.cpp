// Application class

# include "Application.hpp"

using namespace SceneSettings;

Application::Application()
	: m_sceneManager{}
{
	// ウィンドウサイズをFHDに変更し、フルスクリーン化
	Window::Resize(ScreenSize);
	Window::SetFullscreen(true);

	// 全てのシーンを登録し、最初に読み込むシーンを設定
	registerScenes();
	// m_sceneManager.init(State::Title, TransitionDuration);
}

bool Application::run()
{
	// シーン内の更新、描画が成功したかを返す
	return m_sceneManager.update();
}

void Application::registerScenes()
{
	Print << U"Register Scenes!";
}
