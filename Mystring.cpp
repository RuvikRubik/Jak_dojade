#include"Mystring.h"

ostream& operator<<(ostream& os, Mystring str) {
	os << str.napis;
	return os;
}