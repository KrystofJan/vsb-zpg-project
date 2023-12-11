#pragma once
#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include "CallBacks.h"
#include "Camera.h"

class BezierBuilder
{
private:
	int step = 0;

	int stencil_id;
	glm::vec3 bezier1;
	glm::vec3 bezier2;
	glm::vec3 bezier3;
	glm::vec3 bezier4;

	Camera* camera;

	void assignStencil();
	void assignBezierPoint(int index);
public:
	BezierBuilder(Camera* c);
	void handleAssignment();
	glm::mat4x3 buildBezier();
	int getStep();
	int getStencil();
	void reset();
};
