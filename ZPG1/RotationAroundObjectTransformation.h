#pragma once
#include "Transformation.h"
#include "RotationTransformation.h"
#include "TranslationTransformation.h"
#include "DrawableModel.h"
class RotationAroundObjectTransformation : public Transformation
{
private:
	DrawableModel* baseOfRotationModel = nullptr;
	DrawableModel* rotatedModel = nullptr;
	float angle;
	glm::vec3 relativePosition;
public:
	RotationAroundObjectTransformation(float angle, glm::vec3 relativePosition, DrawableModel* baseOfRotationModel);
	void bindRotatedModel(DrawableModel* model);
	glm::vec3 getDistanceInGlobalSpace();
	glm::mat4 applyTransformation() override;
};
