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
{

	system("cls");
	TPlural* plural = nullptr;
	plural = new TPlural();
	int select = 0;
	do
	{
		std::cout << "1.  Default " << std::endl;
		std::cout << "2.  Input end " << std::endl;
		std::cout << "3.  Input begin and end " << std::endl;
		std::cout << "4.  Input begin, end and value " << std::endl;

		std::cout << "5.  Output union " << std::endl;
		std::cout << "6.  Output intersection " << std::endl;
		std::cout << "7.  Output difference " << std::endl;
		std::cout << "8.  Output comparison (more) " << std::endl;
		std::cout << "9.  Output comparison (less) " << std::endl;
		std::cout << "10. Output comparison (equally) " << std::endl;
		std::cout << "11. Output comparison (not equally) " << std::endl;
		std::cout << "0.  Exit " << std::endl;
		std::cin >> select;

		unsigned int beg, end, val;
		if (select == 1)
		{
			system("cls");
			delete plural;
			plural = new TPlural;
			plural->Print();
			std::cout << std::endl;
		}
		else if (select == 2)
		{
			system("cls");
			std::cout << "Input end: ";
			std::cin >> end;
			delete plural;
			plural = new TPlural(end);
			plural->Print();
			std::cout << std::endl;
		}
		else if (select == 3)
		{
			system("cls");
			std::cout << "Input begin: ";
			std::cin >> beg;
			std::cout << "Input end: ";
			std::cin >> end;
			delete plural;
			plural = new TPlural(beg, end);
			plural->Print();
			std::cout << std::endl;
		}
		else if (select == 4)
		{
			system("cls");
			std::cout << "Input begin: ";
			std::cin >> beg;
			std::cout << "Input end: ";
			std::cin >> end;
			std::cout << "Input value: ";
			std::cin >> val;
			delete plural;
			plural = new TPlural(beg, end, val);
			plural->Print();
			std::cout << std::endl;
		}
		else if (select == 5)
		{
			system("cls");
			std::cout << '\t' << " UNION" << '\t' << std::endl;
			std::cout << std::endl;
			std::cout << "Input begin: ";
			std::cin >> beg;
			std::cout << "Input end: ";
			std::cin >> end;
			TPlural tmpPlural(beg, end);
			for (unsigned int i = beg; i <= end; i++)
			{
				std::cout << "Input count of " << i << ": ";
				std::cin >> val;
				tmpPlural.SetElement(i, val);
			}
			plural->Union(tmpPlural);
			plural->Print();
			std::cout << std::endl;
		}
		else if (select == 6)
		{
			system("cls");
			std::cout << '\t' << " INTERSECTION" << '\t' << std::endl;
			std::cout << std::endl;
			std::cout << "Input begin: ";
			std::cin >> beg;
			std::cout << "Input end: ";
			std::cin >> end;
			TPlural tmpPlural(beg, end);
			for (unsigned int i = beg; i <= end; i++)
			{
				std::cout << "Input count of " << i << ": ";
				std::cin >> val;
				tmpPlural.SetElement(i, val);
			}
			plural->Intersection(tmpPlural);
			plural->Print();
			std::cout << std::endl;
		}
		else if (select == 7)
		{
			system("cls");
			std::cout << '\t' << " DIFFERENCE " << '\t' << std::endl;
			std::cout << std::endl;
			std::cout << "Input begin: ";
			std::cin >> beg;
			std::cout << "Input end: ";
			std::cin >> end;
			TPlural tmpPlural(beg, end);
			for (unsigned int i = beg; i <= end; i++)
			{
				std::cout << "Input count of " << i << ": ";
				std::cin >> val;
				tmpPlural.SetElement(i, val);
			}
			plural->Difference(tmpPlural);
			plural->Print();
			std::cout << std::endl;
		}
		else if (select == 8)
		{
			system("cls");
			std::cout << '\t' << " COMPARISON(MORE) " << '\t' << std::endl;
			std::cout << std::endl;
			std::cout << "Input begin: ";
			std::cin >> beg;
			std::cout << "Input end: ";
			std::cin >> end;
			TPlural tmpPlural(beg, end);

			for (unsigned int i = beg; i <= end; i++)
			{
				std::cout << "Input count of " << i << ": ";
				std::cin >> val;
				tmpPlural.SetElement(i, val);
			}

			if (plural->More(tmpPlural))
				std::cout << "More" << std::endl;
			else
				std::cout << "Not more" << std::endl;
			std::cout << std::endl;
		}
		else if (select == 9)
		{
			system("cls");
			std::cout << '\t' << " COMPARISON(LESS) " << '\t' << std::endl;
			std::cout << std::endl;
			std::cout << "Input begin: ";
			std::cin >> beg;
			std::cout << "Input end: ";
			std::cin >> end;
			TPlural tmpPlural(beg, end);

			for (unsigned int i = beg; i <= end; i++)
			{
				std::cout << "Input count of " << i << ": ";
				std::cin >> val;
				tmpPlural.SetElement(i, val);
			}

			if (plural->Less(tmpPlural))
				std::cout << "Less" << std::endl;
			else
				std::cout << "Not less" << std::endl;
			std::cout << std::endl;
		}
		else if (select == 10)
		{
			system("cls");
			std::cout << '\t' << " COMPARISON(EQUALLY) " << '\t' << std::endl;
			std::cout << std::endl;
			std::cout << "Input begin: ";
			std::cin >> beg;
			std::cout << "Input end: ";
			std::cin >> end;
			TPlural tmpPlural(beg, end);

			for (unsigned int i = beg; i <= end; i++)
			{
				std::cout << "Input count of " << i << ": ";
				std::cin >> val;
				tmpPlural.SetElement(i, val);
			}

			if (plural->Equally(tmpPlural))
				std::cout << "Equally" << std::endl;
			else
				std::cout << "Not equally" << std::endl;
			std::cout << std::endl;
		}
		else if (select == 11)
		{
			system("cls");
			std::cout << '\t' << " COMPARISON(NOT EQUALLY) " << '\t' << std::endl;
			std::cout << std::endl;
			std::cout << "Input begin: ";
			std::cin >> beg;
			std::cout << "Input end: ";
			std::cin >> end;
			TPlural tmpPlural(beg, end);
			for (unsigned int i = beg; i <= end; i++)
			{
				std::cout << "Input count of " << i << ": ";
				std::cin >> val;
				tmpPlural.SetElement(i, val);
			}
			if (plural->NotEqually(tmpPlural))
				std::cout << "Not equally" << std::endl;
			else
				std::cout << "Equally" << std::endl;
			std::cout << std::endl;
		}

	} while (select != 0);
	system("cls");
}
//void MenuTask3(){}

void MainMenu()
{
	int select = 0;
	std::cout << "Main menu " << std::endl;
	do
	{
		std::cout << "1. Task 1" << std::endl;
		std::cout << "2. Task 2" << std::endl;
		//std::cout << "3. Task 3" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cin >> select;
		switch (select)
		{
		case 1:
			MenuTask1();
			break;
		case 2:
			MenuTask2();
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

