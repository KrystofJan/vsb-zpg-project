#include "TextureTestScene.h"

void TextureTestScene::initScene()
{
	camera = new Camera(this->window);

	lightRepository = new LightRepository();

	//DirectionalLight* dl = new DirectionalLight(
	//	glm::vec3(2.0, 0, 0),
	//	glm::vec4(1.0, 1.0, 1.0, 1.0),

	//	glm::vec3(1.0f, 0, 0),
	//	glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
	//	glm::vec4(0.4f, 0.4f, 0.4f, 1.0f),
	//	glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)
	//);

	//lightRepository->addLight(dl);


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

	TextureRepository* tex = new TextureRepository();


	tex->addTexture(new TextureCubeMap(
		"textures/cubemap/posx.jpg", "textures/cubemap/negx.jpg",
		"textures/cubemap/posy.jpg", "textures/cubemap/negy.jpg",
		"textures/cubemap/posz.jpg", "textures/cubemap/negz.jpg"
	));

	TransformationComposite* skyBoxTi = new TransformationComposite();
	skyBoxTi->applyTransformation();
	skyBoxTu = new TransformationComposite(skyBoxTi->getModelMatrix(), true);
	DrawableSkyBox *skybox = new DrawableSkyBox(
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


	tex->addTexture(new Texture2D(
		"textures/wooden_fence.png"
	));

	TransformationComposite* plainT2 = new TransformationComposite();
	plainT2->addTransformation(new TranslationTransformation(-3, 'x'));
	plainT2->applyTransformation();
	TransformationComposite* plainTU2 = new TransformationComposite(plainT2->getModelMatrix());
	skyBoxTu->addTransformation(new TranslationTransformation(camera->getPosition()));

	DrawableModel* plain2 = new DrawableModel(
		new TexturedPlainModel(),
		new Material(glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
		tex->getTextureAt(1),
		new TextureShader(camera, lightRepository),
		plainT2,
		plainTU2
	);

	this->drawableModels.push_back(
		plain2
	);

	//tex->addTexture(new Texture2D(
	//	"textures/test.png"
	//));

	//TransformationComposite* plainT3 = new TransformationComposite();
	//plainT3->addTransformation(new TranslationTransformation(-2, 'x'));
	//plainT3->applyTransformation();
	//TransformationComposite* plainTU3 = new TransformationComposite(plainT3->getModelMatrix());

	//DrawableModel* plain3 = new DrawableModel(
	//	new TexturedPlainModel(),
	//	new Material(glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
	//	tex->getTextureAt(2),
	//	new TextureShader(cam, lr),
	//	plainT3,
	//	plainTU3
	//);

	//this->drawableModels.push_back(
	//	plain3
	//);

	tex->addTexture(new Texture2D(
		"textures/models/tree.png"
	));

	TransformationComposite* initTranTree = new TransformationComposite();

	this->drawableModels.push_back(
		new DrawableModel(
			new TreeModel(),
			new Material(
				glm::vec4(1.0, 1.0, 1.0, 1.0), //ambient
				glm::vec4(1, 1, 1, 1.0), //diffuse
				glm::vec4(1.0, 1.0, 1.0, 1.0), //specular strength
				glm::vec4(1.0, 1.0, 1.0, 1.0), // object color
				16 // specular intensity
			),
			tex->getTextureAt(2),
			new PhongMultipleLightsTextured(camera, lightRepository),
			initTranTree,
			new TransformationComposite(initTranTree->applyTransformation())
		)
	);


	
}

void TextureTestScene::display() {
	this->flashlight->updateDirection(camera->getDirection());
	this->flashlight->upgradePosition(camera->getPosition());

	for (DrawableModel* m : drawableModels) {
		m->DisplayDry();
	}
	setWindowSizeBuffer();
}
