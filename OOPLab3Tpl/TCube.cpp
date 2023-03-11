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

double TCube::SurfaceArea()
{
	return this->side * this->side * 6;
}

double TCube::Volume()
{
	return this->side * this->side * this->side;
}

double TCube::Diagonal()
{
	double dosn = 2 * this->side / (sqrt(2));
	return sqrt(dosn * dosn + this->side * this->side);
}

double TCube::VolumeSphere()
{
	double r = this->side / 2;
	return 4 / 3 * M_PI * r * r * r;
}

void TCube::Print()
{
	std::cout << "Side:\t\t" << this->side << std::endl;
	std::cout << "Color:\t\t" << this->color << std::endl;
}

void TCube::PrintAll()
{
	this->Print();
	std::cout << "SurfaceArea:\t" << this->SurfaceArea() << std::endl;
	std::cout << "Volume:\t\t" << this->Volume() << std::endl;
	std::cout << "Digonal:\t" << this->Diagonal() << std::endl;
	std::cout << "VolumeSphere:\t" << this->VolumeSphere() << std::endl;
	std::cout << std::endl;

}



