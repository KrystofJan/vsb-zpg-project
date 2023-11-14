#pragma once
#include <GL/glew.h>
#include <string>
#include <SOIL2.h>
#include <iostream>
class Texture
{
protected:
	GLint textureId;
	int texturePosition;
public:
	void setPosition(int pos);
	int getPosition();
	int getTextureId();
	virtual void Bind() = 0;
	void baseBind();
};

