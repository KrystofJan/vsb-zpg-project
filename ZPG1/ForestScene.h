#pragma once
#include "Scene.h"
class ForestScene : public Scene
{
private:
	SpotLight* flashlight;
public:
	void initScene() override;
	void display() override;
};
