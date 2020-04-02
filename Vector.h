#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <class T, int CAP = 10>
class Vector {
private:
	T elem[CAP];
	int size;
public:
	Vector();
	Vector(const Vector<T, CAP>& v);
	~Vector();
	void addElem(T el);
	void deleteElem(int pos);
	T getAll();
	T getElemPos(int pos);
	void setElemPos(int pos, T el);
	int getSize();
};

//Descr:	create an empty vector
//In:		none
//Out:		an instance of type Vector (without elements)
template <class T, int CAP> Vector<T, CAP>::Vector() {
	this->size = 0;
}

//Descr:	copy constructorr (create a vector)
//In:		another vector
//Out:		an instance of type Vector (with elements from the given vector)
template <class T, int CAP> Vector<T, CAP>::Vector(const Vector<T, CAP>& v) {
	//TO DO
	this->size = v.size;
	for (int i = 0; i < v.size; i++) {
		this->elem[i] = v.elem[i];
	}
}
//Descr:	destroy a vector
//In:		a vector
//Out:		none
template <class T, int CAP> Vector<T, CAP>::~Vector() {
	//TO DO
	this->size = 0;
}
//Descr:	add an elem into a vector
//In:		a vector and an elem
//Out:		the (changed) vector
template <class T, int CAP> void Vector<T, CAP>::addElem(T e) {
	if (this->size < CAP)
		this->elem[this->size++] = e;
	else
		cout << "not enogh space..." << endl;
}
//Descr:	eliminate an element from the vector 
//In:		the vector and a position
//Out:		the vector without the element
template <class T, int CAP> void Vector<T, CAP>::deleteElem(int pos) {
	this->elem[pos] = this->elem[--this->size];
}
//Descr:	access an element from the vector
//In:		the vector and a position
//Out:		the vector's element from the given position
template <class T, int CAP> T Vector<T, CAP>::getElemPos(int pos) {
	return this->elem[pos];
}
//Descr:	change an element from the vector
//In:		the vector, a position and an element
//Out:		the changed vector
template <class T, int CAP>
void Vector<T, CAP>::setElemPos(int pos, T e) {
	this->elem[pos] = e;
}
//Descr:	acces the size of the vector
//In:		the vector
//Out:		the vector's size
template <class T, int CAP> int Vector<T, CAP>::getSize() {
	return this->size;
}

template <class T, int CAP>T Vector<T, CAP>::getAll() {
	//TO DO
	return this->elem;
}

#endif