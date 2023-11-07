#include "RotationAroundObjectTransformation.h"

RotationAroundObjectTransformation::RotationAroundObjectTransformation(float angle, glm::vec3 relativePosition, DrawableModel* baseOfRotationModel)
{
	this->angle = angle;
	this->relativePosition = relativePosition;
	this->baseOfRotationModel = baseOfRotationModel;
}

void RotationAroundObjectTransformation::bindRotatedModel(DrawableModel* model)
{
	this->rotatedModel = model;
}



glm::mat4 RotationAroundObjectTransformation::applyTransformation()
{
	TransformationComposite* transformComposite = new TransformationComposite();

	if (this->rotatedModel == nullptr) {
		transformComposite->applyTransformation();
		return transformComposite->getModelMatrix();
	}
	glm::vec3 dist = this->getDistanceInGlobalSpace();

	transformComposite->addTransformation(new RotationTransformation(this->angle, relativePosition));
	transformComposite->addTransformation(new TranslationTransformation(dist));
	printf("x: %f, y: %f, z: %f \n", dist.x, dist.y, dist.z);
	transformComposite->applyTransformation();
	
	return transformComposite->getModelMatrix();
}

glm::vec3 RotationAroundObjectTransformation::getDistanceInGlobalSpace()
{
	
	glm::vec4 basePos= this->baseOfRotationModel->getUpdatingTransformationModelMatrix() * glm::vec4(1.0f);
	glm::vec4 rotatePos = this->rotatedModel->getUpdatingTransformationModelMatrix() * glm::vec4(1.0f);
	
	glm::vec3 baseOfRotationModelPos = glm::vec3(basePos.x, basePos.y, basePos.z);
	glm::vec3 rotatedModelPos = glm::vec3(basePos.x, basePos.y, basePos.z);
	return baseOfRotationModelPos - rotatedModelPos;
}
