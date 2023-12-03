#pragma once
#include "Line.h"
class BezierCurve : public Line
{
private:
	glm::mat4x3 points;
	float delta = 0.005f;
	glm::mat4 bezierCubic = glm::mat4(glm::vec4(-1.0, 3.0, -3.0, 1.0),
		glm::vec4(3.0, -6.0, 3.0, 0),
		glm::vec4(-3.0, 3.0, 0, 0),
		glm::vec4(1, 0, 0, 0));

	glm::vec4 parameters;

public:
	BezierCurve(glm::mat4x3 points);
	glm::vec3 calculatePoint() override;
};

