#include "genetyka.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <math.h>
#include <iomanip>
#include <string>
#include "exprtk.h"
#include <string>

using namespace std;

void standard1(string function, double xmin, double xmax, int pop_size, int chrom_size, int num_of_generations, double chance_of_mutation, double chance_of_crossover)
{
	double resolution=pow(2,chrom_size)-1;
	int **pop = new int*[pop_size];
	for (int i = 0; i < pop_size; ++i)
		pop[i] = new int[chrom_size];

	init(pop, pop_size, chrom_size);
	for (int t = 0; t < num_of_generations; t++) {
		int **temp = new int*[pop_size];
		for (int z = 0; z < pop_size; ++z)
			temp[z] = new int[chrom_size];

		for (int i = 0; i < pop_size; i++) // operatory genetyczne
		{
			if (probability(chance_of_mutation)) mutation(pop[i], chrom_size);
			if (probability(chance_of_crossover))
			{
				int second = losujCalkowite(0, pop_size - 1);//losowy wybór partnera
				crossover(pop[i], pop[second], chrom_size);
			};
		};
		turniej(pop, temp, pop_size, 1, 1, chrom_size, xmin,xmax);
		for (int i = 0; i < pop_size; i++)
		{
			for (int j = 0; j < chrom_size; j++)
			{
				pop[i][j] = temp[i][j];
			}
		}
		for (int z = 0; z < pop_size; z++) {
			for (int i = 0; i < chrom_size; i++)
			{
				//cout << temp[z][i];
			}
			//cout << endl;
		}
		for (int u = 0; u < pop_size; u++)
		{
			//cout << "czy to tu nie dzia³a? ";
			for (int p = 0; p < chrom_size; p++)
			{
				//temp[u][p] = 0;
			//	cout <<temp[u][p];
			}
			//cout << endl;
		}
		//system("cls");
		//cout << "Wykonano " << 100 * double(double(t) / double(num_of_generations)) << " procent";
		for (int i = 0; i < pop_size; i++)
			delete[] temp[i];
		delete[] temp;
	}
	int k = 0;
	double max = fitness(pop[0], chrom_size, xmin, xmax, resolution, function);
	for (int i = 0; i < pop_size; i++) { //druk(pop[i], chrom_size, p, q, rozdzielczosc); 
		if (fitness(pop[i], chrom_size, xmin, xmax, resolution, function) > max)
		{
			k = i; max = fitness(pop[i], chrom_size, xmin, xmax, resolution, function);
		}
	}
		double s = 0;
		s = binToDec(pop[k], chrom_size);
		double x = xmin + s * (xmax - xmin) / (pow(2, chrom_size) - 1);
		cout << k << " " << setprecision(20) << x << "= " << setprecision(15) << max << endl;;
	
		
/*	for (int t = 0; t < num_of_generations; t++) // ograniczenie pêtli - liczba pokoleñ
	{
		for (int i = 0; i < pop_size; i++)
		{
			for (int j = 0; j < chrom_size; j++)
			{
				std::cout << pop[i][j];
			}
			std::cout << endl;
		}
		std::cout << "----------------" << endl;
		for (int i = 0; i < pop_size; i++) // operatory genetyczne
		{3
			if (probability(chance_of_mutation)) mutation(pop[i], chrom_size);
			if (probability(chance_of_crossover))
			{
				int second = losujCalkowite(0, pop_size - 1);//losowy wybór partnera
				crossover(pop[i], pop[second], chrom_size);
			};
		};

		double *f = new double[pop_size];
		int *selected = new int[pop_size];
		//double f[pop_size]; // wartoœci funkcji przystosowania osobników
		//int selected[pop_size]; // numery osobników wybranych "ko³em ruletki"
		for (int i = 0; i < pop_size; i++) f[i] = fitness(pop[i], chrom_size, xmin, xmax, pow(2,chrom_size)-1,function);

		roulette(f, selected, pop_size);

		for (int i = 0; i < pop_size; i++) copy(temp[i], pop[selected[i]], chrom_size);
		// copy wybranych osobników do tablicy pomocniczej

		for (int i = 0; i < pop_size; i++) copy(pop[i], temp[i], chrom_size);

		// copy zawartoœci tablicy pomocniczej do podstawowej
		delete[] f;
		delete[] selected;

	};
	int k = 0;
	double max = fitness(pop[0], chrom_size, xmin, xmax, pow(2,chrom_size)-1,function);
	for (int i = 0; i < pop_size; i++) { //druk(pop[i], chrom_size, p, q, rozdzielczosc); 
		if (fitness(pop[i], chrom_size, xmin, xmax, pow(2, chrom_size) - 1, function) > max) { k = i; max = fitness(pop[i], chrom_size, xmin, xmax, pow(2, chrom_size) - 1, function); }
		/*for (int i = 0; i < chrom_size; i++)
		{
			delete[] pop[i];
			delete[] temp[i];
		}
		delete[] pop;
		delete[] temp;
	}
	double s = 0;
	s = binToDec(pop[k], chrom_size);
	double x = xmin + s * (xmax - xmin) / (pow(2,chrom_size)-1);
	cout << k << " " << setprecision(20) << x << "= " << setprecision(15) << max << endl;;*/
		for (int i = 0; i < pop_size; i++)
			delete[] pop[i];
		delete[] pop;
};