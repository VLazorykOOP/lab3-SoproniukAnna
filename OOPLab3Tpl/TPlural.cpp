#include "TPlural.h"

TPlural::TPlural() : TPlural(0, 100, 0){}

TPlural::TPlural(unsigned int e) : TPlural(0, e, 0){}

TPlural::TPlural(unsigned int b, unsigned int e) : TPlural(b, e, 0){}

TPlural::TPlural(unsigned int b, unsigned int e, unsigned int val) : beg(b), end(e), state(0)
{
	this->count = this->end - this->beg + 1;
	this->arr = new unsigned int[this->count] {val};
}

TPlural::TPlural(const TPlural& p)
{
	this->beg = p.beg;
	this->end = p.end;
	this->count = this->end - this->beg + 1;
	this->state = p.state;
	this->arr = new unsigned int[this->count];
	for (unsigned int i = 0; i < this->count; i++)
		this->arr[i] = p.arr[i];
}

TPlural::~TPlural()
{
	delete[] this->arr;
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
