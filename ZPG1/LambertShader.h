#pragma once
#include "Shader.h"
class LambertShader : public Shader
{
public:
	LambertShader(Camera* c, LightRepository* l);
};

