#include "BaseLight.h"

BaseLight::BaseLight(glm::vec3 pos, glm::vec4 col)
{
	this->lightPosition = pos;
	this->lightColor = col;
	this->type = 0;
}

glm::vec3 BaseLight::getLightPos()

{
	return this->lightPosition;
}

glm::vec4 BaseLight::getLightColor()
{
	return this->lightColor;
}

int BaseLight::getType()
{
	return this->type;
}

void BaseLight::notify()
{
	for (Observer* o : this->observers) {
		o->update();
	}
}
