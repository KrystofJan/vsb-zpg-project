#version 330
in vec4 worldPos;
in vec3 worldNormal;
out vec4 out_Color;
#define MAX_LIGHTS 4

struct PointLight {
    vec3 position;
    vec4 color;

    float constant;
    float linear;
    float quadratic;

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;
};

struct DirectionalLight {
    vec3 direction;
    vec4 color;
	
    vec4 ambient;
    vec4 diffuse;
    vec4 specular;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    vec4 color;

    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec4 ambient;
    vec4 diffuse;
    vec4 specular;       
};


uniform vec3 cameraPos;
uniform vec4 amb;
uniform vec4 diff;
uniform vec4 specularStrength;
uniform vec4 objColor;
uniform float powExponent;
uniform PointLight pointLights[MAX_LIGHTS];
uniform DirectionalLight dirLight;
uniform SpotLight spotLight;
uniform bool hasDirectionalLight;
uniform bool hasSpotLight;
uniform int ammountOfPointLights;

vec4 CalcSpotLight(SpotLight light);
vec4 CalcPointLight(PointLight light);
vec4 CalcDirectionalLight(DirectionalLight light);

float attenuation(float c, float l, float q, float dist);

void main(void) {
    vec4 result = vec4(0.0f);

    if(hasDirectionalLight)
        result += CalcDirectionalLight(dirLight);
    
    for(int i = 0; i < ammountOfPointLights; i++)
      result += CalcPointLight(pointLights[i]);

    if(hasSpotLight){

        result += CalcSpotLight(spotLight);
    }


    out_Color = objColor *  result;
}

vec4 CalcPointLight(PointLight light){
    vec3 lightDir = normalize(light.position - worldPos.xyz);
    vec4 ambient = light.ambient  * amb * light.color;

    float diffIntensity = max(dot(lightDir ,worldNormal), 0.0);
    vec4 diffuse = light.diffuse  * diff * diffIntensity * light.color;
	
    vec3 viewDir = normalize(cameraPos - worldPos.xyz);
    vec3 reflectDir = reflect(-lightDir, worldNormal); 

	float spec = pow(max(dot(viewDir,reflectDir ), 0.0), powExponent);
    float dist = length(light.position - worldPos.xyz);
    vec4 specular = light.specular * specularStrength * spec * light.color;
    //    if ( dot ( worldNormal , lightDir ) < 0.0) {
    //        specular = vec4 (0.0 , 0.0 , 0.0 , 0.0);
    //    }

    float att = attenuation(light.constant, light.linear, light.quadratic, dist);

    ambient *= att;
    diffuse *= att;
    specular *= att;

    return (ambient + diffuse + specular);
}


vec4 CalcDirectionalLight(DirectionalLight light){
    vec3 lightDir = normalize(-light.direction);

    vec4 ambient = light.ambient  * amb * light.color;

    float diffIntensity = max(dot(lightDir ,worldNormal), 0.0);
    vec4 diffuse = light.diffuse  * diff * diffIntensity * light.color;

    vec3 viewDir = normalize(cameraPos - worldPos.xyz);
    vec3 reflectDir = reflect(-lightDir, worldNormal); 

	float spec = pow(max(dot(viewDir,reflectDir ), 0.0), powExponent);
    vec4 specular = light.specular * specularStrength * spec * light.color;
    //    if ( dot ( worldNormal , lightDir ) < 0.0) {
    //        specular = vec4 (0.0 , 0.0 , 0.0 , 0.0);
    //    }
    return (ambient + diffuse + specular);
}

vec4 CalcSpotLight(SpotLight light){
    // ambient
    vec4 ambient = light.ambient  * amb * light.color;
    
    vec3 lightDir = normalize(light.position - worldPos.xyz);
    float diffIntensity = max(dot(lightDir ,worldNormal), 0.0);
    vec4 diffuse = light.diffuse  * diff * diffIntensity * light.color;
    
    // specular
    vec3 viewDir = normalize(cameraPos - worldPos.xyz);
    vec3 reflectDir = reflect(-lightDir, worldNormal); 

    float spec = pow(max(dot(viewDir,reflectDir ), 0.0), powExponent);
    vec4 specular = light.specular * specularStrength * spec * light.color;
    
    // spotlight (soft edges)
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = (light.cutOff - light.outerCutOff);
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    diffuse  *= intensity;
    specular *= intensity;
    
    // attenuation
    float distance = length(light.position - worldPos.xyz);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    ambient  *= attenuation; 
    diffuse   *= attenuation;
    specular *= attenuation;   
        
    return (ambient + diffuse + specular);

}

float attenuation(float c, float l, float q, float dist){
    float att = 1.0 / (c + l * dist + q * (dist* dist));
    return att;
}