#include "BlinnShader.h"
#include "BlinnShaderDefinition.h"

BlinnShader::BlinnShader(Camera* c, LightRepository* l): Shader(c, l, "BlinnShader.vert", "BlinnShader.frag")
{

}
