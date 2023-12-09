#pragma once
#include "Model.h"
class TexturedPlainModel : public Model
{

public:
	TexturedPlainModel();
	void DrawModel(int id) override;
};
