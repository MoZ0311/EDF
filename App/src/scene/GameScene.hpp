// GameScene class

#pragma once

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
};
