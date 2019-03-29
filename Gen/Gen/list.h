#pragma once
#ifndef LIST_H
#define LIST_H
struct Gdata {
	int *popdata;
	double fitness;
	int n_of_generation;
	Gdata *next;
};
void addToList(Gdata *&head, int *data, int chrom_size, int n);
void printList(Gdata *dane, int chrom_size);
void deleteList(Gdata *&head);


#endif LIST_H