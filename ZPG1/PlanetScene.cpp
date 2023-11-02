#include "PlanetScene.h"

void PlanetScene::initScene()
{
	Camera* c = new Camera(this->window);
	float pos = 10;
	Light* light = new Light(glm::vec3(10, 0.0, 0.0), glm::vec4(1.0, 1.0, 0.0, 1.0));

	TransformationComposite* transform = new TransformationComposite();
	transform->addTransformation(new TranslationTransformation(10, 'x'));
	transform->applyTransformations();

	TransformationComposite* t = new TransformationComposite(transform->getModelMatrix());
	t->addTransformation(new RotationTransformation(0, 'x'));


	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 0.0, .5), 16),
			new ConstantShader(c, light),
			transform,
			t
		)
	);

	TransformationComposite* transform2 = new TransformationComposite();
	transform2->addTransformation(new TranslationTransformation(5.0, 'x'));
	transform2->applyTransformations();
	TransformationComposite* tr = new TransformationComposite(transform2->getModelMatrix());
	tr->addTransformation(new RotationTransformation(3.0f, glm::vec3(5.0, 0, 0)));
	
	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0.0, 1.0, 0.0, .5), 16),
			new LambertShader(c, light),
			transform2,
			tr
		)
	);

	TransformationComposite* transform3 = new TransformationComposite();
	transform3->addTransformation(new TranslationTransformation(-3.0, 'x'));
	transform3->applyTransformations();
	TransformationComposite* tr2 = new TransformationComposite(transform3->getModelMatrix());
	tr2->addTransformation(new RotationTransformation(1.5f, glm::vec3(13.0, 0, 0)));

	//tr2->addTransformation(new RotationTransformation(3.0f, glm::vec3(3.0, 0.0, 0)));

	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 0.5, 1.0, 1.0), 8),
			new PhongShader(c, light),
			transform3,
			tr2
		)
	);

	TransformationComposite* transform4 = new TransformationComposite();
	transform4->addTransformation(new TranslationTransformation(-4.0, 'x'));
	// transform4->addTransformation(new ScaleTransformation(.5));
	transform4->applyTransformations();

	TransformationComposite* tr4 = new TransformationComposite(transform4->getModelMatrix());

	// tr4->addTransformation(new RotationTransformation(1.5, glm::vec3(14.0, 0, 0)));
	tr4->addTransformation(new RotationTransformation(0,'y'));

	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0.5, 1.0, 1.0, 1.0), 8),
			new ConstantShader(c, light),
			transform4,
			tr4
		)
	);
}

void PlanetScene::display()
{


	for (DrawableModel* m : drawableModels) {
		
		m->DisplayDry();
	}
	setWindowSizeBuffer();

	drawableModels.at(3)->transformations->popTransformation();

	glm::vec4 initialPlanetosition = glm::vec4(-3.0, 0, 0, 1.0f);
	glm::vec4 planetWorldPosition = this->drawableModels.at(2)->transformations->getModelMatrix() * initialPlanetosition;

	glm::vec3 planetPos = glm::vec3(planetWorldPosition.x, planetWorldPosition.y, planetWorldPosition.z);

	glm::vec4 initialMoonPosition = glm::vec4(-4.0, 0, 0, 1.0f);
	glm::vec4 moonWorldPos = this->drawableModels.at(3)->transformations->getModelMatrix() * initialMoonPosition;
	glm::vec3 moonPos = glm::vec3(planetWorldPosition.x, planetWorldPosition.y, planetWorldPosition.z);

	// printf("%f, %f, %f\n", planetPos.x, planetPos.y, planetPos.z);
	drawableModels.at(3)->transformations->addTransformation(
		new RotationTransformation(3.0f, planetPos - moonPos)
	);
}
