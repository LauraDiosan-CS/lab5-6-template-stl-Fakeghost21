
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
class RepoFile : public RepoSTL<T>
{
private:
	char* fileNameIn;
public:
	RepoFile();
	RepoFile(const char* fileNameIn);
	~RepoFile();

	void setFileNameIn(const char* fileNameIn);
	void add(T p);
	vector<T> getAll();
	void update(T& oldObj, T& newObj);
	void delete_t(T&);
	int getSize();
	T getPosEntity(int pos);
	void loadFromFile();
	void saveToFile();
	void clear();
};

template<class T>
inline RepoFile<T>::RepoFile()
{
	this->fileNameIn = NULL;
}

template<class T>
inline RepoFile<T>::RepoFile(const char* fileNameIn)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->loadFromFile();
}

template<class T>
inline RepoFile<T>::~RepoFile()
{

}

template<class T>
inline void RepoFile<T>::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

template<class T>
inline void RepoFile<T>::add(T p)
{
	RepoSTL<T>::add(p);
	this->saveToFile();
}

template<class T>
inline vector<T> RepoFile<T>::getAll()
{
	return RepoSTL<T>::getAll();
}

template<class T>
inline void RepoFile<T>::update(T& oldPrajitura, T& newPrajitura)
{
	RepoSTL<T>::update(oldPrajitura, newPrajitura);
	this->saveToFile();
}

template<class T>
inline void RepoFile<T>::delete_t(T&p)
{
	RepoSTL<T>::delete_t(p);
	this->saveToFile();
}

template<class T>
inline int RepoFile<T>::getSize()
{
	return RepoSTL<T>::getSize();
}

template<class T>
inline T RepoFile<T>::getPosEntity(int pos)
{
	return RepoSTL<T>::getPosEntity(pos);
}

template<class T>
inline void RepoFile<T>::loadFromFile()
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
inline void RepoFile<T>::saveToFile()
{
	if (this->fileNameIn != NULL)
	{
		ofstream f(this->fileNameIn);
		int n = RepoSTL<T>::getSize();
		for (int i = 0; i < n; i++)
		{	
			f << RepoSTL<T>::getPosEntity(i);
		}
		f.close();
	}
}

template<class T>
inline void RepoFile<T>::clear()
{
	RepoSTL<T>::clear();
	this->saveToFile();
}

