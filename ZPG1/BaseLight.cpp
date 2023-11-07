#include "BaseLight.h"

BaseLight::BaseLight(glm::vec3 pos, glm::vec4 col)
{
	this->lightPosition = pos;
	this->lightColor = col;
}

glm::vec3 BaseLight::getLightPos()

{
	return this->lightPosition;
}

glm::vec4 BaseLight::getLightColor()
{
	return this->lightColor;
}

void BaseLight::notify()
{
	for (Observer* o : this->observers) {
		o->update();
	}
}
