#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <map>



using namespace std;

template <class T>
class Node
{
private:
	T elem;
	bool presente;

public:
	Node();
	~Node();
	T getElem();
	bool getPresente();
	void setPresente(bool palabra);
	void setElem(T Elem);

};

template<class T>
Node<T>::Node()
{
	this->elem = NULL;
	this->presente = false;
}

template<class T>
Node<T>::~Node()
{
}



template<class T>
T Node<T>::getElem()
{
	return elem;
}

template<class T>
bool Node<T>::getPresente()
{
	return presente;
}

template<class T>
void Node<T>::setPresente(bool palabra)
{
	presente = palabra;
}

template<class T>
void Node<T>::setElem(T elem)
{
	this->elem = elem;
}


