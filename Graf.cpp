#include"Graf.h"
#include <queue>
#include "Kolejka.h"

Graf::Graf(int Dlugosc) :Dlugosc(Dlugosc)
{
	lista = new Lista<graf>[Dlugosc];
}

void Graf::DodajKrawedz(int pocz, int docelowy, int waga) {
    Lista<graf>* temp;
    if((temp = lista[pocz].Find(docelowy, waga)) == NULL){
        temp = new Lista<graf>(new graf(waga, docelowy));
        lista[pocz].AddLast(temp);
    }
    else {
        temp->change(docelowy, waga);
    }
	
    //;
	
}

void Graf::GrafWypisz() {
	Lista<graf>* temp;
	for (int i = 0; i < Dlugosc; i++) {
		cout << "Wierzcholek " << i << ": ";
		temp = &lista[i];
		int dlugosclisty = temp->Getrozmiar();
		for (int i = 0; i < dlugosclisty; i++) {
			cout << temp->GetHead()->docelowy << " " << temp->GetHead()->waga << " ";
			temp = temp->getNext();
		}
		cout << endl;
	}
}

void Graf::Dijkstra(int start,int koniec,int posrednicy,Lista2* miasta) {
    int* dist = new int[Dlugosc];
    int* poprzednik = new int[Dlugosc];
    Kolejka<graf> kol;
    Lista<graf>* temp;
    for (int i = 0; i < Dlugosc; i++) {
        dist[i] = INF;
        poprzednik[i] = -1;
    }
    kol.dodaj(graf(0, start));
    dist[start] = 0;

    // wykonujemy algorytm Dijkstry
    while (!kol.pusty()) {
        int dystans = kol.poczatek().waga;
        int docelowy = kol.poczatek().docelowy;
        kol.usun();
        Lista<graf>* temp = &lista[docelowy];
        int dlugosclisty = temp->Getrozmiar();
        for (int i = 0; i < dlugosclisty; i++) {
            int v = temp->GetHead()->docelowy;
            int nowydystans = dystans + temp->GetHead()->waga;
            if (nowydystans >= dist[v] - 20) {
                if (nowydystans >= dist[v] - 18) {
                    continue;
                }
                cout << "";
            }
            dist[v] = nowydystans;
            if (docelowy != start) {
                poprzednik[v] = docelowy;
            }
            kol.dodaj(graf(nowydystans, v));
            temp = temp->getNext();
        }
    }
    Kolejka<int> kolmiast;
    cout << dist[koniec] << " ";
    if (posrednicy == 1) {
        while (poprzednik[koniec] != -1) {  
            kolmiast.dodaj(poprzednik[koniec]);
            koniec = poprzednik[koniec];
        }
        while (!kolmiast.pusty()) {
            cout << miasta->Wypisz(kolmiast.ogon()) << " ";
            kolmiast.usunkoniec();
        }
    }
    cout << endl;
}


Graf::~Graf()
{
}