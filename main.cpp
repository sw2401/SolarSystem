#include <stdio.h>
#include <GL\freeglut.h>
#include <iostream>

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//polygon reference
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0); glVertex3f(-0.85, 0.115, 0);
	glColor3f(0, 0, 0); glVertex3f(-0.85, 0.0565, 0);
	glColor3f(0, 0, 0); glVertex3f(0.8, 0.0565, 0);
	glColor3f(0, 0, 0); glVertex3f(0.85, 0.115, 0);
	glEnd();

	//words reference
	glRasterPos2d(-0, -0.5);
	char mesg[20] = "Seth Weidman";
	for (int i = 0; i < 12; i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, mesg[i]);

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(300, 15);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Solar System");
	glMatrixMode(GL_PROJECTION);
	glutDisplayFunc(display);
	glutMainLoop();
}