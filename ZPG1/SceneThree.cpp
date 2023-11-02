#include "SceneThree.h"

void SceneThree::initScene()
{
	Camera* c = new Camera(this->window);

	Light* light = new Light(glm::vec3(-10.0, 10.0, -1.0), glm::vec4(1.0, 1.0, 1.0, 1.0));


	glm::vec4 ambient = glm::vec4(0.1, 0.1, 0.1, 1.0);
	glm::vec4 diffuse = glm::vec4(0.385, 0.647, 0.812, 1.0);
	glm::vec4 specular_strength = glm::vec4(1.0, 1.0, 1.0, 1.0);
	glm::vec4 object_Color = glm::vec4(0.47, 0.0, 0.91, 1.0);
	float specular_intensity = 32;

	TransformationComposite* transform = new TransformationComposite();
	transform->addTransformation(new TranslationTransformation(-1, 'y'));
	transform->addTransformation(new ScaleTransformation(1.5));
	transform->applyTransformations();

	TransformationComposite* t = new TransformationComposite(transform->getModelMatrix());
	t->addTransformation(new RotationTransformation(0, 'x'));

	this->drawableModels.push_back(
		new DrawableModel(new PlainModel(),
			new Material(ambient, diffuse, specular_strength, object_Color, specular_intensity),
			new BlinnShader(c, light),
			transform,
			t
		)
	);


	object_Color = glm::vec4(0.91, 0.91, 0.12, 1.0);
	TransformationComposite* transform2 = new TransformationComposite();
	transform2->addTransformation(new TranslationTransformation(-1, 'y'));
	transform2->applyTransformations();

	TransformationComposite* tr = new TransformationComposite(transform2->getModelMatrix());
	tr->addTransformation(new RotationTransformation(0, 'x'));
	this->drawableModels.push_back(
		new DrawableModel(new TreeModel(),
			new Material(ambient, diffuse, specular_strength, object_Color, specular_intensity),
			new PhongShader(c, light),
			transform2,
			tr
		)
	);


	object_Color = glm::vec4(0.91, 0.12, 0.12, 1.0);
	TransformationComposite* transform3 = new TransformationComposite();
	transform3->addTransformation(new TranslationTransformation(0.5, 'x'));
	transform3->addTransformation(new TranslationTransformation(-1, 'y'));
	transform3->addTransformation(new TranslationTransformation(0.5, 'z'));
	transform3->applyTransformations();
	TransformationComposite* rt = new TransformationComposite(transform3->getModelMatrix());
	rt->addTransformation(new RotationTransformation(0 , 'x'));

	this->drawableModels.push_back(
		new DrawableModel(new GiftModel(),
			new Material(ambient, diffuse, specular_strength, object_Color, specular_intensity),
			new LambertShader(c, light),
			transform3,
			rt
		)
	);
}

