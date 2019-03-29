#include "list.h"
#include <iostream>



void deleteList(Gdata *&head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		delete head;
		head = NULL;
		return;
	}
	while (true)
	{
		if (head == NULL)
			break;
		Gdata *tmp = head->next;
		delete head;
		head = tmp;
	}
}

void addToList(Gdata *&head, int *data, int chrom_size, int n)
{
	int *dane = new int[chrom_size];
	for (int i = 0; i < chrom_size; i++)
		dane[i] = data[i];
	if (head == NULL)
	{
		head = new Gdata;
		head->next = NULL;
		head->popdata = dane;
		head->n_of_generation = n;
	}
	else
	{
		Gdata *akt = head;
		while (akt->next != NULL)
		{
			akt = akt->next;
		}
		Gdata *nowy = new Gdata;
		akt->next = nowy;
		nowy->next = NULL;
		nowy->popdata = dane;
		nowy->n_of_generation = n;
	}
}
void printList(Gdata *dane, int chrom_size)
{
	if (dane == NULL)
		return;
	Gdata *akt = dane;

	while (akt != NULL)
	{
		for (int j = 0; j < chrom_size; j++)
		std::	cout << akt->popdata[j];
	std::	cout << std::endl;
		akt = akt->next;
	}
}