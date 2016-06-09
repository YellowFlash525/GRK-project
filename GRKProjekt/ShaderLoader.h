#pragma once

#include "Dependencies/glew.h"
#include <iostream>
#include <string>

class Shader_Loader
{
	public:
	Shader_Loader(const std::string& filename);

	void Bind();

	virtual ~Shader_Loader();

	private:
		static const unsigned NUM_SHADERS = 2;
		Shader_Loader(const Shader_Loader& other) {}
		void operator = (const Shader_Loader& other) {}

		GLuint program;
		GLint shaders[NUM_SHADERS];

};