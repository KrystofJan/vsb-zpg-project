#pragma once
#include "BaseLight.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "SpotLight.h"

class LightRepository
{
private:
	std::vector<BaseLight*> lights;
public:

	void addLight(BaseLight* l);
	BaseLight* LightAt(int i);
	int getLightVecSize();
	// void assignObservers(Shader* s);
};

