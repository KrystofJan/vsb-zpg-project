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
uniform vec4 objColor;
uniform float powExponent;

void main(void) {

    vec3 lightDir = normalize(lightPos - worldPos.xyz);

    vec4 ambient = amb * light_color;

    float diffIntensity = max(dot(lightDir ,worldNormal), 0.0);

    vec4 diffuse = diff * light_color * diffIntensity;

    vec3 viewDir = normalize(cameraPos - worldPos.xyz);

    vec3 reflectDir = reflect(-lightDir, worldNormal); 

	float spec = pow(max(dot(viewDir,reflectDir), 0.0), powExponent);

    vec4 specular = specularStrength * spec * light_color;

    

//    if ( dot ( worldNormal , lightDir ) < 0.0) {

//        specular = vec4 (0.0 , 0.0 , 0.0 , 0.0);
//    }

    out_Color = objColor *  (ambient + diffuse + specular) ;

}