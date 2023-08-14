#include "engine_pch.h"
#include "cameras/CameraControllerEuler.h"
#include "GLFW/glfw3.h"

namespace Engine {

	CameraControllerEuler::CameraControllerEuler(const FPSEulerCameraProps& props)
	{
		m_model = glm::mat4(1.0f);
		m_camera.updateView(m_model);
		m_camera.projection = glm::perspective(glm::radians(props.fovY), props.aspectRatio, props.nearClip, props.farClip);

		m_props = props;
		m_lastMousePosition = InputPoller::getMousePosition();

		m_forward = { -m_model[2][0], -m_model[2][1], -m_model[2][2] };
		m_up = { m_model[1][0], m_model[1][1], m_model[1][2] };
		m_right = { m_model[0][0], m_model[0][1], m_model[0][2] };
	}

	void CameraControllerEuler::onUpdate(float timestep)
	{
		bool camMoved = false;
		if (InputPoller::isKeyPressed(GLFW_KEY_W))
		{
			float y = m_props.position.y;
			m_props.position += m_forward * m_props.translationSpeed * timestep;
			m_props.position.y = y;
			camMoved = true;
		}
		if (InputPoller::isKeyPressed(GLFW_KEY_S))
		{
			float y = m_props.position.y;
			m_props.position -= m_forward * m_props.translationSpeed * timestep;
			m_props.position.y = y;
			camMoved = true;
		}
		if (InputPoller::isKeyPressed(GLFW_KEY_A))
		{
			m_props.position -= m_right * m_props.translationSpeed * timestep;
			camMoved = true;
		}
		if (InputPoller::isKeyPressed(GLFW_KEY_D))
		{
			m_props.position += m_right * m_props.translationSpeed * timestep;
			camMoved = true;
		}

		if (InputPoller::isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
		{
			if (m_lastMousePosition.x >= 0.f)
			{
				camMoved = true;
				glm::vec2 currentMousePosition = InputPoller::getMousePosition();
				glm::vec2 mouseDelta = currentMousePosition - m_lastMousePosition;

				m_props.yaw -= mouseDelta.x * m_props.rotationSpeed * timestep;
				m_props.pitch -= mouseDelta.y * m_props.rotationSpeed * timestep;

				m_props.pitch = std::clamp(m_props.pitch, -89.f, 89.f); /**< Constrain pitch */
			}
			m_lastMousePosition = InputPoller::getMousePosition();
		}
		else
		{
			m_lastMousePosition.x = -1.0f;
		}

		if (camMoved)
		{
			glm::mat4 rotX = glm::rotate(glm::mat4(1.0f), m_props.pitch, glm::vec3(1.0f, 0.0f, 0.0f));
			glm::mat4 rotY = glm::rotate(glm::mat4(1.0f), m_props.yaw, glm::vec3(0.0f, 1.0f, 0.0f));
			m_model = glm::translate(glm::mat4(1.0f), m_props.position) * (rotX * rotY);

			m_camera.updateView(m_model);

			m_forward = { -m_model[2][0], -m_model[2][1], -m_model[2][2] };
			m_up = { m_model[1][0], m_model[1][1], m_model[1][2] };
			m_right = { m_model[0][0], m_model[0][1], m_model[0][2] };
		}
	}
}