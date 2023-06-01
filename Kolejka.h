#pragma once
template <typename dane>
class Kolejka
{
public:
	Kolejka() :pocz(), koniec(), rozmiar(), pojemnosc(8), wartosc(new dane[pojemnosc]){}
	~Kolejka(){	delete[] wartosc;}
	void usun() { pocz = (pocz + 1) % pojemnosc;	rozmiar--; }
	void usunkoniec() { koniec = (koniec - 1) % pojemnosc;	rozmiar--; }
	dane const poczatek() { return wartosc[pocz]; }
	dane const ogon() { return wartosc[koniec-1]; }
	void dodaj(dane wart)
	{
		if (rozmiar == pojemnosc) {
			resize();
		}
		wartosc[koniec] = wart;
		koniec = (koniec + 1) % pojemnosc;
		rozmiar++;
	}
	bool const pusty()
	{
		if (rozmiar == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void resize()
	{
		pojemnosc *= 2;
		dane* wart2 = new dane[pojemnosc];
		for (int i = 0; i < rozmiar; i++) {
			wart2[i] = wartosc[(pocz + i) % rozmiar];
		}
		pocz = 0;
		koniec = rozmiar;
		delete[] wartosc;
		wartosc = wart2;
	}
private:
	int pocz, koniec, rozmiar, pojemnosc;
	dane* wartosc;
};



