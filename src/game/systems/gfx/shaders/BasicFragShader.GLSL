#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 FragPos;
in vec2 TexCoord;

uniform vec3 lightPos;
uniform sampler2D texture1;

void main()
{
    vec3 ambient = 0.5 * vec3(1.0f, 1.0f, 1.0f);

    vec3 norm = normalize(normal);
    vec3 dir = normalize(lightPos - FragPos);

    float diff = max(dot(norm, dir), 0.0);
    vec3 diffuse = diff * vec3(1.0f, 1.0f, 1.0f);

    vec3 result = (ambient + diffuse) * vec3(1.5f,1.5f,1.5f);
    //FragColor = vec4(result, 1.0);
    FragColor = texture(texture1, TexCoord) * vec4(result, 1.0);

}