#pragma once
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

template <class T>
class Node
{
private:
	T Dato;
	string Color;
	Node<T>* izquierda;
	Node<T>* derecha;
	int counter;


public:
	Node();
	~Node();
	Node<T>*& getIzquierda();
	Node<T>*& getDerecha();
	T getDato();
	string getColor();
	void setColor(string newColor);
	void setDato(T dato);
	void setCounter();
	int getCounter();


	void crearIzquierda(Node<T>* newizquierda);
	void crearDerecha(Node<T>* newderecha);
};

template<class T>
Node<T>::Node()
{
	izquierda = NULL;
	derecha = NULL;
	Color = "";
	counter = 0;
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
string Node<T>::getColor()
{
	return Color;
}

template<class T>
void Node<T>::setColor(string newColor)
{
	Color = newColor;
}

template<class T>
void Node<T>::setDato(T dato)
{
	Dato = dato;
	counter++;
}

template<class T>
void Node<T>::crearIzquierda(Node<T>* newizquierda)
{
	izquierda = newizquierda;
}

template<class T>
void Node<T>::crearDerecha(Node<T>* newderecha)
{
	derecha = newderecha;
}


template<class T>
void Node<T>::setCounter()
{
	counter++;
}

template<class T>
int Node<T>::getCounter()
{
	return counter;
}



