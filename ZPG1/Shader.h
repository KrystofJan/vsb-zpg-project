#pragma once
#include "Observer.h"
#include "Camera.h"
#include "ShaderProgram.h"
#include "Material.h"
#include <vector>
#include "LightRepository.h"

class Shader : public Observer, public ShaderProgram
{
protected:
	Camera* camera;
	LightRepository* light_repository;
public:
	Shader(Camera* c, LightRepository* lr, const char* vertexFile, const char* fragmentFile);
	void update() override;
	void updateLights();
	void updatePointLights();
	void updateDirectionalLight();
	void updateSpotLight();
	void updateBaseLight();
};
