#include "Node.h"
#include "List.h"
Node::Node()
{
	this->pPrev = this->pNext = nullptr;
}
//Как передавать цвет фигуре? Просто обычной передачей параметров?
Node::Node(Node *prev, const Shape* pC) //Пришлось убрать const
{
	pPrev = prev;
	pNext = pPrev->pNext;
	pPrev->pNext = this;
	pNext->pPrev = this;
	figure = &pC->Clone();
}

Node::~Node()
{
	if (pNext != 0)
	{
		pNext->pPrev = pPrev;
	}
	if (pPrev != 0)
	{
		pPrev->pNext = pNext;
	}
	delete figure;
}

