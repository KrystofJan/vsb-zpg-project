#pragma once
#include "Scene.h"
class ModelLoadingScene : public Scene
{
private:
	Camera* c;
public:
	void initScene() override;
};
