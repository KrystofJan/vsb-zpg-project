#include "Shader.h"
#include <string.h>
Shader::Shader(Camera* c, Light* light, const char* vertexFile, const char* fragmentFile) 
	: ShaderProgram(vertexFile, fragmentFile){
	this->camera = c;
	this->camera->addObserver(this);

	this->light = light;
	this->light->addObserver(this);
}

Shader::Shader(Camera* c, std::vector<PointLight*> light, const char* vertexFile, const char* fragmentFile)
	: ShaderProgram(vertexFile, fragmentFile) {
	this->camera = c;
	this->camera->addObserver(this);

	for(PointLight* p : light)
	{
		pointLights.push_back(p);
		p->addObserver(this);
	}
}

Shader::Shader(Camera* c, std::vector<PointLight*> light, DirectionalLight* directionalLight, const char* vertexFile, const char* fragmentFile)
	: ShaderProgram(vertexFile, fragmentFile) {
	this->camera = c;
	this->camera->addObserver(this);

	for (PointLight* p : light)
	{
		pointLights.push_back(p);
		p->addObserver(this);
	}

	this->directionalLight = directionalLight;
	this->directionalLight->addObserver(this);
	this->hasDirectLight = true;
}

Shader::Shader(Camera* c, std::vector<PointLight*> light, SpotLight* spotLight, const char* vertexFile, const char* fragmentFile)
	: ShaderProgram(vertexFile, fragmentFile)
{
	this->camera = c;
	this->camera->addObserver(this);

	for (PointLight* p : light)
	{
		pointLights.push_back(p);
		p->addObserver(this);
	}

	this->spotLight = spotLight;
	this->spotLight->addObserver(this);
	this->hasSpotLight = true;
}

Shader::Shader(Camera* c, std::vector<PointLight*> light, DirectionalLight* directionalLight, SpotLight* spotLight, const char* vertexFile, const char* fragmentFile)
	: ShaderProgram(vertexFile, fragmentFile)
{
	this->camera = c;
	this->camera->addObserver(this);

	for (PointLight* p : light)
	{
		pointLights.push_back(p);
		p->addObserver(this);
	}

	this->directionalLight = directionalLight;
	this->directionalLight->addObserver(this);
	this->hasDirectLight = true;

	this->spotLight = spotLight;
	this->spotLight->addObserver(this);
	this->hasSpotLight = true;
}



void Shader::update()
{
	this->setPointLights();
	this->setDirectionalLight();
	this->setSpotLight();
	this->updateUniformLocation("projectionMatrix", &this->camera->getProjectionMatrix()[0][0]);
	this->updateUniformLocation("viewMatrix", &this->camera->getViewMatrix()[0][0]);
	this->updateUniformLocation("cameraPos", this->camera->getPosition());

	this->camera->controls();
}

void Shader::setPointLights()
{
	int count = 0;
	for (int i = 0; i < pointLights.size(); i++) {
		std::string position = "pointLights[" + std::to_string(i) + "].position";
		std::string color = "pointLights[" + std::to_string(i) + "].color";
		std::string constant = "pointLights[" + std::to_string(i) + "].constant";
		std::string linear = "pointLights[" + std::to_string(i) + "].linear";
		std::string quadratic = "pointLights[" + std::to_string(i) + "].quadratic";
		std::string ambient = "pointLights[" + std::to_string(i) + "].ambient";
		std::string diffuse = "pointLights[" + std::to_string(i) + "].diffuse";
		std::string specular = "pointLights[" + std::to_string(i) + "].specular";

		this->updateUniformLocation(position, this->pointLights[i]->getLightPos());
		this->updateUniformLocation(color, this->pointLights[i]->getLightColor());
		this->updateUniformLocation(constant, this->pointLights[i]->getConstant());
		this->updateUniformLocation(linear, this->pointLights[i]->getLinear());
		this->updateUniformLocation(quadratic, this->pointLights[i]->getQuadratic());
		this->updateUniformLocation(ambient, this->pointLights[i]->getAmbient());
		this->updateUniformLocation(diffuse, this->pointLights[i]->getDiffuse());
		this->updateUniformLocation(specular, this->pointLights[i]->getSpecular());
		count++;
	}

	this->updateUniformLocation("ammountOfPointLights", count);
}

void Shader::setDirectionalLight()
{
	if (hasDirectLight) 
	{
		this->updateUniformLocation("dirLight.direction", this->directionalLight->getDirection());
		this->updateUniformLocation("dirLight.color", this->directionalLight->getLightColor());
		this->updateUniformLocation("dirLight.ambient", this->directionalLight->getAmbient());
		this->updateUniformLocation("dirLight.diffuse", this->directionalLight->getDiffuse());
		this->updateUniformLocation("dirLight.specular", this->directionalLight->getSpecular());
	}

}

void Shader::setSpotLight()
{
	if (hasSpotLight) 
	{
		this->updateUniformLocation("spotLight.direction", this->spotLight->getDirection());
		this->updateUniformLocation("spotLight.color", this->spotLight->getLightColor());
		this->updateUniformLocation("spotLight.cutOff", this->spotLight->getCutOff());
		this->updateUniformLocation("spotLight.outerCutOff", this->spotLight->getOuterCutOff());
		this->updateUniformLocation("spotLight.constant", this->spotLight->getConstant());
		this->updateUniformLocation("spotLight.linear", this->spotLight->getLinear());
		this->updateUniformLocation("spotLight.quadratic", this->spotLight->getQuadratic());
		this->updateUniformLocation("spotLight.ambient", this->spotLight->getAmbient());
		this->updateUniformLocation("spotLight.diffuse", this->spotLight->getDiffuse());
		this->updateUniformLocation("spotLight.specular", this->spotLight->getSpecular());
	}

}
