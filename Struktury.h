#pragma once
#include"Mystring.h"
using namespace std;
const int INF = 1e9;

struct Miasto
{
	Miasto(int x, int y, const Mystring nazwa) :nazwa(nazwa), x(x), y(y) {}
	Miasto() :nazwa(""), x(0), y(0) {}
	~Miasto() {};
	Mystring nazwa;
	int x, y;
};

struct wspolrzedne {
	int x, y;
	wspolrzedne(int x, int y) :x(x), y(y) {}
	wspolrzedne():x(),y(){}
};

struct graf {
	int docelowy, waga;
	graf(int w, int d):docelowy(d),waga(w) {
	}
	graf() :docelowy(0), waga(0) {}
};