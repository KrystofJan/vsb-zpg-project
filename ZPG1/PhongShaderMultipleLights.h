#pragma once
#include "Shader.h"

class PhongShaderMultipleLights : public Shader
{
public:
	PhongShaderMultipleLights(Camera* c, LightRepository* lr);
};

