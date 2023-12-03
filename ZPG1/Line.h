#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

class Line
{
private:
	glm::vec3 u;
	glm::vec3 A = glm::vec3(0);
	glm::vec3 B = glm::vec3(30,0,0);

protected:
	float t = 0.1;

public:
	virtual glm::vec3 calculatePoint();
};

