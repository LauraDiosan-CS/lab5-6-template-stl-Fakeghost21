#pragma once
#include "tonomat.h"
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
template <class T>
class RepoSTL {
private:
	vector<T> entity;
	//char* fileNameIn;
public:
	RepoSTL();
	//RepoSTL(const char* fileNameIn);
	~RepoSTL();

	//void setFileNameIn(const char* fileNameIn);
	virtual void clear();
	virtual void add(T p);
	virtual vector<T> getAll();
	virtual void update(T& oldPrajitura, T& newPrajitura);
	virtual void delete_t(T&);
	virtual int getSize();
	virtual T getPosEntity(int pos);
	//void loadFromFile();
	//void saveToFile();

};

template <class T> RepoSTL<T>::RepoSTL() {
	//this->fileNameIn = NULL;
}

template <class T> void RepoSTL<T>::clear()
{
	this->entity.clear();
}

/*
template <class T>RepoSTL<T>::RepoSTL(const char* fileNameIn)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->loadFromFile();
}
*/
template <class T>RepoSTL<T>::~RepoSTL()
{
	this->entity.clear();
}
/*
template <class T> void RepoSTL<T>::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}
*/
template <class T> void RepoSTL<T>::add(T t)
{
	this->entity.push_back(t);
	//this->saveToFile();
}

template <class T> vector<T> RepoSTL<T>::getAll()
{
	return this->entity;
}

template <class T> int RepoSTL<T>::getSize()
{
	return this->entity.size();
}

template <class T> T RepoSTL<T>::getPosEntity(int pos)
{
	return this->entity[pos];
}

template <class T> void RepoSTL<T>::update(T& oldPrajitura, T& newPrajitura)
{
	typename vector<T>::iterator it;

	it = find(this->entity.begin(), this->entity.end(), oldPrajitura);
	if (!(it == this->entity.end()))
	{
		*it = newPrajitura;
	}

	//this->saveToFile();
}

template <class T> void RepoSTL<T>::delete_t(T& p)
{
	typename vector<T>::iterator it;

	it = find(this->entity.begin(), this->entity.end(), p);
	if (!(it == this->entity.end()))
	{
		this->entity.erase(it);
	}
	//this->saveToFile();
}
/*
template <class T> void RepoSTL<T>::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->prajituri.clear();
		ifstream f(this->fileNameIn);
		string nume, ingrediente,token,word;
		int id;
		double pret;
		while (getline(f, token))
		{
			//getline(f, token);
			string sep = " ";
			size_t pos = token.find(sep);
			word = token.substr(0, pos);
			id = stoi(word);
			token.erase(0, pos + sep.length());
			pos = token.find(sep);
			word = token.substr(0, pos);
			nume = word;
			token.erase(0,pos + sep.length());
			pos = token.find(sep);
			word = token.substr(0, pos);
			ingrediente = word;
			token.erase(0, pos + sep.length());
			pos = token.find(sep);
			word = token.substr(0, pos);
			pret = stod(word);
			if (size(nume) > 0 and size(ingrediente) > 0)
			{
				this->addPrajitura(Prajitura(id, nume, ingrediente, pret));
			}
		}
		f.close();
	}
}

template <class T> void RepoSTL<T>::saveToFile()
{
	if (this->fileNameIn != NULL)
	{
		ofstream f(this->fileNameIn);
		for (int i = 0; i < this->prajituri.size(); i++)
		{
			f << this->prajituri[i];
		}
		f.close();
	}
}
*/