#include "TranslationTransformation.h"

TranslationTransformation::TranslationTransformation(float distance, char axis) {
	if (axis == 'x') {
		this->modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(distance, 0.0f, 0.0f));
	}
	else if (axis == 'y') {
		this->modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, distance, 0.0f));
	}
	else {
		this->modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, distance));
	}
}

glm::mat4 TranslationTransformation::applyTransformation()
{
	return this->modelMatrix;
}
