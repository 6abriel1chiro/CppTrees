#pragma once
#include "Tripla.h"

#include <string>
#include <tuple>
#include <math.h>

template<class T>
class Arbol
{
private:
	Tripla<T>* raiz;
public:
	Arbol();
	~Arbol();

	void insertar(T elem);
	void insertar(T elem, Tripla<T> *&A);
	

	bool Buscar(T elem);
	void Buscar(T elem, Tripla<T>* A,bool &encontrado);

	int Menor();
	void Menor(Tripla<T>* A, int &num);

	int Mayor();
	void Mayor(Tripla<T>* A, int& num);

	int Contar();
	void Contar(Tripla<T>* A, int &num);

	int Altura();

	void recorrerInOrder();
	void recorrerPostOrder();
	void recorrerPreOrder();
	void recorrerInOrder(Tripla<T>* A);
	void recorrerPostOrder(Tripla<T>* A);
	void recorrerPreOrder(Tripla<T>* A);

	void mostrarMenoresANumero(int num);
	void mostrarMenoresANumero(Tripla<T>* A, int num);

	void mostrarNivel(int num);
	void mostrarNivel(Tripla<T>* A, int num);
	
	bool eliminar(T elem);
	bool eliminar(T elem, Tripla<T>* A);

	void eliminarArbol();
	void eliminarArbol(Tripla<T>* A);

	tuple<T, bool, bool> siguiente(T elem);
	tuple<T, bool, bool>siguiente(T elem, Tripla<T>* A);

};

template<class T>
Arbol<T>::Arbol()
{
	raiz = NULL;
}

template<class T>
Arbol<T>::~Arbol()
{
	eliminarArbol();
	raiz = NULL;
}


template<class T>
void Arbol<T>::insertar(T elem)
{
	insertar(elem, raiz);
}

template<class T>
void Arbol<T>::insertar(T elem, Tripla<T>* &A)
{
	if (A == NULL)
	{
		A = new Tripla<T>(elem);
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
void Arbol<T>::recorrerInOrder()
{
	recorrerInOrder(raiz);
}

template<class T>
void Arbol<T>::recorrerInOrder(Tripla<T>* A)
{
	if (A != NULL)
	{
		recorrerInOrder(A->getIzquierda());
		cout << A->getDato();
		recorrerInOrder(A->getDerecha());
	}
}

template<class T>
void Arbol<T>::recorrerPostOrder()
{
	recorrerPostOrder(raiz);
}

template<class T>
void Arbol<T>::recorrerPostOrder(Tripla<T>* A)
{
	if (A != NULL)
	{
		recorrerPostOrder(A->getIzquierda());
		recorrerPostOrder(A->getDerecha());
		cout << A->getDato();
	}
}

template<class T>
void Arbol<T>::recorrerPreOrder()
{
	recorrerPreOrder(raiz);
}

template<class T>
void Arbol<T>::recorrerPreOrder(Tripla<T>* A)
{
	if (A != NULL)
	{
		cout << A->getDato();
		recorrerPreOrder(A->getIzquierda());
		recorrerPreOrder(A->getDerecha());
	}
}

template<class T>
bool Arbol<T>::Buscar(T dato)
{
	bool encontrado = false;
	Buscar(dato, raiz,encontrado);
	return encontrado;
}

template<class T>
void Arbol<T>::Buscar(T dato, Tripla<T>* A, bool &encontrado)
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
		}
		Buscar(dato,A->getIzquierda(),encontrado);
		Buscar(dato, A->getDerecha(), encontrado);
	}
}

template<class T>
int Arbol<T>::Menor()
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
void Arbol<T>::Menor(Tripla<T>* A, int &num)
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
int Arbol<T>::Mayor()
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
void Arbol<T>::Mayor(Tripla<T>* A, int& num)
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
int Arbol<T>::Contar()
{
	int num = 0;
	Contar(raiz, num);
	return num;
}

template<class T>
void Arbol<T>::Contar(Tripla<T>* A, int &num)
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
int Arbol<T>::Altura()
{
	int num = 0,tot = 0;
	Contar(raiz, num);
	tot = log(num) + 1;
	return tot+1;
}

template<class T>
void Arbol<T>::mostrarMenoresANumero(int num)
{
	mostrarMenoresANumero(raiz, num);
}

template<class T>
void Arbol<T>::mostrarMenoresANumero(Tripla<T>* A, int num)
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
void Arbol<T>::mostrarNivel(int num)
{
	mostrarNivel(raiz, num);
	cout << endl;
}

template<class T>
void Arbol<T>::mostrarNivel(Tripla<T>* A, int num)
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
bool Arbol<T>::eliminar(T elem)
{
	bool sol;
	sol=eliminar(elem, raiz);
	return sol;
}

template<class T>
bool Arbol<T>::eliminar(T elem, Tripla<T>* A)
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
void Arbol<T>::eliminarArbol()
{
	eliminarArbol(raiz);
}
template<class T>
void Arbol<T>::eliminarArbol(Tripla<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		eliminarArbol(A->getIzquierda());
		eliminarArbol(A->getDerecha());
		delete A;
	}
}

template<class T>
tuple<T, bool, bool> Arbol<T>::siguiente(T elem)
{
	bool res, Enc_Sig;
	T sig;
	tie(sig, res, Enc_Sig)=siguiente(elem, raiz);
	return make_tuple(sig, res, Enc_Sig);
}
template<class T>
tuple<T,bool,bool> Arbol<T>::siguiente(T elem,Tripla<T>* A)
{
	bool res,Enc_Sig;
	T sig;
	int Men;
	if (A == NULL)
	{
		res = false;
	}
	else
	{
		if (elem == A->getDato())
		{
			res = true;
			if (A->getDerecha() == NULL)
			{
				Enc_Sig = false;
			}
			else
			{
				int num;
				num = A->getDerecha()->getDato();
				Menor(A->getDerecha(), num);
				sig = num;
				Enc_Sig = true;
			}
		}
		if (elem > A->getDato())
		{
			tie(sig, res, Enc_Sig) = siguiente(elem,A->getDerecha());
		}
		if (elem < A->getDato())
		{
			tie(sig, res, Enc_Sig) = siguiente(elem, A->getIzquierda());
			if (res == true && Enc_Sig == false)
			{
				Enc_Sig = true;
				sig = A->getDato();
			}
		}
	}
	return make_tuple(sig, res, Enc_Sig);
}