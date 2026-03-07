// CameraController class

# include "CameraController.hpp"
# include "../core/Config.hpp"

using namespace CameraSettings;

CameraController::CameraController(BasicCamera3D& camera)
	: m_camera{ camera }
	, m_playerInput{}
	, m_yaw{ 0 }
	, m_pitch{ 0 }
	, m_sensitivity{ 0.002f }
{

}

void CameraController::update()
{
	const Vec2 cameraAxis{ m_playerInput.GetCameraAxis() };
	if (cameraAxis.isZero())
	{
		return;
	}

	m_yaw += cameraAxis.x * m_sensitivity;
	m_pitch -= cameraAxis.y * m_sensitivity;

	m_pitch = Clamp(m_pitch, -PitchLimit, PitchLimit);

	const Vec3 forward{
		Cos(m_pitch) * Sin(m_yaw),
		Sin(m_pitch),
		Cos(m_pitch) * Cos(m_yaw)
	};

	const Vec3 eyePosition{ m_camera.getEyePosition() };
	m_camera.setView(eyePosition, eyePosition + forward, Vec3::Up());
}
