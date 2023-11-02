#version 330
in vec4 worldPos;
in vec3 worldNormal;
out vec4 out_Color;

uniform vec3 lightPos;
uniform vec4 light_color;
uniform vec4 amb;
uniform vec4 diff;
uniform vec4 objColor;
void main(void) {
    vec3 lightDir = normalize(lightPos - worldPos.xyz);
    vec4 ambient = amb * light_color;

    float diffIntensity = max(dot(lightDir ,worldNormal), 0.0);
    vec4 diffuse = diff * light_color * diffIntensity;

    out_Color = objColor *  (ambient + diffuse) ;
}