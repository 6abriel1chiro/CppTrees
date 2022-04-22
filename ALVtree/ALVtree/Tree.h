#pragma once
#include "Node.h"

template <class T>
class Tree
{
private:
	Node<T>* raiz;
public:
	Tree();
	~Tree();

	void RotarDerechaSimple(Node<T>*& A);
	void RotarIzquierdaSimple(Node<T>*& A);

	void RotarDerechaCompuesto(Node<T>*& A);
	void RotarIzquierdaCompuesto(Node<T>*& A);

	bool insertar(T elem, Node<T>*& A, bool& continuar);
	void insertar(T elem);

	void mostrarInOrder();
	void mostrarInOrder(Node<T>* A);

	void mostrarPostOrder();
	void mostrarPostOrder(Node<T>* A);

	void mostrarPreOrder();
	void mostrarPreOrder(Node<T>* A);

	int Contar();
	void Contar(Node<T>* A, int& num);

	int Altura();
	int Altura(Node<T>* A);

	bool Buscar(T elem);
	void Buscar(T elem, Node<T>* A, bool& encontrado);

};

template<class T>
Tree<T>::Tree()
{
	raiz = NULL;
}

template<class T>
Tree<T>::~Tree()
{
}

template<class T>
void Tree<T>::RotarDerechaSimple(Node<T>*& A)
{
	Node<T>* newRoot = A->getIzquierda();
	Node<T>* flotante;

	if (newRoot->getDerecha() != NULL)
	{
		flotante = newRoot->getDerecha();
	}
	else
	{
		flotante = NULL;
	}	
	newRoot->setDerecha(A);
	A->setIzquierda(flotante);
	A = newRoot;
	A->setFactor(0);
	A->getDerecha()->setFactor(0);
}

template<class T>
void Tree<T>::RotarIzquierdaSimple(Node<T>*& A)
{
	Node<T>* newRoot = A->getDerecha();
	Node<T>* flotante;

	if (newRoot->getIzquierda() != NULL)
	{
		flotante = newRoot->getIzquierda();
	}
	else
	{
		flotante = NULL;
	}
	newRoot->setIzquierda(A);
	A->setDerecha(flotante);
	A = newRoot;
	A->setFactor(0);
	A->getIzquierda()->setFactor(0);
}

template<class T>
void Tree<T>::RotarDerechaCompuesto(Node<T>*& A)
{
	Node<T>* newRoot = A->getIzquierda()->getDerecha();
	Node<T>* newRootLeft = newRoot->getIzquierda();
	Node<T>* newRootRight = newRoot->getDerecha();

	newRoot->setIzquierda(A->getIzquierda());
	newRoot->setDerecha(A);

	A = newRoot;
	if (A->getFactor() == 0)
	{
		A->getIzquierda()->setFactor(0);
		A->getDerecha()->setFactor(0);
	}
		if (A->getFactor() == 1)
		{
			A->getIzquierda()->setFactor(0);
			A->getDerecha()->setFactor(-1);
			A->setFactor(0);
		}
		if (A->getFactor() == -1)
		{
			A->getIzquierda()->setFactor(1);
			A->getDerecha()->setFactor(0);
			A->setFactor(0);
		}
			A->getIzquierda()->setDerecha(newRootLeft);
	A->getDerecha()->setIzquierda(newRootRight);
	
}

template<class T>
void Tree<T>::RotarIzquierdaCompuesto(Node<T>*& A)
{
	Node<T>* newRoot = A->getDerecha()->getIzquierda();
	Node<T>* newRootLeft = newRoot->getIzquierda();
	Node<T>* newRootRight = newRoot->getDerecha();

	newRoot->setDerecha(A->getDerecha());
	newRoot->setIzquierda(A);

	A = newRoot;
	if (A->getFactor() == 0)
	{
		A->getIzquierda()->setFactor(0);
		A->getDerecha()->setFactor(0);
	}
		if (A->getFactor() == 1)
		{
			A->getIzquierda()->setFactor(0);
			A->getDerecha()->setFactor(-1);
			A->setFactor(0);
		}
		if (A->getFactor() == -1)
		{
			A->getIzquierda()->setFactor(1);
			A->getDerecha()->setFactor(0);
			A->setFactor(0);
		}
		A->getDerecha()->setIzquierda(newRootRight);
	   A->getIzquierda()->setDerecha(newRootLeft);
	   
}

template<class T>
bool Tree<T>::insertar(T elem, Node<T>*& A, bool& continuar)
{
	if (A == NULL)
	{
		A = new Node<T>;
		A->setDato(elem);
		continuar = true;
	}
	else
	{
		if (elem < A->getDato())
		{
			insertar(elem, A->getIzquierda(), continuar);
			if (continuar == true)
			{
				A->setFactor(A->getFactor() + 1);
				if (A->getFactor() == 0)
				{
					continuar = false;
				}
				else
				{
					if (A->getFactor() == 2)
					{
						continuar = false;
						if (A->getIzquierda()->getFactor() == 1)
						{
							RotarDerechaSimple(A);
						}
						else
						{
							RotarDerechaCompuesto(A);
						}
					}
				}
			}
		}
		if (elem > A->getDato())
		{
			insertar(elem, A->getDerecha(), continuar);
			if (continuar == true)
			{
				A->setFactor(A->getFactor() - 1);
				if (A->getFactor() == 0)
				{
					continuar = false;
				}
				else
				{
					if (A->getFactor() == -2)
					{
						continuar = false;
						if (A->getDerecha()->getFactor() == -1)
						{
							RotarIzquierdaSimple(A);
						}
						else
						{
							RotarIzquierdaCompuesto(A);
						}
					}
				}
			}
		}
		if (elem == A->getDato())
			A->setCounter();

	}
	return continuar;
}

template<class T>
void Tree<T>::insertar(T elem)
{
	bool continuar = true;
	insertar(elem, raiz, continuar);
}


template<class T>
void Tree<T>::mostrarInOrder()
{
	mostrarInOrder(raiz);
	cout << endl;
}

template<class T>
void Tree<T>::mostrarPostOrder()
{
	mostrarPostOrder(raiz);
	cout << endl;
}

template<class T>
void Tree<T>::mostrarPreOrder()
{
	mostrarPreOrder(raiz);
	cout << endl;
}

template<class T>
void Tree<T>::mostrarInOrder(Node<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		mostrarInOrder(A->getIzquierda());
		cout << A->getDato() << " -> factor :  " << A->getFactor()<< " -> repeticiones :  " << A->getCounter()<< endl;
		mostrarInOrder(A->getDerecha());
	}
}

template<class T>
void Tree<T>::mostrarPostOrder(Node<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		mostrarPostOrder(A->getIzquierda());
		mostrarPostOrder(A->getDerecha());
		cout << A->getDato() <<" -> factor :  " << A->getFactor() << endl;
	}
}

template<class T>
void Tree<T>::mostrarPreOrder(Node<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		cout << A->getDato() << " -> factor :  " << A->getFactor() << endl;
		mostrarPreOrder(A->getIzquierda());
		mostrarPreOrder(A->getDerecha());
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
void Tree<T>::Contar(Node<T>* A, int& num)
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
int Tree<T>::Altura(Node<T>* A)
{
	if (A == NULL)
	{
		return 0;
	}
	else
	{
		if (Altura(A->getIzquierda()) > Altura(A->getDerecha()))
		{
			return Altura(A->getIzquierda()) + 1;
		}
		else
		{
			return Altura(A->getDerecha()) + 1;
		}
	}
}

template<class T>
int Tree<T>::Altura()
{
	int num = 0;
	num = Altura(raiz);
	return num;
}

template<class T>
bool Tree<T>::Buscar(T dato)
{
	bool encontrado = false;
	Buscar(dato, raiz, encontrado);
	return encontrado;
}

template<class T>
void Tree<T>::Buscar(T dato, Node<T>* A, bool& encontrado)
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
			cout << A->getDato();
		}
		Buscar(dato, A->getIzquierda(), encontrado);
		Buscar(dato, A->getDerecha(), encontrado);
	}
}

