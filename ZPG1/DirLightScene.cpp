#include "DirLightScene.h"

void DirLightScene::initScene()
{
	lightRepository = new LightRepository();

	lightRepository->addLight(
		new DirectionalLight(
			glm::vec3(0.0, 0, 0),
			glm::vec4(1.0, 1.0, 1.0, 1.0),

			glm::vec3(0.0f, -1.0f, 0.0f),

			glm::vec4(0.0, 0.0, 0.0, 1.0),
			glm::vec4(0.4, 0.4, 0.4, 1.0),
			glm::vec4(0.4)
		)
	);

	TransformationComposite* initTerrainTran = new TransformationComposite();
	initTerrainTran->addTransformation(new ScaleTransformation(.3));
	TransformationComposite* updateTerrainTran = new TransformationComposite(initTerrainTran->applyTransformation());
	tex = new TextureRepository();

	tex->addTexture(new Texture2D("textures/models/grass.png"));

	drawableModels.push_back(
		new DrawableModel(
			new TerrainModel(),
			new Material(),
			tex->getTextureAt(0),
			new PhongMultipleLightsTextured(camera, lightRepository),
			initTerrainTran,
			updateTerrainTran
		)
	);
}
