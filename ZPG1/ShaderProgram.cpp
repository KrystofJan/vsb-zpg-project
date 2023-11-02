#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* vertexFile, const char* fragmentFile)
	: ShaderLoader(vertexFile, fragmentFile, &this->shaderProgramId)
{
}

void ShaderProgram::activateShaderProgram()
{
	glUseProgram(this->shaderProgramID);
}

void ShaderProgram::deactivateShaderProgram()
{
	glUseProgram(0);
}

void ShaderProgram::updateUniformLocation(std::string variable, const GLfloat* value)
{
	GLint id = glGetUniformLocation(this->shaderProgramID, variable.c_str());

	if (id >= 0) {
		glUniformMatrix4fv(id, 1, GL_FALSE, value);
	}
}

void ShaderProgram::updateUniformLocation(std::string variable, glm::vec3 value)
{
	GLint id = glGetUniformLocation(this->shaderProgramID, variable.c_str());

	if (id >= 0) {
		glUniform3f(id, value.x, value.y, value.z);
	}
}

void ShaderProgram::updateUniformLocation(std::string variable, glm::vec4 value)
{
	GLint id = glGetUniformLocation(this->shaderProgramID, variable.c_str());

	if (id >= 0) {
		glUniform4f(id, value.x, value.y, value.z, value.w);
	}
}

void ShaderProgram::updateUniformLocation(std::string variable, float value)
{
	GLint id = glGetUniformLocation(this->shaderProgramID, variable.c_str());

	if (id >= 0) {
		glUniform1f(id, value);
	}
}

void ShaderProgram::updateUniformLocation(std::string variable, int value)
{
	GLint id = glGetUniformLocation(this->shaderProgramID, variable.c_str());

	if (id >= 0) {
		glUniform1i(id, value);
	}
}