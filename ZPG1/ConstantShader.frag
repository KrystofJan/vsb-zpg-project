#version 330
in vec4 worldPos;
in vec3 worldNormal;
out vec4 out_Color;

uniform vec4 objColor;
void main(void) {
    out_Color = objColor ;
}