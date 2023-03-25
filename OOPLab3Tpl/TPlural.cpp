#include "TPlural.h"
#include <iostream>

TPlural::TPlural() : TPlural(0, 100, 0){}

TPlural::TPlural(unsigned int e) : TPlural(0, e, 0){}

TPlural::TPlural(unsigned int b, unsigned int e) : TPlural(b, e, 0){}

TPlural::TPlural(unsigned int b, unsigned int e, unsigned int val) : beg(b), end(e), state(0)
{
	this->count = this->end - this->beg + 1;
	this->arr = new unsigned int[this->count] {val};
	if (this->arr == nullptr)
		this->state = 1;
}

TPlural::TPlural(const TPlural& p)
{
	this->beg = p.beg;
	this->end = p.end;
	this->count = p.count;
	this->state = p.state;
	this->arr = new unsigned int[this->count];
	if (this->arr == nullptr)
		this->state = 1;
	else
		for (unsigned int i = 0; i < this->count; i++)
			this->arr[i] = p.arr[i];
}

TPlural::~TPlural()
{
	delete[] this->arr;
}

void TPlural::SetElement(unsigned int elem, unsigned int val)
{
	if (this->beg <= elem && elem <= this->end)
		this->arr[elem - this->beg] = val;
	else
		this->state = 3;
}

unsigned int TPlural::GetElement(unsigned int elem)
{
	if (this->beg <= elem && elem <= this->end)
		return this->arr[elem - this->beg];
	this->state = 2;
	return 0;
}

unsigned int TPlural::GetState()
{
	return this->state;
}

TPlural& TPlural::operator=(const TPlural& p)
{
	this->beg = p.beg;
	this->end = p.end;
	this->state = p.state;
	if (this->count != p.count)
	{
		this->count = p.count;
		delete[] this->arr;
		this->arr = new unsigned int[this->count];
		if (this->arr == nullptr)
		{
			this->state = 1;
			return *this;
		}
	}
	for (unsigned int i = 0; i < this->count; i++)
			this->arr[i] = p.arr[i];
	return *this;
}

void TPlural::Print()
{
	std::cout << "[ " << this->beg << "; " << this->end << " ]" << std::endl;
	std::cout << "Count:\t" << this->count << std::endl;
	std::cout << "State:\t" << this->state << std::endl;
	for (unsigned int i = 0; i < this->count; i++)
		std::cout << "\t" << this->beg + i << "\t:\t" << this->arr[i] << std::endl;
}

void TPlural::Union(const TPlural& p)
{
	if (this->beg <= p.beg && p.end <= this->end)
		for (unsigned int elem = p.beg; elem <= p.end; elem++)
			this->arr[elem - this->beg] += p.arr[elem - p.beg];
	else
	{
		unsigned int tmpbeg = this->beg;
		if (tmpbeg > p.beg)
			tmpbeg = p.beg;
		unsigned int tmpend = this->end;
		if (tmpend < p.end)
			tmpend = p.end;
		unsigned int tmpcount = tmpend - tmpbeg + 1;
		unsigned int* tmparr = new unsigned int[tmpcount] {};
		if (tmparr == nullptr)
			this->state = 1;
		
		for (unsigned int elem = this->beg; elem <= this->end; elem++)
			tmparr[elem - tmpbeg] = this->arr[elem - this->beg];
		for (unsigned int elem = p.beg; elem <= p.end; elem++)
			tmparr[elem - tmpbeg] += p.arr[elem - p.beg];

		this->beg = tmpbeg;
		this->end = tmpend;
		this->count = tmpcount;
		delete[] this->arr;
		this->arr = tmparr;
	}
}

void TPlural::Intersection(const TPlural& p)
{
	unsigned int tmpbeg = this->beg;
	if (tmpbeg < p.beg)
		tmpbeg = p.beg;
	unsigned int tmpend = this->end;
	if (tmpend > p.end)
		tmpend = p.end;
	unsigned int tmpcount = tmpend - tmpbeg + 1;
	unsigned int* tmparr = new unsigned int[tmpcount] {};
	if (tmparr == nullptr)
		this->state = 1;

	for (unsigned int elem = tmpbeg; elem <= tmpend; elem++)
	{
		tmparr[elem - tmpbeg] = this->arr[elem - this->beg]; //minimum
		if (tmparr[elem - tmpbeg] > p.arr[elem - p.beg]) 
			tmparr[elem - tmpbeg] = p.arr[elem - p.beg];
	}

	this->beg = tmpbeg;
	this->end = tmpend;
	this->count = tmpcount;
	delete[] this->arr;
	this->arr = tmparr;
}

void TPlural::Difference(const TPlural& p)
{
	unsigned int tmpbeg = this->beg;
	if (tmpbeg < p.beg)
		tmpbeg = p.beg;
	unsigned int tmpend = this->end;
	if (tmpend > p.end)
		tmpend = p.end;
	for (unsigned int elem = tmpbeg; elem <= tmpend; elem++)
	{
		if (this->arr[elem - this->beg] > p.arr[elem - p.beg])
			this->arr[elem - this->beg] -= p.arr[elem - p.beg];
		else
			this->arr[elem - this->beg] = 0;
	}
}

bool TPlural::More(const TPlural& p)
{
	unsigned int sumThis = 0;
	for (unsigned int elem = this->beg; elem <= this->end; elem++)
		sumThis += this->arr[elem - this->beg];
	unsigned int sumP = 0;
	for (unsigned int elem = p.beg; elem <= p.end; elem++)
		sumP += p.arr[elem - p.beg];

	if (sumThis > sumP)
		return true;
	else
		return false;
}

bool TPlural::Less(const TPlural& p)
{
	unsigned int sumThis = 0;
	for (unsigned int elem = this->beg; elem <= this->end; elem++)
		sumThis += this->arr[elem - this->beg];
	unsigned int sumP = 0;
	for (unsigned int elem = p.beg; elem <= p.end; elem++)
		sumP += p.arr[elem - p.beg];

	if (sumThis < sumP)
		return true;
	else
		return false;
	
}

bool TPlural::Equally(const TPlural& p)
{
	if (this->beg!=p.beg)
		return false;
	if (this->end != p.end)
		return false;
	for (unsigned int elem = this->beg; elem <= this->end; elem++)
		if (this->arr[elem - this->beg] != p.arr[elem - p.beg])
			return false;
	return true;
}

bool TPlural::NotEqually(const TPlural& p)
{
	return !this->Equally(p);
}
