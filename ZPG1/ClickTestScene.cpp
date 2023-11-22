#include "ClickTestScene.h"

void ClickTestScene::initScene()
{
	Camera* c = new Camera(this->window);

	BaseLight* light = new BaseLight(glm::vec3(0.0, 0.0, 0.0), glm::vec4(1.0, 1.0, 1.0, 1.0));
	LightRepository* lr = new LightRepository();

	TransformationComposite* initTranLeft = new TransformationComposite();
	initTranLeft->addTransformation(new TranslationTransformation(glm::vec3(.0, 0, 0)));
	TransformationComposite* updateTranLeft = new TransformationComposite(initTranLeft->applyTransformation());


	DrawableModel* left = new DrawableModel(
		new SphereModel(),
		new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 0, 0, .5), 16),
		new ConstantShader(c, lr),
		initTranLeft,
		updateTranLeft
	);

	this->drawableModels.push_back(
		left
	);


	TransformationComposite* initTranRight = new TransformationComposite();
	initTranRight->addTransformation(new TranslationTransformation(glm::vec3(0.0, 0, -4)));
	TransformationComposite* updateTranRight = new TransformationComposite(initTranRight->applyTransformation());


	DrawableModel* right = new DrawableModel(
		new SphereModel(),
		new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(.0, .0, 1, .5), 16),
		new ConstantShader(c, lr),
		initTranRight,
		updateTranRight
	);

	this->drawableModels.push_back(
		right
	);
}
