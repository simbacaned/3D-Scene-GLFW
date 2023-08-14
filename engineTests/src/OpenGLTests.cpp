#include "OpenGLTest.h"

TEST(OpenGL, VertArrayConstructor) {
	GLFW_GL_mock mock;
	Engine::OpenGLVertexArray vao;
	uint32_t id = vao.getRenderID();
	EXPECT_EQ(id, 1);
}
