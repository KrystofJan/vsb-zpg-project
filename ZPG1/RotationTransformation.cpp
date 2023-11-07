#include "RotationTransformation.h"
#include "TransformationComposite.h"

RotationTransformation::RotationTransformation(float angle, char axis) 
{
	if (axis == 'x') {
		this->modelMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
	}
	if (axis == 'y') {
		this->modelMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	if (axis == 'z') {
		this->modelMatrix = glm::rotate(this->modelMatrix, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
	}
}

RotationTransformation::RotationTransformation(float angle, glm::vec3 point) 
{
	this->modelMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle),point);
}

RotationTransformation::RotationTransformation(glm::mat4* matrix, float angle, glm::vec3 point)
{
	this->modelMatrix = glm::rotate(*matrix, glm::radians(angle),point);
}


glm::mat4 RotationTransformation::applyTransformation()
{
	return this->modelMatrix;
}
