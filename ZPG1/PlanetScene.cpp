#include "PlanetScene.h"

void PlanetScene::initScene()
{
	Camera* c = new Camera(this->window);
	float pos = 10;
	Light* light = new Light(glm::vec3(10, 0.0, 0.0), glm::vec4(1.0, 1.0, 0.0, 1.0));
	LightRepository* lr = new LightRepository();

	lr->addLight(light);

	TransformationComposite* transform = new TransformationComposite();
	transform->addTransformation(new TranslationTransformation(10, 'x'));
	transform->applyTransformations();

	TransformationComposite* t = new TransformationComposite(transform->getModelMatrix());
	t->addTransformation(new RotationTransformation(0, 'x'));

	DrawableModel* sun = new DrawableModel(
		new SphereModel(),
		new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 0.0, .5), 16),
		new ConstantShader(c, lr),
		transform,
		t
	);

	this->drawableModels.push_back(
		sun
	);

	TransformationComposite* transform2 = new TransformationComposite();
	transform2->addTransformation(new TranslationTransformation(5.0, 'x'));
	transform2->applyTransformations();

	TransformationComposite* tr = new TransformationComposite(transform2->getModelMatrix());
	tr->addTransformation(new RotationTransformation(3.0f, glm::vec3(5.0, 0, 0)));
	
	this->drawableModels.push_back(
		new DrawableModel(
			new SphereModel(),
			new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0.0, 1.0, 0.0, .5), 16),
			new LambertShader(c, lr),
			transform2,
			tr
		)
	);

	TransformationComposite* transform3 = new TransformationComposite();
	transform3->addTransformation(new TranslationTransformation(-3.0, 'x'));
	transform3->applyTransformations();

	TransformationComposite* tr3 = new TransformationComposite(transform3->getModelMatrix());
	RotationTransformation* venusRot = new RotationTransformation(1.5f, glm::vec3(13.0, 0, 0));
	tr3->addTransformation(venusRot);

	//tr3->addTransformation(new RotationTransformation(3.0f, glm::vec3(3.0, 0.0, 0)));
	DrawableModel* venus = new DrawableModel(
		new SphereModel(),
		new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 0.5, 1.0, 1.0), 8),
		new PhongShader(c, lr),
		transform3,
		tr3
	);

	this->drawableModels.push_back(
		venus
	);

	TransformationComposite* transform4 = new TransformationComposite();
	// transform4->addTransformation(new TranslationTransformation(0, 'x'));
	// transform4->addTransformation(new ScaleTransformation(.5));
	transform4->applyTransformations();

	TransformationComposite* tr4 = new TransformationComposite(transform4->getModelMatrix());
	TransformationComposite* dummy = new TransformationComposite();
	dummy->addTransformation(new RotationTransformation(1, 'z'));
	RotationTransformation* moonRotation = new RotationTransformation(3, glm::vec3(3.0, 0, 0), dummy);
	
	tr4->addTransformation(venusRot);
	tr4->addTransformation(moonRotation);

	DrawableModel* moon = new DrawableModel(
		new SphereModel(),
		new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0.5, 1.0, 1.0, 1.0), 8),
		new ConstantShader(c, lr),
		transform4,
		tr4
	);
	// moonRotation->bindRotatedModel(moon);
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

	// drawableModels.at(3)->transformations->popTransformation();

	// glm::vec4 initialPlanetosition = glm::vec4(-3.0, 0, 0, 1.0f);
	// glm::vec4 planetWorldPosition = this->drawableModels.at(2)->transformations->getModelMatrix() * initialPlanetosition;

	// glm::vec3 planetPos = glm::vec3(planetWorldPosition.x, planetWorldPosition.y, planetWorldPosition.z);

	// glm::vec4 initialMoonPosition = glm::vec4(-4.0, 0, 0, 1.0f);
	// glm::vec4 moonWorldPos = this->drawableModels.at(3)->transformations->getModelMatrix() * initialMoonPosition;
	// glm::vec3 moonPos = glm::vec3(planetWorldPosition.x, planetWorldPosition.y, planetWorldPosition.z);

	// printf("%f, %f, %f\n", planetPos.x, planetPos.y, planetPos.z);
	//drawableModels.at(3)->transformations->addTransformation(
	//	new RotationTransformation(3.0f, planetPos)
	//);
}
