#pragma once
class TPlural
{
private:
	unsigned int* arr = nullptr;
	unsigned int beg;
	unsigned int end;
	unsigned int state; //0 ok; 1 memory error; 2 range read error; 3 range wrire error
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
	void Crossing(const TPlural&);
	void Difference(const TPlural&);

	//�� ������� ��������
	bool More(); 
	bool Less(); 
	bool Equally();
	bool NotEqually();
};

