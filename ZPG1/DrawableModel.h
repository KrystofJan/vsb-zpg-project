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

public:
	TransformationComposite* transformations;
	DrawableModel(Model* mod, Material* mat, Shader* s, TransformationComposite* it, TransformationComposite* t);
	void DisplayDry();
	void Display();
	void UpdateTransformation(TransformationComposite* t);
};