#include "ConstantShader.h"
ConstantShader::ConstantShader(Camera* c, Light* light) : Shader(c, light, "ConstantShader.vert", "ConstantShader.frag")
{
}
