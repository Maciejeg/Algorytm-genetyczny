#include "genetyka.h"
#include <math.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <thread>
using namespace std;

/*CO POTRZEBUJÊ?:
-inicjalizacja: dostaje pust¹ tablicê pop_size X chrom_size
-mutacja: dostaje jeden chromosom
-krzy¿owanie: dostaje dwa chromosomy i miejsce przeciêcia
-base 2 na base 10
-funkcja dopasowania
-kopiowanie z tablicy do tablicy
-algorytm turniej
*/


void init(int **tab, int pop_size, int chrom_size)
{
	for (int i = 0; i < pop_size; i++)
		for (int j = 0; j < chrom_size; j++)
			tab[i][j] = rand() % 2;
}

int probability(double a)
{
	return a < rand() / (double)(RAND_MAX + 1);
}

double fitness(int * tab, int chrom_size, int xmin, int xmax, int method)
{
	double resolution = pow(2, chrom_size) - 1;
	double s = 0;
	s = binToDec(tab, chrom_size, method);
	double x = xmin + s * (xmax - xmin) / resolution;
	return   pow(x,sin(x));
}
void copying(int **input, int **output, int pop_size, int chrom_size)
{
	for (int i = 0; i < pop_size; i++)
	{
		for (int j = 0; j < chrom_size; j++)
		{
			output[i][j] = input[i][j];
		}
	}
}
void mutationAndCrossover(int **tab, int pop_size, int chrom_size, double chance_of_mutation, double chance_of_crossover)
{
	srand(time(NULL));
	for (int i = 0; i < pop_size; i++)
	{
		if (probability(chance_of_mutation))
		{
			int position = rand() % chrom_size;
			tab[i][position] = 1 - tab[i][position];
		}
		if (probability(chance_of_crossover))
		{
			int position = 1 + rand() % (chrom_size - 1);
			int second = rand() % pop_size;
			for (int j = position; j < chrom_size; j++)
			{
				int p = tab[i][j];
				tab[i][j] = tab[second][j];
				tab[i][j] = p;
			}
		}
	}
}

double binToDec(int *tab, int chrom_size, int method)
{
	if (method == 0)
	{
		double suma = 0;
		int a = 0;
		for (int i = chrom_size - 1; i >= 0; i--)
		{
			suma += tab[i] * pow(2, a);
			a++;
		}
		return suma;
	}
	else
	{
		string bin;
		for (int i = 0; i < chrom_size; i++)
		{
			bin += to_string(tab[i]);
		}
		unsigned long long value = std::bitset<64>(bin).to_ullong();
		return value;
	}
}
void multiThread(int ** input, int ** output, double xmin, double xmax, int pop_size, int chrom_size, int q, int method, int *winner, int start)
{
	srand(time(NULL));

	for (int k = start; k < pop_size; k++)
	{
		int *value = new int[q];
		for (int i = 0; i < q; i++)
		{
			bool check; //variable to check or number is already used
			int n; //variable to store the number in
			do
			{
				n = rand() % pop_size;
				//check or number is already used:
				check = true;
				for (int j = 0; j < i; j++)
					if (n == value[j]) //if number is already used
					{
						check = false; //set check to false
						break; //no need to check the other elements of value[]
					}
			} while (!check); //loop until new, unique number is found
			value[i] = n; //store the generated number in the array
		}
		int **tab = new int*[q];
		for (int i = 0; i < q; i++)
		{
			tab[i] = new int[chrom_size];
		}
		for (int i = 0; i < q; i++)
		{
			for (int j = 0; j < chrom_size; j++)
			{
				tab[i][j] = input[value[i]][j];
			}
		}
		double max = fitness(tab[0], chrom_size, xmin, xmax, method);
		int iteration = 0;
		for (int i = 0; i < q; i++)
		{
			if (fitness(tab[i], chrom_size, xmin, xmax, method) >= max)
			{
				max = fitness(tab[i], chrom_size, xmin, xmax, method);
				iteration = i;
			}
		}
		for (int i = 0; i < chrom_size; i++)
		{
			output[k][i] = tab[iteration][i];
		}

		delete[] value;
		for (int i = 0; i < q; i++)
		{
			delete[] tab[i];
		}
		delete[] tab;
	}
}
void tournament(int ** input, int ** output, double xmin, double xmax, int pop_size, int chrom_size, int q, int method, int *winner)
{
	srand(time(NULL));
	thread first(multiThread, input, output, xmin, xmax, pop_size/2, chrom_size, q, method, winner,0);
	thread second(multiThread, input, output, xmin, xmax, pop_size, chrom_size, q, method, winner, pop_size/2);
	/*for (int k = 0; k < pop_size; k++)
	{
		int *value = new int[q];
		for (int i = 0; i < q; i++)
		{
			bool check; //variable to check or number is already used
			int n; //variable to store the number in
			do
			{
				n = rand() % pop_size;
				//check or number is already used:
				check = true;
				for (int j = 0; j < i; j++)
					if (n == value[j]) //if number is already used
					{
						check = false; //set check to false
						break; //no need to check the other elements of value[]
					}
			} while (!check); //loop until new, unique number is found
			value[i] = n; //store the generated number in the array
		}
		int **tab = new int*[q];
		for (int i = 0; i < q; i++)
		{
			tab[i] = new int[chrom_size];
		}
		for (int i = 0; i < q; i++)
		{
			for (int j = 0; j < chrom_size; j++)
			{
				tab[i][j] = input[value[i]][j];
			}
		}
		double max = fitness(tab[0], chrom_size, xmin, xmax, method);
		int iteration = 0;
		for (int i = 0; i < q; i++)
		{
			if (fitness(tab[i], chrom_size, xmin, xmax, method) >= max)
			{
				max = fitness(tab[i], chrom_size, xmin, xmax, method);
				iteration = i;
			}
		}
		for (int i = 0; i < chrom_size; i++)
		{
			output[k][i] = tab[iteration][i];
		}

		delete[] value;
		for (int i = 0; i < q; i++)
		{
			delete[] tab[i];
		}
		delete[] tab;
	}*/
	first.join();
	second.join();
	for (int i = 0; i < chrom_size; i++)
	{
		winner[i] = output[pop_size - 1][i];
		//cout <<": "<<xmin+binToDec(output[i],chrom_size,method)*(xmax-xmin)/(pow(2,chrom_size)-1)<<" ="<< fitness(output[i], chrom_size, xmin, xmax, method) << endl;
	}

}