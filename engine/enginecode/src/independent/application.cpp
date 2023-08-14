/** \file application.cpp
*/
#include <iostream>
#include "engine_pch.h"
#include "core/application.h"
#include <glad/glad.h>
#include "platforms/OpenGL/OpenGLVertexArray.h"
#include "platforms/OpenGL/OpenGLShader.h"
#include "platforms/OpenGL/OpenGLTexture.h"
#include "rendering/indexBuffer.h"

#ifdef NG_PLATFORM_WINDOWS
	#include "platforms/windows/winTimer.h"
	#include "platforms/GLFW/GLFWSystem.h"
#endif

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace Engine {
#pragma region TEMP_CLASS
	class FCVertex
	{
	public:
		glm::vec3 m_pos;
		glm::vec3 m_colour;
		FCVertex() : m_pos(glm::vec3(0.f)), m_colour(glm::vec3(0.f)) {}
		FCVertex(const glm::vec3& pos, const glm::vec3 colour) : m_pos(pos), m_colour(colour) {}
		static BufferLayout getLayout() { return s_layout; }
	private:
		static BufferLayout s_layout;
	};

	class TPVertexNormalised
	{
	public:
		glm::vec3 m_pos;
		std::array<int16_t, 3> m_normal;
		std::array<int16_t, 2> m_uv;

		TPVertexNormalised() : m_pos(glm::vec3(0.f)), m_normal({ 0, 0, 0 }), m_uv({ 0, 0 }) {}
		TPVertexNormalised(const glm::vec3& pos, const std::array<int16_t, 3>& normal, const std::array<int16_t, 2>& uv) : m_pos(pos), m_normal(normal), m_uv(uv) {}
		static BufferLayout getLayout() { return s_layout; }
	private:
		static BufferLayout s_layout;
	};

	BufferLayout FCVertex::s_layout = { ShaderDataType::Float3, ShaderDataType::Float3 };
	BufferLayout TPVertexNormalised::s_layout = { {ShaderDataType::Float3, {ShaderDataType::Short3, true}, {ShaderDataType::Short2, true}}, 24 };
#pragma endregion
	// Set static vars
	Application* Application::s_instance = nullptr;
	CameraControllerEuler* eulerCamera;

	Application::Application()
	{
		if (s_instance == nullptr)
		{
			s_instance = this;
		}
		//start systems

		//start log
		m_logSystem.reset(new Log);
		m_logSystem->start();

		//reset timer
#ifdef NG_PLATFORM_WINDOWS
		m_timer.reset(new WinTimer);
		m_windowsSystem.reset(new GLFWSystem);
#else
		m_timer.reset(new ChronoTimer);
#endif
		// Start the timer.
		m_timer->start();

		// Start the window system.
		m_windowsSystem->start();

		// Define properties for the main application window.
		WindowProperties props("My Game Engine", 1024, 800);

		// Create the main application window.
		m_window.reset(Window::create(props));

		// Set event callbacks for various window events.
		m_window->getEventHandler().setOnFocusCallback(std::bind(&Application::onFocus, this, std::placeholders::_1));
		m_window->getEventHandler().setOnLostFocusCallback(std::bind(&Application::onLostFocus, this, std::placeholders::_1));
		m_window->getEventHandler().setOnCloseCallback(std::bind(&Application::onClose, this, std::placeholders::_1));
		m_window->getEventHandler().setOnSizeCallback(std::bind(&Application::onResize, this, std::placeholders::_1));
		m_window->getEventHandler().setOnKeyPressedCallback(std::bind(&Application::onKeyPressed, this, std::placeholders::_1));
		m_window->getEventHandler().setOnKeyReleasedCallback(std::bind(&Application::onKeyReleased, this, std::placeholders::_1));
		m_window->getEventHandler().setOnMouseButtonPressedCallback(std::bind(&Application::onMouseButtonPressed, this, std::placeholders::_1));
		m_window->getEventHandler().setOnMouseButtonReleasedCallback(std::bind(&Application::onMouseButtonReleased, this, std::placeholders::_1));
		m_window->getEventHandler().setOnMouseMovedCallback(std::bind(&Application::onMouseMoved, this, std::placeholders::_1));
		m_window->getEventHandler().setOnMouseScrollCallback(std::bind(&Application::onMouseScroll, this, std::placeholders::_1));

		InputPoller::setCurrentWindow(m_window->getNativeWindow());

		// Reset the timer.
		m_timer->reset();
	}

	bool Application::onFocus(WindowFocusEvent& e)
	{
		e.handle(true); // Mark the event as handled.
		Log::info("Gained Focus"); // Log an informational message indicating that the application gained focus.
		return e.handled(); // Return whether the event was handled.
	}
	
	bool Application::onLostFocus(WindowLostFocusEvent& e)
	{
		e.handle(true); // Mark the event as handled.
		Log::info("Lost Focus"); // Log an informational message indicating that the application lost focus.
		return e.handled(); // Return whether the event was handled.
	}
	
	bool Application::onClose(WindowCloseEvent& e)
	{
		e.handle(true); // Mark the event as handled.
		m_running = false; 
		return e.handled(); // Return whether the event was handled.
	}

	bool Application::onResize(WindowResizeEvent& e)
	{
		e.handle(true); // Mark the event as handled.
		auto& size = e.getSize();
		Log::info("Window resize event : ({0}, {1})", size.x, size.y); // Log an informational message indicating a window resize event with the new dimensions.
		return e.handled(); // Return whether the event was handled.
	}

	bool Application::onKeyPressed(KeyPressedEvent& e)
	{
		e.handle(true); // Mark the event as handled.
		Log::info("Key pressed event : Key: {0}, Repeat: {1}", e.getKeyCode(), e.getRepeatCount()); // Log an informational message indicating which key was pressed.
		return e.handled(); // Return whether the event was handled.
		std::cout << e.getKeyCode() << std::endl;
		//if(e.getKeyCode)
	}

	bool Application::onKeyReleased(KeyReleasedEvent& e)
	{
		e.handle(true); // Mark the event as handled.
		Log::info("Key released event : Key: {0}", e.getKeyCode()); // Log an informational message indicating which key was released.
		return e.handled(); // Return whether the event was handled.
	}

	bool Application::onMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		e.handle(true); // Mark the event as handled.
		Log::info("Mouse Button Pressed : Button: {0}", e.getButton()); // Log an informational message indicating which mouse button was pressed.
		return e.handled(); // Return whether the event was handled.
	}

	bool Application::onMouseButtonReleased(MouseButtonReleaseEvent& e)
	{
		e.handle(true); // Mark the event as handled.
		Log::info("Mouse Button Released : Button: {0}", e.getButton()); // Log an informational message indicating which mouse button was released.
		return e.handled(); // Return whether the event was handled.
	}

	bool Application::onMouseMoved(MouseMovedEvent& e)
	{
		e.handle(true); // Mark the event as handled.
		auto& position = e.getPos();
		Log::info("Mouse moved event: ({0}, {1})", position.x, position.y); // Log an informational message indicating the mouse has moved and to where.
		return e.handled(); // Return whether the event was handled.
	}

	bool Application::onMouseScroll(MouseScrolledEvent& e)
	{
		e.handle(true); // Mark the event as handled.
		Log::info("Mouse scroll event: {0}", e.getYOffset()); // Log an informational message indicating the scroll wheel was used and the direction.
		return e.handled(); // Return whether the event was handled. // Return whether the event was handled.
	}

	Application::~Application()
	{
		//stop systems
		m_logSystem->stop();

		//stop window system
		m_windowsSystem->stop();
	}


	void Application::run()
	{
#pragma region RAW_DATA

		float cubeVertices[8 * 24] = {
			//	 <------ Pos ------>  <--- normal --->  <-- UV -->
				 0.5f,  0.5f, -0.5f,  0.f,  0.f, -1.f,  0.f,   0.f,
				 0.5f, -0.5f, -0.5f,  0.f,  0.f, -1.f,  0.f,   0.5f,
				-0.5f, -0.5f, -0.5f,  0.f,  0.f, -1.f,  0.33f, 0.5f,
				-0.5f,  0.5f, -0.5f,  0.f,  0.f, -1.f,  0.33f, 0.f,

				-0.5f, -0.5f, 0.5f,   0.f,  0.f,  1.f,  0.33f, 0.5f,
				 0.5f, -0.5f, 0.5f,   0.f,  0.f,  1.f,  0.66f, 0.5f,
				 0.5f,  0.5f, 0.5f,   0.f,  0.f,  1.f,  0.66f, 0.f,
				-0.5f,  0.5f, 0.5f,   0.f,  0.f,  1.f,  0.33,  0.f,

				-0.5f, -0.5f, -0.5f,  0.f, -1.f,  0.f,  1.f,   0.f,
				 0.5f, -0.5f, -0.5f,  0.f, -1.f,  0.f,  0.66f, 0.f,
				 0.5f, -0.5f, 0.5f,   0.f, -1.f,  0.f,  0.66f, 0.5f,
				-0.5f, -0.5f, 0.5f,   0.f, -1.f,  0.f,  1.0f,  0.5f,

				 0.5f,  0.5f, 0.5f,   0.f,  1.f,  0.f,  0.f,   0.5f,
				 0.5f,  0.5f, -0.5f,  0.f,  1.f,  0.f,  0.f,   1.0f,
				-0.5f,  0.5f, -0.5f,  0.f,  1.f,  0.f,  0.33f, 1.0f,
				-0.5f,  0.5f, 0.5f,   0.f,  1.f,  0.f,  0.3f,  0.5f,

				-0.5f,  0.5f, 0.5f,  -1.f,  0.f,  0.f,  0.66f, 0.5f,
				-0.5f,  0.5f, -0.5f, -1.f,  0.f,  0.f,  0.33f, 0.5f,
				-0.5f, -0.5f, -0.5f, -1.f,  0.f,  0.f,  0.33f, 1.0f,
				-0.5f, -0.5f, 0.5f,  -1.f,  0.f,  0.f,  0.66f, 1.0f,

				 0.5f, -0.5f, -0.5f,  1.f,  0.f,  0.f,  1.0f,  1.0f,
				 0.5f,  0.5f, -0.5f,  1.f,  0.f,  0.f,  1.0f,  0.5f,
				 0.5f,  0.5f, 0.5f,   1.f,  0.f,  0.f,  0.66f, 0.5f,
				 0.5f, -0.5f, 0.5f,   1.f,  0.f,  0.f,  0.66f, 1.0f
		};

		std::vector<FCVertex> pyramidVertices(16);

		pyramidVertices.at(0) = FCVertex({ -0.5f, -0.5f, -0.5f }, { 0.8f, 0.2f, 0.8f });
		pyramidVertices.at(1) = FCVertex({ 0.5f, -0.5f, -0.5f }, { 0.8f, 0.2f, 0.8f });
		pyramidVertices.at(2) = FCVertex({ 0.5f, -0.5f,  0.5f }, { 0.8f, 0.2f, 0.8f });
		pyramidVertices.at(3) = FCVertex({ -0.5f, -0.5f,  0.5f }, { 0.8f, 0.2f, 0.8f });
		pyramidVertices.at(4) = FCVertex({ -0.5f, -0.5f, -0.5f }, { 0.2f, 0.8f, 0.2f });
		pyramidVertices.at(5) = FCVertex({ -0.5f, -0.5f,  0.5f }, { 0.2f, 0.8f, 0.2f });
		pyramidVertices.at(6) = FCVertex({ 0.0f,  0.5f,  0.0f }, { 0.2f, 0.8f, 0.2f });
		pyramidVertices.at(7) = FCVertex({ -0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f, 0.f });
		pyramidVertices.at(8) = FCVertex({ 0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f, 0.f });
		pyramidVertices.at(9) = FCVertex({ 0.0f,  0.5f,  0.0f }, { 1.0f, 0.0f, 0.f });
		pyramidVertices.at(10) = FCVertex({ 0.5f, -0.5f,  0.5f }, { 0.8f, 0.8f, 0.2f });
		pyramidVertices.at(11) = FCVertex({ 0.5f, -0.5f, -0.5f }, { 0.8f, 0.8f, 0.2f });
		pyramidVertices.at(12) = FCVertex({ 0.0f,  0.5f,  0.0f }, { 0.8f, 0.8f, 0.2f });
		pyramidVertices.at(13) = FCVertex({ 0.5f, -0.5f, -0.5f }, { 0.f,  0.2f, 1.0f });
		pyramidVertices.at(14) = FCVertex({ -0.5f, -0.5f, -0.5f }, { 0.f,  0.2f, 1.0f });
		pyramidVertices.at(15) = FCVertex({ 0.0f,  0.5f,  0.0f }, { 0.f,  0.2f, 1.0f });

		uint32_t pyramidIndices[3 * 6] =
		{
			0, 1, 2,
			2, 3, 0,
			4, 5, 6,
			7, 8, 9,
			10, 11, 12,
			13, 14, 15
		};

		uint32_t cubeIndices[3 * 12] = {
			0, 1, 2,
			2, 3, 0,
			4, 5, 6,
			6, 7, 4,
			8, 9, 10,
			10, 11, 8,
			12, 13, 14,
			14, 15, 12,
			16, 17, 18,
			18, 19, 16,
			20, 21, 22,
			22, 23, 20
		};
#pragma endregion

#pragma region GL_BUFFERS

		std::shared_ptr<OpenGLVertexArray> cubeVAO;
		std::shared_ptr<OpenGLVertexBuffer> cubeVBO;
		std::shared_ptr<IndexBuffer> cubeIBO;

		cubeVAO.reset(new OpenGLVertexArray);

		BufferLayout cubeBL = { ShaderDataType::Float3, ShaderDataType::Float3, ShaderDataType::Float2 };
		cubeVBO.reset(new OpenGLVertexBuffer(cubeVertices, sizeof(cubeVertices), cubeBL));

		cubeIBO.reset(IndexBuffer::create(cubeIndices, 36));

		cubeVAO->addVertexBuffer(cubeVBO);
		cubeVAO->setIndexBuffer(cubeIBO);

		cubeVAO->unbind();
		cubeVBO->unbind();

		std::shared_ptr<OpenGLVertexArray> pyramidVAO;
		std::shared_ptr<OpenGLVertexBuffer> pyramidVBO;
		std::shared_ptr<IndexBuffer> pyramidIBO;

		pyramidVAO.reset(new OpenGLVertexArray);

		BufferLayout pyramidBL = { ShaderDataType::Float3, ShaderDataType::Float3 };
		pyramidVBO.reset(new OpenGLVertexBuffer(pyramidVertices.data(), sizeof(FCVertex)* pyramidVertices.size(), FCVertex::getLayout()));

		pyramidIBO.reset(new OpenGLIndexBuffer(pyramidIndices, 18));

		pyramidVAO->addVertexBuffer(pyramidVBO);
		pyramidVAO->setIndexBuffer(pyramidIBO);

		pyramidVAO->unbind();
		pyramidVBO->unbind();

#pragma endregion

#pragma region SHADERS
		std::shared_ptr<OpenGLShader> TPShader;
		TPShader.reset(new OpenGLShader("./assets/shaders/texturePhong.glsl"));

		std::shared_ptr<OpenGLShader> FCShader;
		FCShader.reset(new OpenGLShader("./assets/shaders/flatColour.glsl"));
#pragma endregion 

#pragma region TEXTURES
		std::shared_ptr<OpenGLTexture> letterTexture;
		letterTexture.reset(new OpenGLTexture("./assets/textures/letterCube.png"));

		std::shared_ptr<OpenGLTexture> numberTexture;
		numberTexture.reset(new OpenGLTexture("./assets/textures/numberCube.png"));
#pragma endregion

		glm::mat4 models[3];
		models[0] = glm::translate(glm::mat4(1.0f), glm::vec3(-2.f, 0.f, -6.f));
		models[1] = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 0.f, -6.f));
		models[2] = glm::translate(glm::mat4(1.0f), glm::vec3(2.f, 0.f, -6.f));

		glEnable(GL_DEPTH_TEST);
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

		float timestep = 0.f;

		FPSEulerCameraProps props;
		CameraControllerEuler camera(props);
		eulerCamera = &camera;

		glEnable(GL_DEPTH_TEST);
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

		while (m_running)
		{
			timestep = m_timer->reset();

			// Do frame stuff
			float constant = 5.0f;
			for (auto& model : models) { model = glm::rotate(model, timestep * constant, glm::vec3(0.f, 1.0f, 0.f)); }

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glUseProgram(FCShader->getID());
			pyramidVAO->bind();

			GLuint uniformLocation;

			FCShader->uploadMat4("u_model", models[0]);
			FCShader->uploadMat4("u_view", eulerCamera->getCamera().view);
			FCShader->uploadMat4("u_projection", eulerCamera->getCamera().projection);

			glDrawElements(GL_TRIANGLES, pyramidVAO->getDrawCount(), GL_UNSIGNED_INT, nullptr);

			glUseProgram(TPShader->getID());
			cubeVAO->bind();

			TPShader->uploadMat4("u_model", models[1]);
			TPShader->uploadMat4("u_view", eulerCamera->getCamera().view);
			TPShader->uploadMat4("u_projection", eulerCamera->getCamera().projection);
			TPShader->uploadFloat4("u_tint", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
			TPShader->uploadFloat3("u_lightColour", glm::vec3(1.0f, 1.0f, 1.0f));
			TPShader->uploadFloat3("u_lightPos", glm::vec3(1.0f, 4.0f, 6.0f));
			TPShader->uploadFloat3("u_viewPos", glm::vec3(0.0f, 0.0f, 0.0f));

			uniformLocation = glGetUniformLocation(TPShader->getID(), "u_texData");
			glUniform1i(uniformLocation, 0);

			glBindTexture(GL_TEXTURE_2D, letterTexture->getID());
			uniformLocation = glGetUniformLocation(TPShader->getID(), "u_texData");
			glUniform1i(uniformLocation, 0);
			glDrawElements(GL_TRIANGLES, cubeVAO->getDrawCount(), GL_UNSIGNED_INT, nullptr);

			TPShader->uploadMat4("u_model", models[2]);


			glBindTexture(GL_TEXTURE_2D, numberTexture->getID());

			glDrawElements(GL_TRIANGLES, cubeVAO->getDrawCount(), GL_UNSIGNED_INT, nullptr);

			//Frame stuff
			eulerCamera->onUpdate(timestep);
			m_window->onUpdate(timestep);
		}

		Log::info("Exiting");
	}
}
