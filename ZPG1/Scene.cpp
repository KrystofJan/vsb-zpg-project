#include "Scene.h"

static void error_callback(int error, const char* description) { fputs(description, stderr); }
/*
static void error_callback(int error, const char* description) {
	CallbackController& callbackController = CallbackController::getInstance();
	callbackController.error_callback(error, description);
}
*/
Scene::Scene() {

	glfwSetErrorCallback([](int error, const char* description)-> void { CallbackController::getInstance().error_callback(error, description); });
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	/* //inicializace konkretni verze
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,
	GLFW_OPENGL_CORE_PROFILE);  //*/

	this->window = glfwCreateWindow(800, 800, "ZPG", NULL, NULL);
	if (!this->window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(this->window);
	glfwSwapInterval(1);

	this->setMouseMoveCallback();
	this->setMouseClickCallback();
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}

bool Scene::isWindowClosed() {
	return glfwWindowShouldClose(this->window);
}

void Scene::swapBuffer() {
	glfwSwapBuffers(this->window);
}

void Scene::destroyWindow() {
	glfwDestroyWindow(this->window);
}

void Scene::displayTransform() {
	for (DrawableModel* m : drawableModels) {
		m->Display();
		int width, height;
		glfwGetFramebufferSize(this->window, &width, &height);
		float ratio = width / (float)height;
		glViewport(0, 0, width, height);
	}
}
void Scene::display() {
	for (DrawableModel* m : drawableModels) {
		m->DisplayDry();
	}
	setWindowSizeBuffer();
}

void Scene::setWindowSizeBuffer() {
	glfwSetWindowSizeCallback(this->window, [](GLFWwindow* window, int width, int height)-> void {CallbackController::getInstance().window_size_callback(window, width, height); });
}

void Scene::setMouseClickCallback()
{
	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mode)-> void {CallbackController::getInstance().button_callback(window, button, action, mode); });
}

void Scene::setMouseMoveCallback()
{
	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double cx, double cy)-> void {CallbackController::getInstance().cursor_callback(window, cx, cy); });
}

