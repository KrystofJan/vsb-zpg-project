#include "Texture.h"

void Texture::setPosition(int pos)
{
	this->texturePosition = pos;
}

int Texture::getPosition()
{
	return texturePosition;
}

int Texture::getTextureId()
{
	return textureId;
}

void Texture::baseBind()
{
	glActiveTexture(GL_TEXTURE0 + texturePosition);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);
}
