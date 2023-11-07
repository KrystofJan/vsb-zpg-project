#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(glm::vec3 pos, glm::vec4 color,glm::vec3 direciton, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular)
    : BaseLight(pos, color)
{
    this->direction = direciton;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
}

glm::vec3 DirectionalLight::getDirection() {
    return this->direction;
}
glm::vec4 DirectionalLight::getAmbient() {
    return this->ambient;
}
glm::vec4 DirectionalLight::getDiffuse() {
    return this->diffuse;
}
glm::vec4 DirectionalLight::getSpecular() {
    return this->specular;
}