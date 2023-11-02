
const char* vertex_shader_blinn =
"#version 330\n"
"layout(location=0) in vec3 vp;"
"layout(location=1) in vec3 normal;"

"uniform mat4 modelMatrix;"
"uniform mat4 viewMatrix;"
"uniform mat4 projectionMatrix;"

"out vec4 worldPos;"
"out vec3 worldNormal;"

"void main () {"
"    worldPos = modelMatrix * vec4(vp, 1.0);"
"    worldNormal = normalize(mat3(transpose(inverse(modelMatrix))) * normal);"
"    gl_Position = projectionMatrix * (viewMatrix * worldPos);"
"}";
