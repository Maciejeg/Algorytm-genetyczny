#include "gui.h"
#include <conio.h>
#include <iostream>
#include "model.h"
using namespace std;
void menu()
{
	HANDLE Kolor;
	Kolor = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(Kolor, 3);
	cout << "Czy chcesz zdefiniowac wlasne warunki? t/n" << endl;
	char g = _getch();
	int i = 0;
	while (g != 't' && g != 'T' && g != 'n' && g != 'N')
	{
		i++;
		SetConsoleTextAttribute(Kolor, i%100);
		cout << "xD" << endl;

		g = _getch();
	}
	SetConsoleTextAttribute(Kolor, 7);
	/*int pop_size				*/
	/*int chrom_size(max 1023)	*/
	/*double xmin				*/
	/*double xmax				*/
	/*int num_of_generations	*/
	/*double chance_of_mutation */
	/*double chance_of_crossover*/
	/*int q (amount of chromo)  */
	/*int method				*/
	if (g == 't' || g == 'T')
	{
		system("cls");
		double a=-11, b=-11, c=-11, d=-11, e=-11, f=-11, g=-11, h=-11, i=-11, j=-11;
		string k = "-1";
		//cout << "Podaj wielkosc populacji. Wielkosc populacji musi byc wieksza niz 10" << endl;
		cout << "Wielkosc populacji(>=10): ";
		cin >> a;
		while (a < 10)
		{
			system("cls");
			cout << "Wielkosc populacji(>=10): ";
			cin >> a;
			
			
		}
		system("cls");
		cout << "Wielkosc populacji(>=10): " << a << endl;
		
		cout << "Dlugosc chromosomu(>=3): ";
		cin >> b;
		while (b < 3)
		{
			system("cls");
			cout << "Wielkosc populacji(>=10): " << a << endl;
			cout << "Dlugosc chromosomu(>=3): ";
			cin >> b;
		}
		system("cls");
		cout << "Wielkosc populacji(>=10): " << a << endl;
		cout << "Dlugosc chromosomu(>=3): " << b << endl;

		cout << "Xmin: ";
		cin >> c;
		cout << "Xmax: ";
		cin >> d;
		while (c >= d)
		{
			system("cls");
			cout << "Wielkosc populacji(>=10): " << a << endl;
			cout << "Dlugosc chromosomu(>=3): " << b << endl;
			cout << "Xmin: ";
			cin >> c;
			cout << "Xmax: ";
			cin >> d;
		}
		system("cls");
		cout << "Wielkosc populacji(>=10): " << a << endl;
		cout << "Dlugosc chromosomu(>=3): " << b << endl;
		cout << "Xmin: " << c << endl;
		cout << "Xmax: " << d << endl;

		cout << "Ilosc generacji(>=1): ";
		cin >> e;
		while (e < 1)
		{
			system("cls");
			cout << "Wielkosc populacji(>=10): " << a << endl;
			cout << "Dlugosc chromosomu(>=3): " << b << endl;
			cout << "Xmin: " << c << endl;
			cout << "Xmax: " << d << endl;
			cout << "Ilosc generacji(>=1): ";
			cin >> e;
		}
		system("cls");
		cout << "Wielkosc populacji(>=10): " << a << endl;
		cout << "Dlugosc chromosomu(>=3): " << b << endl;
		cout << "Xmin: " << c << endl;
		cout << "Xmax: " << d << endl;
		cout << "Ilosc generacji(>=1): " << e << endl;
		cout << "Prawdopodobienstwo mutacji[0,1]: ";
		cin >> f;
		while (f > 1 || f < 0)
		{
			system("cls");
			cout << "Wielkosc populacji(>=10): " << a << endl;
			cout << "Dlugosc chromosomu(>=3): " << b << endl;
			cout << "Xmin: " << c << endl;
			cout << "Xmax: " << d << endl;
			cout << "Ilosc generacji(>=1): " << e << endl;
			cout << "Prawdopodobienstwo mutacji[0,1]: ";
			cin >> f;
		}
		system("cls");
		cout << "Wielkosc populacji(>=10): " << a << endl;
		cout << "Dlugosc chromosomu(>=3): " << b << endl;
		cout << "Xmin: " << c << endl;
		cout << "Xmax: " << d << endl;
		cout << "Ilosc generacji(>=1): " << e << endl;
		cout << "Prawdopodobienstwo mutacji[0,1]: " << f << endl;
		cout << "Prawdopodobienstwo skrzyzowania[0,1]: ";
		cin >> g;
		while (g > 1 || g < 0)
		{
			system("cls");
			cout << "Wielkosc populacji(>=10): " << a << endl;
			cout << "Dlugosc chromosomu(>=3): " << b << endl;
			cout << "Xmin: " << c << endl;
			cout << "Xmax: " << d << endl;
			cout << "Ilosc generacji(>=1): " << e << endl;
			cout << "Prawdopodobienstwo mutacji[0,1]: " << f << endl;
			cout << "Prawdopodobienstwo skrzyzowania[0,1]: ";
			cin >> g;
		}
		system("cls");
		cout << "Wielkosc populacji(>=10): " << a << endl;
		cout << "Dlugosc chromosomu(>=3): " << b << endl;
		cout << "Xmin: " << c << endl;
		cout << "Xmax: " << d << endl;
		cout << "Ilosc generacji(>=1): " << e << endl;
		cout << "Prawdopodobienstwo mutacji[0,1]: " << f << endl;
		cout << "Prawdopodobienstwo skrzyzowania[0,1]: " << g << endl;
		cout << "Ilosc chromosomow biaracych udzial w selekcji turniejowej[2,w. populacji]: ";
		cin >> h;
		while (h > a || h < 2)
		{
			system("cls");
			cout << "Wielkosc populacji(>=10): " << a << endl;
			cout << "Dlugosc chromosomu(>=3): " << b << endl;
			cout << "Xmin: " << c << endl;
			cout << "Xmax: " << d << endl;
			cout << "Ilosc generacji(>=1): " << e << endl;
			cout << "Prawdopodobienstwo mutacji[0,1]: " << f << endl;
			cout << "Prawdopodobienstwo skrzyzowania[0,1]: " << g << endl;
			cout << "Ilosc chromosomow biaracych udzial w selekcji turniejowej[2,w. populacji]: ";
			cin >> h;
		}
		system("cls");
		cout << "Wielkosc populacji(>=10): " << a << endl;
		cout << "Dlugosc chromosomu(>=3): " << b << endl;
		cout << "Xmin: " << c << endl;
		cout << "Xmax: " << d << endl;
		cout << "Ilosc generacji(>=1): " << e << endl;
		cout << "Prawdopodobienstwo mutacji[0,1]: " << f << endl;
		cout << "Prawdopodobienstwo skrzyzowania[0,1]: " << g << endl;
		cout << "Ilosc chromosomow biaracych udzial w selekcji turniejowej[2,w. populacji]: " << h << endl;
		cout << "Metoda{0,1}: ";
		cin >> i;
		cout << "min/max: ";
		cin >> k;
		while (k != "max"&&k != "min")
		{
			system("cls");
			cout << "Wielkosc populacji(>=10): " << a << endl;
			cout << "Dlugosc chromosomu(>=3): " << b << endl;
			cout << "Xmin: " << c << endl;
			cout << "Xmax: " << d << endl;
			cout << "Ilosc generacji(>=1): " << e << endl;
			cout << "Prawdopodobienstwo mutacji[0,1]: " << f << endl;
			cout << "Prawdopodobienstwo skrzyzowania[0,1]: " << g << endl;
			cout << "Ilosc chromosomow biaracych udzial w selekcji turniejowej[2,w. populacji]: " << h << endl;
			cout << "Metoda{0,1}: " << i << endl;
			cout << "min/max: ";
			cin >> k;
			if (k == "papaj2137")
			{
				c = 0;
				d = 2137;
			}
		}
		system("cls");
		cout << "Wielkosc populacji(>=10): " << a << endl;
		cout << "Dlugosc chromosomu(>=3): " << b << endl;
		cout << "Xmin: " << c << endl;
		cout << "Xmax: " << d << endl;
		cout << "Ilosc generacji(>=1): " << e << endl;
		cout << "Prawdopodobienstwo mutacji[0,1]: " << f << endl;
		cout << "Prawdopodobienstwo skrzyzowania[0,1]: " << g << endl;
		cout << "Ilosc chromosomow biaracych udzial w selekcji turniejowej[2,w. populacji]: " << h << endl;
		cout << "Metoda{0,1}: " << i << endl;
		cout << "min/max: " << k << endl;
		standard(
			/*int pop_size				*/	a,
			/*int chrom_size(max 1023)	*/	b,
			/*double xmin				*/	c,
			/*double xmax				*/	d,
			/*int num_of_generations	*/	e,
			/*double chance_of_mutation */	f,
			/*double chance_of_crossover*/	g,
			/*int q (amount of chromo)  */	h,
			/*int method				*/	i,
			/*string min/max			*/  k);
	}
	else
	{
		standard(
			/*int pop_size				*/	1000,
			/*int chrom_size(max 1023)	*/	100,
			/*double xmin				*/	100,
			/*double xmax				*/	120,
			/*int num_of_generations	*/	100,
			/*double chance_of_mutation */	0.15,
			/*double chance_of_crossover*/	0.66,
			/*int q (amount of chromo)  */	10,
			/*int method				*/	0,
			/*string min/max			*/ "max");

	}
	cin.ignore();
	cin.ignore();
	cin.ignore();
	cin.ignore();
	cin.ignore();
	cin.ignore();
	//std::cout <<  << endl;
}
