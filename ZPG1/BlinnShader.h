#pragma once
#include "Shader.h"
#include "Camera.h"
#include "BaseLight.h"

class BlinnShader : public Shader
{
public:
	BlinnShader(Camera* c, LightRepository* l);
};

