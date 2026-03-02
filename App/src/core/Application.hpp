// Application class

#pragma once

# include "Config.hpp"

class Application
{
public:

	// コンストラクタ
	Application();

	/// @brief アプリケーション全体と最初のシーンを初期化する処理
	/// @return 正常に初期化できた場合は true, それ以外は false
	bool initialize();

	/// @brief ゲーム全体の処理を実行する処理
	/// @return 処理が成功した場合は true, それ以外は false
	bool run();

private:

	// 全てのシーンをシーンマネージャーに登録する処理
	void registerScenes();

	// シーンマネージャー
	SceneSettings::Manager m_sceneManager;
};
