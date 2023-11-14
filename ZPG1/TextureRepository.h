#pragma once
#include "Texture.h"
#include <vector>
class TextureRepository
{
private:
	std::vector<Texture*> textures;
public:
	void addTexture(Texture* tex);
	Texture* getTextureAt(int i);
};
