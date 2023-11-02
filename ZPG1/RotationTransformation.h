#pragma once
#include "Transformation.h"
class RotationTransformation : public Transformation
{
public:
	RotationTransformation(float angle, char axis);
	RotationTransformation(float angle, glm::vec3 point);
	RotationTransformation(float angle, glm::vec3* point);
	glm::mat4 applyTransformation() override;
};
