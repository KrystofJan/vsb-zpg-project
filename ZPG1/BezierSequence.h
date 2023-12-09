#pragma once
#include "BezierCurve.h"
#include <vector>

class BezierSequence : public BezierCurve
{
private:
	int currentIndex;
public:
	BezierSequence();
	std::vector<BezierCurve*> curves;
	glm::vec3 calculatePoint() override;
};
