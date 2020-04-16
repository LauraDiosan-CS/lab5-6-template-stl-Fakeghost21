#pragma once
#include "repo.h"
#include "repoFisiere.h"
#include "bani.h"
#include <map>

class Service {
private:
	RepoSTL<Prajitura>* r;
	RepoSTL<Monede>* m;
public:
	Service();
	Service(RepoSTL<Prajitura>*& r, RepoSTL<Monede>*& m);
	~Service();

	void setRepo(RepoSTL<Prajitura>* r,RepoSTL<Monede>* m);

	void addPrajitura(int id, const string nume,const string ingrediente, double pret);
	vector<Prajitura> getAllCandy();

	Prajitura getPrajituraAtPosition(int pos);
	Prajitura getPrajituraById(int id);
	void updatePrajituraById(int id,const string newName, const string newIngrediente,double newPret);
	void deletePrajituraById(int id);
	void deletePrajituraByPosition(int pos);
		
	vector<Monede> getAllMonede();

	map<string, tuple<double, int>> getAllIngrediente();
	//void getAllIngrediente();
	void afisIngrediente(map<string, tuple<double, int>>);

};