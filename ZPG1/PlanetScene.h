#pragma once
#include "Scene.h"
class PlanetScene : public Scene
{
private:
	Camera* c;
	BaseLight* light;
	TransformationComposite* sunUpdatingTransform;
	TransformationComposite* earthUpdatingTransform;
	TransformationComposite* moonUpdateTransform;
	DrawableModel* moon;
	DrawableModel* earth;
public:
	void initScene() override;
	void display() override;
};

