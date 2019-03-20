#include <stdlib.h>
#include <iostream>
#include "genetyka.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <bitset>
#define PI 3.1415926535897
using namespace std;


int losujCalkowite(int a, int b)
{
	return a + rand() % (b - a + 1);
}
void inicjalizacja(int *t, int n) // losowanie osobników, tablica odwzorowuje kod binarny
{
	for (int i = 0; i < n; i++)
	{
		std::cout << i << std::endl;
		t[i] = losujCalkowite(0, 1);
	}
}

void mutation(int *t, int n) // tablica + wielkoœæ tablicy
{
	int pozycja = losujCalkowite(0, n - 1);
	t[pozycja] = 1 - t[pozycja]; // mutacja: 0 na 1 lub 1 na 0
}

void crossover(int *t1, int *t2, int n)
{
	int pozycja = losujCalkowite(1, n - 1); //losowanie miejsca przeciêcia
	for (int i = pozycja; i < n; i++)
	{
		int p = t1[i]; //podmiana 
		t1[i] = t2[i];
		t2[i] = p;
	};
}

double fitness(int *t, int n, double p, double q, double rozdzielczosc, std::string function)
{

	double s = 0;
	s = binToDec(t, n);
	double x = p + s * (q - p) / rozdzielczosc;
	return x * x + sin(x*x*x) - tan(x);
}

void copy(int *zrodlo, int *cel, int n)
{
	for (int i = 0; i < n; i++) cel[i] = zrodlo[i];
}

int probability(double a)
{	
	return a < rand() / (double)(RAND_MAX + 1);
}

void druk(int *t, int n,int p, int q, double rozdzielczosc) // funkcja pomocnicza: wypisz geny osobnika
{
	for (int i = 0; i < n; i++) std::cout << t[i] << "";
		std::cout << " = " << std::setprecision(5)<<fitness(t, n, p,q,rozdzielczosc) << std::endl;  //...i wartoœæ jego funkcji celu
}

int binToDec(int *tab, int n)
{
	int suma=0;
	int a = 0;
	for (int i = n-1; i>=0; i--)
	{
		suma += tab[i] * pow(2, a);
		a++;
	}
	return suma;//suma;
}
/*int binToDec(int *tab, int n)
{
	int suma = 0;
	int a = 0;
	std::string str;
	for (int i = 0; i < 30; i++) {
		str += std::to_string(tab[i]);
		cout << i << endl;
	}
	cout << str << endl;
	unsigned long long value;
		value = std::bitset<64>(str).to_ullong();

	return value;
}*/
void init(int ** tab, int pop_size, int chrom_size)
{
	for (int i = 0; i < pop_size; i++)
	{
		for (int j = 0; j < chrom_size; j++)
		{
			tab[i][j] = rand() % 2;
		}
	}
}
void init(int pop_size, int chrom_size)
{
	int** a = new int*[pop_size];
	for (int i = 0; i < pop_size; ++i)
		a[i] = new int[chrom_size];

}
	bool f(int *tab, int a, int q)
	{
		bool fd = false;
		for (int i = 0; i < q; i++)
		{
			if (tab[i] == a)
				fd = true;
		}
		return fd;
	}
void turniej(int **input, int **wynik, int pop_size, int m, int q, int chrom_size, double xmin, double xmax)
{
	srand(time(NULL));
	for (int k = 0; k < pop_size; k++) {

		int** tab = new int*[q];
		for (int i = 0; i < q; ++i)
			tab[i] = new int[chrom_size];

		double max = 0; int x = 0; int a = 0;  int* b = new int[q]; for (int i = 0; i < q; i++) b[i] = -1;

		for (int i = 0; i < q; i++)//losowanie bez zwracania
		{
			do 
			{
				a = rand() % pop_size;
			} while (f(b, a, q));
			b[i] = a;
			for (int j = 0; j < chrom_size; j++)
			{
				tab[i][j] = input[a][j];
			}
			if (fitness(tab[i], pop_size, 0, 5, pow(2, chrom_size) - 1) > max)
			{
				max = fitness(tab[i], pop_size, xmin, xmax, pow(2, chrom_size) - 1);
				x = i;
			}
		}

		for (int i = 0; i < chrom_size; i++)
		{
			//cout << tab[x][i] << endl;
			wynik[k][i] = tab[x][i];
		}

		//cout << "--";
		//cout << "Ktory: " << ktory << "    ";

		for (int i = 0; i < chrom_size; i++) 
		{
			//cout << wynik[k][i];
		}
		//cout << endl;


		for (int i = 0; i < q; i++)
		{
			delete[] tab[i];
		}
		delete[] tab;
		delete[] b;

	}
	

};
void roulette(double *dopasowanie, int *wynik, int n, int m)
{
	double *suma = new double[n];
	if (m == -1) m = n;
	suma[0] = (dopasowanie[0] > 0 ? dopasowanie[0] : 0);
	for (int i = 1; i < n; i++) suma[i] = suma[i - 1] + (dopasowanie[i] > 0 ? dopasowanie[i] : 0);
	if (suma[n - 1] > 0) // sum[n-1] przechowuje sumê wartoœci ca³ej populacji
	{
		for (int i = 0; i < n; i++) suma[i] /= suma[n - 1]; // normalizujemy rozk³ad do sumy 1
		for (int i = 0; i < m; i++)
		{
			double r = rand() / (double)(RAND_MAX + 1); // r - losowe z przedzia³u [0,1)
			for (int j = 0; suma[j] < r; j++)
			{
				std::cout << "suma[j]: " << suma[j] <<std:: endl;
				wynik[i] = j; // j - numer pierwszego elementu tablicy sum
				// wiêkszego lub równego r
			}
				
		};
	}
	else for (int i = 0; i < n; i++) wynik[i] = 0;
	for(int i=0; i<n; i++)
	std::cout << "WYNIK[i]: " << wynik[i] << std::endl;
	std::cout << "----------------" << std::endl;
	delete[] suma;
}
