#pragma once

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
