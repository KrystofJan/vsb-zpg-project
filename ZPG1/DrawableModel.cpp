#include "DrawableModel.h"

DrawableModel::DrawableModel(Model* mod, Material* mat, Shader* s,
	TransformationComposite* it, TransformationComposite* t) 
{
	this->model = mod;
	this->material = mat;
	this->shader = s;
	this->initTransformations = it;
	this->transformations = t;
}

void DrawableModel::Display() {
	//this->initTransformations->applyTransformations();

	this->shader->updateUniformLocation("modelMatrix", &this->initTransformations->getModelMatrix()[0][0]);
	this->shader->activateShaderProgram();
	
	this->shader->update();

	this->model->BindModel();
	this->model->DrawModel();

	this->shader->deactivateShaderProgram();
}

void DrawableModel::DisplayDry() {
	this->transformations->applyTransformations();
	this->shader->activateShaderProgram();

	this->shader->updateUniformLocation("modelMatrix", &this->transformations->getModelMatrix()[0][0]);
	this->shader->updateUniformLocation("amb", material->getAmbient());
	this->shader->updateUniformLocation("diff", this->material->getDiffuse());
	this->shader->updateUniformLocation("objColor", this->material->getObjColor());
	this->shader->updateUniformLocation("powExponent", this->material->getSpecIntensity());
	this->shader->updateUniformLocation("specularStrength", this->material->getSpecularStrength());
	this->shader->update();

	this->model->BindModel();
	this->model->DrawModel();
}
