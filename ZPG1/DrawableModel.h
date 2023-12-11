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
	Material* material;
	Texture* texture;
	int id;
public:
	TransformationComposite* transformations;
	TransformationComposite* initTransformations;
	bool isEnemy = false;
	DrawableModel(Model* mod, Material* mat, Texture* te, Shader* s, TransformationComposite* it, TransformationComposite* t);
	DrawableModel(Model* mod, Material* mat, Texture* te, Shader* s, TransformationComposite* it, TransformationComposite* t, bool isEnemy);
	DrawableModel(Model* mod, Material* mat, Shader* s, TransformationComposite* it, TransformationComposite* t);
	glm::mat4 getUpdatingTransformationModelMatrix();
	void assignNewInitialTransformationComposite(TransformationComposite* tc);
	virtual void DisplayDry();
	bool compareIdToStencil(int id);
	std::string getType();
	void Display();
};