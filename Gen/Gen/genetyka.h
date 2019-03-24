#pragma once
#ifndef genetyka_H
#define genetyka_H
#include <string>
using namespace std;
void init(int **tab, int pop_size, int chrom_size);
void mutationAndCrossover(int **tab, int pop_size, int chrom_size, double chance_of_mutation, double chance_of_crossover);
double binToDec(int *tab, int chrom_size, int method);
int probability(double a);
double fitness(int *tab, int chrom_size, int xmin, int xmax, int method);
void tournament(int ** input, int ** output, double xmin, double xmax, int pop_size, int chrom_size, int q, int method, int *winner);
void copying(int **input, int **output, int pop_size, int chrom_size);
#endif // !genetyka_H
