#include "genetyka.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <math.h>
#define POP_SIZE   20
#define CHROM_SIZE 10
int pop[POP_SIZE][CHROM_SIZE];
int temp[POP_SIZE][CHROM_SIZE];

using namespace std;


void s() {
	//srand(time(NULL));
	for (int i = 0; i < POP_SIZE; i++)
	{
		inicjalizacja(pop[i], CHROM_SIZE);
	}
	const double szansa_mutacji = 0.01; // prawdopodobieñstwo mutacji osobnika
	const double szansa_krzyzowania = 0.5; // prawdopodobieñstwo krzy¿owania pary

	for (int t = 0; t < 100; t++) // ograniczenie pêtli - liczba pokoleñ
	{
		for (int i = 0; i < POP_SIZE; i++) // operatory genetyczne
		{
			if (prawdopodobienstwo(szansa_mutacji)) mutacja_poprzez_zamiane(pop[i], CHROM_SIZE);
			if (prawdopodobienstwo(szansa_krzyzowania))
			{
				int second = losujCalkowite(0, POP_SIZE - 1);//losowy wybór partnera
				krzyzowanieJednopunktowe(pop[i], pop[second], CHROM_SIZE);
			};
		};

		double f[POP_SIZE]; // wartoœci funkcji przystosowania osobników
		int selected[POP_SIZE]; // numery osobników wybranych "ko³em ruletki"
		for (int i = 0; i < POP_SIZE; i++) f[i] = funkcjaDopasowania(pop[i], CHROM_SIZE);
		ruletka(f, selected, POP_SIZE);
		for (int i = 0; i < POP_SIZE; i++) kopiowanie(temp[i], pop[selected[i]], CHROM_SIZE);
		// kopiowanie wybranych osobników do tablicy pomocniczej
		for (int i = 0; i < POP_SIZE; i++) kopiowanie(pop[i], temp[i], CHROM_SIZE);

		// kopiowanie zawartoœci tablicy pomocniczej do podstawowej

	};
	cout << "Wynik - populacja koñcowa:" << endl;
	for (int i = 0; i < POP_SIZE; i++) druk(pop[i], CHROM_SIZE);
}