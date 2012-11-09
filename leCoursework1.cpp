// leCoursework1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glfw.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <math.h>


//data structure that describes a vertex
struct Vertex {
    GLfloat position[3];
};

int main( void )
{
	int running = GL_TRUE;
	// Initialize GLFW
	if( !glfwInit() )
	{
		exit( EXIT_FAILURE );
	}
	// Open an OpenGL window
	if( !glfwOpenWindow( 600,600, 0,0,0,0,0,0, GLFW_WINDOW ) )
	{
		glfwTerminate();
		exit( EXIT_FAILURE );
	}
	// Main loop
	while( running )
	{
		// OpenGL rendering goes here...
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Clear The Screen And The Depth Buffer
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-5, 5, -5, 5, -5, 5);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();


		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); //set to draw wireframe

		//vertices of the icosahedron
		GLfloat t = (1.0 + sqrt(5.0)) / 2;
		const struct Vertex icosahedron[12] = {
			{-1.0,t,0},
			{ 1.0,t,0},
			{-1.0,-t,0},
			{ 1.0,-t,0},

			{0.0,-1.0, t},
			{0.0, 1.0, t},
			{0.0,-1.0,-t},
			{0.0, 1.0,-t},

			{ t,0.0,-1.0},
			{ t,0.0, 1.0},
			{-t,0.0,-1.0},
			{-t,0.0, 1.0}
		};


		//draws the twenty triangle faces of the icosahedron
		glBegin(GL_TRIANGLES);

			//the five faces around vertex 0
			glVertex3f(icosahedron[0].position[0],icosahedron[0].position[1],icosahedron[0].position[2]);
			glVertex3f(icosahedron[11].position[0],icosahedron[11].position[1],icosahedron[11].position[2]);
			glVertex3f(icosahedron[5].position[0],icosahedron[5].position[1],icosahedron[5].position[2]);

			glVertex3f(icosahedron[0].position[0],icosahedron[0].position[1],icosahedron[0].position[2]);
			glVertex3f(icosahedron[5].position[0],icosahedron[5].position[1],icosahedron[5].position[2]);
			glVertex3f(icosahedron[1].position[0],icosahedron[1].position[1],icosahedron[1].position[2]);

			glVertex3f(icosahedron[0].position[0],icosahedron[0].position[1],icosahedron[0].position[2]);
			glVertex3f(icosahedron[1].position[0],icosahedron[1].position[1],icosahedron[1].position[2]);
			glVertex3f(icosahedron[7].position[0],icosahedron[7].position[1],icosahedron[7].position[2]);

			glVertex3f(icosahedron[0].position[0],icosahedron[0].position[1],icosahedron[0].position[2]);
			glVertex3f(icosahedron[7].position[0],icosahedron[7].position[1],icosahedron[7].position[2]);
			glVertex3f(icosahedron[10].position[0],icosahedron[10].position[1],icosahedron[10].position[2]);

			glVertex3f(icosahedron[0].position[0],icosahedron[0].position[1],icosahedron[0].position[2]);
			glVertex3f(icosahedron[10].position[0],icosahedron[10].position[1],icosahedron[10].position[2]);
			glVertex3f(icosahedron[11].position[0],icosahedron[11].position[1],icosahedron[11].position[2]);

			//5 faces that are adjacent
			glVertex3f(icosahedron[1].position[0],icosahedron[1].position[1],icosahedron[1].position[2]);
			glVertex3f(icosahedron[5].position[0],icosahedron[5].position[1],icosahedron[5].position[2]);
			glVertex3f(icosahedron[9].position[0],icosahedron[9].position[1],icosahedron[9].position[2]);

			glVertex3f(icosahedron[5].position[0],icosahedron[5].position[1],icosahedron[5].position[2]);
			glVertex3f(icosahedron[11].position[0],icosahedron[11].position[1],icosahedron[11].position[2]);
			glVertex3f(icosahedron[4].position[0],icosahedron[4].position[1],icosahedron[4].position[2]);

			glVertex3f(icosahedron[11].position[0],icosahedron[11].position[1],icosahedron[11].position[2]);
			glVertex3f(icosahedron[10].position[0],icosahedron[10].position[1],icosahedron[10].position[2]);
			glVertex3f(icosahedron[2].position[0],icosahedron[2].position[1],icosahedron[2].position[2]);

			glVertex3f(icosahedron[10].position[0],icosahedron[10].position[1],icosahedron[10].position[2]);
			glVertex3f(icosahedron[7].position[0],icosahedron[7].position[1],icosahedron[7].position[2]);
			glVertex3f(icosahedron[6].position[0],icosahedron[6].position[1],icosahedron[6].position[2]);

			glVertex3f(icosahedron[7].position[0],icosahedron[7].position[1],icosahedron[7].position[2]);
			glVertex3f(icosahedron[1].position[0],icosahedron[1].position[1],icosahedron[1].position[2]);
			glVertex3f(icosahedron[8].position[0],icosahedron[8].position[1],icosahedron[8].position[2]);

			//5 faces about vertex 3
			glVertex3f(icosahedron[3].position[0],icosahedron[3].position[1],icosahedron[3].position[2]);
			glVertex3f(icosahedron[9].position[0],icosahedron[9].position[1],icosahedron[9].position[2]);
			glVertex3f(icosahedron[4].position[0],icosahedron[4].position[1],icosahedron[4].position[2]);

			glVertex3f(icosahedron[3].position[0],icosahedron[3].position[1],icosahedron[3].position[2]);
			glVertex3f(icosahedron[4].position[0],icosahedron[4].position[1],icosahedron[4].position[2]);
			glVertex3f(icosahedron[2].position[0],icosahedron[2].position[1],icosahedron[2].position[2]);

			glVertex3f(icosahedron[3].position[0],icosahedron[3].position[1],icosahedron[3].position[2]);
			glVertex3f(icosahedron[2].position[0],icosahedron[2].position[1],icosahedron[2].position[2]);
			glVertex3f(icosahedron[6].position[0],icosahedron[6].position[1],icosahedron[6].position[2]);

			glVertex3f(icosahedron[3].position[0],icosahedron[3].position[1],icosahedron[3].position[2]);
			glVertex3f(icosahedron[6].position[0],icosahedron[6].position[1],icosahedron[6].position[2]);
			glVertex3f(icosahedron[8].position[0],icosahedron[8].position[1],icosahedron[8].position[2]);

			glVertex3f(icosahedron[3].position[0],icosahedron[3].position[1],icosahedron[3].position[2]);
			glVertex3f(icosahedron[8].position[0],icosahedron[8].position[1],icosahedron[8].position[2]);
			glVertex3f(icosahedron[9].position[0],icosahedron[9].position[1],icosahedron[9].position[2]);

			//5 more adjacent faces
			glVertex3f(icosahedron[4].position[0],icosahedron[4].position[1],icosahedron[4].position[2]);
			glVertex3f(icosahedron[9].position[0],icosahedron[9].position[1],icosahedron[9].position[2]);
			glVertex3f(icosahedron[5].position[0],icosahedron[5].position[1],icosahedron[5].position[2]);

			glVertex3f(icosahedron[2].position[0],icosahedron[2].position[1],icosahedron[2].position[2]);
			glVertex3f(icosahedron[4].position[0],icosahedron[4].position[1],icosahedron[4].position[2]);
			glVertex3f(icosahedron[11].position[0],icosahedron[11].position[1],icosahedron[11].position[2]);

			glVertex3f(icosahedron[6].position[0],icosahedron[6].position[1],icosahedron[6].position[2]);
			glVertex3f(icosahedron[2].position[0],icosahedron[2].position[1],icosahedron[2].position[2]);
			glVertex3f(icosahedron[10].position[0],icosahedron[10].position[1],icosahedron[10].position[2]);

			glVertex3f(icosahedron[8].position[0],icosahedron[8].position[1],icosahedron[8].position[2]);
			glVertex3f(icosahedron[6].position[0],icosahedron[6].position[1],icosahedron[6].position[2]);
			glVertex3f(icosahedron[7].position[0],icosahedron[7].position[1],icosahedron[7].position[2]);

			glVertex3f(icosahedron[9].position[0],icosahedron[9].position[1],icosahedron[9].position[2]);
			glVertex3f(icosahedron[8].position[0],icosahedron[8].position[1],icosahedron[8].position[2]);
			glVertex3f(icosahedron[1].position[0],icosahedron[1].position[1],icosahedron[1].position[2]);

			
 
		glEnd();

		// Swap front and back rendering buffers
		glfwSwapBuffers();
		// Check if ESC key was pressed or window was closed
		running = !glfwGetKey( GLFW_KEY_ESC ) &&
		glfwGetWindowParam( GLFW_OPENED );
	}
	// Close window and terminate GLFW
	glfwTerminate();
	// Exit program
	exit( EXIT_SUCCESS );
}
