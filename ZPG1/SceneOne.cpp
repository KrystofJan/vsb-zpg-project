#include "SceneOne.h"

void SceneOne::initScene()
{
	camera = new Camera(this->window);

	BaseLight* light = new BaseLight(glm::vec3(0.0, 0.0, 0.0), glm::vec4(1.0, 1.0, 1.0, 1.0));
	lightRepository = new LightRepository();

	lightRepository->addLight(light);
	glm::vec4 ambient = glm::vec4(0.1, 0.1, 0.1, 1.0);
	glm::vec4 diffuse = glm::vec4(0.385, 0.647, 0.812, 1.0);
	glm::vec4 specular_strength = glm::vec4(1.0, 1.0, 1.0, 1.0);
	glm::vec4 object_Color = glm::vec4(0.91, 0.97, 0.65, 1.0);
	float specular_intensity = 32;

	ScaleTransformation* sc = new ScaleTransformation(.5);
	TransformationComposite* transform = new TransformationComposite();
	transform->addTransformation(new TranslationTransformation(1, 'y'));
	transform->addTransformation(sc);

	TransformationComposite* tr = new TransformationComposite(transform->applyTransformation());

	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(ambient, diffuse, specular_strength, object_Color, specular_intensity),
			new PhongShader(camera, lightRepository),
			transform,
			tr
		)
	);


	object_Color = glm::vec4(0.47, 0.91, 0.65, 1.0);
	TransformationComposite* transform2 = new TransformationComposite();
	transform2->addTransformation(new TranslationTransformation(-1, 'y'));
	transform2->addTransformation(sc);

	TransformationComposite* tr2 = new TransformationComposite(transform2->applyTransformation());

	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(ambient, diffuse, specular_strength, object_Color, specular_intensity),
			new PhongShader(camera, lightRepository),
			transform2,
			tr2
		)
	);


	object_Color = glm::vec4(0.47, 0.65, 0.91, 1.0);
	TransformationComposite* transform3 = new TransformationComposite();
	transform3->addTransformation(new TranslationTransformation(1, 'x'));
	transform3->addTransformation(sc);

	TransformationComposite* tr3 = new TransformationComposite(transform3->applyTransformation());

	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(ambient, diffuse, specular_strength, object_Color, specular_intensity),
			new PhongShader(camera, lightRepository),
			transform3,
			tr3
		)
	);

	TransformationComposite* transform4 = new TransformationComposite();
	transform4->addTransformation(new TranslationTransformation(-1, 'x'));
	transform4->addTransformation(sc);

	TransformationComposite* tr4 = new TransformationComposite(transform4->applyTransformation());

	object_Color = glm::vec4(0.91, 0.47, 0.91, 1.0);
	this->drawableModels.push_back(
		new DrawableModel(new SphereModel(),
			new Material(ambient, diffuse, specular_strength, object_Color, specular_intensity),
			new BlinnShader(camera, lightRepository),
			transform4,
			tr4
		)
	);
}
