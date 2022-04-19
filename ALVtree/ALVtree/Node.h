#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node
{
private:
	T Dato;
	int factor;
	int counter;
	Node<T>* izquierda;
	Node<T>* derecha;
public:
	Node();
	~Node();

	Node<T>*& getIzquierda();
	Node<T>*& getDerecha();

	T getDato();
	int getFactor();

	void setFactor(int n);
	void setDato(T dato);

	void setIzquierda(Node<T>* newizquierda);
	void setDerecha(Node<T>* newderecha);

		int getCounter();

	void setCounter();
};

template<class T>
Node<T>::Node()
{
	this->izquierda = NULL;
	this->derecha = NULL;
	this->factor = 0;
		this->counter = 0;

}


template<class T>
Node<T>::~Node()
{

}

template<class T>
Node<T>*& Node<T>::getIzquierda()
{
	return izquierda;
}

template<class T>
Node<T>*& Node<T>::getDerecha()
{
	return derecha;
}

template<class T>
T Node<T>::getDato()
{
	return Dato;
}

template<class T>
int Node<T>::getFactor()
{
	return factor;
}

template<class T>
void Node<T>::setFactor(int n)
{
	factor = n;
}

template<class T>
void Node<T>::setDato(T dato)
{
	Dato = dato;
	counter=counter+1;
}

template<class T>
void Node<T>::setIzquierda(Node<T>* newizquierda)
{
	izquierda = newizquierda;
}

template<class T>
void Node<T>::setDerecha(Node<T>* newderecha)
{
	derecha = newderecha;
}


template<class T>
int Node<T>::getCounter()
{
	return counter;
}

template<class T>
void Node<T>::setCounter()
{
	counter = counter+1;
}
