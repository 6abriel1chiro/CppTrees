#pragma once

#include "Node.h"
#define TAM 20000

template<class T>
class Tree
{
private:
	Node<T> arr[TAM];
	int last;
public:
	Tree();
	~Tree();


	void insertar(T elem);
	void recuperarAbajo_Arriba(int posNodo);

	T eliminarMayor();
	void recuperarArriba_Abajo(int posNodo);

	void recorrerMonticulo();

	T getMayor();
	T getMenor();

	int getTam();

	//int contar();

	int getAltura(int posNodo);
	int getAltura();


	bool buscar(T elem);

    list<int> heapSort();


};

template<class T>
Tree<T>::Tree()
{

	last = NULL;
}

template<class T>
Tree<T>::~Tree()
{
 while (arr[1].getPresente() != false)
    {
        eliminarMayor();

    }
}


template<class T>
void Tree<T>::recuperarArriba_Abajo(int posNodo)
{
	int posMayor = 0;
	T aux;
	if (arr[posNodo * 2].getPresente() && arr[posNodo * (2 + 1)].getPresente())
	{	
		if (arr[posNodo * 2].getElem() > arr[posNodo * (2 + 1)].getElem())
			posMayor = posNodo * 2;
		else
			posMayor = posNodo * 2 + 1;

		if (arr[posMayor].getElem() > arr[posNodo].getElem())
		{
			aux = arr[posMayor].getElem();
			arr[posMayor].setElem(arr[posNodo].getElem()) ;
			arr[posNodo].setElem(aux);
			recuperarArriba_Abajo(posMayor);
		}
	}
	else 
	{
		if (arr[posNodo * 2].getPresente())
			if (arr[posNodo * 2].getElem() > arr[posNodo].getElem())
			{
				T aux = arr[posNodo].getElem();
				arr[posNodo].setElem(arr[posNodo * 2].getElem()) ;
				arr[posNodo * 2].setElem(aux);
				recuperarArriba_Abajo(posNodo * 2);
			}
	}
}

template<class T>
void Tree<T>::recuperarAbajo_Arriba(int posNodo)
{
	if (posNodo != 1)
	{
		if (arr[posNodo].getElem() > arr[posNodo / 2].getElem())
		{
			T aux = arr[posNodo /2].getElem();
			arr[posNodo/2].setElem(arr[posNodo].getElem());
			arr[posNodo].setElem(aux);
			recuperarAbajo_Arriba(posNodo / 2);
		}

	}
}

template<class T>
void Tree<T>::insertar(T elem)
{
	if (last == NULL)
	{
		last = 1;

		arr[last].setElem(elem);
		arr[last].setPresente(true);
	}
	else
	{
		last = last + 1;
		arr[last].setElem(elem);
		arr[last].setPresente(true);
		recuperarAbajo_Arriba(last);
	}
}


template<class T>
void Tree<T>::recorrerMonticulo()
{
	for (int i = 1; i <= last; i++)
	{
	//	cout << arr[i].getElem() << " pos : "<<i<<endl;
        		cout << arr[i].getElem()<<" ";


	}
    cout<<endl;
}

template<class T>
T Tree<T>::eliminarMayor()
{
	T mayor;
	if (last == NULL)
	{
		mayor = NULL;
	}
	else
	{
		mayor = arr[1].getElem();
		arr[1].setElem(arr[last].getElem());
		arr[last].setPresente(false);
		last = last - 1;
		if (last == 0)
		{
			last = NULL;
		}
		else
		{
			recuperarArriba_Abajo(1);
		}

	}
	return mayor;
}

template<class T>
T Tree<T>::getMayor()
{
	return arr[1].getElem();
}

template<class T>
T Tree<T>::getMenor()
{
	return arr[last].getElem();
}

template<class T>
int Tree<T>::getTam()
{
	return last;
}



template<class T>
inline int Tree<T>::getAltura(int posNodo)
{
	int posMayor = 0;
	T aux;
	int h = 0;
	if (arr[posNodo * 2].getPresente() && arr[posNodo * (2 + 1)].getPresente())
	{
		h++;
		if (arr[posNodo * 2].getElem() > arr[posNodo * (2 + 1)].getElem())
			posMayor = posNodo * 2;
		else
			posMayor = posNodo * 2 + 1;

		if (arr[posMayor].getElem() > arr[posNodo].getElem())
		{
			aux = arr[posMayor].getElem();
			arr[posMayor].setElem(arr[posNodo].getElem());
			arr[posNodo].setElem(aux);
			getAltura(posMayor);
		}
	}
	else
	{
		if (arr[posNodo * 2].getPresente()) {
			h++;
			if (arr[posNodo * 2].getElem() > arr[posNodo].getElem())
			{
				T aux = arr[posNodo].getElem();
				arr[posNodo].setElem(arr[posNodo * 2].getElem());
				arr[posNodo * 2].setElem(aux);
				getAltura(posNodo * 2);
			}
		}
	}
	return h;
}

template<class T>
inline int Tree<T>::getAltura()
{
	return getAltura(1);
}


template<class T>
inline bool Tree<T>::buscar(T elem)
{
	bool found= false;
	for (int i = 1; i <= last; i++)
	{
		if (elem == arr[i].getElem()) 
		{
			cout << arr[i].getElem() << " " ;
			found = true;
		}
	}
	
	return found;
}

template<class T>
list<int> Tree<T>::heapSort()
{
    list<int> mylist;
    while (arr[1].getPresente() != false)
    {
        T mayor = arr[1].getElem();
        mylist.push_back(mayor);
        eliminarMayor();

    }
    
    return mylist;

}