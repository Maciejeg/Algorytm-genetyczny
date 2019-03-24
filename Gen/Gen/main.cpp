#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include "model.h"
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
int main()
{
	//thread a(standard,10000, 500, 1.5, 2, 100, 0.3, 0.65, 10, 0);
	//thread b(standard, 10000, 500, 2, 3.5, 100, 0.3, 0.65, 10, 0);
	//thread c(standard, 10000, 500, 1.5, 2, 100, 0.3, 0.65, 10, 0);
	//thread d(standard, 10000, 500, 2, 3.5, 100, 0.3, 0.65, 10, 0);
	//thread e(standard, 10000, 500, 1.5, 2, 100, 0.3, 0.65, 10, 0);
	//thread f(standard, 10000, 500, 2, 3.5, 100, 0.3, 0.65, 10, 0);
	//thread g(standard, 10000, 500, 1.5, 2, 100, 0.3, 0.65, 10, 0);
	//thread h(standard, 10000, 500, 2, 3.5, 100, 0.3, 0.65, 10, 0);
	//thread i(standard, 10000, 500, 1.5, 2, 100, 0.3, 0.65, 10, 0);
	//thread j(standard, 10000, 500, 2, 3.5, 100, 0.3, 0.65, 10, 0);
	//thread k(standard, 10000, 500, 1.5, 2, 100, 0.3, 0.65, 10, 0);
	//thread l(standard, 10000, 500, 2, 3.5, 100, 0.3, 0.65, 10, 0);
	standard(
		100,			 //int pop_size
		500,			 //int chrom_size
		1.5,				 //double xmin
		2,				 //double xmax
		100,			 //int num_of_generations
		0.3,			 //double chance_of_mutation
		0.65,			 //double chance_of_crossover
		10,				 //int q (amount of chromosomes that form a tournament group)
		0				 //int method
			);
	//a.join();
	//b.join();
	//c.join();
	//d.join();
	//e.join();
	//f.join();
	//g.join();
	//h.join();
	//i.join();
	//j.join();
	//k.join();
	//l.join();

	cin.ignore();
	return 0;
}