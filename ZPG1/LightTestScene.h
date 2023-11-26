#pragma once
#include "Scene.h"
class LightTestScene : public Scene
{
private:
	SpotLight* flashlight;
public:
	void initScene() override;
	void display() override;
};
