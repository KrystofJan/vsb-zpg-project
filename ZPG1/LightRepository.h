#pragma once
#include "Light.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "SpotLight.h"

class LightRepository
{
private:
	Light* light;
	std::vector<PointLight*> pointLights;
	DirectionalLight* directionalLight;
	SpotLight* spotLight;
	bool _hasDirectLight = false;
	bool _hasSpotLight = false;
	bool _hasBaseLight = false;
	bool _hasPointLights = false;
public:
	void addLight(Light* l);
	void addPointLight(PointLight* pl);
	void addDirectionalLight(DirectionalLight* dl);
	void addSpotLight(SpotLight* sl);
	bool hasPointLights();
	bool hasDirectionalLight();
	bool hasSpotLight();
	bool hasBaseLight();
	PointLight* getPointLightAt(int index);
	SpotLight* getSpotLight();
	DirectionalLight* getDirectionalLight();
	Light* getBaseLight();
	int getPointLightsAmmout();
	// void assignObservers(Shader* s);
};

