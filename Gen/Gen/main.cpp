
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include "genetyka.h"
#include <iomanip>
using namespace std;
#include "genetyka.h"
#include <math.h>
#include "model.h"
#include "exprtk.h"
#include <bitset>
template<unsigned long num>
struct binary
{
	static unsigned const value =
		binary<num / 10>::value << 1 | num % 10;
};

// Specialization for zero
template<>
struct binary<0>
{
	static unsigned const value = 0;
};
int main()
{
	srand(time(NULL));
	/*int pop_size = 10;
	int chrom_size = 20;
	int **pop = new int*[pop_size];
	for (int i = 0; i < pop_size; ++i)
		pop[i] = new int[chrom_size];

	init(pop, pop_size, chrom_size);


	for (int i = 0; i < pop_size; i++)
	{
		for (int j = 0; j < chrom_size; j++)
		{
			cout << setw(3) << pop[i][j];
		}
		cout << endl;
	}

	int x;
	cin >> x;
	int *tab = new int[x];
	cout << " XD " << endl;
	inicjalizacja(tab, 5);
	for (int i = 0; i < 5; i++)
		cout << tab[i];
	cout << " XD " << endl;
	//standard(-6,10,1073741824);
	//int tab[10] = { 1,1,1,1,1,1,1,1,1,1 };
//cout << binToDec(tab, 10) << endl;
	//cout << setprecision(10)<<fitness(tab, 10, 0, 1, 1023) << endl;;//tab,d³,p,q,rozdzielczosc
	delete tab;*/
	standard1("-x^2+10*sin(x)", 2, 5, 100, 25, 100, 0.02, 0.5);//funkcja,a,b,pop_size,chrom_size,ilosc gene, mutprob, crossprob
	//chrom_size max=30 if(chrom_size>30)int out of range

	 //const unsigned long a = 110;
	//cout << a << endl;
//	for (int i = 0; i < 1000; i++)
	{
	//	cout<<binary<a>::value<<endl; //cout << i;
	}
	int tab[64];
	for (int i = 0; i < 64; i++)
		tab[i] = 1;

	std::string str;
	for (int i = 0; i < 64; i++) {
		str += std::to_string(tab[i]);
	}
	cout << str << endl;
	const std::string s = "0010111100011100011";
	unsigned long long value;
	for(int i=0; i<1000; i++)
	 value = std::bitset<64>(str).to_ullong();
	cout << "LOLDASHKDJASHKDJHALSJD" << endl;
	std::cout << value << std::endl;
	cin.ignore();
	cin.ignore();
	cin.ignore();
	cin.ignore();
	cin.ignore();
	cin.ignore();

	cin.ignore();
	return 0;

}

