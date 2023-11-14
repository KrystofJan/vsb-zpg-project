#pragma once

#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include <stdlib.h>
#include <stdio.h>

// todo add constructor for noe modelMatrix

class Transformation
{
public:
	glm::mat4 modelMatrix = glm::mat4(1.0f);
public:
	// TODO delete virtual lol
	// todo enum for axis
	virtual glm::mat4 applyTransformation() = 0;
};

