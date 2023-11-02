
const char* vertex_shader_phong =
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

const char* fragment_shader_phong =
"#version 330\n"
"in vec4 worldPos;"
"in vec3 worldNormal;"
"out vec4 out_Color;"

"uniform vec3 cameraPos;"
"uniform vec3 light_position;"
"uniform vec4 light_color;"
"uniform vec4 amb = vec4(0.1, 0.1, 0.1, 1.0);"
"uniform vec4 diff = vec4(0.385, 0.647, 0.812, 1.0);"
"uniform vec4 specularStrength = vec4(1.0, 1.0, 1.0, 1.0);"
"uniform float powExponent = 16;"
"void main(void) {"
"    vec3 lightDir = normalize(light_position - worldPos.xyz);"
"    vec4 ambient = amb * light_color;"

"    float diffIntensity = max(dot(lightDir ,worldNormal), 0.0);"
"    vec4 diffuse = diff * light_color * diffIntensity;"

"	 vec3 viewDir = normalize(cameraPos - worldPos.xyz);"
"    vec3 reflectDir = reflect(-lightDir, worldNormal);"
"	 float spec = pow(max(dot(viewDir,reflectDir ), 0.0), powExponent);"
"    vec4 specular = specularStrength * spec * light_color;"

"    out_Color = vec4(0.91, 0.47, 0.65, 1.0) *  (ambient + diffuse + specular) ;"
"}";
