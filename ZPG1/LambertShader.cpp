#include "LambertShader.h"
LambertShader::LambertShader(Camera* c, LightRepository* l) : Shader(c, l, "LambertShader.vert", "LambertShader.frag")
{
}
