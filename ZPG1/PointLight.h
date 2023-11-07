#pragma once
#include "BaseLight.h"

class PointLight : public BaseLight
{
private:
    float constant;
    float linear;
    float quadratic;
    glm::vec4 ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;
public:
    PointLight(glm::vec3 pos, glm::vec4 color, float constant, float linear, float quadratic, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular);
    float getConstant();
    float getLinear();
    float getQuadratic();
    glm::vec4 getAmbient();
    glm::vec4 getDiffuse();
    glm::vec4 getSpecular();

};

