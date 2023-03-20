// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.

#include <iostream>
#include "TCube.h"
#include "TPlural.h"

void MenuTask1()
{
	system("cls");
	TCube cube;
	int select = 0;
	do
	{
		std::cout << "1. Input side " << std::endl;
		std::cout << "2. Input color " << std::endl;
		std::cout << "3. Output surface area " << std::endl;
		std::cout << "4. Output volume " << std::endl;
		std::cout << "5. Output diagonal " << std::endl;
		std::cout << "6. Output volume sphere " << std::endl;
		std::cout << "7. All info " << std::endl;
		std::cout << "0. Exit " << std::endl;
		std::cin >> select;

		switch (select)
		{
		case 1:
			system("cls");
			double s;
			std::cout << "Input side: ";
			std::cin >> s;
			cube.SetSide(s);
			break;
		case 2:
			system("cls");
			unsigned int c;
			std::cout << "Input color: ";
			std::cin >> c;
			cube.SetColor(c);
			break;
		case 3:
			system("cls");
			std::cout << "Surface area: " << cube.SurfaceArea() << std::endl;
			std::cout << std::endl;
			break;
		case 4:
			system("cls");
			std::cout << "Volume: " << cube.Volume() << std::endl;
			std::cout << std::endl;
			break;
		case 5:
			system("cls");
			std::cout << "Diagonal: " << cube.Diagonal() << std::endl;
			std::cout << std::endl;
			break;
		case 6:
			system("cls");
			std::cout << "Volume Sphere: " << cube.VolumeSphere() << std::endl;
			std::cout << std::endl;
			break;
		case 7:
			system("cls");
			std::cout << "All info: " << std::endl;
			cube.PrintAll();
			std::cout << std::endl;
			break;

		default:
			system("cls");
			break;
		}

	} while (select != 0);
	system("cls");


}
void MenuTask2()
{}
void MenuTask3()
{}

void MainMenu()
{
	int select = 0;
	std::cout << "Main menu " << std::endl;
	do
	{
		std::cout << "1. Task 1" << std::endl;
		std::cout << "2. Task 2" << std::endl;
		std::cout << "3. Task 3" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cin >> select;
		switch (select)
		{
		case 1:
			MenuTask1();
			break;
		case 2:
			break;
		case 3:
			break;


		default:
			system("cls");
			break;
		}

	} while (select != 0);
	system("cls");
}

int main()
{
	MainMenu();
}

