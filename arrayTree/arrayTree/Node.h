#pragma once

#include <iostream>
using namespace std;

template<class T>
class Node
{
private:
	T dato;
	bool exists;
public:
	//Node(T dato);
	Node();
	~Node();
	T getDato();
	bool getExistence();
	void setExistence();
	void setDato(T dato);
};



template<class T>
Node<T>::Node()
{
	dato = NULL;
	exists = false;
}

template<class T>
Node<T>::~Node()
{

}

template<class T>
T Node<T>::getDato()
{
	return dato;
}

template<class T>
bool Node<T>::getExistence()
{
	return exists;
}



template<class T>
void Node<T>::setDato(T dato)
{
	this->dato = dato;
	exists=true;
}

template<class T>
void Node<T>::setExistence()
{
	//exists = true;
}




