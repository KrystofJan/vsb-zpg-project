#pragma once
#include "Model.h"
class TriangleModel : public Model
{
private:
	float points[4][2][4] = {
	{ { -.5f , -0.5f , .5f , 1 } , { 1 , 1 , 0 , 1 } } ,
	{ { -.5f , 0.5f , .5f , 1 } , { 1 , 0 , 0 , 1 } } ,
	{ { .5f , 0.5f , .5f , 1 } , { 0 , 0 , 0 , 1 } } ,
	{ { .5f , -0.5f , .5f , 1 } , { 0 , 1 , 0 , 1 } } ,
	};
public:
	TriangleModel();
	void DrawModel() override;
};

