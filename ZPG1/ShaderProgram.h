#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "ShaderLoader.h"

class ShaderProgram : public ShaderLoader
{
private:
	GLuint shaderProgramId; // maybe delete and use the one from shaderLoader ?
public:
	ShaderProgram(const char* vertexFile, const char* fragmentFile);
	void activateShaderProgram();
	void deactivateShaderProgram();
	void updateUniformLocation(std::string variable, const GLfloat* value);
	void updateUniformLocation(std::string variable, glm::vec3 value);
	void updateUniformLocation(std::string variable, glm::vec4 value);
	void updateUniformLocation(std::string variable, float value);
	void updateUniformLocation(std::string variable, int value);
};
