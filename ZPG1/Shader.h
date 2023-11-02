#pragma once
#include "Observer.h"
#include "Camera.h"
#include "Light.h"
#include "PointLight.h"
#include "ShaderProgram.h"
#include "Material.h"
#include "DirectionalLight.h"
#include "SpotLight.h"
#include <vector>

class Shader : public Observer, public ShaderProgram
{
protected:
	Camera* camera;
	Light* light;
	std::vector<PointLight*> pointLights;
	DirectionalLight* directionalLight;
	SpotLight* spotLight;
	bool hasDirectLight = false;
	bool hasSpotLight = false;
public:
	Shader(Camera* c, Light* light, const char* vertexFile, const char* fragmentFile);
	Shader(Camera* c, std::vector<PointLight*> light, const char* vertexFile, const char* fragmentFile);
	Shader(Camera* c, std::vector<PointLight*> light, SpotLight* spotLight, const char* vertexFile, const char* fragmentFile);
	Shader(Camera* c, std::vector<PointLight*> light, DirectionalLight* directionalLight, const char* vertexFile, const char* fragmentFile);
	Shader(Camera* c, std::vector<PointLight*> light, DirectionalLight* directionalLight, SpotLight* spotLight, const char* vertexFile, const char* fragmentFile);
	void update() override;
	void setPointLights();
	void setDirectionalLight();
	void setSpotLight();
};
