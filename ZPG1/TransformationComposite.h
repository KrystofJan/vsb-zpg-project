#pragma once
#include "Transformation.h"
#include <vector>
class TransformationComposite
{
private:
	std::vector<Transformation*> transformations;
	glm::mat4 modelMatrix;
public:
	TransformationComposite();
	TransformationComposite(glm::mat4 modelMatrix);
	void addTransformation(Transformation* t);
	void applyTransformations();
	void popTransformation();
	glm::mat4 getModelMatrix();
};

