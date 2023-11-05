#pragma once
#include "Transformation.h"
class TranslationTransformation : public Transformation
{
public:
	TranslationTransformation(float distance, char axis);
	TranslationTransformation(glm::vec3 point);
	glm::mat4 applyTransformation() override;
};

