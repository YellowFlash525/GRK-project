#version 430 core

in vec2 texCord0;
uniform sampler2D diffuse;

void main()
{
  gl_FragColor = texture(diffuse, texCord0);
}