#version 460 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D mainTexture;

void main()
{
	FragColor = texture(mainTexture, TexCoord);
}