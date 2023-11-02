#include "Light.h"

Light::Light(glm::vec3 pos, glm::vec4 col)
{
	this->lightPosition = pos;
	this->lightColor = col;
}

glm::vec3 Light::getLightPos()

{
	return this->lightPosition;
}

glm::vec4 Light::getLightColor()
{
	return this->lightColor;
}

void Light::notify()
{
	for (Observer* o : this->observers) {
		o->update();
	}
}
