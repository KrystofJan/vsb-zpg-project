#include "LightRepository.h"

void LightRepository::addLight(Light* l)
{
	this->light = l;
	_hasBaseLight = true;
}

void LightRepository::addPointLight(PointLight* pl)
{
	this->pointLights.push_back(pl);
	_hasPointLights = true;
}

void LightRepository::addDirectionalLight(DirectionalLight* dl)
{
	this->directionalLight = dl;
	_hasDirectLight = true;
}

void LightRepository::addSpotLight(SpotLight* sl)
{
	this->spotLight = sl;
	_hasSpotLight = true;
}

bool LightRepository::hasPointLights()
{
	return this->_hasPointLights;
}
bool LightRepository::hasDirectionalLight()
{
	return this->_hasDirectLight;
}
bool LightRepository::hasSpotLight()
{
	return this->_hasSpotLight;
}
bool LightRepository::hasBaseLight() 
{
	return this->_hasBaseLight;
}
int LightRepository::getPointLightsAmmout()
{
	return this->pointLights.size();
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

PointLight* LightRepository::getPointLightAt(int index) {
	return this->pointLights.at(index);
}
SpotLight* LightRepository::getSpotLight() {
	return this->spotLight;
}
DirectionalLight* LightRepository::getDirectionalLight() {
	return this->directionalLight;
}
Light* LightRepository::getBaseLight() {
	return this->light;
}
