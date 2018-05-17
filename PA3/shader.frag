#version 330 core

// This is a sample fragment shader.

uniform struct Material{

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;

}material;

uniform struct DirLight{

    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    
}dirLight;

uniform struct PointLight{
    
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    
}pointLight;

uniform struct SpotLight{
    
    vec3 direction;
    
    vec3 position;
    float constant;
    float linear;
    float quadratic;
    float cutOff;
    float outerCutOff;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    
}spotLight;

in vec3 fragNormals;
in vec3 fragPos;

out vec4 color;

uniform int lightOn = 1;

uniform vec3 viewPos;

//Function Prototypes
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main(){
    
    vec3 result;
    
    vec3 norm = normalize(fragNormals);
    
    vec3 viewDir = normalize(viewPos - fragPos);
    
    //if(lightOn == 1){
        
        result = CalcDirLight(dirLight, norm, viewDir);
    //}
    
    /*else if(lightOn == 2){
    
        //for(int i = 0; i < 4; i++){
        
            result = CalcPointLight(pointLight, norm, fragPos, viewDir);
        //}
    }
    
    else{
    
        result = CalcSpotLight(spotLight, norm, fragPos, viewDir);
    }*/
    
    //color = vec4(1.0f, 0.0f, 0.0f, 0.0f);
    
    /**use to return lights calculations**/
    color = vec4(result, 1.0);
    
    /*used to test vectors and values*/
    //color = vec4(dirLight.specular, 1.0f);
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir){
 
    vec3 lightDir = normalize(-light.direction);
 
    float diff = max(dot(normal, lightDir), 0.0);
 
    vec3 reflectDir = reflect(-lightDir, normal);
 
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
 
    vec3 ambient = light.ambient * material.ambient;
 
    vec3 diffuse = light.diffuse * diff * material.diffuse;
 
    vec3 specular = light.specular * spec * material.specular;
 
    return(ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir){

    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    // Combine results
    vec3 ambient = light.ambient * material.diffuse;
    vec3 diffuse = light.diffuse * material.diffuse;
    vec3 specular = light.specular * spec * material.specular;
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    
    return (ambient + diffuse + specular);
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = pow(dot(light.direction, -lightDir),spotLight.cutOff) / (/*light.constant + light.linear * distance +*/ light.quadratic * (distance * distance));
    // Combine results
    vec3 ambient = light.ambient * material.diffuse;
    vec3 diffuse = light.diffuse * diff * material.diffuse;
    vec3 specular = light.specular * spec * material.specular;
    //ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    
    if(acos(dot(light.direction, -lightDir)) <= spotLight.outerCutOff){
    
        return (ambient + diffuse + specular);
        //return ambient + pow(max(dot(light.direction, -lightDir),0), light.outerCutOff * attenuation * (diffuse + specular);
        
    }
    
    else{
    
        return ambient;
        //return ambient + pow(max(dot(Light.direction, -lightDir),0), Light.outer* ateen*(diffuse+spec)
    }
}