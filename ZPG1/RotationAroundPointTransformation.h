#pragma once
#include "Transformation.h"
class RotationAroundPointTransformation : public Transformation
{
public:
	RotationAroundPointTransformation(float angle, char axis);
	glm::mat4 applyTransformation() override;
};


