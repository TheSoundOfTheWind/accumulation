<<<<<<< HEAD
#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	FragColor = mix(texture(texture1, TexCoord),
		        texture(texture2, TexCoord), 0.2);
=======
#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	FragColor = mix(texture(texture1, TexCoord),
		        texture(texture2, TexCoord), 0.2);
>>>>>>> 1d751b2d5d0f314aae5ee85cadda02a076b13d0f
}