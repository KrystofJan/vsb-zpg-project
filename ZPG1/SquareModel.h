#pragma once
#include "Model.h"
class SquareModel : public Model
{
private:
	float points[4][2][4] = {
	{ { .0f , 0.0f , .0f , 1.0f } , { 1.0f , 0.0f , 0.0f , 1.0f } } ,
	{ { .0f , -.5f , .0f , 1.0f } , { 0.0f , 1.0f , 0.0f , 1.0f } } ,
	{ { .5f , -.5f , .0f , 1.0f } , { 0.0f , 0.0f , 1.0f , 1.0f } } ,
	{ { .5f , .0f , .0f , 1.0f } , { 1.0f , 0.0f , 1.0f , 1.0f } } ,
	};
public:
	SquareModel();
	void DrawModel(int id) override;
};
