#include "ForestScene.h"
#include <stdlib.h>
#include <random>
void ForestScene::initScene()
{
	Camera* c = new Camera(this->window);
	float pos = 3;
	BaseLight* light = new BaseLight(glm::vec3(3, 10.0, 0.0), glm::vec4(1.0, 1.0, 1.0, 1.0));
	LightRepository* lr = new LightRepository();
	std::uniform_real_distribution<float> distribution(0.0, 0.5);

	 lr->addBaseLight(light);
	//DirectionalLight* dl = new DirectionalLight(
	//	glm::vec3(2.0, 0, 0),
	//	glm::vec4(1.0, 1.0, 1.0, 1.0),

	//	glm::vec3(-0.2f, -1.0f, -0.3f),
	//	glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
	//	glm::vec4(0.4f, 0.4f, 0.4f, 1.0f),
	//	glm::vec4(0.5f, 0.5f, 0.5f, 1.0f)
	//);
	//lr->addDirectionalLight(dl);

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


	this->drawableModels.push_back(
		new DrawableModel(
			new PlainModel(),
			new Material(
				glm::vec4(0.1, 0.1, 0.1, 1.0),	// ambient
				glm::vec4(0.385, 0.647, 0.812, 1.0),  // diffuse
				glm::vec4(1.0, 1.0, 1.0, 1.0), // specStrength
				glm::vec4(0.1, 0.5, 0.3, 1.0), // color
				64 // specIntensity
			),
			new LambertShader(c, lr),
			plain_trans,
			updating_plain_trans
		)
	);
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
						glm::vec4(0.1, 0.7, 0.3, 1.0), // color
						8 // specIntensity
					),
					new PhongShader(c, lr),
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
					new PhongShader(c, lr),
					bush_trans,
					updating_bush_trans
				)
			);
		}
	}

	//suzi
	TransformationComposite* suzi_trans = new TransformationComposite();
	suzi_trans->addTransformation(new ScaleTransformation(2));
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
				glm::vec4(0.1, 0.5, 0.3, 1.0), // color
				64 // specIntensity
			),
			new BlinnShader(c, lr),
			suzi_trans,
			updating_suzi_trans
		)
	);
}
