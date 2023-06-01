#pragma once
#include "Wiaderko.h"
static int numer = 0;
const int wiaderka = 10000;
const int drugia = 20;
class Hashmap
{
public:
	Hashmap();
	~Hashmap();
	void Dodaj(Mystring);
	int Szukaj(Mystring);

private:
	unsigned int Hash(Mystring str);
	Wiaderko** tab;
};

Hashmap::Hashmap()
{
	tab = new Wiaderko * [wiaderka];
	for (int i = 0; i < wiaderka; i++) {
		tab[i] = new Wiaderko[drugia];
		for (int y = 0; y < drugia; y++) {
			tab[i][y].numer = -1;
		}
	}
}


unsigned int Hashmap::Hash(Mystring str) {
	unsigned long hash = 0;
	int i = 0;
	int c;

	while (c = str[i++])
		hash = c + (hash << 6) + (hash << 16) - hash;

	return hash;
}

void Hashmap::Dodaj(Mystring nazwa) {
	unsigned long temp2 = Hash(nazwa);
	long temp = temp2 % wiaderka;
	if (tab[temp][0].numer == -1) {
		tab[temp][0].numer = numer;
		tab[temp][0].key = temp2;
		numer++;
	}
	else {
		for (int i = 1; i < drugia; i++) {
			if (tab[temp][i].numer == -1) {
				tab[temp][i].numer = numer;
				tab[temp][i].key = temp2;
				numer++;
				return;
			}
		}
	}
}

int Hashmap::Szukaj(Mystring nazwa) {
	unsigned long temp2 = Hash(nazwa);
	long temp3 = temp2 % wiaderka;
	for (int i = 0; i < drugia; i++) {
		if (tab[temp3][i].key == temp2) {
			return tab[temp3][i].numer;
		}
	}
	return tab[temp3]->numer;
}

Hashmap::~Hashmap()
{
}