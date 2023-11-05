#pragma once
#include "Scene.h"
class LightTestScene : public Scene
{
private:
	SpotLight* flashlight;
	Camera* c;
public:
	void initScene() override;
	void display() override;
};
