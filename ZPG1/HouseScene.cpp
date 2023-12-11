#include "HouseScene.h"
#include <stdlib.h>
#include <random>

void HouseScene::initScene()
{

	float pos = 3;
	lightRepository = new LightRepository();
	loadModels();
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
		glm::vec4(1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0)
	);
	lightRepository->addLight(flashlight);

	lightRepository->addLight(
		new PointLight(
			glm::vec3(-2.0, .5, -4),
			glm::vec4(1.0, 0.0, 0.0, 1.0),
			1.f,
			0.01f,
			0.001f,
			glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
			glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
		)
	);

	lightRepository->addLight(
		new PointLight(
			glm::vec3(-4.0, 1, 0),
			glm::vec4(1.0, 1.0, 1.0, 1.0),
			0.4f,
			0.4f,
			0.1f,
			glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
			glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
		)
	);


	lightRepository->addLight(
		new PointLight(
			glm::vec3(2.0, 1, 5),
			glm::vec4(1.0, 1.0, 1.0, 1.0),
			0.4f,
			0.4f,
			0.1f,
			glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
			glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
		)
	);

	lightRepository->addLight(
		new PointLight(
			glm::vec3(3.0, 1, 0),
			glm::vec4(1.0, 1.0, 1.0, 1.0),
			0.4f,
			0.4f,
			0.1f,
			glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
			glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
		)
	);

	//DirectionalLight* dl = new DirectionalLight(
	//	glm::vec3(0.0, 10, 0),
	//	glm::vec4(1.0, 1.0, 1.0, 1.0),

	//	glm::vec3(0.0f, -1.0f, 0.0f),

	//	glm::vec4(0.1, 0.1, 0.1, 1.0),
	//	glm::vec4(0.4, 0.4, 0.4, 1.0),
	//	glm::vec4(1.0)
	//);

	// lightRepository->addLight(dl);

	tex = new TextureRepository();

	tex->addTexture(new TextureCubeMap(
		"textures/nightSky/posz.bmp", "textures/nightSky/negz.bmp",
		"textures/nightSky/posy.bmp", "textures/nightSky/negy.bmp",
		"textures/nightSky/posx.bmp", "textures/nightSky/negx.bmp"
	));

	TransformationComposite* skyBoxTi = new TransformationComposite();

	TransformationComposite* skyBoxTu = new TransformationComposite(skyBoxTi->applyTransformation(), true);
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

	TransformationComposite* initTerrainTran = new TransformationComposite(true);
	TransformationComposite* updateTerrainTran = new TransformationComposite(initTerrainTran->applyTransformation());

	tex->addTexture(new Texture2D("textures/models/grass.png"));

	drawableModels.push_back(
		new DrawableModel(
			new TerrainModel(),
			new Material(
				glm::vec4(0, 0, 0, 1.0),
				glm::vec4(0.7, 0.7, 0.7, 1.0),
				glm::vec4(1.0, 1.0, 1.0, 1.0),
				glm::vec4(0.1, 0.1, 0.1, 1.0),
				32
			),
			tex->getTextureAt(1),
			new PhongMultipleLightsTextured(camera, lightRepository),
			initTerrainTran,
			updateTerrainTran
		)
	);

	TransformationComposite* initHouseTran = new TransformationComposite(true);
	initHouseTran->addTransformation(new ScaleTransformation(.1));
	TransformationComposite* updateHouseTran = new TransformationComposite(true);
	updateHouseTran->addTransformation(initHouseTran);

	houseTexture = new Texture2D("textures/models/house.png");
	tex->addTexture(houseTexture);

	drawableModels.push_back(
		new DrawableModel(
			houseModel,
			new Material(),
			tex->getTextureAt(2),
			new PhongMultipleLightsTextured(camera, lightRepository),
			initHouseTran,
			updateHouseTran
		)
	);

	TransformationComposite* treeInit = new TransformationComposite(true);
	treeInit->addTransformation(new TranslationTransformation(glm::vec3(5, 0, 0)));
	treeInit->addTransformation(new ScaleTransformation(0.01));

	treeTexture = new Texture2D("textures/models/tree.png");
	tex->addTexture(treeTexture);

	treeShader = new PhongMultipleLightsTextured(camera, lightRepository);
	zombieShader = new PhongMultipleLightsTextured(camera, lightRepository);
	houseShader = new PhongMultipleLightsTextured(camera, lightRepository);

	TransformationComposite* initZombieTran = new TransformationComposite(true);
	initZombieTran->addTransformation(new TranslationTransformation(glm::vec3(5, 0, .5)));
	initZombieTran->addTransformation(new ScaleTransformation(.1));
	initZombieTran->addTransformation(new RotationTransformation(120, glm::vec3(0, 1, 0)));

	TransformationComposite* updateZombieTran = new TransformationComposite(true);
	updateZombieTran->addTransformation(initZombieTran);

	zombieTexture = new Texture2D("textures/models/zombie.png");
	tex->addTexture(zombieTexture);

	drawableModels.push_back(
		new DrawableModel(
			zombieModel,
			zombieMaterial,
			tex->getTextureAt(4),
			new PhongMultipleLightsTextured(camera, lightRepository),
			initZombieTran,
			updateZombieTran,
			true
		)
	);

	// 
	TransformationComposite* initSphereTran3 = new TransformationComposite(true);
	initSphereTran3->addTransformation(new TranslationTransformation(glm::vec3(-3.0, .5, -4)));
	initSphereTran3->addTransformation(new ScaleTransformation(.25));

	TransformationComposite* updateSphereTran3 = new TransformationComposite(true);
	updateSphereTran3->addTransformation(initSphereTran3);

	drawableModels.push_back(
		new DrawableModel(
			new SphereModel(),
			new Material(),
			new PhongShaderMultipleLights(camera, lightRepository),
			initSphereTran3,
			updateSphereTran3
		)
	);


	TransformationComposite* initZombieTran3 = new TransformationComposite(true);
	initZombieTran3->addTransformation(new TranslationTransformation(glm::vec3(5.4, 0, .8)));
	initZombieTran3->addTransformation(new ScaleTransformation(.1));
	initZombieTran3->addTransformation(new RotationTransformation(-120.0f, glm::vec3(0, 1, 0)));

	TransformationComposite* updateZombieTran3 = new TransformationComposite(true);
	updateZombieTran3->addTransformation(initZombieTran3);


	drawableModels.push_back(
		new DrawableModel(
			zombieModel,
			zombieMaterial,
			tex->getTextureAt(4),
			new PhongMultipleLightsTextured(camera, lightRepository),
			initZombieTran3,
			updateZombieTran3,
			true
		)
	);
	TransformationComposite* initZombieTran2 = new TransformationComposite(true);
	initZombieTran2->addTransformation(new TranslationTransformation(glm::vec3(5.7, 0, -.5)));
	initZombieTran2->addTransformation(new ScaleTransformation(.1));
	initZombieTran2->addTransformation(new RotationTransformation(-90.0f, glm::vec3(0, 1, 0)));

	TransformationComposite* updateZombieTran2 = new TransformationComposite(true);
	updateZombieTran2->addTransformation(initZombieTran2);

	drawableModels.push_back(
		new DrawableModel(
			zombieModel,
			zombieMaterial,
			tex->getTextureAt(4),
			new PhongMultipleLightsTextured(camera, lightRepository),
			initZombieTran2,
			updateZombieTran2,
			true
		)
	);

	//tree
	for (int i = 0; i < 10; ++i) 
	{
		for (int j = 0; j < 10; ++j) 
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<float> distribution(0.007, .05);
			std::uniform_real_distribution<float> distribution2(0.0, 359.0);
			std::uniform_real_distribution<float> xx(-5, 5);

			float scale_float = distribution(gen);
			float rot_float = distribution2(gen);
			float x = 0;
			float y = 0;

			do {
				x = xx(gen);
				y = xx(gen);

			} while ((y >= -1.3 && y <= 1.3) && (x >= -1 && x<=1));

			TransformationComposite* tree_trans = new TransformationComposite(true);
			tree_trans->addTransformation(new TranslationTransformation(glm::vec3(x, 0.0, y)));
			tree_trans->addTransformation(new RotationTransformation(rot_float, glm::vec3(0.0, 1.0, 0.0)));
			tree_trans->addTransformation(new ScaleTransformation(scale_float));
			TransformationComposite* updating_tree_trans = new TransformationComposite(true);
			updating_tree_trans->addTransformation(tree_trans);

			this->drawableModels.push_back(
				new DrawableModel(
					treeModel,
					treeMaterial,
					tex->getTextureAt(3),
					treeShader,
					tree_trans,
					updating_tree_trans
				)
			);
		}
	}
}

void HouseScene::display() {
	this->flashlight->updateDirection(camera->getDirection());
	this->flashlight->upgradePosition(camera->getPosition());

	if (CallBacks::plantTree) {
		plantTreeToCursor();
		// printf("%f, %f, %f \n",CallBacks::position.x, CallBacks::position.y, CallBacks::position.z);
		// selected_stencil = CallBacks::stencil_id;
		CallBacks::plantTree = false;
	}

	travelBezier();
	shoot();
	for (DrawableModel* m : drawableModels) {
		m->DisplayDry();
	}
	setWindowSizeBuffer();
}

void HouseScene::loadModels()
{
	treeModel = new TreeModel();
	treeMaterial = new Material(
		glm::vec4(1.0, 1.0, 1.0, 1.0), //ambient
		glm::vec4(1, 1, 1, 1.0), //diffuse
		glm::vec4(1.0, 1.0, 1.0, 1.0), //specular strength
		glm::vec4(1.0, 1.0, 1.0, 1.0), // object color
		16 // specular intensity
	);
	treeTexture = new Texture2D("textures/models/tree.png");

	zombieModel = new ZombieModel();
	zombieMaterial = new Material(
		glm::vec4(1.0, 1.0, 1.0, 1.0), //ambient
		glm::vec4(1, 1, 1, 1.0), //diffuse
		glm::vec4(1.0, 1.0, 1.0, 1.0), //specular strength
		glm::vec4(1.0, 1.0, 1.0, 1.0), // object color
		16 // specular intensity
	);
	zombieTexture = new Texture2D("textures/models/zombie.png");

	houseModel = new HouseModel();
	houseMaterial = new Material();
	houseTexture = new Texture2D("textures/models/house.jpg");
}

void HouseScene::shoot()
{
	if (CallBacks::shoot) {
		for (int i = 0; i < drawableModels.size();i++) {

			if(drawableModels[i]->compareIdToStencil(CallBacks::stencil_id) && drawableModels[i]->isEnemy)
			{
				drawableModels.erase(std::next(drawableModels.begin(), i));
				break;
			}
		}
		
		CallBacks::shoot = false;
	}
}
