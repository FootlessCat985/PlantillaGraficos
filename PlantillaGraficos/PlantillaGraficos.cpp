// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include <iostream>

using namespace std;

void dibujarPoligono()
{
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.9f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.1f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glVertex3f(0.4f, 0.5f, 0.0f);
	glVertex3f(0.6f, 0.3f, 0.0f);
	glVertex3f(0.3f, 0.7f, 0.0f);

	glEnd();
}

void dibujarTrianguloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex3f(0.0f, 0.0f, 0.0);
	glVertex3f(0.1f, 0.1f, 0.0);
	glVertex3f(0.2f, 0.0f, 0.0);

	glVertex3f(0.2f, 0.15f, 0.0);

	glEnd();
}

void dibujarLineaContinua() {
	glBegin(GL_LINE_STRIP);

	glColor3f(0.1f, 0.3f, 0.75f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.7f, 0.7f, 0.0f);
	glVertex3f(0.9f, 0.7f, 0.0f);
	glVertex3f(0.4f, 0.25f, 0.0f);
	glVertex3f(0.4f, -0.1f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.4f, -0.1f, 0.0f);
	glVertex3f(0.9f, 0.5f, 0.0f);
	glVertex3f(0.9f, 0.7f, 0.0f);

	glEnd();
}

void dinujarTriangulos() {
	//Establecemos el tipo de primitiva
	glBegin(GL_TRIANGLES);
	//Establecemos color
	glColor3f(1.0f, 0.7f, 0.7f);
	//Enviar vertices
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.3f, 0.0f);
	glVertex3f(0.5f, -0.3f, 0.0f);

	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.3f, 0.0f);
	//Especificar que dejamos de dibujar
	glEnd();
}

void dibujarLineas() {
	glBegin(GL_LINES);
	glColor3f(0.4f, 0.8f, 0.7f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, -0.4f, 0.0f);
	glEnd();
}

void dibujar() {
	dibujarPoligono();
}

int main()
{
	//declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar glfw
	//terminamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo inicial glfw
	//inicializamos la ventana
	window = glfwCreateWindow(800, 600, "Ventana", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto se activan las funciones "modernas" (GPU)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK)
	{
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.9, 0.2, 0.5, 1);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//Actualizar valores y dibujar
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despues del ciclo de dibujo
	//Eliminamos ventana y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}

