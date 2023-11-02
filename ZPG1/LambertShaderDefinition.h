#pragma once
const char* vertex_shader_lambert =
"#version 330\n"
"layout(location=0) in vec3 vp;"
"layout(location=1) in vec3 nor;"

"uniform mat4 modelMatrix;"
"uniform mat4 viewMatrix;"
"uniform mat4 projectionMatrix;"
"uniform vec3 light_position;"

"out vec4 frag_position;"
"out vec3 frag_normal;"
"out vec3 frag_light_dir;"
"void main () {"
"    frag_position = modelMatrix * vec4(vp, 1.0);"
"    frag_normal = normalize(mat3(transpose(inverse(modelMatrix))) * nor);"
"    frag_light_dir = normalize(light_position - frag_position.xyz);"
"    gl_Position = projectionMatrix * (viewMatrix * frag_position);"
"}";
