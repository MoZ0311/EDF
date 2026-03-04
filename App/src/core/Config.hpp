#pragma once

// ゲーム名
inline const String GameTitle{ U"EDF" };

// 画面サイズ
inline constexpr Size ScreenSize{ 1920, 1080 };

// トリガーが押されたと認識する深さの閾値
inline constexpr float TriggerThreshold{ 0.3f };

namespace SceneSettings
{
	// 各シーンの列挙型定義
	enum class State
	{
		Title,	// タイトルシーン
		Game,	// ゲームシーン
		Clear	// クリアシーン
	};

	// シーン遷移の間隔
	inline constexpr SecondsF TransitionDuration{ 0.5f };

	// SceneManager<State>の別名定義
	using Manager = SceneManager<State>;
}

namespace UISettings
{
	// ボタンのサイズ
	inline constexpr Size ButtonSize{ 300, 60 };

	// ボタンの枠の太さ
	inline constexpr float ButtonThickness{ 2.0f };

	// ボタンの丸み
	inline constexpr float ButtonRoundness{ ButtonSize.y / 2.0f };

	// ボタンのトランジション
	inline constexpr Transition ButtonTransition{ 0.2s, 0.2s };

	// ボタン同士の間隔
	inline constexpr Point ButtonOffset{ 0, 100 };

	// ボタンの文字の色
	inline constexpr ColorF ButtonTextCollor{ 0.3 };
}
