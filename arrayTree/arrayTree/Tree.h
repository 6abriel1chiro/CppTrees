#pragma once
#include <string>
#include "Node.h"

#define tam 20

template<class T>
class Arbol
{
private:
	Node<T> arr[tam] = { NULL };
public:
	Arbol();
	~Arbol();
	void insertar(T dato, T padre);
	bool insertarElementoRecursivo(T elem, T padre, int posRaiz);
	int contar();
	int contarRecursivo(int pos);
	int calcularAltura();
	int calcularAlturaRecursivo(int pos);
	void recorrerInOrder();
	void recorrerInOrderRecursivo(int pos);
	void recorrerPostOrder();
	void recorrerPostOrderRecursivo(int pos);
	void recorrerPreOrder();
	void recorrerPreOrderRecursivo(int pos);
};

template<class T>
Arbol<T>::Arbol()
{

}

template<class T>
Arbol<T>::~Arbol()
{

}

template<class T>
bool Arbol<T>::insertarElementoRecursivo(T elem, T padre, int posRaiz)
{
	bool res = false;
	if (arr[posRaiz].exists() == false)
	{
		arr[posRaiz].setDato(elem);
		arr[posRaiz].setexistsnte();
		res = true;
	}
	else
	{
		if (arr[posRaiz].getDato() == padre)
		{
			if (arr[posRaiz * 2].exists() == false)
			{
				arr[posRaiz * 2].setDato(elem);
				arr[posRaiz * 2].setexistsnte();
				res = true;
			}
			else
			{
				if (arr[(posRaiz * 2) + 1].exists() == false)
				{
					arr[(posRaiz * 2) + 1].setDato(elem);
					arr[(posRaiz * 2) + 1].setexistsnte();
					res = true;
				}
			}
		}
		else
		{
			res = insertarElementoRecursivo(elem, padre, posRaiz * 2);
			if (res == false)
			{
				res = insertarElementoRecursivo(elem, padre, (posRaiz * 2) + 1);
			}
		}
	}
	return res;
}

template<class T>
void Arbol<T>::insertar(T dato, T padre)
{
	int pos = 1;
	bool resp;
	resp = insertarElementoRecursivo(dato, padre, pos);
}

template<class T>
int Arbol<T>::contar()
{
	int pos = 1;
	int resp;
	resp = contarRecursivo(pos);
	return resp;
}

template<class T>
int Arbol<T>::contarRecursivo(int pos)
{
	int res;
	int res1, res2;
	if (arr[pos].exists() == false)
	{
		res = 0;
	}
	else
	{
		res1 = contarRecursivo(pos * 2);
		res2 = contarRecursivo((pos * 2) + 1);
		res = res1 + res2 + 1;
	}
	return res;
}


template<class T>
int Arbol<T>::calcularAltura()
{
	int pos = 1;
	int resp;
	resp = calcularAlturaRecursivo(pos);
	return resp;
}

template<class T>
int Arbol<T>::calcularAlturaRecursivo(int pos)
{
	int res;
	int res1, res2;
	if (arr[pos].exists() == false)
	{
		res = 0;
	}
	else
	{
		res1 = calcularAlturaRecursivo(pos * 2);
		res2 = calcularAlturaRecursivo((pos * 2) + 1);
		if (res1 > res2)
		{
			res = res1 + 1;
		}
		else
		{
			res = res2 + 1;
		}
	}
	return res;
}

template<class T>
void Arbol<T>::recorrerInOrder()
{
	int pos = 1;
	recorrerInOrderRecursivo(pos);
	cout << endl;
}

template<class T>
void Arbol<T>::recorrerInOrderRecursivo(int pos)
{
	if (arr[pos].exists() == false)
	{
		return;
	}
	else
	{
		recorrerInOrderRecursivo(pos * 2);
		cout << (arr[pos].getDato()) << " ";
		recorrerInOrderRecursivo((pos * 2) + 1);
	}
}

template<class T>
void Arbol<T>::recorrerPostOrder()
{
	int pos = 1;
	recorrerPostOrderRecursivo(pos);
	cout << endl;
}

template<class T>
void Arbol<T>::recorrerPostOrderRecursivo(int pos)
{
	int res;
	int res1, res2;
	if (arr[pos].exists() == false)
	{

	}
	else
	{
		recorrerPostOrderRecursivo(pos * 2);
		recorrerPostOrderRecursivo((pos * 2) + 1);
		cout << (arr[pos].getDato()) << " ";
	}
}

template<class T>
void Arbol<T>::recorrerPreOrder()
{
	int pos = 1;
	recorrerPreOrderRecursivo(pos);
	cout << endl;
}

template<class T>
void Arbol<T>::recorrerPreOrderRecursivo(int pos)
{
	int res;
	int res1, res2;
	if (arr[pos].exists() == false)
	{

	}
	else
	{
		cout << (arr[pos].getDato()) << " ";
		recorrerPreOrderRecursivo(pos * 2);
		recorrerPreOrderRecursivo((pos * 2) + 1);
	}
}

