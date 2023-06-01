#pragma once
#include <cstddef>
#include<string>
#include"Struktury.h"
#include <iostream>
using namespace std;

template <typename dane>
class Lista
{
public:
	Lista() :Parametry(nullptr), next(nullptr), rozmiar(0) {}
	Lista(dane* temp) : Parametry(temp),next(nullptr),rozmiar(0) {}
	int const Getrozmiar() { return rozmiar; }
	dane* GetHead() {	return Parametry;}
	Lista* getNext() { return next; }
	void AddLast(Lista* temp) {
		Lista* last = GetLast(this);
		if (last == NULL) {
			*this = *temp;
			rozmiar++;
			return;
		}
		rozmiar++;
		last->next = temp;
	};
	Lista* GetLast(Lista* firstNode) {
		if (rozmiar == 0) {
			return NULL;
		}
		Lista* temp = firstNode;
		for (int i = 1; i < rozmiar; i++) {
			temp = temp->next;
		}
		return temp;
	};
	Lista* Find(int docelowy,int waga) {
		Lista* temp = this;
		for (int i = 0; i < rozmiar; i++) {
			if (temp->Parametry->docelowy == docelowy && temp->Parametry->waga == waga) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
	void change(int docelowy, int waga) {
		this->Parametry->docelowy = docelowy;
		this->Parametry->waga = waga;
	}
	~Lista() {}
private:
	dane* Parametry;
	Lista* next;
	int rozmiar;
};