#pragma once
#include "Node.h"

class Trie
{
private:
	Node* raiz;
public:
	Trie();
	~Trie();
	void insertTrie(Node*& raiz, string palabra, int pos);
	bool buscarPalabra(Node*& raiz, string palabra, int pos);


	void insertTrie( string palabra);
	bool buscarPalabra(string palabra);
};

Trie::Trie()
{
	raiz = new Node();
	raiz->setElem('.');
}

Trie::~Trie()
{
}

void Trie::insertTrie(Node *& raiz ,string palabra,int pos)
{

	if (raiz == NULL) {
		raiz = new Node();
		raiz->setElem(palabra[pos]);
		if (pos == palabra.length())
			raiz->setFinal();
		else
			insertTrie(raiz->getSon(), palabra, pos++);
	}
	else
	{
		if (raiz->getElem() == palabra[pos])
			insertTrie(raiz->getSon(), palabra, pos++);
		else
			insertTrie(raiz->getBro(), palabra, pos);
	}
}

bool Trie::buscarPalabra(Node*& raiz, string palabra, int pos)
{
	if (raiz != NULL) {
		if (raiz->getElem() == palabra[pos])
		{
			cout << raiz->getElem();
			if (raiz->getFinal())
				return true;
			buscarPalabra(raiz->getSon(), palabra, pos++);
		}
		else
			buscarPalabra(raiz->getBro(), palabra, pos++);
	}
	return false;

}

inline void Trie::insertTrie(string palabra)
{
	insertTrie(raiz, palabra, 0);
}

inline bool Trie::buscarPalabra(string palabra)
{
	return buscarPalabra(raiz, palabra, 0);
}




