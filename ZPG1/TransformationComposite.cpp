#include "TransformationComposite.h"
#include "TranslationTransformation.h"

TransformationComposite::TransformationComposite(glm::mat4 modelMatrix, bool fromStart)
{
	this->modelMatrix = modelMatrix;
	this->fromStart = fromStart;
}
TransformationComposite::TransformationComposite(bool fromStart)
{
	this->modelMatrix = glm::mat4(1.0f);
	this->fromStart = fromStart;
}

void TransformationComposite::addTransformation(Transformation* t)
{
	this->transformations.push_back(t);
}

glm::mat4 TransformationComposite::applyTransformation()
{
	if (fromStart) 
		this->modelMatrix = glm::mat4(1.0);

	for (Transformation* t : transformations) {
		this->modelMatrix *= t->applyTransformation();
	}
	
	return this->modelMatrix;
}

void TransformationComposite::popTransformation()
{
	this->transformations.pop_back();
}

//void TransformationComposite::popTranslateTransformations()
//{
//	transformations.erase(
//		std::remove_if(
//			transformations.begin(),
//			transformations.end(),
//			[](const auto& transformation) {
//				return dynamic_cast<TranslationTransformation*>(transformation);
//			}
//		),
//		transformations.end()
//	);
//}

glm::mat4 TransformationComposite::getModelMatrix()
{
	return this->modelMatrix;
}

void TransformationComposite::resetComposite(/*glm::mat4 mat*/)
{
	transformations.clear();
	this->modelMatrix = glm::mat4(1) /*mat*/;
}
