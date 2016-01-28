#version 330 Core

in vec2 TexCoord;

out vec4 fColor;

uniform sampler2D myTexture;

void main() 
{ 
	fColor = texture(myTexture, TexCoord) * vec4(1.0, 0.0, 1.0, 1.0);

}
