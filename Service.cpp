#include "Service.h"
#include <string.h>
#include <utility>


Service::Service()
{
	this->r = new RepoSTL<Prajitura>;
	this->m = new RepoSTL<Monede>;
}

Service::Service(RepoSTL<Prajitura>*& repo,RepoSTL<Monede>*& repo2)
{
	this->r = repo;
	this->m = repo2;
}

Service::~Service()
{
}

void Service::setRepo(RepoSTL<Prajitura>* repo,RepoSTL<Monede>* repo2)
{
	this->r = repo;
	this->m = repo2;
}

void Service::addPrajitura(int id,const string nume,const string ingrediente, double pret)
{
	this->r->add(Prajitura(id,nume,ingrediente,pret));
}

vector<Prajitura> Service::getAllCandy()
{
	return this->r->getAll();
}

Prajitura Service::getPrajituraAtPosition(int pos)
{
	return this->r->getPosEntity(pos);
}

Prajitura Service::getPrajituraById(int id)
{	
	vector<Prajitura> prajituri = this->r->getAll();
	for (int i = 0; i < this->r->getSize(); i++)
	{
		if (prajituri[i].getId() == id)
		{
			return prajituri[i];
		}
	}
}

void Service::updatePrajituraById(int id, const string newName, const string newIngrediente, double newPret)
{
	vector<Prajitura> prajituri = this->r->getAll();
	Prajitura newPrajitura(id,newName,newIngrediente,newPret);
	for (int i = 0; i < this->r->getSize(); i++)
	{
		if (prajituri[i].getId() == id)
		{
			Prajitura oldPrajitura(id,prajituri[i].getNume(), prajituri[i].getIngrediente(), prajituri[i].getPret());
			this->r->update(oldPrajitura, newPrajitura);
			return;
		}
	}
}

void Service::deletePrajituraById(int id)
{
	vector<Prajitura> prajituri = this->r->getAll();
	for (int i = 0; i < this->r->getSize(); i++)
	{
		if (prajituri[i].getId() == id)
		{
			Prajitura prajDel(id, prajituri[i].getNume(), prajituri[i].getIngrediente(), prajituri[i].getPret());
			this->r->delete_t(prajDel);
			return;
		}
	}
}

void Service::deletePrajituraByPosition(int pos)
{
	Prajitura prajDel = this->r->getPosEntity(pos);
	this->r->delete_t(prajDel);
}

vector<Monede> Service::getAllMonede()
{
	return this->m->getAll();
}

map<string,tuple<double,int>> Service::getAllIngrediente()
{
	vector<Prajitura> prajituri = this->r->getAll();
	map <string, tuple<double,int>> m;
	string ingred;
	for (int i = 0; i < this->r->getSize(); i++)
	{
		ingred = prajituri[i].getIngrediente();

		string token, sep = ",";
		size_t pos;
		do {
			pos = ingred.find(sep);
			token = ingred.substr(0, pos);
			if (m.find(token) == m.end())
			{
				double value = prajituri[i].getPret();
				tuple <double, int> t(value, 1);
				m[token] = t;
			}
			else {
				get<0>(m.find(token)->second) += prajituri[i].getPret();
				get<1>(m.find(token)->second)++;
			}
			ingred.erase(0, pos + sep.length());
		} while (pos != string::npos);
	}
	return m;
}

void Service::afisIngrediente(map<string, tuple<double, int>> m)
{
	map<string, tuple<double, int>>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " :: " << get<0>(it->second) / get<1>(it->second)<< endl;
		it++;
	}
}
