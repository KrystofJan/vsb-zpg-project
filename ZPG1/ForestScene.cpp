#include "ForestScene.h"
#include <stdlib.h>
void ForestScene::initScene()
{
	Camera* c = new Camera(this->window);
	float pos = 3;
	Light* light = new Light(glm::vec3(3, 0.0, 0.0), glm::vec4(1.0, 1.0, 0.0, 1.0));
	LightRepository* lr = new LightRepository();

	lr->addLight(light);

	TransformationComposite* transform = new TransformationComposite();
	transform->addTransformation(new ScaleTransformation(1000));
	transform->applyTransformations();

	TransformationComposite* t = new TransformationComposite(transform->getModelMatrix());
	t->addTransformation(new RotationTransformation(0, 'x'));

	this->drawableModels.push_back(
		new DrawableModel(new PlainModel(),
			new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
			new ConstantShader(c, lr),
			transform,
			t
		)
	);

	for (int i = -10; i < 0; i++) {
		TransformationComposite* transform2 = new TransformationComposite();

		transform2->addTransformation(new TranslationTransformation(rand() % 21 - 10, 'z'));
		for (int j = -10; j < 0; j++) {
			transform2->addTransformation(new TranslationTransformation(rand() % 21 - 10 , 'x'));

			transform2->applyTransformations();

			TransformationComposite* t2 = new TransformationComposite(transform2->getModelMatrix());
			t2->addTransformation(new RotationTransformation(0, 'x'));
			this->drawableModels.push_back(
				new DrawableModel(new TreeModel(),
					new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0.0, 1.0, 0.0, 1.0), 16),
					new PhongShader(c, lr),
					transform2,
					t2
				)
			);
		}
		
	}


	TransformationComposite* transform3 = new TransformationComposite();
	transform3->addTransformation(new ScaleTransformation(1));
	transform3->addTransformation(new TranslationTransformation(1, 'y'));
	transform3->applyTransformations();

	TransformationComposite* t3 = new TransformationComposite(transform3->getModelMatrix());
	t3->addTransformation(new RotationTransformation(0, 'x'));


	this->drawableModels.push_back(
		new DrawableModel(new BushModel(),
			new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
			new LambertShader(c, lr),
			transform3,
			t3
		)
	);


	TransformationComposite* transform4 = new TransformationComposite();
	transform4->addTransformation(new ScaleTransformation(1));
	transform4->addTransformation(new TranslationTransformation(3,'x'));
	transform4->addTransformation(new TranslationTransformation(1,'y'));
	transform4->applyTransformations();

	TransformationComposite* t4 = new TransformationComposite(transform4->getModelMatrix());
	t4->addTransformation(new RotationTransformation(0, 'x'));


	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0.0, 1.0, 1.0, 1.0), 16),
			new PhongShader(c, lr),
			transform4,
			t4
		)
	);

	TransformationComposite* transform5 = new TransformationComposite();
	transform5->addTransformation(new ScaleTransformation(1));
	transform5->addTransformation(new TranslationTransformation(-3, 'x'));
	transform5->addTransformation(new TranslationTransformation(1, 'y'));
	transform5->applyTransformations();

	TransformationComposite* t5 = new TransformationComposite(transform5->getModelMatrix());
	t5->addTransformation(new RotationTransformation(0, 'x'));

	this->drawableModels.push_back(
		new DrawableModel(new SuziModel(),
			new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 0.0, 1.0), 16),
			new BlinnShader(c, lr),
			transform5,
			t5
		)
	);

}
