#pragma once
#include "Texture.h"
class Texture2D : public Texture
{
private:
	std::string path;
public:
	Texture2D(std::string path);
	void Bind() override;
		
};

