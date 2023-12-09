#pragma once
#include "Scene.h"
class HouseScene : public Scene
{
private:
	SpotLight* flashlight;
public:
	void initScene() override;
	void display() override;
	void shoot();
};

