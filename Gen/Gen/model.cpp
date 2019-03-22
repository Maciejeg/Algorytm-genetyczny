#include "model.h"
#include "genetyka.h"
#include <iostream>

using namespace std;

void standard(int pop_size, int chrom_size, int xmin, int xmax, int num_of_generations, double chance_of_mutation, double chance_of_crossover, int q, int method)
{
	int *winner = new int[chrom_size];
	int **tab = new int*[pop_size];
	for (int i = 0; i < pop_size; i++)
	{
		tab[i] = new int[chrom_size];
	}
	init(tab, pop_size, chrom_size);
	double max;
	for (int i = 0; i < num_of_generations; i++)
	{
		int **out = new int*[pop_size];
		for (int i = 0; i < pop_size; i++)
		{
			out[i] = new int[chrom_size];
		}

		mutationAndCrossover(tab, pop_size, chrom_size, chance_of_mutation, chance_of_crossover);
		tournament(tab, out, xmin, xmax, pop_size, chrom_size, q, method, winner);
		copying(out, tab, pop_size, chrom_size);
		for (int i = 0; i < pop_size; i++)
		{
			delete[] out[i];
		}
		delete[] out;
	}
	for (int i = 0; i < pop_size; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
	for (int i = 0; i < chrom_size; i++)
	{
		cout << winner[i];
	}
	cout << ": " << xmin + binToDec(winner, chrom_size, method)*(xmax - xmin) / (pow(2, chrom_size) - 1) << " =" << fitness(winner, chrom_size, xmin, xmax, method) << endl;
}
