#pragma once
#include "Node.h"

template <class T>
class AVLtree
{
private:
	Node<T>* raiz;
public:
	AVLtree();
	~AVLtree();

	void RotarDerechaSimple(Node<T>*& A);
	void RotarIzquierdaSimple(Node<T>*& A);

	void RotarDerechaCompuesto(Node<T>*& A);
	void RotarIzquierdaCompuesto(Node<T>*& A);

	void insertar(T elem, Node<T>*& A, bool& continuar);
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

	bool Buscar2(T elem);
	bool Buscar2(Node<T>* A, T elem);
};

template<class T>
AVLtree<T>::AVLtree()
{
	raiz = NULL;
}

template<class T>
AVLtree<T>::~AVLtree()
{
}

template<class T>
void AVLtree<T>::RotarDerechaSimple(Node<T>*& A)
{
	Node<T>* aux = A->getIzquierda();
	Node<T>* temp;
	if (aux->getDerecha() != NULL)
	{
		temp = aux->getDerecha();
	}
	else
	{
		temp = NULL;
	}	
	aux->setDerecha(A);
	A->setIzquierda(temp);
	A = aux;
	A->setFactor(0);
	A->getDerecha()->setFactor(0);
}

template<class T>
void AVLtree<T>::RotarIzquierdaSimple(Node<T>*& A)
{
	Node<T>* aux = A->getDerecha();
	Node<T>* temp;
	if (aux->getIzquierda() != NULL)
	{
		temp = aux->getIzquierda();
	}
	else
	{
		temp = NULL;
	}
	aux->setIzquierda(A);
	A->setDerecha(temp);
	A = aux;
	A->setFactor(0);
	A->getIzquierda()->setFactor(0);
}

template<class T>
void AVLtree<T>::RotarDerechaCompuesto(Node<T>*& A)
{
	Node<T>* NuevaRaiz = A->getIzquierda()->getDerecha();
	Node<T>* tempI = NuevaRaiz->getIzquierda();
	Node<T>* tempD = NuevaRaiz->getDerecha();
	NuevaRaiz->setIzquierda(A->getIzquierda());
	NuevaRaiz->setDerecha(A);
	NuevaRaiz->getDerecha()->setIzquierda(tempD);
	NuevaRaiz->getIzquierda()->setDerecha(tempI);
	A = NuevaRaiz;
	if (A->getFactor() == 0)
	{
		A->getIzquierda()->setFactor(0);
		A->getDerecha()->setFactor(0);
	}
	else
	{
		if (A->getFactor() == 1)
		{
			A->getIzquierda()->setFactor(0);
			A->getDerecha()->setFactor(-1);
			A->setFactor(0);
		}
		else
		{
			A->getIzquierda()->setFactor(1);
			A->getDerecha()->setFactor(0);
			A->setFactor(0);
		}
	}
}

template<class T>
void AVLtree<T>::RotarIzquierdaCompuesto(Node<T>*& A)
{
	Node<T>* NuevaRaiz = A->getDerecha()->getIzquierda();
	Node<T>* tempI = NuevaRaiz->getIzquierda();
	Node<T>* tempD = NuevaRaiz->getDerecha();
	NuevaRaiz->setDerecha(A->getDerecha());
	NuevaRaiz->setIzquierda(A);
	NuevaRaiz->getIzquierda()->setDerecha(tempI);
	NuevaRaiz->getDerecha()->setIzquierda(tempD);
	A = NuevaRaiz;
	if (A->getFactor() == 0)
	{
		A->getIzquierda()->setFactor(0);
		A->getDerecha()->setFactor(0);
	}
	else
	{
		if (A->getFactor() == 1)
		{
			A->getIzquierda()->setFactor(0);
			A->getDerecha()->setFactor(-1);
			A->setFactor(0);
		}
		else
		{
			A->getIzquierda()->setFactor(1);
			A->getDerecha()->setFactor(0);
			A->setFactor(0);
		}
	}
}

template<class T>
void AVLtree<T>::insertar(T elem, Node<T>*& A, bool& continuar)
{
	if (A == NULL)
	{
		A = new Node<T>();
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
	}
}

template<class T>
void AVLtree<T>::insertar(T elem)
{
	bool continuar = true;
	insertar(elem, raiz, continuar);
}


template<class T>
void AVLtree<T>::mostrarInOrder()
{
	mostrarInOrder(raiz);
	cout << endl;
}

template<class T>
void AVLtree<T>::mostrarPostOrder()
{
	mostrarPostOrder(raiz);
	cout << endl;
}

template<class T>
void AVLtree<T>::mostrarPreOrder()
{
	mostrarPreOrder(raiz);
	cout << endl;
}

template<class T>
void AVLtree<T>::mostrarInOrder(Node<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		mostrarInOrder(A->getIzquierda());
		cout << A->getDato() << ", " << A->getFactor() << endl;
		mostrarInOrder(A->getDerecha());
	}
}

template<class T>
void AVLtree<T>::mostrarPostOrder(Node<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		mostrarPostOrder(A->getIzquierda());
		mostrarPostOrder(A->getDerecha());
		cout << A->getDato() << ", " << A->getFactor() << endl;
	}
}

template<class T>
void AVLtree<T>::mostrarPreOrder(Node<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		cout << A->getDato() << ", " << A->getFactor() << endl;
		mostrarPreOrder(A->getIzquierda());
		mostrarPreOrder(A->getDerecha());
	}
}

template<class T>
int AVLtree<T>::Contar()
{
	int num = 0;
	Contar(raiz, num);
	return num;
}

template<class T>
void AVLtree<T>::Contar(Node<T>* A, int& num)
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
int AVLtree<T>::Altura(Node<T>* A)
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
int AVLtree<T>::Altura()
{
	int num = 0;
	num = Altura(raiz);
	return num;
}

template<class T>
bool AVLtree<T>::Buscar(T dato)
{
	bool encontrado = false;
	Buscar(dato, raiz, encontrado);
	return encontrado;
}

template<class T>
void AVLtree<T>::Buscar(T dato, Node<T>* A, bool& encontrado)
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

template<class T>
bool AVLtree<T>::Buscar2(T dato)
{
	bool encontrado = false;
	encontrado = Buscar2(raiz,dato);
	return encontrado;
}

template<class T>
bool AVLtree<T>::Buscar2(Node<T>* A, T elementoBuscar)
{
	if (A == NULL)
	{
		return false;
	}
	else if (A->getDato() == elementoBuscar)
	{
		cout << A->getDato();
		return true;
	}
	else if (elementoBuscar < A->getDato())
	{
		return Buscar2(A->getIzquierda(), elementoBuscar);
	}
	else
	{
		return Buscar2(A->getDerecha(), elementoBuscar);
	}
}