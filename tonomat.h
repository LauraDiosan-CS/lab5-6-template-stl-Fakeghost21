#pragma once
#include <ostream>
using namespace std;

class Prajitura {
private:
	string nume;
	string ingrediente;
	double pret;
	int id;
public:
	Prajitura();
	Prajitura(int id,string nume,string ingrediente,double pret);
	Prajitura(const Prajitura& t);
	~Prajitura();
	string getNume();
	string getIngrediente();
	int getId();
	double getPret();
	void setId(int id);
	void setNume(const string nume);
	void setPret(double pret);
	void setIngrediente(string ingrediente);
	Prajitura& operator=(const Prajitura& t);
	bool operator==(const Prajitura& t);
	friend ostream& operator<<(ostream& os, const Prajitura& t);
};