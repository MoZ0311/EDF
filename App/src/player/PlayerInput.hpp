# pragma once

class PlayerInput
{
public:

	// コンストラクタ
	PlayerInput(uint8 playerIndex = 0);

	// プレイヤーの移動方向の算出
	Vec2 GetMovementAxis() const;

	// カメラの操作
	Vec2 GetCameraAxis() const;

	// 決定ボタンが押されたか
	bool KeyConfirm() const;

	// キャンセルボタンが押されたか
	bool KeyCancel() const;

	// 上側キーが押されたか
	bool KeyUpper() const;

	// 下側キーが押されたか
	bool KeyLower() const;

	// メニューボタンが押されたか
	bool KeyMenu() const;

private:

	// 操作しているプレイヤーのインデックス
	const uint8 m_playerIndex;

	// 接続されているコントローラー
	detail::XInput_impl m_controller;
};
