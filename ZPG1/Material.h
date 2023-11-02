#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdlib.h>
#include <stdio.h>
#include <string>

class Material
{
private:
	glm::vec4 ambient;
	glm::vec4 diffuse;
	glm::vec4 specular_strength;
	glm::vec4 object_Color;
	float specular_intensity;

public:
	Material(glm::vec4 ambient,	glm::vec4 diffuse, glm::vec4 specular_strength,	glm::vec4 object_Color,	float specular_intensity);
	Material();
	glm::vec4 getAmbient();
	glm::vec4 getDiffuse();
	glm::vec4 getSpecularStrength();
	glm::vec4 getObjColor();
	float getSpecIntensity();
};

