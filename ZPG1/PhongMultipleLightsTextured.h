#pragma once
#include "Shader.h"
class PhongMultipleLightsTextured : public Shader
{
public:
	PhongMultipleLightsTextured(Camera* c, LightRepository* lr);
};

