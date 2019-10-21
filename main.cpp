#include <stdio.h>
#include <GL\freeglut.h>
#include <iostream>
#include "planets.h"

//void display() {
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//polygon reference
//	glBegin(GL_POLYGON);
//	glColor3f(0, 0, 0); glVertex3f(-0.85, 0.115, 0);
//	glColor3f(0, 0, 0); glVertex3f(-0.85, 0.0565, 0);
//	glColor3f(0, 0, 0); glVertex3f(0.8, 0.0565, 0);
//	glColor3f(0, 0, 0); glVertex3f(0.85, 0.115, 0);
//	glEnd();
//
//	//words reference
//	glRasterPos2d(-0, -0.5);
//	char mesg[20] = "Seth Weidman";
//	for (int i = 0; i < 12; i++)
//		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, mesg[i]);
//
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(300, 15);
//	glutInitWindowSize(600, 600);
//	glutCreateWindow("Solar System");
//	glMatrixMode(GL_PROJECTION);
//	glutDisplayFunc(display);
//	glutMainLoop();
//}

//GEEKS to GEEKS Animation

// global declaration 
int x, y;
float i, j;

// Function to display animation 
void display(void)
{
	// Reset background color with black (since all three argument is 0.0) 
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set picture color to green (in RGB model) 
	// as only argument corresponding to G (Green) is 1.0 and rest are 0.0 
	glColor3f(0.0, 1.0, 0.0);

	// Set width of point to one unit 
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set window size in X- and Y- direction 
	gluOrtho2D(-780, 780, -420, 420);

	// Outer loop to make figure moving 
	// loop variable j iterated up to 10000, 
	// indicating that figure will be in motion for large amount of time 
	// around 10000/6.29 = 1590 time it will revolve 
	// j is incremented by small value to make motion smoother 
	for (j = 0; j < 10000; j += 0.01)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POINTS);

		// Iterate i up to 2*pi, i.e., 360 degree 
		// plot point with slight increment in angle, 
		// so, it will look like a continuous figure 

		// Loop is to draw outer circle 
		for (i = 0; i < 6.29; i += 0.001)
		{
			x = 200 * cos(i);
			y = 200 * sin(i);
			glVertex2i(x, y);

			// For every loop, 2nd glVertex function is 
			// to make smaller figure in motion 
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		// 7 loops to draw parallel latitude 
		for (i = 1.17; i < 1.97; i += 0.001)
		{
			x = 400 * cos(i);
			y = -150 + 300 * sin(i);
			glVertex2i(x, y);
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		for (i = 1.07; i < 2.07; i += 0.001)
		{
			x = 400 * cos(i);
			y = -200 + 300 * sin(i);
			glVertex2i(x, y);
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		for (i = 1.05; i < 2.09; i += 0.001)
		{
			x = 400 * cos(i);
			y = -250 + 300 * sin(i);
			glVertex2i(x, y);
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		for (i = 1.06; i < 2.08; i += 0.001)
		{
			x = 400 * cos(i);
			y = -300 + 300 * sin(i);
			glVertex2i(x, y);
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		for (i = 1.10; i < 2.04; i += 0.001)
		{
			x = 400 * cos(i);
			y = -350 + 300 * sin(i);
			glVertex2i(x, y);
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		for (i = 1.16; i < 1.98; i += 0.001)
		{
			x = 400 * cos(i);
			y = -400 + 300 * sin(i);
			glVertex2i(x, y);
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		for (i = 1.27; i < 1.87; i += 0.001)
		{
			x = 400 * cos(i);
			y = -450 + 300 * sin(i);
			glVertex2i(x, y);
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		// Loop is to draw vertical line 
		for (i = 200; i >= -200; i--)
		{
			glVertex2i(0, i);
			glVertex2i(-600 * cos(j), i / 2 - 100 * sin(j));
		}

		// 3 loops to draw vertical ellipse (similar to longitude) 
		for (i = 0; i < 6.29; i += 0.001)
		{
			x = 70 * cos(i);
			y = 200 * sin(i);
			glVertex2i(x, y);
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		for (i = 0; i < 6.29; i += 0.001)
		{
			x = 120 * cos(i);
			y = 200 * sin(i);
			glVertex2i(x, y);
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		for (i = 0; i < 6.29; i += 0.001)
		{
			x = 160 * cos(i);
			y = 200 * sin(i);
			glVertex2i(x, y);
			glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
		}

		// Loop to make orbit of revolution 
		for (i = 0; i < 6.29; i += 0.001)
		{
			x = 600 * cos(i);
			y = 100 * sin(i);
			glVertex2i(x, y);
		}
		glEnd();
		glFlush();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(680, 384);
	glutInitWindowPosition(25, 25);
	glutCreateWindow("Revolution");
	glutDisplayFunc(display);
	glutMainLoop();
}