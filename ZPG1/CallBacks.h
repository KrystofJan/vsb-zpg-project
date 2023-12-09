#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

#include <stdlib.h>
#include <stdio.h>

class CallBacks
{
public:
	static bool clicked;
	static glm::vec3 position;
	static int stencil_id;
	static bool plantTree;
	static bool moveObj;
	static bool shoot;

	static void error_callback(int error, const char* description);

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static void window_focus_callback(GLFWwindow* window, int focused);

	static void window_iconify_callback(GLFWwindow* window, int iconified);

	static void window_size_callback(GLFWwindow* window, int width, int height);

	static void cursor_callback(GLFWwindow* window, double x, double y);

	static void button_callback(GLFWwindow* window, int button, int action, int mode);
};
