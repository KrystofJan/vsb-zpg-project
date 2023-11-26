#pragma once
#include "Scene.h"
class TextureTestScene : public Scene
{
private:
	DrawableSkyBox* skyBox;
	TransformationComposite* skyBoxTu;
public:
	void initScene();
	void display() override;
};

