#version 330
in vec3 Color;
out vec4 frag_colour;
void main () {
     frag_colour = vec4(Color,0.0);
}