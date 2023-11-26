#include "ModelLoadingScene.h"

void ModelLoadingScene::initScene()
{
	camera = new Camera(this->window);
	lightRepository = new LightRepository();
	TextureRepository* tr = new TextureRepository();
	DirectionalLight* dl = new DirectionalLight(
		glm::vec3(.0, 10, 0),
		glm::vec4(0.956863, 0.913725, 0.607843, 1.0),

		glm::vec3(-0.5f, -1.0f, 0.5f),

		glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
		glm::vec4(0.4f, 0.4f, 0.4f, 1.0f),
		glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)
	);
	lightRepository->addLight(dl);

	DirectionalLight* dld = new DirectionalLight(
		glm::vec3(.0, 10, 0),
		glm::vec4(0.956863, 0.913725, 0.607843, 1.0),

		glm::vec3(-1.0f, 0.0f, 0.0f),

		glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
		glm::vec4(0.4f, 0.4f, 0.4f, 1.0f),
		glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)
	);
	lightRepository->addLight(dld);

	TransformationComposite* initHouseTran = new TransformationComposite();
	initHouseTran->addTransformation(new ScaleTransformation(.1));
	TransformationComposite* updateHouseTran = new TransformationComposite(initHouseTran->applyTransformation());

	tr->addTexture(new Texture2D("textures/models/tree.png"));

	drawableModels.push_back(
		new DrawableModel(
			new TreeModel(),
			new Material(),
			tr->getTextureAt(0),
			new TextureShader(camera, lightRepository),
			initHouseTran,
			updateHouseTran
		)
	);

	TransformationComposite* initZombieTran = new TransformationComposite();
	initZombieTran->addTransformation(new TranslationTransformation(glm::vec3(6.0, 0, 3.5)));
	initZombieTran->addTransformation(new RotationTransformation(45.0f, glm::vec3(0,1,0)));

	TransformationComposite* updateZombieTran = new TransformationComposite(initZombieTran->applyTransformation());

	tr->addTexture(new Texture2D("textures/models/zombie.png"));

	drawableModels.push_back(
		new DrawableModel(
			new ZombieModel(),
			new Material(),
			tr->getTextureAt(1),
			new TextureShader(camera, lightRepository),
			initZombieTran,
			updateZombieTran
		)
	);

}
