#pragma once
#include "Shape.h"
#include <iostream>
class List;
class Node
{
	Node* pPrev;
	Node* pNext;
	Shape *figure;
public:
	Node();
	Node(Node *prev, const Shape *pc);
	~Node();
	friend std::ostream& operator<< (std::ostream& out, const List& list);
	friend class List;
	friend class Shape; 
	friend class Rect;
	friend class Circle;
};

