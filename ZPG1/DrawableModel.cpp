#include "DrawableModel.h"

DrawableModel::DrawableModel(Model* mod, Material* mat, Texture* te, Shader* s,
	TransformationComposite* it, TransformationComposite* t) 
{
	this->model = mod;
	this->material = mat;
	this->shader = s;
	this->initTransformations = it;
	this->transformations = t;
	this->texture = te;
}

DrawableModel::DrawableModel(Model* mod, Material* mat, Shader* s, TransformationComposite* it, TransformationComposite* t)
{
	this->model = mod;
	this->material = mat;
	this->shader = s;
	this->initTransformations = it;
	this->transformations = t;
}


glm::mat4 DrawableModel::getUpdatingTransformationModelMatrix()
{
	return this->transformations->getModelMatrix();
}

void DrawableModel::Display() {
	//this->initTransformations->applyTransformations();
	this->shader->activateShaderProgram();

	this->shader->updateUniformLocation("modelMatrix", &this->initTransformations->getModelMatrix()[0][0]);
	
	// this->shader->updateUniformLocation("textureUnitID", 0);

	this->shader->update();

	this->model->BindModel();
	this->model->DrawModel();

	this->shader->deactivateShaderProgram();
}



void DrawableModel::DisplayDry() {
	this->transformations->applyTransformation();
	this->shader->activateShaderProgram();

	if (texture != nullptr) {
		this->shader->updateUniformLocation("textureUnitID", this->texture->getPosition());
	}

	this->shader->updateUniformLocation("modelMatrix", &this->transformations->getModelMatrix()[0][0]);

	this->shader->updateUniformLocation("amb", this->material->getAmbient());
	this->shader->updateUniformLocation("diff", this->material->getDiffuse());
	this->shader->updateUniformLocation("objColor", this->material->getObjColor());
	this->shader->updateUniformLocation("powExponent", this->material->getSpecIntensity());
	this->shader->updateUniformLocation("specularStrength", this->material->getSpecularStrength());

	this->shader->update();

	this->model->BindModel();
	this->model->DrawModel();
}
