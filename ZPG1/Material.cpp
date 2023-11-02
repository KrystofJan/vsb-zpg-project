#include "Material.h"

Material::Material(glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular_strength, glm::vec4 object_Color, float specular_intensity)
{
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular_strength = specular_strength;
	this->object_Color = object_Color;
	this->specular_intensity = specular_intensity;
}
Material::Material() 
{
	this->ambient = glm::vec4(0.1, 0.1, 0.1, 1.0);
	this->diffuse = glm::vec4(0.385, 0.647, 0.812, 1.0);
	this->specular_strength = glm::vec4(1.0, 1.0, 1.0, 1.0);
	this->object_Color = glm::vec4(0.91, 0.47, 0.65, 1.0);
	this->specular_intensity = 16;
}
glm::vec4 Material::getAmbient() {
	return this->ambient;
}
glm::vec4 Material::getDiffuse() {
	return this->diffuse;
}
glm::vec4 Material::getSpecularStrength() {
	return this->specular_strength;
}
glm::vec4 Material::getObjColor() {
	return this->object_Color;
}
float Material::getSpecIntensity() {
	return this->specular_intensity;
}