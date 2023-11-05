#pragma once
#include "Model.h"
#include "Shader.h"
#include "TransformationComposite.h"
#include "Material.h"
class DrawableModel
{
private:
	Model* model;
	Shader* shader;
	TransformationComposite* initTransformations;
	Material* material;
	TransformationComposite* transformations;

public:
	DrawableModel(Model* mod, Material* mat, Shader* s, TransformationComposite* it, TransformationComposite* t);
	glm::mat4 getUpdatingTransformationModelMatrix();
	void DisplayDry();
	void Display();
};