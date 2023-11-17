#include "PhongMultipleLightsTextured.h"

PhongMultipleLightsTextured::PhongMultipleLightsTextured(Camera* c, LightRepository* lr)
	: Shader(c, lr, "PhongMultipleLightsTextured.vert", "PhongMultipleLightsTextured.frag")
{
}