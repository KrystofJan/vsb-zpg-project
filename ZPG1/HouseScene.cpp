#include "HouseScene.h"
#include <stdlib.h>
#include <random>

void HouseScene::initScene()
{
	camera = new Camera(this->window);
	float pos = 3;
	lightRepository = new LightRepository();

	this->flashlight = new SpotLight(
		camera->getPosition(),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		camera->getDirection(),
		glm::cos(glm::radians(17.5f)),
		glm::cos(glm::radians(20.0f)),
		1.0f,
		0.2f,
		0.01f,
		glm::vec4(0.1, 0.1, 0.1, 1.0),
		glm::vec4(0.385, 0.647, 0.812, 1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0)
	);
	lightRepository->addLight(flashlight);

	DirectionalLight* dl = new DirectionalLight(
		glm::vec3(1.0, -1, 0),
		glm::vec4(1.0, 1.0, 1.0, 1.0),

		glm::vec3(-0.2f, -1.0f, -0.3f),
		glm::vec4(0.1, 0.1, 0.1, 1.0),
		glm::vec4(0.385, 0.647, 0.812, 1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0)
	);
	lightRepository->addLight(dl);

	TextureRepository* tex = new TextureRepository();


	tex->addTexture(new TextureCubeMap(
		"textures/nightSky/posx.bmp", "textures/nightSky/negx.bmp",
		"textures/nightSky/posy.bmp", "textures/nightSky/negy.bmp",
		"textures/nightSky/posz.bmp", "textures/nightSky/negz.bmp"
	));

	TransformationComposite* skyBoxTi = new TransformationComposite();
	skyBoxTi->applyTransformation();
	TransformationComposite* skyBoxTu = new TransformationComposite(skyBoxTi->getModelMatrix(), true);
	DrawableSkyBox* skybox = new DrawableSkyBox(
		new SkyCubeModel(),
		new Material(glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 0.0, 1.0), 16),
		tex->getTextureAt(0),
		new SkyBoxTextureShader(camera, lightRepository),
		skyBoxTi,
		skyBoxTu
	);

	this->drawableModels.push_back(
		skybox
	);


	TransformationComposite* initTerrainTran = new TransformationComposite();
	TransformationComposite* updateTerrainTran = new TransformationComposite(initTerrainTran->applyTransformation());

	tex->addTexture(new Texture2D("textures/models/grass.png"));


	drawableModels.push_back(
		new DrawableModel(
			new TerrainModel(),
			new Material(),
			tex->getTextureAt(1),
			new PhongMultipleLightsTextured(camera, lightRepository),
			initTerrainTran,
			updateTerrainTran
		)
	);

	TransformationComposite* initHouseTran = new TransformationComposite();
	initHouseTran->addTransformation(new ScaleTransformation(.1));
	TransformationComposite* updateHouseTran = new TransformationComposite(initHouseTran->applyTransformation());

	tex->addTexture(new Texture2D("textures/models/house.png"));

	drawableModels.push_back(
		new DrawableModel(
			new HouseModel(),
			new Material(),
			tex->getTextureAt(2),
			new PhongMultipleLightsTextured(camera, lightRepository),
			initHouseTran,
			updateHouseTran
		)
	);

	TransformationComposite* treeInit = new TransformationComposite();
	treeInit->addTransformation(new TranslationTransformation(glm::vec3(10, 0, 0)));
	treeInit->addTransformation(new ScaleTransformation(0.01));

	tex->addTexture(new Texture2D("textures/models/tree.png"));
	this->drawableModels.push_back(
		new DrawableModel(
			new TreeModel(),
			new Material(),
			tex->getTextureAt(3),
			new PhongMultipleLightsTextured(camera, lightRepository),
			treeInit,
			new TransformationComposite(treeInit->applyTransformation())
		)
	);

	//tree
	//tex->addTexture(new Texture2D("textures/models/tree.png"));
	//for (int i = 0; i < 5; ++i) 
	//{
	//	for (int j = 0; j < 5; ++j) 
	//	{
	//		std::random_device rd;  // Initialize the random number generator
	//		std::mt19937 gen(rd()); // Create a Mersenne Twister random number generator
	//		std::uniform_real_distribution<float> distribution(0.01, .1); // Define the range
	//		std::uniform_real_distribution<float> distribution2(0.0, 359.0); // Define the range
	//		std::uniform_real_distribution<float> xx(0.0, 10); // Define the range

	//		float scale_float = distribution(gen);
	//		float rot_float = distribution2(gen);
	//		float x = xx(gen);
	//		float y = xx(gen);

	//		TransformationComposite* tree_trans = new TransformationComposite();
	//		tree_trans->addTransformation(new TranslationTransformation(glm::vec3(x, 0.0, y)));
	//		tree_trans->addTransformation(new RotationTransformation(rot_float, glm::vec3(0.0, 1.0, 0.0)));
	//		tree_trans->addTransformation(new ScaleTransformation(scale_float));
	//		TransformationComposite* updating_tree_trans = new TransformationComposite(tree_trans->applyTransformation());

	//		this->drawableModels.push_back(
	//			new DrawableModel(
	//				new TreeModel(),
	//				new Material(),
	//				tex->getTextureAt(3),
	//				new PhongMultipleLightsTextured(camera, lightRepository),
	//				tree_trans,
	//				updating_tree_trans
	//			)
	//		);
	//	}
	//}
}

void HouseScene::display() {
	this->flashlight->updateDirection(camera->getDirection());
	this->flashlight->upgradePosition(camera->getPosition());

	if (CallBacks::clicked) {
		plantTreeToCursor();
		// printf("%f, %f, %f \n",CallBacks::position.x, CallBacks::position.y, CallBacks::position.z);

		CallBacks::clicked = false;
	}

	for (DrawableModel* m : drawableModels) {
		m->DisplayDry();
	}
	setWindowSizeBuffer();
}
