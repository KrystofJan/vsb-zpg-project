#pragma once
#include "Scene.h"
class PlanetScene : public Scene
{
private:
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

