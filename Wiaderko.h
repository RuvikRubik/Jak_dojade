#pragma once
class Wiaderko
{
public:
	Wiaderko();
	Wiaderko(int key, int numer) :key(key), numer(numer) {}
	~Wiaderko();
	unsigned long key;
	int numer;
private:
};

Wiaderko::Wiaderko():key(),numer()
{
}

Wiaderko::~Wiaderko()
{
}
