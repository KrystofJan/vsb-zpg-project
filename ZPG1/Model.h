#pragma once
// Login: ZAH0089
#include <GL/glew.h>


//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

class Model
{
protected:
	GLuint VBO;
	GLuint VAO;
public:
	Model();
	void BindModel();
	virtual void DrawModel() = 0;
};

