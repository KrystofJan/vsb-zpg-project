#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <stdlib.h>
#include <stdio.h>

class Transformation
{
public:
	glm::mat4 modelMatrix = glm::mat4(1.0f);
public:
	virtual glm::mat4 applyTransformation() = 0;
};

