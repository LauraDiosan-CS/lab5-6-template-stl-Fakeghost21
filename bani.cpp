#include "bani.h"
#include <string.h>

Monede::Monede()
{
	this->nume = 0.0;
	this->numar = 0;
}

Monede::Monede(float nume,int numar)
{
	this->nume = nume;
	this->numar = numar;
}

Monede::Monede(const Monede& m)
{
	this->nume = m.nume;
	this->numar = m.numar;
}

Monede::~Monede()
{
	this->nume = 0.0;
	this->numar = 0;
}

float Monede::getNume()
{
	return this->nume;
}

int Monede::getNumar()
{
	return this->numar;
}

void Monede::setNume(float nume)
{
	this->nume = nume;
}

void Monede::setNumar(int numar)
{
	this->numar = numar;
}

Monede& Monede::operator=(const Monede& t)
{
	this->setNume(t.nume);
	this->setNumar(t.numar);
	return *this;
}

ostream& operator<<(ostream& os, const Monede& t)
{
	os << t.nume << " " << t.numar << endl;
	return os;
}

istream& operator>>(istream& is, Monede& t)
{
	// TODO: insert return statement here
	is >> t.nume >> t.numar;
	return is;
}

bool Monede::operator==(const Monede& t)
{
	return this->nume == t.nume and this->numar == t.nume;
}
