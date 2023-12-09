#include "BezierSequence.h"

BezierSequence::BezierSequence()
{
}

glm::vec3 BezierSequence::calculatePoint()
{
	if ((currentIndex+1 >= curves.size() && curves[currentIndex]->isFinished()) || isDone) {
		isDone = true;
		return glm::vec4(0);
	}
	if (curves[currentIndex]->isFinished()) {
		currentIndex++;
	}

	return curves[currentIndex]->calculatePoint();
}
