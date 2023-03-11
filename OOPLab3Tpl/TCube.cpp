#define _USE_MATH_DEFINES
#include "TCube.h"
#include <iostream>
#include <cmath>

TCube::TCube() : side(1), color(0)
{
}

TCube::TCube(double valS, unsigned int valC) : TCube()
{
	if (valS > 0)
		this->side = valS;
	this->color = valC;
}

TCube::TCube(TCube& cube)
{
	this->side = cube.side;
	this->color = cube.color;
}

TCube::~TCube(){}

void TCube::SetSide(double val)
{
	if (val > 0)
		this->side = val;
}

double TCube::GetSide()
{
	return this->side;
}

void TCube::SetColor(unsigned int val)
{
	this->color = val;
}

unsigned int TCube::GetColor()
{
	return this->color;
}



