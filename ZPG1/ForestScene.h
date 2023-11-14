#pragma once
#include "Scene.h"
class ForestScene : public Scene
{
private:
	SpotLight* flashlight;
	Camera* c;
public:
	void initScene() override;
	void display() override;
};
