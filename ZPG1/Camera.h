#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include <stdlib.h>
#include <stdio.h>
#include "Subject.h"


class Camera : public Subject
{
private:
	float yaw = -90.0f;	
	float pitch = 0.0f;

	float lastX = 1;
	float lastY = 1;
	float startX = 0;
	float startY = 0;

	bool firstMouse = true;

	float dampeningFactor = 0.1f;

	float sensitivity = 0.1f;

	GLFWwindow* window;
	
	glm::vec3 direction;

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;
public:
	Camera(GLFWwindow* window);
	void call_cursor(double x, double y);
	void controls(void);
	glm::mat4 getProjectionMatrix();
	glm::mat4 getViewMatrix(void);
	glm::vec3 getPosition();
	glm::vec3 getDirection();
	glm::vec3 unProjectCameraPos(glm::vec3 position);
	void notify();
};

