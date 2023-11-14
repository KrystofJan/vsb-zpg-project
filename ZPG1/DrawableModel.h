#pragma once
#include "Model.h"
#include "Shader.h"
#include "TransformationComposite.h"
#include "Material.h"
#include "Texture.h"
#include "TextureRepository.h"
class DrawableModel
{
protected:
	Model* model;
	Shader* shader;
	TransformationComposite* initTransformations;
	Material* material;
	TransformationComposite* transformations;
	Texture* texture;
public:
	DrawableModel(Model* mod, Material* mat, Texture* te, Shader* s, TransformationComposite* it, TransformationComposite* t);
	DrawableModel(Model* mod, Material* mat, Shader* s, TransformationComposite* it, TransformationComposite* t);
	glm::mat4 getUpdatingTransformationModelMatrix();
	virtual void DisplayDry();
	void Display();
};