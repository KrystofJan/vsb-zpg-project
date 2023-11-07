#pragma once
#include "BaseLight.h"

class SpotLight : public BaseLight
{
private:
    glm::vec3 direction;
    float cutOff;
    float outerCutOff;
    float constant;
    float linear;
    float quadratic;
    glm::vec4 ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;

public:
    SpotLight(glm::vec3 pos, glm::vec4 color, glm::vec3 dir, float cutOff, float outerCutOff, float constant, float linear, float quadratic, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular);
    glm::vec3 getDirection();
    float getCutOff();
    float getOuterCutOff();
    float getConstant();
    float getLinear();
    float getQuadratic();
    glm::vec4 getAmbient();
    glm::vec4 getDiffuse();
    glm::vec4 getSpecular();
    void updateDirection(glm::vec3 direction);
    void upgradePosition(glm::vec3 pos);
};

