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

	bool insercionRecursiva(T elem, T padre, int posRaiz);
	int contar();
	int cuentaRecursiva(int pos);
	int calcularAltura(int pos); //debe recibir 1 la primera vez
	void recorrerInOrder(int pos); //debe recibir 1 la primera vez
	void recorrerPostOrder(int pos);//debe recibir 1 la primera vez
	void recorrerPreOrder(int pos); //debe recibir 1 la primera vez
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
bool Arbol<T>::insercionRecursiva(T elem, T padre, int posRaiz)
{
	bool res = false;
	if (arr[posRaiz].getExistence() == false)
	{
		arr[posRaiz].setDato(elem);
		arr[posRaiz].setExistence();
		res = true;
	}
	else
	{
		if (arr[posRaiz].getDato() == padre)
		{
			if (arr[posRaiz * 2].getExistence() == false)
			{
				arr[posRaiz * 2].setDato(elem);
				arr[posRaiz * 2].setExistence();
				res = true;
			}
			else
			{
				if (arr[(posRaiz * 2) + 1].getExistence() == false)
				{
					arr[(posRaiz * 2) + 1].setDato(elem);
					arr[(posRaiz * 2) + 1].setExistence();
					res = true;
				}
			}
		}
		else
		{
			res = insercionRecursiva(elem, padre, posRaiz * 2);
			if (res == false)
			{
				res = insercionRecursiva(elem, padre, (posRaiz * 2) + 1);
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
	resp = insercionRecursiva(dato, padre, pos);
}

template<class T>
int Arbol<T>::contar()
{
	int pos = 1;
	int resp;
	resp = cuentaRecursiva(pos);
	return resp;
}

template<class T>
int Arbol<T>::cuentaRecursiva(int pos)
{
	int res;
	int res1, res2;
	if (arr[pos].getExistence() == false)
	{
		res = 0;
	}
	else
	{
		res1 = cuentaRecursiva(pos * 2);
		res2 = cuentaRecursiva((pos * 2) + 1);
		res = res1 + res2 + 1;
	}
	return res;
}


template<class T>
int Arbol<T>::calcularAltura(int pos)
{
	//int pos = 1;
	int res;
	int res1, res2;																
	if (arr[pos].getExistence() == false)
	{
		res = 0;
	}
	else
	{
		res1 = calcularAltura(pos * 2);
		res2 = calcularAltura((pos * 2) + 1);
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
void Arbol<T>::recorrerInOrder(int pos)
{
	//int pos = 1;
	if (arr[pos].getExistence() == false)
	{
		//cout << "empty" << endl;
		return;
	}
	else
	{
		recorrerInOrder(pos * 2);
		cout << (arr[pos].getDato()) << " ";
		recorrerInOrder((pos * 2) + 1);
	}
	cout << endl;
}



template<class T>
void Arbol<T>::recorrerPostOrder(int pos) //debe recibir 1 la primera vez
{
	int res=0;
	if (arr[pos].getExistence() == false)
	{
		//cout << "empty" << endl;
	}
	else
	{
		recorrerPostOrder(pos * 2);
		recorrerPostOrder((pos * 2) + 1);
		cout << (arr[pos].getDato()) << " ";
	}
	cout << endl;
}



template<class T>
void Arbol<T>::recorrerPreOrder(int pos)
{
	//int pos = 1;
	int res=0;
	if (arr[pos].getExistence() == false)
	{
	//	cout << "empty" << endl;

	}
	else
	{
		cout << (arr[pos].getDato()) << " ";
		recorrerPreOrder(pos * 2);
		recorrerPreOrder((pos * 2) + 1);
	}	
	cout << endl;
}



