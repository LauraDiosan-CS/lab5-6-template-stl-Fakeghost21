
#pragma once
#include "tonomat.h"
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
#include "repo.h"
using namespace std;
template <class T>
class Repo : public RepoSTL<T>
{
private:
	char* fileNameIn;
public:
	Repo();
	Repo(const char* fileNameIn);
	~Repo();

	void setFileNameIn(const char* fileNameIn);
	void addPrajitura(T p);
	vector<T> getAll();
	void updatePrajitura(T& oldPrajitura, T& newPrajitura);
	void deletePrajitura(T&);
	int getSize();
	T getPosPrajitura(int pos);
	void loadFromFile();
	void saveToFile();

};

template<class T>
inline Repo<T>::Repo()
{
	this->fileNameIn = NULL;
}

template<class T>
inline Repo<T>::Repo(const char* fileNameIn)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->loadFromFile();
}

template<class T>
inline Repo<T>::~Repo()
{

}

template<class T>
inline void Repo<T>::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

template<class T>
inline void Repo<T>::addPrajitura(T p)
{
	RepoSTL<T>::add(p);
	this->saveToFile();
}

template<class T>
inline vector<T> Repo<T>::getAll()
{
	return RepoSTL<T>::getAll();
}

template<class T>
inline void Repo<T>::updatePrajitura(T& oldPrajitura, T& newPrajitura)
{
	RepoSTL<T>::update(oldPrajitura, newPrajitura);
	this->saveToFile();
}

template<class T>
inline void Repo<T>::deletePrajitura(T&p)
{
	RepoSTL<T>::delete_t(p);
	this->saveToFile();
}

template<class T>
inline int Repo<T>::getSize()
{
	return RepoSTL<T>::getSize();
}

template<class T>
inline T Repo<T>::getPosPrajitura(int pos)
{
	return RepoSTL<T>::getPosEntity(pos);
}

template<class T>
inline void Repo<T>::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		RepoSTL<T>::clear();
		ifstream f(this->fileNameIn);
		T element;
		while (f >> element)
		{
				RepoSTL <T>::add(element);
		}
		f.close();
	}
}

template<class T>
inline void Repo<T>::saveToFile()
{
	if (this->fileNameIn != NULL)
	{
		ofstream f(this->fileNameIn);
		int n = this->getSize();
		for (int i = 0; i < n; i++)
		{
			f << this->getAll()[i];
		}
		f.close();
	}
}

