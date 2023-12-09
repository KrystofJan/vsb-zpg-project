#pragma once
#include "Model.h"
#include "Sphere.h"
class SphereModel : public Model
{

public:
	SphereModel();
	void DrawModel(int id) override;
};

