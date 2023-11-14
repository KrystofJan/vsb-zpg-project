#include "LightTestScene.h"

void LightTestScene::initScene()
{
	c = new Camera(this->window);

	LightRepository* lr = new LightRepository();

	//BaseLight* plainLight = new BaseLight(	
	//	glm::vec3(7.0, 0, 0),
	//	glm::vec4(1.0, 1.0, 1.0, 1.0)
	//);
	// lr->addLight(plainLight);
	DirectionalLight* dl = new DirectionalLight(
		glm::vec3(2.0f, .0f, .0f),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),

		glm::vec3(-0.2f, -1.0f, -0.3f),
		glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
		glm::vec4(0.4f, 0.4f, 0.4f, 1.0f),
		glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)
	);
	lr->addLight(dl);
	this->flashlight = new SpotLight(
		c->getPosition(),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		c->getDirection(),
		glm::cos(glm::radians(12.5f)),
		glm::cos(glm::radians(15.0f)),
		0.4f,
		0.4f,
		0.1f,
		glm::vec4(0.1, 0.1, 0.1, 1.0),
		glm::vec4(0.385, 0.647, 0.812, 1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0)
	);
	lr->addLight(flashlight);


	lr->addLight(
		new PointLight(
			glm::vec3(2.0, 0, 0),
			glm::vec4(1.0, 1.0, 1.0, 1.0),
			0.4f,
			0.4f,
			0.1f,
			glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
			glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
		)
	);

	// plain
	TransformationComposite* transformPlain = new TransformationComposite();
	transformPlain->addTransformation(new TranslationTransformation(-1, 'y'));
	transformPlain->addTransformation(new ScaleTransformation(5));
	transformPlain->applyTransformation();

	TransformationComposite* tp = new TransformationComposite(transformPlain->getModelMatrix());
	tp->addTransformation(new RotationTransformation(0, 'x'));

	this->drawableModels.push_back(
		new DrawableModel(new PlainModel(),
			new Material(glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
			new PhongShaderMultipleLights(c, lr),
			transformPlain,
			tp
		)
	);

	TransformationComposite* transform = new TransformationComposite();
	transform->addTransformation(new TranslationTransformation(0, 'x'));
	transform->addTransformation(new ScaleTransformation(0.5));
	transform->applyTransformation();

	TransformationComposite* t = new TransformationComposite(transform->getModelMatrix());
	t->addTransformation(new RotationTransformation(0, 'x'));

	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(glm::vec4(1,1, 1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
			new PhongShaderMultipleLights(c, lr),
			transform,
			t
		)
	);

	TransformationComposite* transform2 = new TransformationComposite();
	transform2->addTransformation(new TranslationTransformation( -3.0, 'z'));
	transform2->addTransformation(new ScaleTransformation(0.5));
	transform2->applyTransformation();

	TransformationComposite* t2 = new TransformationComposite(transform2->getModelMatrix());
	t2->addTransformation(new RotationTransformation(0, 'x'));

	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(glm::vec4(1,1, 1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
			new PhongShaderMultipleLights(c, lr),
			transform2,
			t2
		)
	);

	TransformationComposite* transform3 = new TransformationComposite();
	transform3->addTransformation(new TranslationTransformation( 3, 'z'));
	transform3->addTransformation(new TranslationTransformation( -2, 'x'));
	transform3->addTransformation(new ScaleTransformation(0.5));
	transform3->applyTransformation();

	TransformationComposite* t3 = new TransformationComposite(transform3->getModelMatrix());
	t3->addTransformation(new RotationTransformation(0, 'x'));

	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(glm::vec4(1,1, 1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
			new PhongShaderMultipleLights(c, lr),
			transform3,
			t3
		)
	);
}

void LightTestScene::display() {
	this->flashlight->updateDirection(c->getDirection());
	this->flashlight->upgradePosition(c->getPosition());

	for (DrawableModel* m : drawableModels) {
		m->DisplayDry();
	}
	setWindowSizeBuffer();
}