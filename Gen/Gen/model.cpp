#include "genetyka.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <math.h>
#include <iomanip>
#define POP_SIZE   2000
#define CHROM_SIZE 10
int pop[POP_SIZE][CHROM_SIZE];
int temp[POP_SIZE][CHROM_SIZE];

using namespace std;


void standard(int p, int q, double rozdzielczosc) {
	int tabmax[CHROM_SIZE];
	for (int i = 0; i < CHROM_SIZE; i++) tabmax[i] = 1;
	srand(time(NULL));
	for (int i = 0; i < POP_SIZE; i++)
	{
		inicjalizacja(pop[i], CHROM_SIZE);
	}
	const double szansa_mutacji = 0.01; // prawdopodobie�stwo mutacji osobnika
	const double szansa_krzyzowania = 0.5; // prawdopodobie�stwo krzy�owania pary

	for (int t = 0; t < 100; t++) // ograniczenie p�tli - liczba pokole�
	{
		for (int i = 0; i < POP_SIZE; i++) // operatory genetyczne
		{
			if (prawdopodobienstwo(szansa_mutacji)) mutacja_poprzez_zamiane(pop[i], CHROM_SIZE);
			if (prawdopodobienstwo(szansa_krzyzowania))
			{
				int second = losujCalkowite(0, POP_SIZE - 1);//losowy wyb�r partnera
				krzyzowanieJednopunktowe(pop[i], pop[second], CHROM_SIZE);
			};
		};

		double f[POP_SIZE]; // warto�ci funkcji przystosowania osobnik�w
		int selected[POP_SIZE]; // numery osobnik�w wybranych "ko�em ruletki"
		for (int i = 0; i < POP_SIZE; i++) f[i] = funkcjaDopasowania(pop[i], CHROM_SIZE,p,q,rozdzielczosc);
		ruletka(f, selected, POP_SIZE);
		for (int i = 0; i < POP_SIZE; i++) kopiowanie(temp[i], pop[selected[i]], CHROM_SIZE);
		// kopiowanie wybranych osobnik�w do tablicy pomocniczej
		for (int i = 0; i < POP_SIZE; i++) kopiowanie(pop[i], temp[i], CHROM_SIZE);

		// kopiowanie zawarto�ci tablicy pomocniczej do podstawowej

	};
	cout << "Wynik - populacja ko�cowa:" << endl;
	int k = 0;
	double max = funkcjaDopasowania(pop[0], CHROM_SIZE, p, q, rozdzielczosc);
	for (int i = 0; i < POP_SIZE; i++) { //druk(pop[i], CHROM_SIZE, p, q, rozdzielczosc); 
	if (funkcjaDopasowania(pop[i], CHROM_SIZE, p, q, rozdzielczosc) > max) { k = i; max = funkcjaDopasowania(pop[i], CHROM_SIZE, p, q, rozdzielczosc); }

	}
	cout << k << " " << setprecision(10)<<max << endl;;
	
}