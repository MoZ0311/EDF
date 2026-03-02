# include <Siv3D.hpp>
# include "App/src/core/Application.hpp"

void Main()
{
	// Application classを作成し、初期化
	Application app{};
	if (!app.initialize())
	{
		// 初期化に失敗時、即座に終了
		return;
	}

	while (System::Update())
	{
		ClearPrint();

		// ゲームループ中に更新に失敗した時
		if (!app.run())
		{
			// アプリケーションを終了する
			break;
		}
	}
}
