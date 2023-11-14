#pragma once
#include "DrawableModel.h"

class DrawableSkyBox : public DrawableModel
{
public:
	DrawableSkyBox(Model* mod, Material* mat, Texture* te, Shader* s, TransformationComposite* it, TransformationComposite* t);
	void DisplayDry() override;
};

