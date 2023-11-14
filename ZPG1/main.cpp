// Login: ZAH0089

#include "Renderer.h"
#include "Scene.h"
#include "SceneOne.h"
#include "SceneTwo.h"
#include "SceneThree.h"
#include "PlanetScene.h"
#include "ForestScene.h"
#include "TextureTestScene.h"
#include "LightTestScene.h"

int main(void)
{
	// SceneOne *s = new SceneOne(); // Phong
	// SceneTwo *s = new SceneTwo();
	// LightTestScene* s = new LightTestScene(); // svetla
	// SceneThree *s = new SceneThree(); //idk
	// PlanetScene *s = new PlanetScene(); // planetky
	ForestScene* s = new ForestScene(); // stromecky
	// TextureTestScene* s = new TextureTestScene();
	Renderer* r = new Renderer(s);	
	r->Render();
}