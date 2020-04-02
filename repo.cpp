#include "repo.h"
#include <fstream>
#include <string.h>
using namespace std;

RepoSTL::RepoSTL() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

RepoSTL::RepoSTL(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->loadFromFile();
}

void RepoSTL::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void RepoSTL::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

void RepoSTL::addPrajitura(Prajitura t) 
{
	this->prajituri.addElem(t);
	this->saveToFile();
}

Vector<Prajitura> RepoSTL::getAll() 
{
	return this->prajituri.getAll;
}

int RepoSTL::getSize()
{
	return this->prajituri.getSize();
}

Prajitura RepoSTL::getPosPrajitura(int pos)
{
	if (pos < 0 or pos > this->prajituri.getSize() - 1)
	{
		string emptyName = "";
		string emptyIngrediente = "";
		return Prajitura(0,emptyName,emptyIngrediente,0);
	}
	return this->prajituri.getElemPos(pos);
}

void RepoSTL::updatePrajitura(Prajitura& oldPrajitura, Prajitura& newPrajitura)
{
	for (int i = 0; i < this->prajituri.getSize(); i++)
	{
		if (this->prajituri.getElemPos(i) == oldPrajitura)
		{
			this->prajituri.getElemPos(i) = newPrajitura;
		}
	}

	this->saveToFile();
}

void RepoSTL::deletePrajitura(int pos)
{
	this->prajituri.getElemPos(pos);
	this->saveToFile();
}

void RepoSTL::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->prajituri.getAll();
		ifstream f(this->fileNameIn);
		string nume, ingrediente;
		int id;
		double pret;
		while (!f.eof())
		{
			f >> id >> nume >> ingrediente >> pret;
			if (size(nume) > 0 and size(ingrediente) > 0)
			{
				this->addPrajitura(Prajitura(id, nume,ingrediente , pret));
			}
		}
		f.close();
	}
}

void RepoSTL::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (int i = 0; i < this->prajituri.getSize(); i++)
		{
			f << this->prajituri.getElemPos(i) << endl;
		}
		f.close();
	}
}
