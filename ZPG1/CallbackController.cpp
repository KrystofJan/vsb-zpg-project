#include "CallbackController.h"

CallBacks& CallbackController::getInstance()
{
	static CallBacks *instance;
	return *instance;
}

void CallbackController::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	return getInstance().key_callback(window, key, scancode, action, mods);
}

void CallbackController::error_callback(int error, const char* description) {
	return getInstance().error_callback(error, description);
}

void CallbackController::window_focus_callback(GLFWwindow* window, int focused) {
	return getInstance().window_focus_callback(window, focused);
}

void CallbackController::window_iconify_callback(GLFWwindow* window, int iconified) {

	return getInstance().window_iconify_callback(window, iconified);
}

void CallbackController::window_size_callback(GLFWwindow* window, int width, int height) {

	return getInstance().window_size_callback(window, width, height);
}

void CallbackController::cursor_callback(GLFWwindow* window, double x, double y) {

	return getInstance().cursor_callback(window, x, y);
}

void CallbackController::button_callback(GLFWwindow* window, int button, int action, int mode) {
	return getInstance().button_callback(window, button, action, mode);
}
