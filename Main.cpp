#include<iostream>
#include<string>
#include"Kolejka.h"
#include "Graf.h"
#include "Hashmap.h"
#include "Lista-v2.h"
#include"Mystring.h"
using namespace std;

void wczytanieGraphu(int* x, int* y) {
    Mystring linia;
    int litera;
    while ((litera = getchar()) != '\n') {
        if (litera == ' ') {
            *x = Mystring::stoi(linia);
            linia = "";
        }
        else {
            linia += litera;
        }
        
    }
    *y = Mystring::stoi(linia);
}

Mystring znajdznazwemiasta(int x,int y,char** mapa,int maxx,int maxy) {
    wspolrzedne opcje[] = { {0,1},{-1,0},{-1,1},{0,-1},{-1,-1},{1,-1},{1,0},{1,1} };
    Mystring nazwamiasta;
    
    for (int i = 0; i < 8; i++) {
        int chgx = opcje[i].x;
        int chgy = opcje[i].y;
        int temp = 1;
        //sprawdzenie czy nie wychodzimy za tablice i czy dane pole jest liter�
        if (x+chgx >= 0 && x+ chgx < maxx && y+ chgy >= 0 && y+ chgy < maxy && mapa[x + chgx][y + chgy] > 47) {
            if(mapa[x + chgx][y + chgy - temp] < 47){
                while (mapa[x + chgx][y + chgy - --temp] > 47) {
                    nazwamiasta += mapa[x + chgx][y + chgy - temp];
                }
                break;
            }
            else if (mapa[x + chgx][y + chgy + temp] < 47) {
                while (mapa[x + chgx][y + chgy + --temp] > 47);
                while (mapa[x + chgx][y + chgy + ++temp] > 47) {
                    nazwamiasta += mapa[x + chgx][y + chgy + temp];
                }
                break;
            }
            else {

            }
        }
    }
    return nazwamiasta;
    //cout << x << " " << y << " " << nazwamiasta << endl;
}

void bfs(wspolrzedne pocz, char** mapa,int x,int y,Graf* g,int indeksmiasta, Lista2* miasta) {
    wspolrzedne opcje[] = { {-1,0},{0,-1},{1,0},{0,1} };
    int brakpolaczen = 0;
    for (int i = 0; i < 4; i++) {
        int sasx = pocz.x + opcje[i].x;
        int sasy = pocz.y + opcje[i].y;
        if (sasx >= 0 && sasy >= 0 && sasx < y && sasy < x && mapa[sasx][sasy] != '#') {
            brakpolaczen++;
        }
    }
    if (brakpolaczen == 4) {
        return;
    }
    int** dist = new int* [y];
    for (int i = 0; i < y; i++) {
        dist[i] = new int[x];
    }
    Kolejka<wspolrzedne> kol;
    kol.dodaj(pocz);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            dist[i][j] = INF;
        }
    }
    dist[pocz.x][pocz.y] = 0;
    while (!kol.pusty()) {
        wspolrzedne u = kol.poczatek();
        kol.usun();
        for (int i = 0; i < 4; i++) {
            int sasx = u.x + opcje[i].x;
            int sasy = u.y + opcje[i].y;
            if (sasx >= 0 && sasy >= 0 && sasx < y && sasy < x && mapa[sasx][sasy] == '#' && dist[sasx][sasy] == INF) {
                //mapa[sasx][sasy] = '@';
                kol.dodaj({ sasx,sasy });
                dist[sasx][sasy] = dist[u.x][u.y] + 1;
            }
            if (sasx >= 0 && sasy >= 0 && sasx < y && sasy < x && mapa[sasx][sasy] == '*') {//  && (sasy != pocz.y || sasx != pocz.x)
                if (dist[sasx][sasy] > dist[u.x][u.y] + 1) {
                    dist[sasx][sasy] = dist[u.x][u.y] + 1;
                    //cout << miasta->Find(sasx, sasy) << " " << sasx << " " << sasy << " " << dist[sasx][sasy] << endl;
                    int koniec = miasta->Find(sasx, sasy);
                    g->DodajKrawedz(indeksmiasta, koniec, dist[sasx][sasy]);
                    //g.DodajKrawedz(koniec, indeksmiasta, dist[sasx][sasy]);
                }
            }
        }
    }
    for (int i = 0; i < y; i++) {
        delete[] dist[i];
    }
    delete[] dist;
}

int main() {
    Hashmap* miasta = new Hashmap();
    int x, y;
    int iloscMiast = 0;
    //wczytanie wielkosci mapy i tworzenie tablicy 2 wymiarowej
    wczytanieGraphu(&x, &y);
    char** mapa = new char* [y];
    for (int i = 0; i < y; i++) {
        mapa[i] = new char[x];
    }
    //wczytanie mapy
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            mapa[i][j] = getchar();
            if (mapa[i][j] == '*') {
                iloscMiast++;
            }
        }
        getchar();
    }
    //wczytanie miast
    Lista2* miasta2 = new Lista2(iloscMiast);
    Mystring temp;
    Graf* g = new Graf(iloscMiast);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (mapa[i][j] == '*') {
                //odpalenie funkcji kt�ra znajduje nazw� miasta
                temp = znajdznazwemiasta(i, j, mapa, y, x);
                miasta2->Dodaj(Miasto(i, j, temp));
                miasta->Dodaj(temp);
            }

        }
    }
    //tworzenie grafu o wielkosci ilosci miast

    iloscMiast = 0;
    //Lista<Miasto>* temp = miasta;
    // wyszukanie dlugosci drog miedzy wszystkimi miastami
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (mapa[i][j] == '*') {

                bfs(wspolrzedne(i, j), mapa, x, y, g, iloscMiast, miasta2);
                iloscMiast++;
            }

        }
    }
    //wczytanie wszystkich polaczen lotnicych
    int b, petle,s3;
    Mystring d;
    char tab[40];
    char str[15];
    char str1[15];
    while ((b = getchar()) != '\n') {
        d += b;
    }
    int e = 0;
    petle = Mystring::stoi(d);
    d = "";
    for (int i = 0; i < petle; i++) {
        while ((b = getchar()) != '\n') {
            tab[e] = b;
            e++;
        }
        tab[e] = '\0';
        e = 0;
        sscanf_s(tab, "%s %s %d", str, sizeof(str), str1, sizeof(str1), &s3);
        int s1 = miasta->Szukaj(str);
        int s2 = miasta->Szukaj(str1);
        g->DodajKrawedz(s1, s2, s3);
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    //wyszukiwanie najkrotszej drogi


    while ((b = getchar()) != '\n') {
        d += b;
    }
    petle = Mystring::stoi(d);
    d = "";
    for (int i = 0; i < petle; i++) {
        while ((b = getchar()) != '\n') {
            tab[e] = b;
            e++;
        }
        tab[e] = '\0';
        e = 0;
        sscanf_s(tab, "%s %s %d", str, sizeof(str), str1, sizeof(str1), &s3);
        int s1 = miasta->Szukaj(str);
        int s2 = miasta->Szukaj(str1);
        g->Dijkstra(s1, s2, s3, miasta2);
    }
    

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < y; i++) {
        delete[] mapa[i];
    }
    delete[] mapa;
    return 1;
}