#pragma once
#include "Shader.h"
class ConstantShader : public Shader
{
public:
	ConstantShader(Camera* c, LightRepository* l);
};

