#include "BezierBuilder.h"

BezierBuilder::BezierBuilder(Camera* c)
{
	this->camera = c;
}

void BezierBuilder::handleAssignment()
{
	if (step == 0) {
		assignStencil();
		step++;
	}
	else if (step > 0 && step < 5) {
		assignBezierPoint(step);
		step++;
	}
}

void BezierBuilder::assignStencil()
{
	stencil_id = CallBacks::stencil_id;
}

void BezierBuilder::assignBezierPoint(int index)
{
	switch (index) {
		case 1: {
			bezier1 = camera->unProjectCameraPos(CallBacks::position);
			break;
		}
		case 2: {
			bezier2 = camera->unProjectCameraPos(CallBacks::position);
			break;
		}
		case 3: {
			bezier3 = camera->unProjectCameraPos(CallBacks::position);
			break;
		}
		case 4: {
			bezier4 = camera->unProjectCameraPos(CallBacks::position);
			break;
		}
	}
}

 glm::mat4x3 BezierBuilder::buildBezier()
{
	 return glm::mat4x3(bezier1, bezier2, bezier3, bezier4);
}

 int BezierBuilder::getStep()
 {
	 return step;
 }

 int BezierBuilder::getStencil()
 {
	 return stencil_id;
 }

 void BezierBuilder::reset()
 {
	 step = 0;
 }
