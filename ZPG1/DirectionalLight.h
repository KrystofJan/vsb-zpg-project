#pragma once
#include "Light.h"
class DirectionalLight : public Light
{
private:
	glm::vec3 direction;
    glm::vec4 ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;
public:
    DirectionalLight(glm::vec3 pos, glm::vec4 color, glm::vec3 direciton, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular);
    glm::vec3 getDirection();
    glm::vec4 getAmbient();
    glm::vec4 getDiffuse();
    glm::vec4 getSpecular();
};

