#include "PlanetScene.h"

void PlanetScene::initScene()
{
	Camera* c = new Camera(this->window);
	float pos = 10;
	BaseLight* light = new BaseLight(glm::vec3(0.0, 0.0, 0.0), glm::vec4(1.0, 1.0, 0.5, 1.0));
	LightRepository* lr = new LightRepository();

	lr->addLight(light);

	TransformationComposite* sunInitTransform = new TransformationComposite();
	sunInitTransform->addTransformation(new ScaleTransformation(2));

	sunUpdatingTransform = new TransformationComposite(sunInitTransform->applyTransformation());

	DrawableModel* sun = new DrawableModel(
		new SphereModel(),
		new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 0.5, .5), 16),
		new ConstantShader(c, lr),
		sunInitTransform,
		sunUpdatingTransform
	);

	this->drawableModels.push_back(
		sun
	);

	TransformationComposite* earthInitTransform = new TransformationComposite();
	earthInitTransform->addTransformation(new TranslationTransformation(-8.0, 'x'));
	earthInitTransform->applyTransformation();

	earthUpdatingTransform = new TransformationComposite(earthInitTransform->getModelMatrix());
	earthUpdatingTransform->addTransformation(new TranslationTransformation(glm::vec3(8.0, 0, 0)));
	earthUpdatingTransform->addTransformation(new RotationTransformation(1.5, glm::vec3(0, 1, 0)));
	earthUpdatingTransform->addTransformation(new TranslationTransformation(glm::vec3(-8.0, 0, 0)));

	this->earth = new DrawableModel(
		new SphereModel(),
		new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0, 1, 0, 1.0), 8),
		new PhongShader(c, lr),
		earthInitTransform,
		earthUpdatingTransform
	);

	this->drawableModels.push_back(
		earth
	);

	TransformationComposite* moonInitTransform = new TransformationComposite();

	TransformationComposite* moon2InitTransform = new TransformationComposite();
	moon2InitTransform->addTransformation(new TranslationTransformation(-3.0, 'x'));
	// moon2InitTransform->addTransformation(new ScaleTransformation(0.2));

	moon2InitTransform->applyTransformation();

	TransformationComposite* moonUpdt = new TransformationComposite(moon2InitTransform->getModelMatrix());
	// moonUpdt->addTransformation(new ScaleTransformation(0.5));

	moonUpdt->addTransformation(new TranslationTransformation(glm::vec3(3.0, 0, 0)));
	moonUpdt->addTransformation(new RotationTransformation(5, glm::vec3(0, 1, 0)));
	moonUpdt->addTransformation(new TranslationTransformation(glm::vec3(-3.0, 0, 0)));

	moonUpdateTransform = new TransformationComposite(moonInitTransform->getModelMatrix(), true);

	moonUpdateTransform->addTransformation(earthUpdatingTransform);
	moonUpdateTransform->addTransformation(moonUpdt);
	moonUpdateTransform->addTransformation(new ScaleTransformation(0.5));

	this->moon = new DrawableModel(
		new SphereModel(),
		new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(.4, 0.4, 0.8, .5), 64),
		new PhongShader(c, lr),
		moonInitTransform,
		moonUpdateTransform
	);

	this->drawableModels.push_back(
		moon
	);
}

void PlanetScene::display()
{
	for (DrawableModel* m : drawableModels) {
		m->DisplayDry();
	}
	setWindowSizeBuffer();
}
