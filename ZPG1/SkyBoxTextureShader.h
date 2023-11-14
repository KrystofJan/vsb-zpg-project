#pragma once
#include "Shader.h"
class SkyBoxTextureShader : public Shader
{
public:
	SkyBoxTextureShader(Camera* c, LightRepository* light);
	void update() override;
};

