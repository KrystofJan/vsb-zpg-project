#include "TransformationComposite.h"

TransformationComposite::TransformationComposite(glm::mat4 modelMatrix)
{
	this->modelMatrix = modelMatrix;
}
TransformationComposite::TransformationComposite()
{
	this->modelMatrix = glm::mat4(1.0f);
}

void TransformationComposite::addTransformation(Transformation* t)
{
	this->transformations.push_back(t);
}

void TransformationComposite::applyTransformations()
{
	for (Transformation* t : transformations) {
		this->modelMatrix *= t->applyTransformation();
	}
}

void TransformationComposite::popTransformation()
{
	this->transformations.pop_back();
}

glm::mat4 TransformationComposite::getModelMatrix()
{
	return this->modelMatrix;
}
