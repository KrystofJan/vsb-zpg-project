const char* vertex_shader =
"#version 330\n"
"layout(location=0) in vec3 vp;"
"uniform mat4 modelMatrix;"
"uniform mat4 viewMatrix;"
"uniform mat4 projectionMatrix;"
"in vec3 color;"
"out vec3 Color;"
"void main () {"
"	  Color=color;"
"     gl_Position = projectionMatrix * (viewMatrix * (modelMatrix * vec4(vp, 1.0)));"
"}";
