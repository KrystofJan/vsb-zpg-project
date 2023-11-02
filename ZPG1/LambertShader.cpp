#include "LambertShader.h"
LambertShader::LambertShader(Camera* c, Light* light) : Shader(c, light, "LambertShader.vert", "LambertShader.frag")
{
}
