#pragma once
#include "Struktury.h"
#include<iostream>
static int i = 0;
class Lista2
{
public:
	Lista2(int);
	~Lista2();
	int Find(int,int);
	Mystring Wypisz(int);
	void Dodaj(Miasto);
private:
	Miasto* tab;
	int wielkosc;
};