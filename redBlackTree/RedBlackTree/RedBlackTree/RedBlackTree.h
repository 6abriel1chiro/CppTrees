#pragma once
#include "Node.h"

template <class T>
class RBtree
{
private:
	Node<T>* raiz;
public:
	RBtree();
	~RBtree();
	void RotarIzquierda(Node<T>*& A);
	void RotarDerecha(Node<T>*& A);
	void Insertar(T elemento);
	void Insertar(Node<T>*& A, T elem, bool& continuar, bool& paridad, bool& lado);

	void mostrarInOrder();
	void mostrarInOrder(Node<T>* A);

	void mostrarPostOrder();
	void mostrarPostOrder(Node<T>* A);

	void mostrarPreOrder();
	void mostrarPreOrder(Node<T>* A);

	int Contar();
	void Contar(Node<T>* A, int& num);

	int Altura();
	T Buscar(T);
	bool eliminar(T);

	bool revisarRojoNegro();
	void revisarRojoNegro(Node<T>* A, bool& encontrado);

	int ContarNegro();
	void ContarNegro(Node<T>* A, int& num);

	int AlturaNegra();
	int AlturaNegra(Node<T>* A, int& tot);
	int AlturaNegra2();
	int AlturaNegra(Node<T>* A);
};

template<class T>
RBtree<T>::RBtree()
{
	raiz = NULL;
}

template<class T>
RBtree<T>::~RBtree()
{

}

template<class T>
void RBtree<T>::RotarIzquierda(Node<T>*& A)
{
	Node<T>* aux = NULL;
	Node<T>* auxIzquierda = A->getDerecha();
	if (auxIzquierda->getIzquierda() == NULL)
	{
		aux = auxIzquierda->getIzquierda();
	}
	auxIzquierda->crearIzquierda(A);
	A->crearDerecha(aux);
	A = auxIzquierda;
}


template<class T>
void RBtree<T>::RotarDerecha(Node<T>*& A)
{
	Node<T>* aux = NULL;
	Node<T>* auxDerecha = A->getIzquierda();;
	if (auxDerecha->getDerecha() != NULL)
	{
		aux = auxDerecha->getDerecha();
	}
	auxDerecha->crearDerecha(A);
	A->crearIzquierda(aux);
	A = auxDerecha;
}

template<class T>
void RBtree<T>::Insertar(T elem)
{
	bool Continuar, Paridad, Lado; //lado derecho true
	Insertar(raiz, elem, Continuar, Paridad, Lado);
}

template<class T>
void RBtree<T>::Insertar(Node<T>*& A, T elem, bool& conti, bool& pari, bool& lado)
{
	if (A == NULL)
	{
		A = new Node<T>();
		A->setDato(elem);
		A->setColor("Rojo");
		conti = true;
		pari = true;
	}
	else
	{
		if (elem < A->getDato())
		{
			Insertar(A->getIzquierda(), elem, conti, pari, lado);
			if (conti == true)
			{
				if (pari == true)
				{
					if (A->getColor() == "Negro")
					{
						conti = false;
					}
					else
					{
						pari = false;
						lado = false;
					}
				}
				else
				{
					if (pari == false)
					{
						if (A->getDerecha() != NULL && A->getDerecha()->getColor() == "Rojo")
						{
							A->getIzquierda()->setColor("Negro");
							A->getDerecha()->setColor("Negro");
							A->setColor("Rojo");
							pari = true;
						}
						else
						{
							conti = false;
							if (lado == true)
							{
								RotarIzquierda(A->getIzquierda());
							}
							A->getIzquierda()->setColor("Negro");
							A->setColor("Rojo");
							RotarDerecha(A);
						}
					}
				}
			}
		}
		if (elem > A->getDato())
		{
			Insertar(A->getDerecha(), elem, conti, pari, lado);
			if (conti == true)
			{
				if (pari == true)
				{
					if (A->getColor() == "Negro")
					{
						conti = false;
					}
					else
					{
						pari = false;
						lado = true;
					}
				}
				else
				{
					if (pari == false)
					{
						if (A->getIzquierda() != NULL && A->getIzquierda()->getColor() == "Rojo")
						{
							A->getIzquierda()->setColor("Negro");
							A->getDerecha()->setColor("Negro");
							A->setColor("Rojo");
							pari = true;
						}
						else
						{
							conti = false;
							if (lado == false)
							{
								RotarDerecha(A->getDerecha());
							}
							A->getDerecha()->setColor("Negro");
							A->setColor("Rojo");
							RotarIzquierda(A);
						}
					}
				}
			}
		}
	}
}

template<class T>
void RBtree<T>::mostrarInOrder()
{
	mostrarInOrder(raiz);
	cout << endl;
}

template<class T>
void RBtree<T>::mostrarPostOrder()
{
	mostrarPostOrder(raiz);
	cout << endl;
}

template<class T>
void RBtree<T>::mostrarPreOrder()
{
	mostrarPreOrder(raiz);
	cout << endl;
}

template<class T>
void RBtree<T>::mostrarInOrder(Node<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		mostrarInOrder(A->getIzquierda());
		cout << A->getDato() << ", " << A->getColor() <<endl;
		mostrarInOrder(A->getDerecha());
	}
}

template<class T>
void RBtree<T>::mostrarPostOrder(Node<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		mostrarPostOrder(A->getIzquierda());
		mostrarPostOrder(A->getDerecha());
		cout << A->getDato() << ", " << A->getColor() <<endl;
	}
}

template<class T>
void RBtree<T>::mostrarPreOrder(Node<T>* A)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		cout << A->getDato() << ", " << A->getColor() <<endl;
		mostrarPreOrder(A->getIzquierda());
		mostrarPreOrder(A->getDerecha());
	}
}

template<class T>
int RBtree<T>::Contar()
{
	int num = 0;
	Contar(raiz, num);
	return num;
}

template<class T>
void RBtree<T>::Contar(Node<T>* A, int& num)
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
int RBtree<T>::Altura()
{
	int num = 0, tot = 0;
	Contar(raiz, num);
	tot = log(num) + 1;
	return tot + 1;
}

template<class T>
inline T RBtree<T>::Buscar(T)
{
	return T();
}

template<class T>
inline bool RBtree<T>::eliminar(T)
{
	return false;
}

template<class T>
bool RBtree<T>::revisarRojoNegro()
{
	bool correcto=false;
	revisarRojoNegro(raiz,correcto);
	return correcto;
}

template<class T>
void RBtree<T>::revisarRojoNegro(Node<T>* A, bool& res)
{
	bool res1;
	bool res2;
	bool resIzq = false;
	bool resDer = false;
	if (A == NULL)
	{
		return;
	}
	else
	{
		if (A->getColor() == "Rojo")
		{
			if (A->getDerecha() != NULL)
			{
				if (A->getDerecha()->getColor() == "Negro")
				{
					resDer = true;
				}
			}
			else
			{
				resDer = true;
			}
			if (A->getIzquierda() != NULL)
			{
				if (A->getIzquierda()->getColor() == "Negro")
				{
					resIzq = true;
				}
			}
			else
			{
				resIzq = true;
			}
			if (resDer == true && resIzq == true)
			{
				res1 = true;
				res2 = true;
				res = true;
			}
		}
		revisarRojoNegro(A->getDerecha(),res1);
		revisarRojoNegro(A->getIzquierda(),res2);
	}
	if (res1 == false || res2 == false)
	{
		res = false;
	}
}

template<class T>
int RBtree<T>::ContarNegro()
{
	int num = 0;
	ContarNegro(raiz, num);
	return num;
}

template<class T>
void RBtree<T>::ContarNegro(Node<T>* A, int& num)
{
	if (A == NULL)
	{
		return;
	}
	else
	{
		if (A->getColor() == "Negro")
		{
			num = num + 1;
		}
		ContarNegro(A->getIzquierda(), num);
		ContarNegro(A->getDerecha(), num);
	}
}



template<class T>
int RBtree<T>::AlturaNegra(Node<T>* A, int &tot)
{
	if (A == NULL)
	{
		return 0;
	}
	else
	{
		if (A->getIzquierda() > A->getDerecha())
		{
			if (A->getColor() == "Negro")
			{
				tot = tot + 1;
			}
			AlturaNegra(A->getIzquierda(), tot);
		}
		else
		{
			if (A->getColor() == "Negro")
			{
				tot = tot + 1;	
			}
			AlturaNegra(A->getDerecha(), tot);
		}
	}
}

template<class T>
int RBtree<T>::AlturaNegra(Node<T>* A)
{
	if (A == NULL)
	{
		return 0;
	}
	else
	{
		if(A->getIzquierda() > A->getDerecha())
		{
			if (A->getColor() == "Negro")
			{
				return AlturaNegra(A->getIzquierda()) + 1;
			}
			else
			{
				return AlturaNegra(A->getIzquierda());
			}
		}
		else
		{
			if (A->getColor() == "Negro")
			{
				return AlturaNegra(A->getDerecha()) + 1;
			}
			else
			{
				return AlturaNegra(A->getDerecha());
			}
		}
	}
}

template<class T>
int RBtree<T>::AlturaNegra()
{
	/*int num = 0, tot = 0;
	ContarNegro(raiz, num);
	tot = log(num) + 1;
	return tot + 1;*/
	int num = 0;
	AlturaNegra(raiz,num);
	return num;
}

template<class T>
int RBtree<T>::AlturaNegra2()
{
	/*int num = 0, tot = 0;
	ContarNegro(raiz, num);
	tot = log(num) + 1;
	return tot + 1;*/
	int num = 0;
	num = AlturaNegra(raiz);
	return num;
}