// Application class

# include "Application.hpp"
# include "../scene/TitleScene.hpp"

using namespace SceneSettings;

Application::Application()
	: m_sceneManager{}
{
	
}

bool Application::initialize()
{
	// ウィンドウの各種設定
	Window::SetTitle(GameTitle);
	Window::SetFullscreen(true);

	// 全てのシーンを登録し、最初のシーンを初期化
	registerScenes();
	if (!m_sceneManager.init(State::Title, TransitionDuration))
	{
		return false;
	}

	// 全ての初期化処理を終え、true(正常に初期化完了)を返す
	return true;
}

bool Application::run()
{
	Print << Scene::Size();

	// シーン内の更新、描画が成功したかを返す
	return m_sceneManager.update();
}

void Application::registerScenes()
{
	m_sceneManager.add<TitleScene>(State::Title);
}
