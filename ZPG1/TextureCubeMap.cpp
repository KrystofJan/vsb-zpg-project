#include "TextureCubeMap.h"

TextureCubeMap::TextureCubeMap(std::string xpos, std::string xneg, std::string ypos, std::string yneg, std::string zpos, std::string zneg)
{

	this->xpos = xpos;
	this->xneg = xneg;
	this->ypos = ypos;
	this->yneg = yneg;
	this->zpos = zpos;
	this->zneg = zneg;
}

void TextureCubeMap::Bind() {

	glActiveTexture(GL_TEXTURE0 + texturePosition);
	GLuint image = SOIL_load_OGL_cubemap(
		xpos.c_str(), xneg.c_str(),
		ypos.c_str(), yneg.c_str(),
		zpos.c_str(), zneg.c_str(),
		SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS
	);
	if (image == 0) {
		std::cout << "An error occurred while loading image." << std::endl;
		exit(EXIT_FAILURE);
	}
	glBindTexture(GL_TEXTURE_CUBE_MAP, image);
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
}
