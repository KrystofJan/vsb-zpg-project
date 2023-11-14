#include "LightRepository.h"

void LightRepository::addLight(BaseLight* l)
{
	lights.push_back(l);
}

BaseLight* LightRepository::LightAt(int i)
{
	return lights.at(i);
}

int LightRepository::getLightVecSize()
{
	return lights.size();
}

//void LightRepository::assignObservers(Shader* s)
//{
//	if (_hasBaseLight) {
//		this->light->addObserver(s);
//	}
//	if (_hasDirectLight) {
//		this->directionalLight->addObserver(s);
//	}
//	if (_hasPointLights) {
//		for (PointLight* pl : pointLights) {
//			pl->addObserver(s);
//		}
//	}
//	if (_hasSpotLight) {
//		this->spotLight->addObserver(s);
//	}
//}
