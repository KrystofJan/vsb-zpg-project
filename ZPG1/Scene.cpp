#include "Scene.h"

Scene::Scene() {
	glfwSetErrorCallback([](int error, const char* description)-> void { CallbackController::getInstance().error_callback(error, description); });
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	this->window = glfwCreateWindow(800, 800, "ZPG", NULL, NULL);
	if (!this->window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	camera = new Camera(this->window);
	bezierBuilder = new BezierBuilder(camera);

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


	bezierSequence->curves.push_back(
		new BezierCurve(
			glm::mat4x3(
				glm::vec3(0, 0, 0),
				glm::vec3(10, 0, 0),
				glm::vec3(10, 0, 10),
				glm::vec3(0, 0, 10)
			)
		)
	);

	bezierSequence->curves.push_back(
		new BezierCurve(
			glm::mat4x3(
				glm::vec3(0, 0, 10),
				glm::vec3(-10, 0, 10),
				glm::vec3(-10, 0, 20),
				glm::vec3(0, 0, 20)
			)
		)
	);
	bezierSequence->curves.push_back(
		new BezierCurve(
			glm::mat4x3(
				glm::vec3(0, 0, 20),
				glm::vec3(10, 0, 20),
				glm::vec3(10, 0, 30),
				glm::vec3(0, 0, 30)
			)
		)
	);
	bezierSequence->curves.push_back(
		new BezierCurve(
			glm::mat4x3(
				glm::vec3(0, 0, 30),
				glm::vec3(10, 0, 30),
				glm::vec3(10, 0, 20),
				glm::vec3(0, 0, 20)
			)
		)
	);	
	bezierSequence->curves.push_back(
		new BezierCurve(
			glm::mat4x3(
				glm::vec3(0, 0, 20),
				glm::vec3(-10, 0, 20),
				glm::vec3(-10, 0, 10),
				glm::vec3(0, 0, 10)
			)
		)
	);
	bezierSequence->curves.push_back(
		new BezierCurve(
			glm::mat4x3(
				glm::vec3(0, 0, 10),
				glm::vec3(10, 0, 10),
				glm::vec3(10, 0, 0),
				glm::vec3(0, 0, 0)
			)
		)
	);

	// loadModels();
}

void Scene::loadModels() {
	treeModel = new TreeModel();
	treeMaterial = new Material(
		glm::vec4(1.0, 1.0, 1.0, 1.0), //ambient
		glm::vec4(1, 1, 1, 1.0), //diffuse
		glm::vec4(1.0, 1.0, 1.0, 1.0), //specular strength
		glm::vec4(1.0, 1.0, 1.0, 1.0), // object color
		16 // specular intensity
	);
	treeTexture = new Texture2D("textures/models/tree.png");
	tex->addTexture(treeTexture);

	treeTexture->Bind();

	zombieModel = new ZombieModel();
	zombieMaterial = new Material(
		glm::vec4(1.0, 1.0, 1.0, 1.0), //ambient
		glm::vec4(1, 1, 1, 1.0), //diffuse
		glm::vec4(1.0, 1.0, 1.0, 1.0), //specular strength
		glm::vec4(1.0, 1.0, 1.0, 1.0), // object color
		16 // specular intensity
	);
	zombieTexture = new Texture2D("textures/models/zombie.png");
	tex->addTexture(zombieTexture);
	zombieTexture->Bind();
	houseModel = new HouseModel();
	houseMaterial = new Material();
	houseTexture = new Texture2D("textures/models/house.png");
	tex->addTexture(houseTexture);

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
	if (CallBacks::clicked) {
		plantTreeToCursor();
		CallBacks::clicked = false;
	}

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

void Scene::plantTreeToCursor()
{

	if (picked_id > 0) {
		glm::vec3 position = this->camera->unProjectCameraPos(CallBacks::position);
		TransformationComposite* initT = new TransformationComposite();
		initT->addTransformation(new TranslationTransformation(position));
		initT->addTransformation(new ScaleTransformation(0.1));

		DrawableModel* model;
		if (pickedType == "tree") {
			model = new DrawableModel(
				treeModel,
				treeMaterial,
				treeTexture,
				treeShader,
				initT,
				new TransformationComposite(initT->applyTransformation())
			);
			drawableModels.push_back(model);

		}
		else if (pickedType == "zombie") {
			model = new DrawableModel(
				zombieModel,
				zombieMaterial,
				zombieTexture,
				zombieShader,
				initT,
				new TransformationComposite(initT->applyTransformation()),
				true
			);
			drawableModels.push_back(model);

		}
		else if (pickedType == "house") {
			model = new DrawableModel(
				houseModel,
				houseMaterial,
				houseTexture,
				houseShader,
				initT,
				new TransformationComposite(initT->applyTransformation())
			);
			drawableModels.push_back(model);

		}
		picked_id = -1;
		return;
	}

	for (int i = 0; i < drawableModels.size(); i++) {

		if (drawableModels[i]->compareIdToStencil(CallBacks::stencil_id) )
		{
			pickedType = drawableModels[i]->getType();
			picked_id = CallBacks::stencil_id;
			break;
		}
	}
	CallBacks::plantTree = false;
}

void Scene::travelOnLine(int index)
{
	drawableModels[index]->transformations->resetComposite(/*glm::mat4(1)*/);
	drawableModels[index]->transformations->addTransformation(new TranslationTransformation(b->calculatePoint()));
}

void Scene::travelBezier()
{
	if (b != nullptr) {

		for (int i = 0; i < drawableModels.size(); i++) {

			if (drawableModels[i]->compareIdToStencil(stencil_id) && !bezierSequence->isFinished())
			{ 
				drawableModels[i]->transformations->resetComposite(/*drawableModels[i]->initTransformations->applyTransformation()*/);
				drawableModels[i]->transformations->addTransformation(new TranslationTransformation(bezierSequence->calculatePoint()));
				drawableModels[i]->transformations->addTransformation(drawableModels[i]->initTransformations);

				break;
			}
		}

	}
	else if (bezierBuilder->getStep() < 1 && CallBacks::moveObj && CallBacks::stencil_id != 1) {
		bezierBuilder->handleAssignment();
		CallBacks::moveObj = false;
	}
	else if (bezierBuilder->getStep() == 1 && CallBacks::stencil_id != 1){
		bezier = bezierBuilder->buildBezier();
		b = new BezierCurve(bezier);
		stencil_id = bezierBuilder->getStencil();
		CallBacks::moveObj = false;
	}
}
