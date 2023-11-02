#include "RotationTransformation.h"

RotationTransformation::RotationTransformation(float angle, char axis) {
	if (axis == 'x') {
		this->modelMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::normalize(glm::vec3(1.0f, 0.0f, 0.0f)));
	}
	if (axis == 'y') {
		this->modelMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f)));
	}
	if (axis == 'z') {
		this->modelMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::normalize(glm::vec3(0.0f, 0.0f, 1.0f)));
	}
}
RotationTransformation::RotationTransformation(float angle, glm::vec3 point) {

	glm::mat4 translationToMatrix = glm::translate(this->modelMatrix, point);
	glm::mat4 rotationMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f)));
	
	glm::mat4 translationbackMatrix = glm::translate(this->modelMatrix, -point);

	this->modelMatrix = translationToMatrix * rotationMatrix * translationbackMatrix;
}
RotationTransformation::RotationTransformation(float angle, glm::vec3 *point) {

	glm::mat4 translationToMatrix = glm::translate(this->modelMatrix, *point);
	glm::mat4 rotationMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f)));
	
	glm::mat4 translationbackMatrix = glm::translate(this->modelMatrix, -*point);

	this->modelMatrix = translationToMatrix * rotationMatrix * translationbackMatrix;
}
glm::mat4 RotationTransformation::applyTransformation()
{
	return this->modelMatrix;
}
