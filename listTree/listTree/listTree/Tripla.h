#pragma once

#include <iostream>
using namespace std;

template<class T>
class Tripla
{
private:
	T dato;
	Tripla* siguiente;
	Tripla* anterior;
public:
	Tripla(T dato);
	Tripla();
	~Tripla();
	T getDato();
	void setDato(T dato);
	Tripla<T>*& getDerecha();
	void crearSiguiente(Tripla<T>* dato);
	Tripla<T>*& getIzquierda();
	void crearAnterior(Tripla<T>* dato);
};

template<class T>
Tripla<T>::Tripla(T dato)
{
	this->dato = dato;
	siguiente = NULL;
	anterior = NULL;
}

template<class T>
Tripla<T>::Tripla()
{
	dato = NULL;
	siguiente = NULL;
	anterior = NULL;
}

template<class T>
Tripla<T>::~Tripla()
{

}

template<class T>
T Tripla<T>::getDato()
{
	return dato;
}

template<class T>
void Tripla<T>::setDato(T dato)
{
	this->dato = dato;
}


template<class T>
Tripla<T>*& Tripla<T>::getDerecha()
{
	return siguiente;
}


template<class T>
void Tripla<T>::crearSiguiente(Tripla<T>* nuevoSig)
{
	siguiente = nuevoSig;
}

template<class T>
Tripla<T>*& Tripla<T>::getIzquierda()
{
	return anterior;
}

/*
template<class T>
void Tripla<T>::crearAnterior(T* dato)
{
	anterior = new Tripla<T>(dato);
}*/


template<class T>
void Tripla<T>::crearAnterior(Tripla<T>* nuevoAnt)
{
	anterior = nuevoAnt;
}






