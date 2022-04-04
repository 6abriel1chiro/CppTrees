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
	bool eliminar(T elem, Node<T>*& A);

	void eliminarTree();
	void eliminarTree(Node<T>* A);


};

template<class T>
Tree<T>::Tree()
{
	raiz = NULL;
}

template<class T>
Tree<T>::~Tree()
{
	eliminarTree();
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
	sol=eliminar(elem, raiz);
	return sol;
}

template<class T>
bool Tree<T>::eliminar(T elem, Node<T>*& A)
{
	bool res = false;
	if (A == NULL)
	{
		return res;
	}
	else
	{
		if (elem < A->getDato())
		{
			res = eliminar(elem, A->getIzquierda());
		}
		if (elem > A->getDato());
		{
			res = eliminar(elem, A->getDerecha());
		}
		if (elem == A->getDato())
		{
			res = true;
			if (A->getIzquierda() == NULL && A->getDerecha() == NULL)
			{
				delete A;
			}
			else
			{
				int num, may, min;
				if (A->getIzquierda() != NULL && A->getDerecha() != NULL)
				{
					num = rand() % 2;
					if (num == 0)
					{
						may = A->getIzquierda()->getDato();
						Mayor(A->getIzquierda(),may);
						T elemento = may;
						A->setDato(elemento);
						res = eliminar(elemento, A->getIzquierda());
					}
					if (num == 1)
					{
						min = A->getDerecha()->getDato();
						Menor(A->getDerecha(), min);
						T elemento = min;
						A->setDato(elemento);
						res = eliminar(elemento, A->getDerecha());
					}
				}
				else
				{
					if (A->getIzquierda() == NULL && A->getDerecha() != NULL) //1 hijo der
					{
						may = A->getDerecha()->getDato();
						Mayor(A->getDerecha(), may);
						T elemento = may;
						A->setDato(elemento);
						res = eliminar(elemento, A->getDerecha());
					}
					else
					{
						min = A->getIzquierda()->getDato();
						Menor(A->getIzquierda(), min);
						T elemento = min;
						A->setDato(elemento);
						res = eliminar(elemento, A->getIzquierda());
					}
				}
			}
		}
	}
	return res;
}

template<class T>
void Tree<T>::eliminarTree()
{
	eliminarTree(raiz);
}
template<class T>
void Tree<T>::eliminarTree(Node<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		eliminarTree(A->getIzquierda());
		eliminarTree(A->getDerecha());
		delete A;
	}
}

