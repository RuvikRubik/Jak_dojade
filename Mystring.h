#pragma once
#include <string.h>
#include<iostream>

using namespace std;
class Mystring
{
public:
	Mystring() :size(1)
	{
		napis = new char[1];
		napis[0] = '\0';
	}
	~Mystring(){
	}
	Mystring(const char* other) {
		size = strlen(other) + 1;
		napis = new char[size];
		strcpy_s(napis, size, other);
	}
	friend ostream& operator<<(ostream& os, Mystring str);
	static int stoi(Mystring str) {
		int wynik = 0;
		for (int i = 0; i < str.size - 1; i++) {
			int liczba = str.napis[i] - '0';
			wynik = wynik * 10 + liczba;
		}
		return wynik;
	}
	bool operator==(const char* str) {
		if (size - 1 != strlen(str)) {
			return false;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (napis[i] != str[i]) {
					return false;
				}
			}
			return true;
		}
	}
	char operator[](int index) {
		return napis[index];
	}
	Mystring operator+=(char str) {
		int tempsize = size + 1;
		char* temp = new char[tempsize];
		strcpy_s(temp, tempsize, napis);
		temp[tempsize - 2] = str;
		temp[tempsize - 1] = '\0';
		napis = temp;
		size++;
		return temp;
	}
	void operator=(Mystring str) {
		napis = new char[str.size];
		size = str.size;
		strcpy_s(napis, size, str.napis);
	}
	char* getnapis() {
		return napis;
	}
	int getsize() {
		return size;
	}
private:
	char* napis;
	int size;

};