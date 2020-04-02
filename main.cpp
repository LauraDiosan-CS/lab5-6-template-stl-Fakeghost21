#include "repo.h"
#include "tonomat.h"
#include <iostream>

int main()
{	
	//test_products();
	//test_repoST_accounts();
	//RepoSTL r("TestTonomatIn.txt", "TestTonomatOut.txt");
	//Tonomat t3("2h3208#", "Telefon", 2300);
	//r.addTonomat(t3);
	RepoSTL r("TestTonomatIn.txt", "TestTonomatOut.txt");
	Prajitura p(1000, "barabule", "cartofi rosii spanac", 12.56);
	r.addPrajitura(p);
	cout << "da";
	return 0;
}