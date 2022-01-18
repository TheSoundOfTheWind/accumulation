<<<<<<< HEAD
#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;
void main()
{
	FragColor = mix(texture(texture1, TexCoord),
		        texture(texture2, TexCoord), mixValue);
=======
#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;
void main()
{
	FragColor = mix(texture(texture1, TexCoord),
		        texture(texture2, TexCoord), mixValue);
>>>>>>> 1d751b2d5d0f314aae5ee85cadda02a076b13d0f
}