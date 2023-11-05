#include "TranslationTransformation.h"

TranslationTransformation::TranslationTransformation(float distance, char axis) 
{
	glm::vec3 dist = glm::vec3(0.0f);

	if (axis == 'x') {
		dist.x = distance;
	}
	else if (axis == 'y') {
		dist.y = distance;
	}
	else {
		dist.z = distance;
	}

	this->modelMatrix = glm::translate(glm::mat4(1.0f), dist);
}
TranslationTransformation::TranslationTransformation(glm::vec3 point) 
{
	this->modelMatrix = glm::translate(glm::mat4(1.0f), point);
}

glm::mat4 TranslationTransformation::applyTransformation()
{
	return this->modelMatrix;
}
