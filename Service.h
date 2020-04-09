#pragma once
#include "repo.h"
#include "repoFisiere.h"
#include "bani.h"

class Service {
private:
	Repo<Prajitura> r;
	Repo<Monede> m;
public:
	Service();
	Service(Repo<Prajitura>& r, Repo<Monede>& m);
	~Service();

	void setRepo(Repo<Prajitura> r,Repo<Monede> m);

	void addPrajitura(int id, const string nume,const string ingrediente, double pret);
	vector<Prajitura> getAllCandy();

	Prajitura getPrajituraAtPosition(int pos);
	Prajitura getPrajituraById(int id);
	void updatePrajituraById(int id,const string newName, const string newIngrediente,double newPret);
	void deletePrajituraById(int id);
	void deletePrajituraByPosition(int pos);
		
	vector<Monede> getAllMonede();

};