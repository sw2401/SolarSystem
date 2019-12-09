//Source.cpp is a collaborate effort on behalf of all team members
//Jacob: Texturing implementation
//Seth: Main functions, methods, and implementations
//Peter: Planet data and functions
//ALL CODE REFERENCES AND METHODS CAN BE FOUND AT THE BOTTOM OF THIS .CPP FILE
#include <GL/glut.h>
#include <string>
#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <Windows.h>
#include "planets.h"
#include "imageloader.h"

;//Please leave the semicolon here alone. It doesn't like to be bothered
GLuint loadTexture(image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

void writeBitmapString(void* font, char* string)
{
	char* c;
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

using namespace std;
static double cameraDist = -30.0; //camera distance
static double universeSpeed; // general speed of revolution around the sun
double speedVar = 0;

static void display(void) // void
{
	if (stopA == 0) //if stop animation is cued
	{
		universeSpeed -= 0.015 + speedVar; //relative speed of all planets around the sun, increasing universalSpeed will increase the current range all planets have. Suggest putting a variable here to increase observable speed as we stated in our mission
		//making the planets go their intended direction, counter-clockwise
	}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_NORMALIZE);
		glEnable(GL_COLOR_MATERIAL);

		const char* planetTextures[] = { "sun.bmp" , "mercury.bmp", "venus.bmp", "earth.bmp", "mars.bmp", "jupiter.bmp", "saturn.bmp", "uranus.bmp", "neptune.bmp", "pluto.bmp" };

		GLuint pTexture;
		//image* sun = loadBMP("sun.bmp"); pTexture = loadTexture(sun); delete sun;

		//image loader By Jacob
		for (int i = 0; i < 10; i++) 
		{
			image* planetT = loadBMP(planetTextures[i]); //load the planet texture
			pTexture = loadTexture(planetT); //apply the planet texture to type of GLuint
			delete planetT; //dereference the planet texture pointer
			(*p[i]).drawOrbit(universeSpeed, cameraDist, pTexture); //draw the planet
		}
		glutSwapBuffers();
		glFlush();
}

static void input(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'j'://slower
		if (speedVar >= -0.01)
		{
			speedVar -= 0.005;
			cout << "Speed down. Current Speed: " << speedVar << endl;
		}
		break;
	case 'k'://faster
		speedVar += 0.005;
		cout << "Speed up. Current Speed: " << speedVar << endl;
		break;
	case 's': //stop
		stopA = !stopA;
		if (stopA == 1)
		{
			cout << "Animation Stopped." << endl;
		}
		else
		{
			cout << "Animation Resumed." << endl;
		}
		break;
	case '=':
		cameraDist += 0.35;
		break;
	case '-':
		cameraDist -= 0.35;
		break;
	}
	glutPostRedisplay();
}

static void idle(void)
{
	glutPostRedisplay();
}


int main(int argc, char* argv[])
{
	//assigning my variables to an array of pointers
	p[0] = &sun; p[1] = &mercury; p[2] = &venus; p[3] = &earth; p[4] = &mars; p[5] = &jupiter; p[6] = &saturn; p[7] = &uranus; p[8] = &neptune; p[9] = &pluto;

	//GL-things
	glutInit(&argc, argv);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(100, 200);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Model of the Solar System");
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(input);
	glutIdleFunc(idle);
	glClearColor(0, 0, 0, 0);

	//coloring and lighting properties below
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	//end coloring and lighting properties
	
	glutMainLoop();

	return EXIT_SUCCESS;
}

//sources utilzed:
//solary system fucntionality https://gist.github.com/aazpitarte/29e938e33e9001d28576
//planet information from https://www.bobthealien.co.uk/solarsystem/table.htm
//scaling information from https://www.exploratorium.edu/ronh/solar_system/
//texture code http://www.codeincodeblock.com/2012/05/simple-method-for-texture-mapping-on.html
//textures https://github.com/Sectah/Solar-system