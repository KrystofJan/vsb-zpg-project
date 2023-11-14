#include "TextureShader.h"

TextureShader::TextureShader(Camera* c, LightRepository* light)
	: Shader(c, light, "TextureShader.vert", "TextureShader.frag")
{
}
