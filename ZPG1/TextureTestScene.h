#pragma once
#include "Scene.h"
class TextureTestScene : public Scene
{
private:
	DrawableSkyBox* skyBox;
	TransformationComposite* skyBoxTu;
	SpotLight* flashlight;
public:
	void initScene();
	void display() override;
};

