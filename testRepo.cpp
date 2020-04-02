#include "testeRepo.h"
#include "tonomat.h"
#include "repo.h"
#include <string.h>
#include <cassert>
#include <iostream>

void add()
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
	assert(p1.getNume() == "Tiramisu");
}

void set()
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

void test_products()
{
	add();
	set();
	cout << "Tests Products are OK!\n";
}
