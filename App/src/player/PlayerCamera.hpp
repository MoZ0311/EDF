// PlayerCamera class

#pragma once

class PlayerCamera
{
public:

	// コンストラクタ
	PlayerCamera(const BasicCamera3D& camera);

	// 更新処理
	void update();

private:

	// 操作するカメラのアドレス
	const BasicCamera3D& m_camera;
};
