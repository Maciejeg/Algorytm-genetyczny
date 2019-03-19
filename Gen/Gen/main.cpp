
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include "genetyka.h"
#include <iomanip>
using namespace std;
#include "genetyka.h"
#include <math.h>
#include "model.h"

int main()
{
	/*int pop_size = 10;
	int chrom_size = 20;
	int **pop = new int*[pop_size];
	for (int i = 0; i < pop_size; ++i)
		pop[i] = new int[chrom_size];

	init(pop, pop_size, chrom_size);


	for (int i = 0; i < pop_size; i++)
	{
		for (int j = 0; j < chrom_size; j++)
		{
			cout << setw(3) << pop[i][j];
		}
		cout << endl;
	}

	int x;
	cin >> x;
	int *tab = new int[x];
	cout << " XD " << endl;
	inicjalizacja(tab, 5);
	for (int i = 0; i < 5; i++)
		cout << tab[i];
	cout << " XD " << endl;
	//standard(-6,10,1073741824);
	//int tab[10] = { 1,1,1,1,1,1,1,1,1,1 };
//cout << binToDec(tab, 10) << endl;
	//cout << setprecision(10)<<fitness(tab, 10, 0, 1, 1023) << endl;;//tab,d³,p,q,rozdzielczosc
	delete tab;*/
	standard1("-x^2+10*sin(x)", 0, 5, 200, 10, 100, 0.02, 0.5);
	cin.ignore();
	cin.ignore();
	cin.ignore();
	cin.ignore();
	cin.ignore();
	cin.ignore();

	cin.ignore();
	return 0;

}

