#pragma once
#include "Transformation.h"
#include "TransformationComposite.h"
class RotationTransformation : public Transformation
{
public:
	RotationTransformation(float angle, char axis);
	RotationTransformation(float angle, glm::vec3 point); 
	RotationTransformation(glm::mat4 *matrix, float angle, glm::vec3 point);
	glm::mat4 applyTransformation() override;
};
