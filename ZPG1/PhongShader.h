#pragma 
#include "Shader.h"
class PhongShader : public Shader
{
public:
	PhongShader(Camera* c, Light* light);
	PhongShader(Camera* c, std::vector<PointLight*> lights);
	PhongShader(Camera* c, std::vector<PointLight*> lights, DirectionalLight* d);
	PhongShader(Camera* c, std::vector<PointLight*> lights, SpotLight* s);
	PhongShader(Camera* c, std::vector<PointLight*> lights, DirectionalLight* d, SpotLight* s);
};
