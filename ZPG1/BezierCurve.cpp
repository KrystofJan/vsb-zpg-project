#include "BezierCurve.h"

BezierCurve::BezierCurve()
{

}

BezierCurve::BezierCurve(glm::mat4x3 points)
{
	this->points = points;
}

glm::vec3 BezierCurve::calculatePoint()
{
	if (t >= 1.0f || t <= 0.0f)
		isDone = true; // delta *= -1;
	t += delta;
	parameters = glm::vec4(t * t * t, t * t, t, 1.0f);
	return parameters * bezierCubic * glm::transpose(points);
}

bool BezierCurve::isFinished()
{
	return isDone;
}
