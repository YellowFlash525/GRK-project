#pragma once
#include "Dependencies/glew.h"
#include <string>

class texture
{
public:
	texture(const std::string& file);
	void Bind(unsigned int unit);
	virtual ~texture();
private:
	texture(const texture& other);
	void operator = (const texture& other){}
	GLuint textureId;
};