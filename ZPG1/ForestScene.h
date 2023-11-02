#pragma once
#include "Scene.h"
class ForestScene : public Scene
{
public:
	void initScene() override;
	void addTree(int dir, char axis, Camera* c, Light* light);
};
