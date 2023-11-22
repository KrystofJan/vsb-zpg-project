#include "ForestScene.h"
#include <stdlib.h>
#include <random>
#include <assimp/Importer.hpp>

void ForestScene::initScene()
{
	c = new Camera(this->window);
	float pos = 3;
	LightRepository* lr = new LightRepository();

	/*BaseLight* light = new BaseLight(glm::vec3(3, 10.0, 0.0), glm::vec4(0.003922, 0, 0.082353,1.0));
	 lr->addLight(light);*/

	 this->flashlight = new SpotLight(
		 c->getPosition(),
		 glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		 c->getDirection(),
		 glm::cos(glm::radians(17.5f)),
		 glm::cos(glm::radians(20.0f)),
		 1.0f,
		 0.2f,
		 0.01f,
		 glm::vec4(0.1, 0.1, 0.1, 1.0),
		 glm::vec4(0.385, 0.647, 0.812, 1.0),
		 glm::vec4(1.0, 1.0, 1.0, 1.0)
	 );
	 lr->addLight(flashlight);

	DirectionalLight* dl = new DirectionalLight(
		glm::vec3(2.0, 0, 0),
		glm::vec4(1.0, 1.0, 1.0, 1.0),

		glm::vec3(-0.2f, -1.0f, -0.3f),
		glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
		glm::vec4(0.4f, 0.4f, 0.4f, 1.0f),
		glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)
	);
	lr->addLight(dl);

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
		 new SkyBoxTextureShader(c, lr),
		 skyBoxTi,
		 skyBoxTu
	 );

	 this->drawableModels.push_back(
		 skybox
	 );

	//sun
	TransformationComposite* sun_trans = new TransformationComposite();
	sun_trans->addTransformation(new ScaleTransformation(5));
	sun_trans->addTransformation(new TranslationTransformation(glm::vec3(0.0, 10, 0.0)));
	sun_trans->applyTransformation();
	TransformationComposite* updating_sun_trans = new TransformationComposite(sun_trans->getModelMatrix());


	this->drawableModels.push_back(
		new DrawableModel(
			new SphereModel(),
			new Material(
				glm::vec4(0.1, 0.1, 0.1, 1.0),	// ambient
				glm::vec4(0.385, 0.647, 0.812, 1.0),  // diffuse
				glm::vec4(1.0, 1.0, 1.0, 1.0), // specStrength
				glm::vec4(.5, .5, .5, 1.0), // color
				32 // specIntensity
			),
			new ConstantShader(c, lr),
			sun_trans,
			updating_sun_trans
		)
	);

	//plain
	TransformationComposite* plain_trans = new TransformationComposite();
	plain_trans->addTransformation(new ScaleTransformation(50));
	plain_trans->applyTransformation();
	TransformationComposite* updating_plain_trans = new TransformationComposite(plain_trans->getModelMatrix());

	TextureRepository* tr = new TextureRepository();
	tr->addTexture(new Texture2D("textures/cubemap/negy.jpg"));
	this->drawableModels.push_back(
		new DrawableModel(
			new TexturedPlainModel(),
			new Material(
				glm::vec4(0.1, 0.1, 0.1, 1.0),	// ambient
				glm::vec4(0.385, 0.647, 0.812, 1.0),  // diffuse
				glm::vec4(1.0, 1.0, 1.0, 1.0), // specStrength
				glm::vec4(0.1, 0.5, 0.3, 1.0), // color
				64 // specIntensity
			),
			tr->getTextureAt(0),
			new PhongMultipleLightsTextured(c, lr),
			plain_trans,
			updating_plain_trans
		)
	);
	tr->addTexture(new Texture2D("textures/models/tree.png"));
	//trees
	for (int i = 5; i > -5; --i) {
		for (int j = 5; j > -5; --j) {
			TransformationComposite* tree_trans = new TransformationComposite();
			std::random_device rd;  // Initialize the random number generator
			std::mt19937 gen(rd()); // Create a Mersenne Twister random number generator
			std::uniform_real_distribution<float> distribution(0.3, 1.3); // Define the range
			std::uniform_real_distribution<float> distribution2(0, 359); // Define the range

			float scale_float = distribution(gen);
			float rot_float = distribution2(gen);
			tree_trans->addTransformation(new TranslationTransformation(glm::vec3(i*5, 0.0, j*5)));
			tree_trans->addTransformation(new RotationTransformation(rot_float, glm::vec3(0.0, 1.0, 0.0)));
			tree_trans->addTransformation(new ScaleTransformation(scale_float));
			tree_trans->applyTransformation();
			TransformationComposite* updating_tree_trans = new TransformationComposite(tree_trans->getModelMatrix());

			this->drawableModels.push_back(
				new DrawableModel(
					new TreeModel(),
					new Material(
						glm::vec4(0.1, 0.1, 0.1, 1.0),	// ambient
						glm::vec4(0.385, 0.647, 0.812, 1.0),  // diffuse
						glm::vec4(1.0, 1.0, 1.0, 1.0), // specStrength
						glm::vec4(0.3, 0.9, 0.4, 1.0), // color
						8 // specIntensity
					),
					// tr->getTextureAt(1),
					new PhongShaderMultipleLights(c, lr),
					tree_trans,
					updating_tree_trans
				)
			);
		}
	}
	//bush
	for (int i = 5; i > -5; --i) {
		for (int j = 5; j > -5; --j) {
			std::random_device rd;  // Initialize the random number generator
			std::mt19937 gen(rd()); // Create a Mersenne Twister random number generator
			std::uniform_real_distribution<float> distribution(0, 359); // Define the range

			float rot_float = distribution(gen);

			TransformationComposite* bush_trans = new TransformationComposite();
			bush_trans->addTransformation(new TranslationTransformation(glm::vec3(i * 5 + 3, 0.0, j * 5)));
			bush_trans->addTransformation(new RotationTransformation(rot_float, glm::vec3(0.0, 1.0, 0.0)));
			bush_trans->addTransformation(new ScaleTransformation(1.5));
			bush_trans->applyTransformation();
			TransformationComposite* updating_bush_trans = new TransformationComposite(bush_trans->getModelMatrix());

			this->drawableModels.push_back(
				new DrawableModel(
					new BushModel(),
					new Material(
						glm::vec4(0.1, 0.1, 0.1, 1.0),	// ambient
						glm::vec4(0.385, 0.647, 0.812, 1.0),  // diffuse
						glm::vec4(1.0, 1.0, 1.0, 1.0), // specStrength
						glm::vec4(0.2, 1.0, 0.4, 1.0), // color
						8 // specIntensity
					),
					new PhongShaderMultipleLights(c, lr),
					bush_trans,
					updating_bush_trans
				)
			);
		}
	}

	//suzi
	TransformationComposite* suzi_trans = new TransformationComposite();
	suzi_trans->addTransformation(new ScaleTransformation(.7));
	suzi_trans->addTransformation(new TranslationTransformation(glm::vec3(2.0, 1.0, 1)));

	suzi_trans->applyTransformation();
	TransformationComposite* updating_suzi_trans = new TransformationComposite(suzi_trans->getModelMatrix());

	this->drawableModels.push_back(
		new DrawableModel(
			new SuziModel(),
			new Material(
				glm::vec4(0.1, 0.1, 0.1, 1.0),	// ambient
				glm::vec4(0.385, 0.647, 0.812, 1.0),  // diffuse
				glm::vec4(1.0, 1.0, 1.0, 1.0), // specStrength
				glm::vec4(0.192157, 0.129412, 0.070588, 1.0), // color
				1 // specIntensity
			),
			new PhongShaderMultipleLights(c, lr),
			suzi_trans,
			updating_suzi_trans
		)
	);

	TransformationComposite* initHouseTran = new TransformationComposite();
	initHouseTran->addTransformation(new TranslationTransformation(glm::vec3(-35, 0, 0)));
	initHouseTran->addTransformation(new RotationTransformation(30.0f,glm::vec3(0, 1, 0)));
	TransformationComposite* updateHouseTran = new TransformationComposite(initHouseTran->applyTransformation());

	tr->addTexture(new Texture2D("textures/models/house.png"));

	drawableModels.push_back(
		new DrawableModel(
			new HouseModel(),
			new Material(),
			tr->getTextureAt(2),
			new PhongMultipleLightsTextured(c, lr),
			initHouseTran,
			updateHouseTran
		)
	);


	TransformationComposite* initZombieTran = new TransformationComposite();
	initZombieTran->addTransformation(new TranslationTransformation(glm::vec3(-25, 0, 3.5)));
	initZombieTran->addTransformation(new RotationTransformation(-45.0f, glm::vec3(0, 1, 0)));

	TransformationComposite* updateZombieTran = new TransformationComposite(initZombieTran->applyTransformation());

	tr->addTexture(new Texture2D("textures/models/zombie.png"));

	drawableModels.push_back(
		new DrawableModel(
			new ZombieModel(),
			new Material(),
			tr->getTextureAt(3),
			new TextureShader(c, lr),
			initZombieTran,
			updateZombieTran
		)
	);

}

void ForestScene::display() {
	this->flashlight->updateDirection(c->getDirection());
	this->flashlight->upgradePosition(c->getPosition());
	for (DrawableModel* m : drawableModels) {
		m->DisplayDry();
	}
	setWindowSizeBuffer();
}
