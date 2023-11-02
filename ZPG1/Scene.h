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

#include "CubeModel.h"
#include "SphereModel.h"
#include "SuziModel.h"
#include "BushModel.h"
#include "PhongShader.h"
#include "RainbowShader.h"
#include "LambertShader.h"
#include "Light.h"
#include "BlinnShader.h"
#include "PlainModel.h"
#include "TreeModel.h"
#include "GiftModel.h"
#include "ConstantShader.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "SpotLight.h"

class Scene
{
protected:
	std::vector<DrawableModel*> drawableModels;

	// TODO change
public:
	GLFWwindow* window;
	Scene();
	virtual void initScene() = 0;
	bool isWindowClosed();
	void swapBuffer();
	void destroyWindow();
	void displayTransform();
	void setWindowSizeBuffer();
	void virtual display();
};

