#include "TextureRepository.h"

void TextureRepository::addTexture(Texture* tex)
{
	textures.push_back(tex);
	tex->setPosition(this->textures.size());
	tex->Bind();
}

Texture* TextureRepository::getTextureAt(int i)
{
	return textures[i];
}
