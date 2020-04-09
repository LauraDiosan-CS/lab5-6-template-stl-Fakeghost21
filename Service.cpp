#include "Service.h"

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