#pragma once
#ifndef GENETYKA_H
#define GENETYKA_H
#include <string>
int losujCalkowite(int a, int b);
void inicjalizacja(int t[], int n);
void mutation(int t[], int n);
void crossover(int t1[], int t2[], int n);
double fitness(int t[], int n, double p, double q, double rozdzielczosc, std::string function = "x");
void copy(int zrodlo[], int cel[], int n);
int probability(double a);
void roulette(double dopasowanie[], int wynik[], int n, int m = -1);
void druk(int t[], int n, int p, int q, double rozdzielczosc); // funkcja pomocnicza: wypisz geny osobnika
int binToDec(int tab[], int n);
void init(int **tab, int pop_size, int chrom_size);
#endif //GENETYKA_H