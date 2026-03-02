// TitleScene class

# include "TitleScene.hpp"
# include "../core/Config.hpp"

using namespace SceneSettings;
using namespace UISettings;

TitleScene::TitleScene(const InitData& init)
	: IScene{ init }
	, m_startButton{
		Arg::center = TitleButtonPoint,
		ButtonSize,
		ButtonRoundness
	}
	, m_exitButton{ m_startButton.movedBy(ButtonOffset) }
	, m_startTransition{ ButtonTransition }
	, m_exitTransition{ ButtonTransition }
	, m_currentSelectingButton{ SelectingButton::None }
	, m_isUsingPad{ false }
{
	Scene::SetBackground(Palette::Mediumaquamarine);
}

void TitleScene::update()
{
	/*
	if (PlayerInput::KeyUpper())
	{
		m_currentSelectingButton = SelectingButton::Start;
		m_isUsingPad = true;
	}
	else if (PlayerInput::KeyLower())
	{
		m_currentSelectingButton = SelectingButton::Exit;
		m_isUsingPad = true;
	}
	*/

	// ゲームパッドを使用しているかで分岐
	if (m_isUsingPad)
	{
		Cursor::RequestStyle(CursorStyle::Hidden);
		if (!Cursor::DeltaRaw().isZero())
		{
			m_isUsingPad = false;
		}
	}
	else
	{
		const bool onStart{ m_startButton.mouseOver() };
		const bool onExit{ m_exitButton.mouseOver() };

		if (onStart || onExit)
		{
			Cursor::RequestStyle(CursorStyle::Hand);
			m_currentSelectingButton = onStart ? SelectingButton::Start : SelectingButton::Exit;
		}
		else
		{
			m_currentSelectingButton = SelectingButton::None;
		}
	}

	m_startTransition.update(m_currentSelectingButton == SelectingButton::Start);
	m_exitTransition.update(m_currentSelectingButton == SelectingButton::Exit);

	if (MouseL.down())
	{
		switch (m_currentSelectingButton)
		{
		case SelectingButton::Start:
			changeScene(State::Game, TransitionDuration);
			break;

		case SelectingButton::Exit:
			System::Exit();
			break;

		default:
			break;
		}
	}

	Print << FromEnum(m_currentSelectingButton);
}

void TitleScene::draw() const
{
	// Startボタンの描画
	m_startButton.draw(ColorF{ 1.0, m_startTransition.value() }).drawFrame(ButtonThickness);
	// FontAsset(Assets::Makinas)(U"START").drawAt(m_startButton.center(), Components::ButtonTextCollor);

	// Exitボタンの描画
	m_exitButton.draw(ColorF{ 1.0, m_exitTransition.value() }).drawFrame(ButtonThickness);
	// FontAsset(Assets::Makinas)(U"EXIT").drawAt(m_exitButton.center(), Components::ButtonTextCollor);
}
