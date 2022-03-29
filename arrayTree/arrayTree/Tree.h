#pragma once
#include <string>
#include "Node.h"

#define tam 30000

template<class T>
class Arbol
{
private:
	Node<T> arr[tam];
public:
	Arbol();
	~Arbol();
	bool insert(T dato, int posRaiz);

	int contar();
	int cuentaRecursiva(int pos);
	int calcularAltura(int pos); //debe recibir 1 la primera vez
	void recorrerInOrder(int pos); //debe recibir 1 la primera vez
	void recorrerPostOrder(int pos);//debe recibir 1 la primera vez
	void recorrerPreOrder(int pos); //debe recibir 1 la primera vez

	T getMenor(int posRaiz);
	T buscar(T dato , int raiz);

	int contarHojas(int raiz);

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
inline bool Arbol<T>::insert(T dato, int posRaiz)
{
	bool res = false;
	if (arr[posRaiz].getExistence() == false) {
		arr[posRaiz].setDato(dato);
		res = true;
	}
	else {
		if (((posRaiz*2)+1) < tam)
		{
			if (dato < arr[posRaiz].getDato())
				res=insert(dato, posRaiz * 2);
			else
			if (dato > arr[posRaiz].getDato())
			{
				res=insert(dato, ((posRaiz * 2) + 1));

			}
		}
	}
	return res;
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
		return;
	}
	else
	if (((pos*2)+1) < tam)
	{
		recorrerInOrder(pos * 2);
		cout <<arr[pos].getDato()<< " ";
		recorrerInOrder((pos * 2) + 1);
	}

}



template<class T>
void Arbol<T>::recorrerPostOrder(int pos) //debe recibir 1 la primera vez
{
	int res=0;
	if (arr[pos].getExistence() == false)
	{
		return;
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
	if (arr[pos].getExistence() == false)
	{
	return;
	}
	else
	{
		cout << (arr[pos].getDato()) << " ";
		recorrerPreOrder(pos * 2);
		recorrerPreOrder((pos * 2) + 1);
	}	
	cout << endl;
}

template <class T>
T Arbol<T>::buscar(T dato, int raiz) {
while (arr[raiz].getExistence() != false)
{
	if (dato < arr[raiz].getDato())
	{
	raiz = raiz * 2;
	
	}
	if (dato > arr[raiz].getDato()) 
	{
	raiz = (raiz * 2) + 1;

	}
	else{return arr[raiz].getDato();}
}
return -1;
}

template <class T>
T Arbol<T>::getMenor(int raiz)
{
	if (arr[raiz].getDato() == false) {return 0;}
	else
	{
		T menor = arr[1].getDato();
		while (arr[raiz * 2].getExistence() != false) 
		{
			raiz = raiz * 2;
		}
		menor = arr[raiz].getDato();
		return menor;
	}
}

template <class T>
int Arbol<T>::contarHojas(int raiz)
{

	if(arr[raiz].getExistence()==false)    
        return 0; //vacio
    if(arr[raiz*2].getExistence()==false && arr[(raiz*2) + 1].getExistence()==false)
        return 1;   // solo hay 1 nodo     
    else
        return contarHojas(raiz*2)+contarHojas(((raiz*2) + 1));

}