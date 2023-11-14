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

	this->updateUniformLocation("projectionMatrix", &this->camera->getProjectionMatrix()[0][0]);
	this->updateUniformLocation("viewMatrix", &this->camera->getViewMatrix()[0][0]);
	this->updateUniformLocation("cameraPos", this->camera->getPosition());

	this->camera->controls();
}

void Shader::updateLights()
{
	this->updateUniformLocation("ammountOfLights", this->light_repository->getLightVecSize());

	this->updateBaseLight();
	this->updatePointLights();
	this->updateDirectionalLight();
	this->updateSpotLight();
}

void Shader::updateBaseLight() 
{
	for (int i = 0; i < this->light_repository->getLightVecSize(); i++) {
		if (this->light_repository->LightAt(i)->getType() == 0) {
			BaseLight* l = light_repository->LightAt(i);

			std::string position = "lights[" + std::to_string(i) + "].position";
			std::string color = "lights[" + std::to_string(i) + "].color";
			std::string type = "lights[" + std::to_string(i) + "].type";
			this->updateUniformLocation(type, 0);
			this->updateUniformLocation(position, l->getLightPos());
			this->updateUniformLocation(color, l->getLightColor());
			this->updateUniformLocation("lightPos", l->getLightPos());
			this->updateUniformLocation("light_color", l->getLightColor());

		}
	}
}

void Shader::updatePointLights()
{
	for (int i = 0; i < this->light_repository->getLightVecSize(); i++) {
		if (this->light_repository->LightAt(i)->getType() == 2) 
		{
			BaseLight* bl = dynamic_cast<BaseLight*>(light_repository->LightAt(i));
			PointLight* pl = dynamic_cast<PointLight*>(bl);

			std::string position = "lights[" + std::to_string(i) + "].position";
			std::string color = "lights[" + std::to_string(i) + "].color";
			std::string constant = "lights[" + std::to_string(i) + "].constant";
			std::string linear = "lights[" + std::to_string(i) + "].linear";
			std::string quadratic = "lights[" + std::to_string(i) + "].quadratic";
			std::string ambient = "lights[" + std::to_string(i) + "].ambient";
			std::string diffuse = "lights[" + std::to_string(i) + "].diffuse";
			std::string specular = "lights[" + std::to_string(i) + "].specular";
			std::string type = "lights[" + std::to_string(i) + "].type";
			this->updateUniformLocation(type, 2);

			this->updateUniformLocation(position, pl->getLightPos());
			this->updateUniformLocation(color, pl->getLightColor());
			this->updateUniformLocation(constant, pl->getConstant());
			this->updateUniformLocation(linear, pl->getLinear());
			this->updateUniformLocation(quadratic, pl->getQuadratic());
			this->updateUniformLocation(ambient, pl->getAmbient());
			this->updateUniformLocation(diffuse, pl->getDiffuse());
			this->updateUniformLocation(specular, pl->getSpecular());
		}
	}
}

void Shader::updateDirectionalLight()
{
	for (int i = 0; i < this->light_repository->getLightVecSize(); i++) {
		if (light_repository->LightAt(i)->getType() == 1) {
			BaseLight* bl = dynamic_cast<BaseLight*>(light_repository->LightAt(i));
			DirectionalLight* dl = dynamic_cast<DirectionalLight *>(bl);

			std::string color = "lights[" + std::to_string(i) + "].color";
			std::string dir = "lights[" + std::to_string(i) + "].direction";
			std::string ambient = "lights[" + std::to_string(i) + "].ambisent";
			std::string diffuse = "lights[" + std::to_string(i) + "].diffuse";
			std::string specular = "lights[" + std::to_string(i) + "].specular";
			std::string type = "lights[" + std::to_string(i) + "].type";
			this->updateUniformLocation(type, 1);

			this->updateUniformLocation(dir, dl->getDirection());
			this->updateUniformLocation(color, dl->getLightColor());
			this->updateUniformLocation(ambient, dl->getAmbient());
			this->updateUniformLocation(diffuse, dl->getDiffuse());
			this->updateUniformLocation(specular, dl->getSpecular());
		}
	}
}

void Shader::updateSpotLight()
{
	
	for (int i = 0; i < this->light_repository->getLightVecSize(); i++) {
		if (this->light_repository->LightAt(i)->getType() == 3) {
			BaseLight* bl = dynamic_cast<BaseLight*>(light_repository->LightAt(i));
			SpotLight* sl = dynamic_cast<SpotLight*>(bl);

			std::string position = "lights[" + std::to_string(i) + "].position";
			std::string color = "lights[" + std::to_string(i) + "].color";
			std::string dir = "lights[" + std::to_string(i) + "].direction";
			std::string cu = "lights[" + std::to_string(i) + "].cutOff";
			std::string ocu = "lights[" + std::to_string(i) + "].outerCutOff";
			std::string constant = "lights[" + std::to_string(i) + "].constant";
			std::string linear = "lights[" + std::to_string(i) + "].linear";
			std::string quadratic = "lights[" + std::to_string(i) + "].quadratic";
			std::string ambient = "lights[" + std::to_string(i) + "].ambisent";
			std::string diffuse = "lights[" + std::to_string(i) + "].diffuse";
			std::string specular = "lights[" + std::to_string(i) + "].specular";

			std::string type = "lights[" + std::to_string(i) + "].type";
			this->updateUniformLocation(type, 3);

			this->updateUniformLocation(position, sl->getLightPos());
			this->updateUniformLocation(dir, sl->getDirection());
			this->updateUniformLocation(color, sl->getLightColor());
			this->updateUniformLocation(cu, sl->getCutOff());
			this->updateUniformLocation(ocu, sl->getOuterCutOff());
			this->updateUniformLocation(constant, sl->getConstant());
			this->updateUniformLocation(linear, sl->getLinear());
			this->updateUniformLocation(quadratic, sl->getQuadratic());
			this->updateUniformLocation(ambient, sl->getAmbient());
			this->updateUniformLocation(diffuse, sl->getDiffuse());
			this->updateUniformLocation(specular, sl->getSpecular());
		}
	}
}
