#pragma once
class TPlural
{
private:
	unsigned int* arr = nullptr;
	unsigned int beg;
	unsigned int end;
	unsigned int count;
	unsigned int state = 0; //0 ok; 1 memory error; 2 range read error; 3 range wrire error

public:
	TPlural();
	TPlural(unsigned int);
	TPlural(unsigned int, unsigned int);
	TPlural(unsigned int, unsigned int, unsigned int);
	TPlural(const TPlural&);
	~TPlural();

	void SetElement(unsigned int elem, unsigned int val);
	unsigned int GetElement(unsigned int);
	unsigned int GetState();

	TPlural& operator = (const TPlural&);
	
	void Print();
	void Union(const TPlural&);
	void Intersection(const TPlural&);
	void Difference(const TPlural&);

	
	bool More(const TPlural&); //по кількості елементів
	bool Less(const TPlural&); //по кількості елементів
	bool Equally(const TPlural&);
	bool NotEqually(const TPlural&);


};

