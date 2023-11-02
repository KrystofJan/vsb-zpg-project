#include "BlinnShader.h"
#include "BlinnShaderDefinition.h"

BlinnShader::BlinnShader(Camera* c, Light* l): Shader(c, l, "BlinnShader.vert", "BlinnShader.frag")
{

}
