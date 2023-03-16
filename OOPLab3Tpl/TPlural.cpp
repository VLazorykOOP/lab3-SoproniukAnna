#include "TPlural.h"

TPlural::TPlural() : beg(0), end(100), state(0), arr(nullptr)
{
	this->arr = new unsigned int[beg - end];
}

TPlural::TPlural(unsigned int end) : beg(0), state(0), arr(nullptr)
{
	this->arr = new unsigned int[beg - end];
}

TPlural::TPlural(unsigned int beg, unsigned int end) : state(0), arr(nullptr)
{
	this->arr = new unsigned int[beg - end];
}

TPlural::TPlural(unsigned int beg, unsigned int end, unsigned int val) : state(0)
{
	this->arr = new unsigned int[beg - end] {val};
}

TPlural::TPlural(const TPlural&)
{
}

TPlural::~TPlural()
{
}

void TPlural::SetElement(unsigned int elem, unsigned int val)
{

}

unsigned int TPlural::GetElement(unsigned int)
{
	return 0;
}

unsigned int TPlural::GetState()
{
	return 0;
}
