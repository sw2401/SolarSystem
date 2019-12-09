//BEGIN "planets.h"
//Planet data implemented by Pete
//ALL CODE REFERENCES AND METHODS CAN BE FOUND AT THE BOTTOM OF THE SOURCE.CPP FILE
#pragma once
#ifndef planets_h
#define planets_h
#include <gl/freeglut.h>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//reverse variable
int reverseO = 0; //not yet implemented
int stopA = 0;

bool rev = 0;

//time variables
double timeVariable = 700;
double timeStorage = 0;
double xStore = 0;
double yStore = 0;

//lighting component below
const GLfloat diffuse[] = { 1, 1, 1, 1 };
const GLfloat position[] = { -50, -20, 0, 0 };
const GLfloat specular[] = { 1, 1, 1, 1 };
const GLfloat ambient[] = { 0, 0, 0, 1 };

static void resize(int w, int h) //setting window ratio
{
	float aspectRatioWidth = (float)w; //converting from int to float because 
	float aspectRatioHeight = (float)h;
	const float aspectRatio = aspectRatioWidth / aspectRatioHeight; //maintains aspect ratio
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glFrustum(aspectRatio * -1, aspectRatio, -1.0, 1.0, 2.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//NOTE: this model does not account for axis of rotation as it is so slow that it would take 26,000 years for the axis to change observably.

const int oneDay = 86166; //actual value of a day on earth in seconds
const int oneEarthDay = 86400; //the approximate value of seconds in each day as is needed to calculate other planet's days

//used as a template for all planets
struct planet //all units in metric
{
	double xPos; //position of x coord, set to 0 in constructor
	double yPos; //position of y coord, set to 0 in constructor
	long long int distanceFromSun; //approximate distance from planet's center to the sun's center measured in km
	string name; //self explanitory
	float diameter;	//size of planet in terms of diameter measured in km
	float axisAngle; //tilt of planet in orbit, measured in degrees
	float dayTime; //time it takes for the planet to experience a full revolution in orbit, equivalent to 1 earth day. measured in seconds
	float yearTime; //time it takes for the planet to rotate around the sun and return to the same point in orbit as it started, measured in seconds
	double red; //red value
	double green; //green value
	double blue; //blue value

	//constructors
	planet();//default
	planet(string, long long int, float, float, float, float, double, double, double);//takes arguments

	//for scaling you can pass a fraction like you would a ratio
	void scale(double);
	void changeTime(double);
	void drawOrbit(double, double, GLuint); //for prior version delete GLuint

	//individual scaling
	void scaleDiameter(double);
	void scaleDistance(long long);
	void scaleDay(double);
};

//default constructor
planet::planet()
{
	name = "";
	xPos = 0;
	yPos = 0;
	distanceFromSun = 0;
	diameter = 0;
	axisAngle = 0;
	dayTime = 0;
	yearTime = 0;
	red = 0;
	green = 0;
	blue = 0;
}

//constructor taking input
planet::planet(string n, const long long int dist, const float diam, const float angle, const float day, const float year, double r, double g, double b)
{
	this->name = n;
	this->distanceFromSun = dist;
	this->diameter = diam;
	this->axisAngle = angle;
	this->dayTime = day;
	this->yearTime = year;
	this->red = r;
	this->green = g;
	this->blue = b;
	xPos = 0;
	yPos = 0;
}

planet** p = new planet * [10];

//oneEarthDay * 87.969 mercury yeartime
// 224 * oneEarthDay venus yeartime

//defining the planets	sum = 1.5, mercury = .5, venus = .5, earth = .6, mars = .5, jupiter = .8, saturn = .7, uranus = .5, neptune = .5, pluto = .5
planet sun("sun", 0, 1.5, 7.25, 0, 0, 1.0, 1.0, 1.0); //only represented as a planet for ease of creation since we won't have other stars
planet mercury("mercury", 2, 0.15, 2.11, 59 * oneEarthDay, .947567, 0.7f, 0.25f, 0.3f); //name, distance from sun, diameter of planet, angle of rotation, speed of rotation, speed of revolution, red, green, blue
planet venus("venus", 3.5, 0.2, 177.3, 243 * oneEarthDay, .83332, 1.0, 0.4, 0.0);
planet earth("earth", 4.5, 0.3, 23.5, oneDay, .7423458, 0.0, 1.0, 1.0);
planet mars("mars", 5.5, 0.35, 25, 88620, .6558888, 1.0, 0.1, 0.0);
planet jupiter("jupiter", 7.9, 0.75, 3.13, 35700, .52341, 1.0, 0.8, 0.7);
planet saturn("saturn", 9.8, 0.55, 26.7, 38340, .411111112, 1.0, 0.8, 1.0);
planet uranus("uranus", 10.6, 0.12, 98, 62040, .323233, 0.0, 1.0, 0.6);
planet neptune("neptune", 11.4, 0.12, 28.32, 58020, .236532, 0.0, 1.0, 1.0);
planet pluto("pluto", 12.5, 0.09, 119.61, 6 * oneEarthDay + 32400, .17312565, 0.0, 1.0, 1.0);
//references from https://www.bobthealien.co.uk/solarsystem/table.htm
//scaling from https://www.exploratorium.edu/ronh/solar_system/

//scaling for individual planets
void planet::scaleDiameter(double n)
{
	this->diameter = n;
}

void planet::scaleDistance(long long n)
{
	this->distanceFromSun = n;
}

void planet::scaleDay(double n)
{
	this->dayTime = n;
}

//mass scaling
void planet::scale(double ratio)
{
	//scale sun
	sun.diameter = sun.diameter * ratio;
	sun.distanceFromSun = sun.distanceFromSun * ratio;
	//scale mercury
	mercury.diameter = mercury.diameter * ratio;
	mercury.distanceFromSun = mercury.distanceFromSun * ratio;
	//scale venus
	venus.diameter = venus.diameter * ratio;
	venus.distanceFromSun = venus.distanceFromSun * ratio;
	//scale earth
	earth.diameter = earth.diameter * ratio;
	earth.distanceFromSun = earth.distanceFromSun * ratio;
	//scale mars
	mars.diameter = mars.diameter * ratio;
	mars.distanceFromSun = mars.distanceFromSun * ratio;
	//scale jupiter
	jupiter.diameter = jupiter.diameter * ratio;
	jupiter.distanceFromSun = jupiter.distanceFromSun * ratio;
	//scale saturn
	saturn.diameter = saturn.diameter * ratio;
	saturn.distanceFromSun = saturn.distanceFromSun * ratio;
	//scale uranus
	uranus.diameter = uranus.diameter * ratio;
	uranus.distanceFromSun = uranus.distanceFromSun * ratio;
	//scale neptune
	neptune.diameter = neptune.diameter * ratio;
	neptune.distanceFromSun = neptune.distanceFromSun * ratio;
	//scale pluto
	pluto.diameter = pluto.diameter * ratio;
	pluto.distanceFromSun = pluto.distanceFromSun * ratio;
}

void planet::changeTime(double timeChange)//change the obersvable time of the planets revolutions and rotation on axis
{
	mercury.dayTime = mercury.dayTime * timeChange;
	mercury.yearTime = mercury.yearTime * timeChange;

	venus.dayTime = venus.dayTime * timeChange;
	venus.yearTime = venus.yearTime * timeChange;

	earth.dayTime = earth.dayTime * timeChange;
	earth.yearTime = earth.yearTime * timeChange;

	mars.dayTime = mars.dayTime * timeChange;
	mars.yearTime = mars.yearTime * timeChange;

	jupiter.dayTime = jupiter.dayTime * timeChange;
	jupiter.yearTime = jupiter.yearTime * timeChange;

	saturn.dayTime = saturn.dayTime * timeChange;
	saturn.yearTime = saturn.yearTime * timeChange;

	uranus.dayTime = uranus.dayTime * timeChange;
	uranus.yearTime = uranus.yearTime * timeChange;

	neptune.dayTime = neptune.dayTime * timeChange;
	neptune.yearTime = neptune.yearTime * timeChange;

	pluto.dayTime = pluto.dayTime * timeChange;
	pluto.yearTime = pluto.yearTime * timeChange;
}

// Function will compute new planet position
void planet::drawOrbit(double universeSpeed, double cameraDist, GLuint texture) { //to restore prior version get rid of GLuint texture

	xPos = sin(universeSpeed * yearTime) * distanceFromSun * 1.5; //calculating x on each redraw
	yPos = cos(universeSpeed * yearTime) * distanceFromSun;

	//TEXTURING
	//the below code was exchanged for the next commented-out block of code
	glColor3d(red, green, blue); //making the planet colored
	glPushMatrix();
	GLUquadricObj* quadric;
	quadric = gluNewQuadric();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	//gluSphere(quadric, 1.0, 20.0, 20.0);
	glTranslated(xPos, yPos, cameraDist); //calculating viewing angle based on closeness based on these coordinates, multiplying x by 3 looks really cool
	glRotated(50.0 * universeSpeed, 0, 0, 1);
	gluSphere(quadric, diameter, 20, 20);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
#endif // !planets_h