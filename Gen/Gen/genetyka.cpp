#include <stdlib.h>
#include <iostream>
#include "genetyka.h"
#define PI 3.14159265359



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

double funkcjaDopasowania(int t[], int n)
{
	double s = 0;
	for (int i = 0; i < n; i++) s += t[i];
	s /= n;
	return s * s; // dana funkcja 
}

void kopiowanie(int zrodlo[], int cel[], int n)
{
	for (int i = 0; i < n; i++) cel[i] = zrodlo[i];
}

int prawdopodobienstwo(double a)
{
	return a < rand() / (double)(RAND_MAX + 1);
}

void druk(int t[], int n) // funkcja pomocnicza: wypisz geny osobnika
{
	for (int i = 0; i < n; i++) std::cout << t[i] << "";
	std::cout << " = " << funkcjaDopasowania(t, n) << std::endl; //...i wartoœæ jego funkcji celu
};

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
