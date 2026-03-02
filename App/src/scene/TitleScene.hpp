// TitleScene class

#pragma once

# include "../core/Config.hpp"

class TitleScene : public SceneSettings::Manager::Scene
{
public:

	// コンストラクタ
	TitleScene(const InitData& init);

	// 更新処理
	void update() override;

	// 描画処理
	void draw() const override;

private:

	// ボタンの選択状態の列挙型定義
	enum class SelectingButton
	{
		None,	// ボタンは未選択状態
		Start,	// ゲーム開始ボタンを選択中
		Exit,	// ゲーム終了ボタンを選択中
	};

	// ゲーム開始ボタンの設定
	const RoundRect m_startButton;
	Transition m_startTransition;

	// ゲーム終了ボタンの設定
	const RoundRect m_exitButton;
	Transition m_exitTransition;

	// 選択中のボタン
	SelectingButton m_currentSelectingButton;

	// ゲームパッドを使うか
	bool m_isUsingPad;
};
