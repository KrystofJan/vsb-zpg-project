#include "SceneTwo.h"
void SceneTwo::initScene()
{
	Camera* c = new Camera(this->window);

	ScaleTransformation* sc = new ScaleTransformation(1);
	TransformationComposite* transform = new TransformationComposite();
	transform->addTransformation(new TranslationTransformation(1, 'z'));
	transform->addTransformation(sc);
	transform->applyTransformations();

	TransformationComposite* t = new TransformationComposite(transform->getModelMatrix());
	t->addTransformation(new TranslationTransformation(0.0, 'z'));

	Light* light = new Light(glm::vec3(0.0, 0.0, -1.0), glm::vec4(1.0, 1.0, 1.0, 1.0));
	LightRepository* lr = new LightRepository();

	lr->addLight(light);

	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(glm::vec4(0.1, 0.1, 0.1, 1.0), glm::vec4(0.385, 0.647, 0.812, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 0.0, 1.0), 1),
			new PhongShader(c, lr),
			transform,
			t
		)
	);
}

