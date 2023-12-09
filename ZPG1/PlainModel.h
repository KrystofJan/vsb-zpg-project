#pragma once
#include "Model.h"

class PlainModel : public Model
{

public:
	PlainModel();
	void DrawModel(int id) override;
};

