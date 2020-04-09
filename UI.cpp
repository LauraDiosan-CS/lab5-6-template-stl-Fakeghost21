#include "UI.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

UI::UI()
{
}

UI::UI(Service& service)
{
	this->service = service;
}

void UI::displayMenu()
{
	cout << "1.Adauga prajitura : \n"
		<< "2.Afiseaza toate prajiturile : \n"
		<< "3.Sterge o prajitura dupa id : \n"
		<< "4.Update la o prajitura dupa id : \n"
		<< "5.Cantitatea de monede detinuta de aparat cat si suma totala : \n"
		<< "x.Iesire!\n";
}

void UI::AddPrajitura(int id, const string nume, const string ingrediente, double pret)
{
	this->service.addPrajitura(id,nume,ingrediente,pret);
}

void UI::ShowAllCandy()
{
	vector <Prajitura> prajituri = this->service.getAllCandy();
	int size = prajituri.size();
	for (int i = 0; i < size; i++)
	{
		cout << prajituri[i] << "\n";
	}
}

void UI::UpdateByID(int id, const string newName, const string newIngrediente, double newPret)
{
	this->service.updatePrajituraById(id,newName,newIngrediente,newPret);
}

void UI::DeleteByID(int id)
{
	this->service.deletePrajituraById(id);
}

void UI::ShowALLMonede()
{
	vector <Monede> m = this->service.getAllMonede();
	int size = m.size();
	int sum = 0;
	cout << "Moneda | Cantitate"<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << m[i];
		sum += m[i].getNumar() * m[i].getNume();
	}
	cout << "Suma : " << sum << endl;
}

void UI::runUI()
{
	string optiune;
	int id;
	double pret;
	string nume, ingrediente;
	while (true)
	{	
		this->displayMenu();
		cin >> optiune;
		if (optiune == "1")
		{	
			cout << "Id-ul prajiturii : ";
			cin >> id;
			cout << "Numele prajiturii : ";
			cin >> nume;
			cout << "Ingredientele prajiturii : ";
			cin >> ingrediente;
			cout << "Pretul prajiturii : ";
			cin >> pret;
			this->AddPrajitura(id,nume,ingrediente,pret);
		}
		if (optiune == "2")
		{
			this->ShowAllCandy();
		}
		if (optiune == "3")
		{	
			cout << "Id-ul prajiturii pe care doriti sa o stergeti : ";
			cin >> id;
			this->DeleteByID(id);
		}
		if (optiune == "4")
		{
			cout << "Id-ul prajiturii pentru update : ";
			cin >> id;
			cout << "Numele noii prajituri : ";
			cin >> nume;
			cout << "Ingredientele noii prajituri : ";
			cin >> ingrediente;
			cout << "Pretul noii prajituri : ";
			cin >> pret;
			this->UpdateByID(id, nume, ingrediente, pret);
		}
		if (optiune == "5")
		{	
			this->ShowALLMonede();
		}
		if (optiune == "x")
		{
			cout << "Ati iesit din program!\n";
			break;
		}
		else cout << "Optiune invalida!\n";
	}
}