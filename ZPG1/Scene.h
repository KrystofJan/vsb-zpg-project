#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "CallBacks.h"
#include "Model.h"
#include "Shader.h"
#include "TriangleModel.h"
#include "SquareModel.h"
#include "DrawableModel.h"
#include "RedShader.h"
#include "BlueShader.h"
#include "CallbackController.h"
#include "RotationTransformation.h"
#include "TranslationTransformation.h"
#include "ScaleTransformation.h"
#include "RotationAroundObjectTransformation.h"

#include "CubeModel.h"
#include "SphereModel.h"
#include "SuziModel.h"
#include "BushModel.h"
#include "PhongShader.h"
#include "RainbowShader.h"
#include "LambertShader.h"
#include "BaseLight.h"
#include "BlinnShader.h"
#include "PlainModel.h"
#include "TreeModel.h"
#include "GiftModel.h"
#include "ConstantShader.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "SpotLight.h"
#include "PhongShaderMultipleLights.h"
#include "TexturedPlainModel.h"
#include "TextureShader.h"
#include "SkyCubeModel.h"
#include "SkyBoxTextureShader.h"
#include "TextureRepository.h"
#include "Texture2D.h"
#include "TextureCubeMap.h"
#include "DrawableSkyBox.h"
#include "PhongMultipleLightsTextured.h"
#include "HouseModel.h"
#include "ZombieModel.h"
#include "TerrainModel.h"
#include "Line.h"
#include "BezierCurve.h"
#include "BezierBuilder.h"
#include "BezierSequence.h"

class Scene
{
private:
	int* mouseX;
	int* mouseY;
	DrawableModel* tree;
	string pickedType = "NaN";
	BezierCurve* b = nullptr;
	int stencil_id = -1;
	int picked_id = -1;
protected:
	std::vector<DrawableModel*> drawableModels;
	GLFWwindow* window;
	Camera* camera;
	LightRepository* lightRepository;
	
	TextureRepository* tex;

	PhongMultipleLightsTextured* treeShader;
	BezierBuilder* bezierBuilder;


	BezierSequence* bezierSequence = new BezierSequence();
	TransformationComposite* bezierComposite = new TransformationComposite();
	glm::mat4x3 bezier;


	ZombieModel* zombieModel;
	Material* zombieMaterial;
	Texture2D* zombieTexture;
	Shader* zombieShader;

	HouseModel* houseModel;
	Material* houseMaterial;
	Texture2D* houseTexture;
	Shader* houseShader;

	TreeModel* treeModel;
	Material* treeMaterial;
	Texture2D* treeTexture;

	DrawableModel* pickedModel;
	TransformationComposite* pickedInitTransformations;

public:
	Scene();
	virtual void loadModels();
	virtual void initScene() = 0;
	bool isWindowClosed();
	void swapBuffer();
	void destroyWindow();
	void displayTransform();
	void setWindowSizeBuffer();
	void setMouseClickCallback();
	void setMouseMoveCallback();
	void plantTreeToCursor();
	void travelOnLine(int index);
	void travelBezier();
	void virtual display();
};

