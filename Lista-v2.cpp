#include"Lista-v2.h"

Lista2::Lista2(int wielkosc) :wielkosc(wielkosc)
{
	tab = new Miasto[wielkosc];
}

int Lista2::Find(int x, int y) {
	for (int i = 0; i < wielkosc; i++) {
		if (tab[i].x == x && tab[i].y == y) {
			return i;
		}

	}
	return -1;
}

void Lista2::Dodaj(Miasto c) {
	tab[i] = c;
	i++;
}

Mystring Lista2::Wypisz(int i) {
	return tab[i].nazwa;
}

Lista2::~Lista2()
{
}