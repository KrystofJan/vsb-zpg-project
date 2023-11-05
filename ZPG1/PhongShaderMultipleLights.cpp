#include "PhongShaderMultipleLights.h"

PhongShaderMultipleLights::PhongShaderMultipleLights(Camera* c, LightRepository* lr)
	: Shader(c, lr, "PhongShaderMultipleLights.vert", "PhongShaderMultipleLights.frag")
{
}
