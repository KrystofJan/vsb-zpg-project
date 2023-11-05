#include "LightTestScene.h"

void LightTestScene::initScene()
{
	Camera* c = new Camera(this->window);
	//float pos = 10;


	LightRepository* lr = new LightRepository();

	Light* plainLight = new Light(	
		glm::vec3(7.0, 0, 0),
		glm::vec4(1.0, 1.0, 1.0, 1.0)
	);
	lr->addLight(plainLight);
	DirectionalLight* dl = new DirectionalLight(
		glm::vec3(2.0, 0, 0),
		glm::vec4(1.0, 1.0, 1.0, 1.0),

		glm::vec3(-0.2f, -1.0f, -0.3f),
		glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
		glm::vec4(0.4f, 0.4f, 0.4f, 1.0f),
		glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)
	);
	lr->addDirectionalLight(dl);
	SpotLight* sl = new SpotLight(
		glm::vec3(0.0, 10, 3),
		glm::vec4(1.0, 1.0, 1.0, 1.0),
		glm::vec3(0.0, 0, 0) - glm::vec3(0.0, 10, 3),
		glm::cos(glm::radians(12.5f)),
		glm::cos(glm::radians(15.0f)),
		0.2,
		0.2,
		0.2,
		glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
		glm::vec4(0.4f, 0.4f, 0.4f, 1.0f),
		glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)
	);
	lr->addSpotLight(sl);


	lr->addPointLight(
		new PointLight(
			glm::vec3(2.0, 0, 0),
			glm::vec4(1.0, 1.0, 1.0, 1.0),
			0.1,
			0.1,
			0.001,
			glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
			glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
		)
	);

	lr->addPointLight(
		new PointLight(
			glm::vec3(-13.0, 0, 0),
			glm::vec4(1.0, 1.0, 1.0, 1.0),
			0.5,
			0.5,
			0.01,
			glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
			glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
		)
	);

	lr->addPointLight(
		new PointLight(
			glm::vec3(0.0, 20.0, 0),
			glm::vec4(1.0, 1.0, 1.0, 1.0),
			0.5,
			0.5,
			0.01,
			glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
			glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
		)
	);
	//// light cubes
	//
	//TransformationComposite* transformCube1 = new TransformationComposite();
	//transformCube1->addTransformation(new TranslationTransformation(2.0, 'x'));
	//transformCube1->addTransformation(new ScaleTransformation(0.3));
	//transformCube1->applyTransformations();

	//TransformationComposite* tc1 = new TransformationComposite(transformCube1->getModelMatrix());
	//tc1->addTransformation(new RotationTransformation(0, 'x'));

	//this->drawableModels.push_back(
	//	new DrawableModel(new CubeModel(),
	//		new Material(glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
	//		new ConstantShader(c, plainLight),
	//		transformCube1,
	//		tc1
	//	)
	//);	

	//TransformationComposite* transformCube2 = new TransformationComposite();
	//transformCube2->addTransformation(new TranslationTransformation(-13.0, 'x'));
	//transformCube2->addTransformation(new ScaleTransformation(0.3));
	//transformCube2->applyTransformations();

	//TransformationComposite* tc2 = new TransformationComposite(transformCube2->getModelMatrix());
	//tc2->addTransformation(new RotationTransformation(0, 'x'));

	//this->drawableModels.push_back(
	//	new DrawableModel(new CubeModel(),
	//		new Material(glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
	//		new ConstantShader(c, plainLight),
	//		transformCube2,
	//		tc2
	//	)
	//);


	//TransformationComposite* transformCube3 = new TransformationComposite();
	//transformCube3->addTransformation(new TranslationTransformation(20.0, 'y'));
	//transformCube3->addTransformation(new ScaleTransformation(0.3));
	//transformCube3->applyTransformations();

	//TransformationComposite* tc3 = new TransformationComposite(transformCube3->getModelMatrix());
	//tc3->addTransformation(new RotationTransformation(0, 'x'));

	//this->drawableModels.push_back(
	//	new DrawableModel(new CubeModel(),
	//		new Material(),
	//		new ConstantShader(c, plainLight),
	//		transformCube3,
	//		tc3
	//	)
	//);
	// plain
	TransformationComposite* transformPlain = new TransformationComposite();
	transformPlain->addTransformation(new TranslationTransformation(-1, 'y'));
	transformPlain->addTransformation(new ScaleTransformation(5));
	transformPlain->applyTransformations();

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
	transform->applyTransformations();

	TransformationComposite* t = new TransformationComposite(transform->getModelMatrix());
	t->addTransformation(new RotationTransformation(0, 'x'));

	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(glm::vec4(1,1, 1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 1),
			new PhongShaderMultipleLights(c, lr),
			transform,
			t
		)
	);
}
