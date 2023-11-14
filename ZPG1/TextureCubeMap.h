#pragma once
#include "Texture.h"
class TextureCubeMap : public Texture
{
private:
	std::string xpos;
	std::string xneg;
	std::string ypos;
	std::string yneg;
	std::string zpos;
	std::string zneg;
public:
	TextureCubeMap(std::string xpos, std::string xneg, std::string ypos, std::string yneg, std::string zpos, std::string zneg);
	void Bind() override;
};

