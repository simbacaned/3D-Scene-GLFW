#version 440 core
			
layout(location = 0) out vec4 colour;

in vec3 normal;
in vec3 fragmentPos;
in vec2 texCoord;


uniform vec3 u_lightPos; 
uniform vec3 u_viewPos; 	
uniform vec3 u_lightColour;	
uniform vec4 u_tint;

uniform sampler2D u_texData;

void main()
{
	float ambientStrength = 0.4;
	vec3 ambient = ambientStrength * u_lightColour;
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(u_lightPos - fragmentPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * u_lightColour;
	float specularStrength = 0.8;
	vec3 viewDir = normalize(u_viewPos - fragmentPos);
	vec3 reflectDir = reflect(-lightDir, norm);  
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
	vec3 specular = specularStrength * spec * u_lightColour;  
	
	colour = vec4((ambient + diffuse + specular), 1.0) * texture(u_texData, texCoord) * u_tint;
}