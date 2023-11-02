#include "PhongShader.h"

PhongShader::PhongShader(Camera *c, Light* light) 
	: Shader(c, light, "PhongShader.vert", "PhongShader.frag")
{
}

PhongShader::PhongShader(Camera* c, std::vector<PointLight*> lights) 
	: Shader(c, lights, "PhongShader.vert", "PhongShader.frag")
{
}

PhongShader::PhongShader(Camera* c, std::vector<PointLight*> lights, DirectionalLight* d) 
	: Shader(c, lights,d, "PhongShader.vert", "PhongShader.frag")
{
}

PhongShader::PhongShader(Camera* c, std::vector<PointLight*> lights, DirectionalLight* d, SpotLight* s) 
	: Shader(c, lights, d, s, "PhongShader.vert", "PhongShader.frag")
{
}
PhongShader::PhongShader(Camera* c, std::vector<PointLight*> lights,  SpotLight* s) 
	: Shader(c, lights, s, "PhongShader.vert", "PhongShader.frag")
{
}
