#version 450
layout(location = 0) in vec3 vp;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;


out vec3 fragmentLocalPosition;
void main () {
    fragmentLocalPosition = vp;
    gl_Position = projectionMatrix * viewMatrix * vec4(vp, 1.0);
}
