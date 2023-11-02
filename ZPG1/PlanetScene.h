#pragma once
#include "Scene.h"
class PlanetScene : public Scene
{
private:
	Camera* c;
	Light* light;
public:
	void initScene() override;
	void display() override;
};

