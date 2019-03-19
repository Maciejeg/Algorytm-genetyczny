#include <stdlib.h>
#include <iostream>
#include "genetyka.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679



int losujCalkowite(int a, int b)
{
	return a + rand() % (b - a + 1);
}
void inicjalizacja(int t[], int n) // losowanie osobników, tablica odwzorowuje kod binarny
{
	for (int i = 0; i < n; i++)
	{
		t[i] = losujCalkowite(0, 1);
	}
}

void mutacja_poprzez_zamiane(int t[], int n) // tablica + wielkoœæ tablicy
{
	int pozycja = losujCalkowite(0, n - 1);
	t[pozycja] = 1 - t[pozycja]; // mutacja: 0 na 1 lub 1 na 0
}

void krzyzowanieJednopunktowe(int t1[], int t2[], int n)
{
	int pozycja = losujCalkowite(1, n - 1); //losowanie miejsca przeciêcia
	for (int i = pozycja; i < n; i++)
	{
		int p = t1[i]; //podmiana 
		t1[i] = t2[i];
		t2[i] = p;
	};
}

double funkcjaDopasowania(int t[], int n, double p, double q, double rozdzielczosc)
{
	double s = 0;
	s=decymalizacja(t, n);
	double x = p + s*(q - p) / rozdzielczosc;
	return -x * x + 10 * sin(x*x);
}

void kopiowanie(int zrodlo[], int cel[], int n)
{
	for (int i = 0; i < n; i++) cel[i] = zrodlo[i];
}

int prawdopodobienstwo(double a)
{	
	return a < rand() / (double)(RAND_MAX + 1);
}

void druk(int t[], int n,int p, int q, double rozdzielczosc) // funkcja pomocnicza: wypisz geny osobnika
{
	for (int i = 0; i < n; i++) std::cout << t[i] << "";
		std::cout << " = " << std::setprecision(5)<<funkcjaDopasowania(t, n, p,q,rozdzielczosc) << std::endl;  //...i wartoœæ jego funkcji celu
}
int decymalizacja(int tab[], int n)
{
	int suma=0;
	int a = 0;
	for (int i = n-1; i>=0; i--)
	{
		suma += tab[i] * pow(2, a);
		a++;
	}
	return suma;
}
;

void ruletka(double dopasowanie[], int wynik[], int n, int m)
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
				wynik[i] = j; // j - numer pierwszego elementu tablicy sum
				// wiêkszego lub równego r
		};
	}
	else for (int i = 0; i < m; i++) wynik[i] = 0;
	delete[] suma;
}
