// CameraController class

#pragma once

#include "PlayerInput.hpp"

class CameraController
{
public:

	// コンストラクタ
	CameraController(BasicCamera3D& camera);

	// 更新処理
	void update();

private:

	// 操作するカメラのアドレス
	BasicCamera3D& m_camera;

	// 入力管理クラス
	PlayerInput m_playerInput;

	// yaw角
	float m_yaw;

	// pitch角
	float m_pitch;

	// カメラ感度
	const float m_sensitivity;
};
