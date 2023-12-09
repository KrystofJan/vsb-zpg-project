#include "DrawableModel.h"

static int index = 1;
DrawableModel::DrawableModel(Model* mod, Material* mat, Texture* te, Shader* s,
	TransformationComposite* it, TransformationComposite* t) 
{
	index++;
	this->id = index;
	this->model = mod;
	this->material = mat;
	this->shader = s;
	this->initTransformations = it;
	this->transformations = t;
	this->texture = te;
}

DrawableModel::DrawableModel(Model* mod, Material* mat, Texture* te, Shader* s,
	TransformationComposite* it, TransformationComposite* t, bool isEnemy)
{
	index++;
	this->id = index;
	this->model = mod;
	this->material = mat;
	this->shader = s;
	this->initTransformations = it;
	this->transformations = t;
	this->texture = te;
	this->isEnemy = isEnemy;
}

DrawableModel::DrawableModel(Model* mod, Material* mat, Shader* s, TransformationComposite* it, TransformationComposite* t)
{
	index++;
	this->id = index;
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

//void DrawableModel::assignNewInitialTransformationComposite(TransformationComposite* tc) {
//	this->initTransformations = tc;
//}

void DrawableModel::Display() {
	//this->initTransformations->applyTransformations();
	this->shader->activateShaderProgram();

	this->shader->updateUniformLocation("modelMatrix", &this->initTransformations->getModelMatrix()[0][0]);
	
	// this->shader->updateUniformLocation("textureUnitID", 0);

	this->shader->update();

	this->model->BindModel();
	this->model->DrawModel(this->id);

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
	this->model->DrawModel(id);
}

bool DrawableModel::compareIdToStencil(int id)
{
	return (this->id == id);
}
