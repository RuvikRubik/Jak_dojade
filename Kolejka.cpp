//#include"Kolejka.h"
//
//Kolejka<dane>::Kolejka() :pocz(), koniec(), rozmiar(), pojemnosc(8), wartosc(new dane[pojemnosc])
//{
//}
//
//Kolejka<dane>::~Kolejka()
//{
//	delete[] wartosc;
//}
//
//void Kolejka<dane>::dodaj(dane wart)
//{
//	if (rozmiar == pojemnosc) {
//		resize();
//	}
//	wartosc[koniec] = wart;
//	koniec = (koniec + 1) % pojemnosc;
//	rozmiar++;
//}
//
//void Kolejka::usun()
//{
//	pocz = (pocz + 1) % pojemnosc;
//	rozmiar--;
//}
//
//dane Kolejka::poczatek()
//{
//	return wartosc[pocz];
//}
//
//bool  Kolejka::pusty()
//{
//	if (rozmiar == 0) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
//void Kolejka::resize()
//{
//	pojemnosc *= 2;
//	int* wart2 = new int[pojemnosc];
//	for (int i = 0; i < rozmiar; i++) {
//		wart2[i] = wartosc[(pocz + i) % rozmiar];
//	}
//	pocz = 0;
//	koniec = rozmiar;
//	delete[] wartosc;
//	wartosc = wart2;
//}
//
//
//Kolejka();
//~Kolejka();
//void dodaj(dane);
//void usun();
//dane poczatek();
//bool pusty();
//void resize();