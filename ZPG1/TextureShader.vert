#version 330
layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;


uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

//out vec4 worldPos;
//out vec3 worldNormal;
out vec2 uvc;

void main () {
    vec4 worldPos = modelMatrix * vec4(vp, 1.0);
    // worldNormal = normalize(mat3(transpose(inverse(modelMatrix))) * normal);
    uvc = uv;
    gl_Position = projectionMatrix * viewMatrix * worldPos;
}