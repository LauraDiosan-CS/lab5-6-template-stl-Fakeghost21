#pragma once
#include <ostream>
#include <istream>
using namespace std;

class Monede {
private:
	float nume;
	int numar;

public:
	Monede();
	Monede(float nume,int numar);
	Monede(const Monede& m);
	~Monede();
	float getNume();
	int getNumar();
	void setNume(float nume);
	void setNumar(int numar);
	Monede& operator=(const Monede& t);
	friend ostream& operator<<(ostream& os, const Monede& t);
	friend istream& operator>>(istream& is, Monede& t);
};