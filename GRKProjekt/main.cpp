#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include <iostream>
#include "Dependencies\SOIL.h"
#include "ShaderLoader.h"
#include "mesh.h"
#include "texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Mesh *mesh;

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.3, 0.3, 1.0);
	mesh->Draw();
	glutPostRedisplay();
	glutSwapBuffers();

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000,800);
	glutCreateWindow("OpenGL Pierwsze Okno");
	glewInit();
	Shader_Loader shader("./basicShader");
	texture texture("./bricks.jpg");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
						   Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
						   Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
	};

	mesh = new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	glutDisplayFunc(renderScene);
	shader.Bind();
	texture.Bind(0);
	glutMainLoop();
	return 0;
}
