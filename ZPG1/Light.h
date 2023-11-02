#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include "Subject.h"

class Light : public Subject
{
private:
	glm::vec3 lightPosition;
	glm::vec4 lightColor;

public:
	Light(glm::vec3 pos, glm::vec4 col);
	glm::vec3 getLightPos();
	glm::vec4 getLightColor();
	void notify() override;
};

