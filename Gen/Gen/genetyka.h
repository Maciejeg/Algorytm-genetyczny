#pragma once
#ifndef GENETYKA_H
#define GENETYKA_H

int losujCalkowite(int a, int b);
void inicjalizacja(int t[], int n);
void mutacja_poprzez_zamiane(int t[], int n);
void krzyzowanieJednopunktowe(int t1[], int t2[], int n);
double funkcjaDopasowania(int t[], int n, double p, double q, double rozdzielczosc);
void kopiowanie(int zrodlo[], int cel[], int n);
int prawdopodobienstwo(double a);
void ruletka(double dopasowanie[], int wynik[], int n, int m = -1);
void druk(int t[], int n, int p, int q, double rozdzielczosc); // funkcja pomocnicza: wypisz geny osobnika
int decymalizacja(int tab[], int n);

#endif //GENETYKA_H