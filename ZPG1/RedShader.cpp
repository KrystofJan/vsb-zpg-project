#include "RedShader.h"


RedShader::RedShader(Camera* c, Light* light) : Shader(c, light, "RedShader.vs", "RedShader.fs")
{
}
