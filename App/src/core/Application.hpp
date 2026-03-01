// Application class

#pragma once

# include "Config.hpp"

class Application
{
public:

	// コンストラクタ
	Application();

	/// @brief ゲーム全体の処理を実行する関数。
	/// @return 処理が成功した場合は true、それ以外は false を返す。
	bool run();

private:

	// 全てのシーンをシーンマネージャーに登録する処理
	void registerScenes();

	// シーンマネージャー
	SceneManager<SceneSettings::State> m_sceneManager;
};
