#include "Texture2D.h"


Texture2D::Texture2D(std::string path)
{
	this->path = path;
	// this->texturePosition = texturePosition;
}

void Texture2D::Bind() {
	glActiveTexture(GL_TEXTURE0 + texturePosition);
	this->textureId = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	
	if (this->textureId == 0) {
		std::cout << "An error occurred while loading image." << std::endl;
		exit(EXIT_FAILURE);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBindTexture(GL_TEXTURE_2D, this->textureId);
}
