#pragma once
#include "Transformation.h"
class TranslationTransformation : public Transformation
{
public:
	TranslationTransformation(float distance, char axis);
	glm::mat4 applyTransformation() override;
};

