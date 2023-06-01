#pragma once
#include"Lista.h"
#include "Lista-v2.h"
#include <iostream>
using namespace std;

class Graf
{
public:
	Graf(int);
	void DodajKrawedz(int, int, int);
	void GrafWypisz();
	void Dijkstra(int,int,int,Lista2*);
	~Graf();
private:
	int Dlugosc;
	Lista<graf>* lista;
};
