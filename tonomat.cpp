#include "tonomat.h"
#include <string.h>
using namespace std;

Prajitura::Prajitura()
{
	this->id = 0;
	this->pret = 0;
	this->nume = "";
	this->ingrediente = "";
}

Prajitura::Prajitura(int id, string nume, string ingrediente, double pret)
{	
	this->nume = nume;
	this->ingrediente = ingrediente;
	this->pret = pret;
	this->id = id;
}

Prajitura::Prajitura(const Prajitura& t)
{	
	this->nume = t.nume;
	this->ingrediente = t.ingrediente;
	this->pret = t.pret;
	this->id = t.id;
}

Prajitura::~Prajitura()
{	
	this->id = 0;
	this->nume = "";
	this->pret = 0;
	this->ingrediente = "";
}

int Prajitura::getId()
{
	return this->id;
}

string Prajitura::getNume()
{
	return this->nume;
}

string Prajitura::getIngrediente()
{
	return this->ingrediente;
}

double Prajitura::getPret()
{
	return this->pret;
}

void Prajitura::setId(int id)
{
	this->id = id;
}

void Prajitura::setNume(const string nume)
{
	this->nume = nume;
}

void Prajitura::setPret(double pret)
{
	this->pret = pret;
}

void Prajitura::setIngrediente(const string ingrediente)
{
	this->ingrediente = ingrediente;
}

Prajitura& Prajitura::operator=(const Prajitura& t) 
{	
	this->setId(t.id);
	this->setIngrediente(t.ingrediente);
	this->setNume(t.nume);
	this->setPret(t.pret);
	return *this;
}

bool Prajitura::operator==(const Prajitura& t) 
{
	return this->id == t.id && this->nume == t.nume && this->pret == t.pret && this->ingrediente == ingrediente;
}

ostream& operator<<(ostream& os, const Prajitura& t)
{
	os << t.id << " " << t.nume << " " << t.ingrediente<< " " << t.pret << endl;
	return os;
}

istream& operator>>(istream& is, Prajitura& t)
{
	// TODO: insert return statement here
	is >> t.id >> t.nume >> t.ingrediente>> t.pret;
	return is;
}

