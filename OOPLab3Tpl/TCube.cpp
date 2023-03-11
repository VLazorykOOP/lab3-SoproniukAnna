#include "TCube.h"

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
