#pragma once
#include "tonomat.h"
#include <vector>
#include "Vector.h"



class RepoSTL {
private:
	Vector<Prajitura> prajituri;
	char* fileNameIn;
	char* fileNameOut;
public:
	RepoSTL();
	RepoSTL(const char* fileNameIn, const char* fileNameOut);
	~RepoSTL();

	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameIOut);

	void addPrajitura(Prajitura p);
	Vector<Prajitura> getAll();
	void updatePrajitura(Prajitura& oldPrajitura, Prajitura& newPrajitura);
	void deletePrajitura(int pos);
	int getSize();
	Prajitura getPosPrajitura(int pos);
	void loadFromFile();
	void saveToFile();
};