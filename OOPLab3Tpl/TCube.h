#pragma once
class TCube
{
private:
	double side;
	unsigned int color;
public:
	TCube();
	TCube(double, unsigned int);
	TCube(TCube&);
	~TCube();

	void SetSide(double);
	double GetSide();
	void SetColor(unsigned int);
	unsigned int GetColor();

	double SurfaceArea();
	double Volume();
	double Digonal();
	double VolumeSphere();
	void Print();
	void PrintAll();
};

