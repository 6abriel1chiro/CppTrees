#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <chrono>




using namespace std;

class Node
{
private:
	bool isFinal;
	char elem;
	Node* bro;
	Node* son;

public:
	Node();
	~Node();

	char getElem();
	void setElem(char elem);

	bool checkFinal();
	void setFinal();

	Node*& getSon();
	Node*& getBro();


	void setSon(Node* son);
	void setBro(Node* bro);

	bool getFinal();

};

Node::Node()
{
	isFinal = false;
	bro = NULL;
	son = NULL;
	
}

Node::~Node()
{
}

inline char Node::getElem()
{
	return elem;
}

inline void Node::setElem(char elem)
{
	this->elem = elem;
}

inline bool Node::checkFinal()
{
	return isFinal;
}

inline void Node::setFinal()
{
	this->isFinal = true;
}

inline Node*& Node::getSon()
{
	return son;
}

inline Node*& Node::getBro()
{
	return bro;
}

inline void Node::setSon(Node* son)
{
	this->son = son;
}

inline void Node::setBro(Node* bro)
{
	this->bro = bro;

}

inline bool Node::getFinal()
{
	return  isFinal;
}
