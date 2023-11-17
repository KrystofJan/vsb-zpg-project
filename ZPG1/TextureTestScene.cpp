#include "TextureTestScene.h"

void TextureTestScene::initScene()
{
	cam = new Camera(this->window);

	LightRepository* lr = new LightRepository();

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
		new SkyBoxTextureShader(cam, lr),
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
	skyBoxTu->addTransformation(new TranslationTransformation(cam->getPosition()));

	DrawableModel* plain2 = new DrawableModel(
		new TexturedPlainModel(),
		new Material(glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16),
		tex->getTextureAt(1),
		new TextureShader(cam, lr),
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


	
}

void TextureTestScene::display() {
	for (DrawableModel* m : drawableModels) {
		m->DisplayDry();
	}
	setWindowSizeBuffer();
}
