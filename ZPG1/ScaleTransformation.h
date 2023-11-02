#pragma once
#include "Transformation.h"
class ScaleTransformation : public Transformation
{
public:
	ScaleTransformation(float scale);
	glm::mat4 applyTransformation() override;
};

