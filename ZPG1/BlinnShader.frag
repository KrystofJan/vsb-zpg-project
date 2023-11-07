#version 330
in vec4 worldPos;
in vec3 worldNormal;
out vec4 out_Color;

uniform vec3 cameraPos;
uniform vec3 lightPos;
uniform vec4 light_color;
uniform vec4 amb;
uniform vec4 diff;
uniform vec4 specularStrength;
uniform float powExponent;
void main(void) {
    vec3 lightDir = normalize(lightPos - worldPos.xyz);
    vec4 ambient = amb * light_color;
    float diffIntensity = max(dot(lightDir ,worldNormal), 0.0);
    vec4 diffuse = diff * light_color * diffIntensity;

	vec3 viewDir = normalize(cameraPos - worldPos.xyz);
	vec3 halfwayDir = normalize(lightDir + viewDir);

	float spec = pow(max(dot(worldNormal,halfwayDir ), 0.0), 120);
    vec4 specular = specularStrength * spec * light_color;

    out_Color = vec4(0.91, 0.47, 0.65, 1.0) *  (ambient + diffuse + specular) ;
}