#version 430 core

layout(location =0) in vec3 position;
layout(location =1) in vec2 texCord;

out vec2 texCord0;

void main()
{
	gl_Position = vec4(position, 1.0);
	texCord0 = texCord;
}