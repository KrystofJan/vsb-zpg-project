#pragma once

#include <glm/mat4x4.hpp> // glm::mat4

#include "Subject.h"

class BaseLight : public Subject
{
protected:
	glm::vec3 lightPosition;
	glm::vec4 lightColor;
	int type;
public:
	BaseLight(glm::vec3 pos, glm::vec4 col);
	glm::vec3 getLightPos();
	glm::vec4 getLightColor();
	int getType();
	void notify() override;
};

