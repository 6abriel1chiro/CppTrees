#pragma once
#include "Node.h"

#include <string>
#include <tuple>
#include <math.h>

template<class T>
class Tree
{
private:
	Node<T>* raiz;
public:
	Tree();
	~Tree();

	void insertar(T elem);
	void insertar(T elem, Node<T> *&A);
	

	bool Buscar(T elem);
	void Buscar(T elem, Node<T>* A,bool &encontrado);

	int Menor();
	void Menor(Node<T>* A, int &num);	
	


	int Mayor();
	void Mayor(Node<T>* A, int& num);

	int Contar();
	void Contar(Node<T>* A, int &num);

	int Altura();

	void recorrerInOrder();
	void recorrerPostOrder();
	void recorrerPreOrder();

	void recorrerInOrder(Node<T>* A);
	void recorrerPostOrder(Node<T>* A);
	void recorrerPreOrder(Node<T>* A);

	void mostrarMenoresANumero(int num);
	void mostrarMenoresANumero(Node<T>* A, int num);

	void mostrarNivel(int num);
	void mostrarNivel(Node<T>* A, int num);
	
	bool eliminar(T elem);
	bool eliminar(Node<T>*& raiz,T dato);

	void eliminarRaiz();
	bool eliminarRaiz(Node<T>* A);

};

template<class T>
Tree<T>::Tree()
{
	raiz = NULL;
}

template<class T>
Tree<T>::~Tree()
{
	eliminarRaiz();
	raiz = NULL;
}


template<class T>
void Tree<T>::insertar(T elem)
{
	insertar(elem, raiz);
}

template<class T>
void Tree<T>::insertar(T elem, Node<T>* &A)
{
	if (A == NULL)
	{
		A = new Node<T>(elem);
	}
	else
	{
		if (elem < A->getDato())
		{
			insertar(elem, A->getIzquierda());
		}
		else
		//else if (elem > A->getDato());
		{
			insertar(elem, A->getDerecha());
		}
	}
}


template<class T>
void Tree<T>::recorrerInOrder()
{
	recorrerInOrder(raiz);
}

template<class T>
void Tree<T>::recorrerInOrder(Node<T>* A)
{
	if (A != NULL)
	{
		recorrerInOrder(A->getIzquierda());
		cout << A->getDato() << " ";
		recorrerInOrder(A->getDerecha());
	}
	cout << endl;
}

template<class T>
void Tree<T>::recorrerPostOrder()
{
	recorrerPostOrder(raiz);
}

template<class T>
void Tree<T>::recorrerPostOrder(Node<T>* A)
{
	if (A != NULL)
	{
		recorrerPostOrder(A->getIzquierda());
		recorrerPostOrder(A->getDerecha());
		cout << A->getDato()<<" ";
	}
	cout << endl;

}

template<class T>
void Tree<T>::recorrerPreOrder()
{
	recorrerPreOrder(raiz);
}

template<class T>
void Tree<T>::recorrerPreOrder(Node<T>* A)
{
	if (A != NULL)
	{
		cout << A->getDato();
		recorrerPreOrder(A->getIzquierda());
		recorrerPreOrder(A->getDerecha());
	}
	cout << endl;

}

template<class T>
bool Tree<T>::Buscar(T dato)
{
	bool encontrado = false;
	Buscar(dato, raiz,encontrado);
	return encontrado;
}

template<class T>
void Tree<T>::Buscar(T dato, Node<T>* A, bool &encontrado)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		if (dato == A->getDato())
		{
			encontrado = true;
			cout << A->getDato()<< " ";
		}
		Buscar(dato,A->getIzquierda(),encontrado);
		Buscar(dato, A->getDerecha(), encontrado);
	}
}

template<class T>
int Tree<T>::Menor()
{
	int num=0;
	if (raiz != NULL)
	{
		num = raiz->getDato();
		Menor(raiz,num);
	}
	return num;
}



template<class T>
void Tree<T>::Menor(Node<T>* A, int &num)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		if (num > A->getDato())
		{
			num = A->getDato();
		}
		Menor(A->getIzquierda(), num);
		Menor(A->getDerecha(), num);
	}
}

template<class T>
int Tree<T>::Mayor()
{
	int num = 0;
	if (raiz != NULL)
	{
		num = raiz->getDato();
		Mayor(raiz, num);
	}
	return num;
}

template<class T>
void Tree<T>::Mayor(Node<T>* A, int& num)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		if (num < A->getDato())
		{
			num = A->getDato();
		}
		Mayor(A->getIzquierda(), num);
		Mayor(A->getDerecha(), num);
	}
}

template<class T>
int Tree<T>::Contar()
{
	int num = 0;
	Contar(raiz, num);
	return num;
}

template<class T>
void Tree<T>::Contar(Node<T>* A, int &num)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		num = num + 1;
		Contar(A->getIzquierda(), num);
		Contar(A->getDerecha(), num);
	}
}

template<class T>
int Tree<T>::Altura()
{
	int num = 0,tot = 0;
	Contar(raiz, num);
	tot = log(num) + 1;
	return tot+1;
}

template<class T>
void Tree<T>::mostrarMenoresANumero(int num)
{
	mostrarMenoresANumero(raiz, num);
}

template<class T>
void Tree<T>::mostrarMenoresANumero(Node<T>* A, int num)
{
	if (A != NULL)
	{
		mostrarMenoresANumero(A->getIzquierda(),num);
		if (num > A->getDato())
		{
			cout << A->getDato();
		}
		mostrarMenoresANumero(A->getDerecha(),num);
	}
}

template<class T>
void Tree<T>::mostrarNivel(int num)
{
	mostrarNivel(raiz, num);
	cout << endl;
}

template<class T>
void Tree<T>::mostrarNivel(Node<T>* A, int num)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		if (num == 1) //mientras no sea ese numero disminuye
		{
			cout << A->getDato() << " ";
		}
		else
		{
			mostrarNivel(A->getIzquierda(), num - 1);
			mostrarNivel(A->getDerecha(), num - 1);
		}
	}
}

template<class T>
bool Tree<T>::eliminar(T elem)
{
	bool sol;
	sol=eliminar(raiz, elem);
	return sol;
}

template<class T>
bool Tree<T>::eliminar(Node<T>*& raiz, T dato)
{
	bool res = true;
	if (raiz == NULL) {
		res = false;
	}
	else if (raiz->getDato() == dato) {
		if (raiz->getIzquierda() != NULL and raiz->getDerecha() != NULL) {
			delete raiz;
		}
		else {
			if (raiz->getDerecha() != NULL) {
				T men = raiz->getIzquierda()->getDato();
				Menor(raiz->getIzquierda(), men);
				men = raiz->getIzquierda()->getDato();
				Menor(raiz->getIzquierda(), men);		
				raiz->setDato(men);
				eliminar(raiz->getDerecha(), men);
			}
			else {
				T may;
				may = raiz->getDerecha()->getDato();
				Mayor(raiz->getDerecha(), may);
				Mayor(raiz->getIzquierda(), may);
				raiz->setDato(may);
				eliminar(raiz->getIzquierda(), may);
			}
		}
	}
	else {
		if (dato > raiz->getDato()) {
			eliminar(raiz->getDerecha(), dato);
		}
		else {
			eliminar(raiz->getIzquierda(), dato);
		}
	}
	return res;
}

template<class T>
void Tree<T>::eliminarRaiz()
{
	eliminarRaiz(raiz);
}
template<class T>
bool Tree<T>::eliminarRaiz(Node<T>* A)
{
	bool res = true;
	if (raiz == NULL) {
		res = false;
		cout << "empty" << endl;
	}
	else {
		if (raiz->getIzquierda() != NULL) {
			T mayor = raiz->getIzquierda()->getDato();
			Mayor(raiz->getIzquierda(),mayor);
			raiz->setDato(mayor);
			eliminar(raiz->getIzquierda(), mayor);
		}
		else {
			if (raiz->getDerecha() != NULL) {
				T menor = raiz->getDerecha()->getDato();
				Menor(raiz->getDerecha(),menor);
				raiz->setDato(menor);
				eliminar(raiz->getDerecha(), menor);
			}
			else {
				delete raiz;
				raiz = NULL;
			}
		}
	}
	return res;
}

