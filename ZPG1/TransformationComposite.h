#pragma once
#include "Transformation.h"
#include <vector>
class TransformationComposite : public Transformation
{
private:
	std::vector<Transformation*> transformations;
	glm::mat4 modelMatrix;
public:
	bool fromStart;
	TransformationComposite(bool fromStart = false);
	TransformationComposite(glm::mat4 modelMatrix, bool fromStart = false);
	void addTransformation(Transformation* t);
	glm::mat4 applyTransformation() override;
	void popTransformation();
	glm::mat4 getModelMatrix();
	void resetComposite(/*glm::mat4 mat*/);
};

