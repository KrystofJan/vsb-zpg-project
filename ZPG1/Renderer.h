#pragma once
#include "Scene.h"
class Renderer
{
private:
	Scene* scene;
public:
	Renderer(Scene* scene);
	void Render();
};
