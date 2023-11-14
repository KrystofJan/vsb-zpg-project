#version 330
in vec3 fragmentLocalPosition;

uniform samplerCube textureUnitID;

out vec4 frag_colour;

void main () {	 
    frag_colour = texture(textureUnitID, fragmentLocalPosition);
}
