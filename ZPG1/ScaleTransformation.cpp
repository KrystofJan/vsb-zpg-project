#include "ScaleTransformation.h"

ScaleTransformation::ScaleTransformation(float scale)
{
	this->modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scale));
}

glm::mat4 ScaleTransformation::applyTransformation()
{
	return this->modelMatrix;
}
