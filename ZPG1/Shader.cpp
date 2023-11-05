#include "Shader.h"
#include <string.h>

Shader::Shader(Camera* c, LightRepository* lr, const char* vertexFile, const char* fragmentFile)
	: ShaderProgram(vertexFile, fragmentFile)
{
	this->camera = c;
	this->camera->addObserver(this);

	this->light_repository = lr;
	// this->light_repository->assignObservers(this);
}

void Shader::update()
{
	this->updateLights();
	this->updateUniformLocation("projectionMatrix", &this->camera->getProjectionMatrix()[0][0]);
	this->updateUniformLocation("viewMatrix", &this->camera->getViewMatrix()[0][0]);
	this->updateUniformLocation("cameraPos", this->camera->getPosition());

	this->camera->controls();
}

void Shader::updateLights()
{
	this->updateBaseLight();
	this->updatePointLights();
	this->updateDirectionalLight();
	this->updateSpotLight();
}

void Shader::updateBaseLight() 
{
	if (this->light_repository->hasBaseLight()) 
	{
		Light* l = this->light_repository->getBaseLight();
		this->updateUniformLocation("lightPos", l->getLightPos());
		this->updateUniformLocation("light_color", l->getLightColor());
	}
}

void Shader::updatePointLights()
{
	if (!this->light_repository->hasPointLights()) {
		return;
	}
	int count = 0;
	for (int i = 0; i < this->light_repository->getPointLightsAmmout(); i++) {
		std::string position = "pointLights[" + std::to_string(i) + "].position";
		std::string color = "pointLights[" + std::to_string(i) + "].color";
		std::string constant = "pointLights[" + std::to_string(i) + "].constant";
		std::string linear = "pointLights[" + std::to_string(i) + "].linear";
		std::string quadratic = "pointLights[" + std::to_string(i) + "].quadratic";
		std::string ambient = "pointLights[" + std::to_string(i) + "].ambient";
		std::string diffuse = "pointLights[" + std::to_string(i) + "].diffuse";
		std::string specular = "pointLights[" + std::to_string(i) + "].specular";
		PointLight* pl = this->light_repository->getPointLightAt(i);
		this->updateUniformLocation(position, pl->getLightPos());
		this->updateUniformLocation(color, pl->getLightColor());
		this->updateUniformLocation(constant, pl->getConstant());
		this->updateUniformLocation(linear, pl->getLinear());
		this->updateUniformLocation(quadratic, pl->getQuadratic());
		this->updateUniformLocation(ambient, pl->getAmbient());
		this->updateUniformLocation(diffuse, pl->getDiffuse());
		this->updateUniformLocation(specular, pl->getSpecular());
		count++;
	}

	this->updateUniformLocation("ammountOfPointLights", count);
}

void Shader::updateDirectionalLight()
{
	if (this->light_repository->hasDirectionalLight()) 
	{
		DirectionalLight* dl = this->light_repository->getDirectionalLight();
		this->updateUniformLocation("dirLight.direction", dl->getDirection());
		this->updateUniformLocation("dirLight.color", dl->getLightColor());
		this->updateUniformLocation("dirLight.ambient", dl->getAmbient());
		this->updateUniformLocation("dirLight.diffuse", dl->getDiffuse());
		this->updateUniformLocation("dirLight.specular", dl->getSpecular());
	}

}

void Shader::updateSpotLight()
{
	if (this->light_repository->hasSpotLight()) 
	{
		SpotLight* sl = this->light_repository->getSpotLight();
		this->updateUniformLocation("spotLight.direction", sl->getDirection());
		this->updateUniformLocation("spotLight.color", sl->getLightColor());
		this->updateUniformLocation("spotLight.cutOff", sl->getCutOff());
		this->updateUniformLocation("spotLight.outerCutOff", sl->getOuterCutOff());
		this->updateUniformLocation("spotLight.constant", sl->getConstant());
		this->updateUniformLocation("spotLight.linear", sl->getLinear());
		this->updateUniformLocation("spotLight.quadratic", sl->getQuadratic());
		this->updateUniformLocation("spotLight.ambient", sl->getAmbient());
		this->updateUniformLocation("spotLight.diffuse", sl->getDiffuse());
		this->updateUniformLocation("spotLight.specular", sl->getSpecular());
	}
}
