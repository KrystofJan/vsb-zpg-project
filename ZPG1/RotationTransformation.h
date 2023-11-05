#pragma once
#include "Transformation.h"
#include "TransformationComposite.h"
class RotationTransformation : public Transformation
{
public:
	RotationTransformation(float angle, char axis);
	RotationTransformation(float angle, glm::vec3 point); 
	RotationTransformation(float angle, glm::vec3 point, TransformationComposite* prevTransformationComposite);
	glm::mat4 applyTransformation() override;
};
