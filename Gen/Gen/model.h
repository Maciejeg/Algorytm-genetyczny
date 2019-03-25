#pragma once
#ifndef model_H
#define model_H
#include <thread>
#include <string>
using namespace std;
void standard(int pop_size, int chrom_size, double xmin, double xmax, int num_of_generations, double chance_of_mutation, double chance_of_crossover, int q, int method,string minmax, int num_of_threads = std::thread::hardware_concurrency() / 2);

#endif // !model_H

