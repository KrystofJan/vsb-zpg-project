#include "PhongShader.h"

PhongShader::PhongShader(Camera *c, LightRepository* light) 
	: Shader(c, light, "PhongShader.vert", "PhongShader.frag")
{
}
