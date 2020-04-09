
#include "testeRepo.h"
#include "tonomat.h"
#include "repoFisiere.h"
#include "Service.h"
#include "bani.h"
#include <string.h>
#include <cassert>
#include <iostream>
#include <vector>

void addGet()
{
	char* code1 = new char[10];
	char* code2 = new char[10];
	char* name1 = new char[20];
	char* name2 = new char[20];
	Prajitura p1(1, "Bananaiada", "Banane,crema de branza;",12.99);
	Prajitura p2(2, "Tiramisu","Cacao,frisca,mascarpone;",11.50);
	assert(p1.getPret() == 12.99);
	assert(p2.getId() == 2);
	assert(p1.getNume() == "Bananaiada");
	assert(p2.getNume() == "Tiramisu");
}

void addSet()
{
	char* code1 = new char[10];
	char* code2 = new char[10];
	char* name1 = new char[20];
	char* name2 = new char[20];
	float nr2 = 2.3;
	Prajitura p1(1, "Bananaiada", "Banane,crema de branza;", 12.99);
	Prajitura p2(2, "Tiramisu", "Cacao,frisca,mascarpone;", 11.50);
	p1.setPret(3.3);
	p2.setId(100);
	p2.setNume("Broscuta");
	p2.setPret(20.45);
	assert(p1.getPret() == 3.3);
}

void testeEntitate()
{
	addGet();
	addSet();
	cout << "Tests Products are OK!\n";
}

void testRepo()
{
	char* code1 = new char[10];
	char* code2 = new char[10];
	char* name1 = new char[20];
	char* name2 = new char[20];
	float nr2 = 2.3;
	Prajitura p1(1, "Bananaiada", "Banane,crema de branza;", 12.99);
	Prajitura p2(2, "Tiramisu", "Cacao,frisca,mascarpone;", 11.50);
	Prajitura p3(3, "Bananaia", "Banane,crema de branza;", 12.0);
	Prajitura p4(4, "Tiramisul", "Cacao,frisca,mascarpone;", 11.51);
	Prajitura p5(5, "Bananaiadaaa", "Banane,crema de branza;", 12.998);
	Prajitura p6(6, "Tiramisule", "Cacao,frisca,mascarpone;", 11.56);
	Repo<Prajitura> r("TesteRepo.txt");
	assert(r.getSize() == 0);
	r.addPrajitura(p1);
	r.addPrajitura(p2);
	r.addPrajitura(p3);
	r.addPrajitura(p4);
	r.addPrajitura(p5);
	r.addPrajitura(p6);
	vector<Prajitura> v = r.getAll();
	assert(v.size() == 6);
	for(int i = 0;i<r.getSize();i++)
		assert(r.getPosPrajitura(i) == r.getAll()[i]);
	Prajitura pNew(10, "Clatite", "Frisca,banane,ciocolata,faina,lapte", 12.99);
	assert(r.getPosPrajitura(0) == p1);
	r.updatePrajitura(p1, pNew);
	assert(r.getPosPrajitura(0) == pNew);
	r.deletePrajitura(pNew);
	assert(r.getSize() == 5);
	assert(r.getAll()[0] == p2);
	r.deletePrajitura(p5);
	r.deletePrajitura(p6);
	assert(r.getSize() == 3);
	v = r.getAll();
	assert(v.size() == 3);
	for (int i = 0; i < r.getSize(); i++)
		assert(v[i] == r.getAll()[i]);
	remove("TesteRepo.txt");

}

void testeRepo()
{
	testRepo();
	cout << "Merg testele la repo!\n";
}

void testService()
{	
	Repo<Prajitura> r("TesteServicePraji.txt");
	Repo<Monede> m("TesteServiceBani.txt");
	Service s(r,m);
	char* code1 = new char[10];
	char* code2 = new char[10];
	char* name1 = new char[20];
	char* name2 = new char[20];
	float nr2 = 2.3;
	Prajitura p1(1, "Clatite", "Banane,crema de branza;", 11.99);
	Prajitura p2(2, "Tort", "Cacao,frisca,mascarpone;", 10.50);
	Prajitura p3(3, "Tort", "Banane,crema de branza;", 10.0);
	Prajitura p4(4, "Clatite", "Cacao,frisca,mascarpone;", 21.51);
	Prajitura p5(5, "LavaCake", "Ciocolata,faina", 12.99);
	Prajitura p6(6, "Tiramisu", "Cacao,frisca,mascarpone;", 11.56);
	vector<Prajitura> v = s.getAllCandy();
	assert(v.size() == 0);
	s.addPrajitura(p1.getId(),p1.getNume(),p1.getIngrediente(),p1.getPret());
	s.addPrajitura(p2.getId(), p2.getNume(), p2.getIngrediente(), p2.getPret());
	s.addPrajitura(p3.getId(), p3.getNume(), p3.getIngrediente(), p3.getPret());
	s.addPrajitura(p4.getId(), p4.getNume(), p4.getIngrediente(), p4.getPret());
	s.addPrajitura(p5.getId(), p5.getNume(), p5.getIngrediente(), p5.getPret());
	s.addPrajitura(p6.getId(), p6.getNume(), p6.getIngrediente(), p6.getPret());
	v = s.getAllCandy();
	assert(v.size() == 6);
	for (int i = 0; i < 6; i++)
		assert(s.getPrajituraAtPosition(i) == s.getAllCandy()[i]);
	Prajitura pNew(5, "Inghetata", "Frisca,lapte,gheata,ciocolata", 21.9);
	s.updatePrajituraById(5, "Inghetata", "Frisca,lapte,gheata,ciocolata", 21.9);
	assert(s.getPrajituraById(5) == pNew);
	assert(s.getPrajituraAtPosition(4) == pNew);
	s.deletePrajituraById(5);
	assert(s.getPrajituraAtPosition(4) == p6);
	v = s.getAllCandy();
	assert(v.size() == 5);
	s.deletePrajituraByPosition(4);
	v = s.getAllCandy();
	for (int i = 0; i < v.size(); i++)
		assert(!(s.getPrajituraAtPosition(i) == p6));
	remove("TesteService.txt");
	vector <Monede> mon = s.getAllMonede();
	assert(mon.size() == 7);

}

void service()
{
	testService();
	cout << "Merg testele la service!\n";
}
