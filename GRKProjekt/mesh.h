#pragma once
#include "Dependencies/glew.h"
#include "glm\glm.hpp"

class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCord)
	{
		this->pos = pos;
		this->texCord = texCord;
	}

	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec2* GetTextCord() { return &texCord; }
private:
	glm::vec3 pos;
	glm::vec2 texCord;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	void Draw();

	virtual ~Mesh();

private:
	Mesh(const Mesh& other);
	void operator = (const Mesh& other);

	enum
	{
		POSITION_VB,
		TEXTCORD_VB,
		NUM_BUFFERS
	};

	GLuint vertexArrayObject;
	GLuint vertexArrayBuffers[NUM_BUFFERS];
	unsigned int drawCount;

};