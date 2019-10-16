#pragma once
#ifndef planets_h
#define planets_h
#include <iostream>
#include <string>
using namespace std;

//NOTE: this model does not account for axis of rotation as it is so slow that it would take 26,000 years for the axis to change observably.

const int oneDay = 86166; //actual value of a day on earth in seconds
const int oneEarthDay = 86400; //the approximate value of seconds in each day as is needed to calculate other planet's days

//used as a template for all planets
struct planet //all units in metric
{
	unsigned long long int distanceFromSun; //approximate distance from planet's center to the sun's center measured in km
	float diameter;	//size of planet in terms of diameter measured in km
	float axisAngle; //tilt of planet in orbit, measured in degrees
	float dayTime; //time it takes for the planet to experience a full revolution in orbit, equivalent to 1 earth day. measured in seconds
	float yearTime; //time it takes for the planet to rotate around the sun and return to the same point in orbit as it started, measured in seconds

	planet();//default
	planet(unsigned long long int, float, float, float, float);//takes arguments
	
	//for scaling you can pass a fraction like you would a ratio
	void scale(double);
};

//default constructor
planet::planet()
{
	distanceFromSun = 0;
	diameter = 0;
	axisAngle = 0;
	dayTime = 0;
	yearTime = 0;
}

//constructor taking input
planet::planet(const unsigned long long int dist, const float diam, const float angle, const float day, const float year)
{
	this->distanceFromSun = dist;
	this->diameter = diam;
	this->axisAngle = angle;
	this->dayTime = day;
	this->yearTime = year;
}

//defining the planets
planet sun(0, 864340, 7.25, 0, 0); //only represented as a planet for ease of creation since we won't have other stars
planet mercury(57900000, 4878, 2.11, 59 * oneEarthDay, oneEarthDay * 87.969);
planet venus(108160000, 12104, 177.3, 243 * oneEarthDay, 224 * oneEarthDay);
planet earth(149600000, 12756, 23.5, oneDay, oneDay * 365);
planet mars(227936640, 6794, 25, 88620, 687 * oneEarthDay);
planet jupiter(788369000, 142984, 3.13, 35700, 374265450.72);
planet saturn(1427034000, 120536, 26.7, 38340, 915151608);
planet uranus(2870658186, 51118, 98, 62040, 2650783968);
planet neptune(4496976000, 49532, 28.32, 58020, 5200585689.6);
planet pluto(5500000000, 950, 119.61, 6 * oneEarthDay + 32400, (4 * 365 * oneEarthDay) + (220 * oneEarthDay));
//references from https://www.bobthealien.co.uk/solarsystem/table.htm and various other sites

void planet::scale(double ratio)
{
	//scale sun
	sun.diameter = sun.diameter / ratio;
	sun.distanceFromSun = sun.distanceFromSun / ratio;
	//scale mercury
	mercury.diameter = mercury.diameter / ratio;
	mercury.distanceFromSun = mercury.distanceFromSun / ratio;
	//scale venus
	venus.diameter = venus.diameter / ratio;
	venus.distanceFromSun = venus.distanceFromSun / ratio;
	//scale earth
	earth.diameter = earth.diameter / ratio;
	earth.distanceFromSun = earth.distanceFromSun / ratio;
	//scale mars
	mars.diameter = mars.diameter / ratio;
	mars.distanceFromSun = mars.distanceFromSun / ratio;
	//scale jupiter
	jupiter.diameter = jupiter.diameter / ratio;
	jupiter.distanceFromSun = jupiter.distanceFromSun / ratio;
	//scale saturn
	saturn.diameter = saturn.diameter / ratio;
	saturn.distanceFromSun = saturn.distanceFromSun / ratio;
	//scale uranus
	uranus.diameter = uranus.diameter / ratio;
	uranus.distanceFromSun = uranus.distanceFromSun / ratio;
	//scale neptune
	neptune.diameter = neptune.diameter / ratio;
	neptune.distanceFromSun = neptune.distanceFromSun / ratio;
	//scale pluto
	pluto.diameter = pluto.diameter / ratio;
	pluto.distanceFromSun = pluto.distanceFromSun / ratio;
}

#endif // !planets_h