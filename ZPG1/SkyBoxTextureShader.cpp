#include "SkyBoxTextureShader.h"

SkyBoxTextureShader::SkyBoxTextureShader(Camera* c, LightRepository* light)
	: Shader(c, light, "SkyBoxTextureShader.vert", "SkyBoxTextureShader.frag") 
{
}

void SkyBoxTextureShader::update()
{

	this->updateUniformLocation("projectionMatrix", &this->camera->getProjectionMatrix()[0][0]);
	this->updateUniformLocation("viewMatrix", glm::mat4(glm::mat3(this->camera->getViewMatrix())));
	this->updateUniformLocation("cameraPos", this->camera->getPosition());

	this->camera->controls();
}