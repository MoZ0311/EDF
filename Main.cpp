# include <Siv3D.hpp>
# include "App/src/core/Application.hpp"

void Main()
{
	Application app{};

	while (System::Update())
	{
		// ゲームループ中に更新に失敗した時
		if (!app.run())
		{
			// アプリケーションを終了する
			break;
		}
	}
}
