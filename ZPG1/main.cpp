// Login: ZAH0089

#include "Renderer.h"
#include "Scene.h"
#include "SceneOne.h"
#include "SceneTwo.h"
#include "SceneThree.h"
#include "PlanetScene.h"
#include "ForestScene.h"
#include "LightTestScene.h"

int main(void)
{
	// SceneOne *s = new SceneOne();
	// SceneTwo *s = new SceneTwo();
	LightTestScene* s = new LightTestScene();
	// SceneThree *s = new SceneThree();
	// PlanetScene *s = new PlanetScene();
	// ForestScene* s = new ForestScene();
	Renderer* r = new Renderer(s);	
	r->Render();
}