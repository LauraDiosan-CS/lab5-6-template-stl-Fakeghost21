#include "repo.h"
#include <iostream>
#include "testeRepo.h"
#include "UI.h"
#include "repoFisiere.h"
#include "bani.h"

int main()
{	
	testeEntitate();
	testeRepo();
	service();
	//test_repoST_accounts();
	//RepoSTL r("TestTonomatIn.txt", "TestTonomatOut.txt");
	//Tonomat t3("2h3208#", "Telefon", 2300);
	//r.addTonomat(t3);
	Repo<Prajitura> r("TestTonomatIn.txt");
	Repo<Monede> m("Monede.txt");
	Service s(r,m);
	UI ui(s);
	ui.runUI();
	//Prajitura p(1000, "bar", "cartofi rosii spanac", 12.56);
	//Prajitura p2(100, "barul", "cartofile rosii spanac", 12.566);
	//r.addPrajitura(p);
	//r.addPrajitura(p2);
	//cout << "da";


	return 0;
}