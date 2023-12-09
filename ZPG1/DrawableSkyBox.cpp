#include "DrawableSkyBox.h"

DrawableSkyBox::DrawableSkyBox(Model* mod, Material* mat, Texture* te, Shader* s, TransformationComposite* it, TransformationComposite* t)
	:DrawableModel(mod, mat, te, s, it, t)
{
}

void DrawableSkyBox::DisplayDry()
{
	this->shader->activateShaderProgram();

	this->shader->updateUniformLocation("textureUnitID", this->texture->getPosition());

	this->shader->update();

	this->model->BindModel();
	this->model->DrawModel(id);
}
