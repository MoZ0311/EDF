// PlayerInput class

# include "PlayerInput.hpp"

// コンストラクタ
PlayerInput::PlayerInput(uint8 playerIndex)
	: m_playerIndex{ playerIndex }
	, m_controller{ XInput(m_playerIndex) }
{
	// デッドゾーン設定
	m_controller.setLeftThumbDeadZone();
	m_controller.setRightThumbDeadZone();
}

// プレイヤーの移動方向の算出
Vec2 PlayerInput::GetMovementAxis() const
{
	if (m_controller.isConnected())
	{
		// 左スティックの入力値を使用
		const Vec2 inputVector{ m_controller.leftThumbX, m_controller.leftThumbY };

		// 値が0でなければ、return
		if (!inputVector.isZero())
		{
			return inputVector;
		}
	}

	// キー入力を平面ベクトルに変換(trueを1, falseを0として算術演算)
	const Vec2 keyInputVector{ KeyD.pressed() - KeyA.pressed(), KeyW.pressed() - KeyS.pressed() };
	return keyInputVector.normalized();
}

// カメラの操作
Vec2 PlayerInput::GetCameraAxis() const
{
	if (m_controller.isConnected())
	{
		// 右スティックの入力値を使用
		const Vec2 inputVector{ -m_controller.rightThumbX, m_controller.rightThumbY };

		// 値が0でなければ、return
		if (!inputVector.isZero())
		{
			// return inputVector * Config::Camera::RotateSpeed;
		}
	}

	// カーソルの移動量を取得
	return -Cursor::DeltaF();
}

// 決定ボタンが押されたか
bool PlayerInput::KeyConfirm() const
{
	const InputGroup confirmKey{ KeySpace | KeyEnter | MouseL | m_controller.buttonB };
	return confirmKey.down();
}

// キャンセルボタンが押されたか
bool PlayerInput::KeyCancel() const
{
	const InputGroup cancelKey{ KeyBackspace | KeyC | MouseR | m_controller.buttonA };
	return cancelKey.down();
}

// 上側キーが押されたか
bool PlayerInput::KeyUpper() const
{
	const InputGroup upperKey{ KeyW | KeyUp | m_controller.buttonUp };
	return upperKey.down();
}

// 下側キーが押されたか
bool PlayerInput::KeyLower() const
{
	const InputGroup lowerKey{ KeyS | KeyDown | m_controller.buttonDown };
	return lowerKey.down();
}

// メニューボタンが押されたか
bool PlayerInput::KeyMenu() const
{
	const InputGroup menuKey{ KeyTab | m_controller.buttonY };
	return menuKey.down();
}
