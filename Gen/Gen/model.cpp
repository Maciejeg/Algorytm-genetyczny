#include "model.h"
#include "genetyka.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <fstream>
#include "list.h"
using namespace std;

int bestOfTable(int**tab, int pop_size, int chrom_size, double xmin, double xmax, int method)
{
	double max;
	int iteracja = 0;
	max = fitness(tab[0], chrom_size, xmin, xmax, method);
	for (int i = 0; i < pop_size; i++)
	{
		if (fitness(tab[i], chrom_size, xmin, xmax, method) > max)
		{
			max = fitness(tab[i], chrom_size, xmin, xmax, method);
			iteracja = i;
		}
	}
	return iteracja;
}
void standard(int pop_size, int chrom_size, double xmin, double xmax, int num_of_generations, double chance_of_mutation, double chance_of_crossover, int q, int method, string minmax, int num_of_threads)
{
	srand(time(NULL));
	int *control = new int[chrom_size];
	for (int i = 0; i < chrom_size; i++)
		control[i] = rand() % 2;
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	Gdata *dane = new Gdata;
	dane = NULL;
	ofstream output("wynik.csv");
	int *winner = new int[chrom_size];
	int **tab = new int*[pop_size];
	for (int i = 0; i < pop_size; i++)
	{
		tab[i] = new int[chrom_size];
	}
	init(tab, pop_size, chrom_size);
	double max;
	int n = 0;
	for (int k = 0; k < num_of_generations; k++)
	{
		n = k;
		int **out = new int*[pop_size];
		for (int i = 0; i < pop_size; i++)
		{
			out[i] = new int[chrom_size];
		}

		mutationAndCrossover(tab, pop_size, chrom_size, chance_of_mutation, chance_of_crossover);
		tournament(tab, out, xmin, xmax, pop_size, chrom_size, q, method, winner, minmax);
		copying(out, tab, pop_size, chrom_size);
		for (int i = 0; i < pop_size; i++)
		{
			delete[] out[i];
		}
		delete[] out;

		addToList(dane, winner, chrom_size, k);
		system("cls");
		cout <<"Wykonano "<< double(k+1) / double(num_of_generations)*100<< " procent."<< endl;
		for (int i = 0; i < chrom_size; i++)
		{
			cout << winner[i];
		}
		bool controlb = true;
		for (int i = 0; i < chrom_size; i++)
		{
			if (winner[i] != control[i])
				controlb = false;
		}
		if (controlb) break;
		for (int i = 0; i < chrom_size; i++)
		{
			control[i] = winner[i];
		}
	}
	
	for (int i = 0; i < pop_size; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
	cout << endl << "Zwycieski chromosom" << endl;
	for (int i = 0; i < chrom_size; i++)
	{
		cout << winner[i];
	}
	double value = xmin + binToDec(winner, chrom_size, method)*(xmax - xmin) / (pow(2, chrom_size) - 1);
	cout << endl <<
		"f(" << setprecision(20)
		<< xmin + binToDec(winner, chrom_size, method)*(xmax - xmin) / (pow(2, chrom_size) - 1)
		<< ")" << " = " << setprecision(20) << fitness(winner, chrom_size, xmin, xmax, method)
		<< endl;
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	cout << "Obliczenie ekstremum globalnego funkcji na przedziale [" 
		<< xmin << "," << xmax << "] trwalo " 
		<< std::chrono::duration_cast<std::chrono::seconds>(end - start).count() 
		<< " sekund." << endl << "koniec" << endl;
	for (int i = 0; i < n; i++)
	{
		int *tab = new int[chrom_size];
		for (int j = 0; j < chrom_size; j++)
		{
			tab[j] = dane->popdata[j];
			output << dane->popdata[j];
		}
		output << ";" <<double(xmin+binToDec(tab,chrom_size,0)*(xmax-xmin)/(pow(2,chrom_size)-1))<< ";"<<fitness(tab, chrom_size, xmin, xmax, method);
		output << endl;
		dane = dane->next;
	}
	deleteList(dane);
}
