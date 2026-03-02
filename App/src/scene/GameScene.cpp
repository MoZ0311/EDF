// GameScene class

# include "GameScene.hpp"

GameScene::GameScene(const InitData& init)
	: IScene{ init }
{
	Scene::SetBackground(Palette::Firebrick);
}

void GameScene::update()
{
	Cursor::RequestStyle(CursorStyle::Hidden);
	Cursor::SetPos(Scene::Center());
}

void GameScene::draw() const
{

}
