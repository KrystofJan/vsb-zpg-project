#pragma once
#include "DrawableModel.h"

class ModelRepository
{
private:
	DrawableModel* skyBox;
	std::vector<DrawableModel*> models;
public:
	ModelRepository(std::vector<DrawableModel*> models);
	ModelRepository(std::vector<DrawableModel*> models, DrawableModel* skyBox);

	void displayModels();
	void displaySkyBox();
};

