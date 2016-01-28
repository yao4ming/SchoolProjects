#version 330 Core

in vec3 vPosition;
in vec2 texCoord;

out vec2 TexCoord;

uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(vPosition, 1.0);
	TexCoord = texCoord;
}

