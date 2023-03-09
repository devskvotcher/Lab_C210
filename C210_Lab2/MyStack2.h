#pragma once
#include <iostream>
template <typename T>
class MyStack2
{
	class Node
	{
	public:
		T m_data;
		Node* pNext;
		Node(const T& data) { m_data = data; };
	};
	Node* m_pHead;
public:
	MyStack2() { m_pHead = nullptr; size = 0; }
	~MyStack2();
	MyStack2(const MyStack2&);
	MyStack2& operator=(const MyStack2&);

	size_t size;
	void push(const T&);
	void pop(); //throw(std::out_of_range); // remove the last element
	T top() const; //throw(std::out_of_range); // just return the last element (do not remove it!)
private:
	void Print(std::ostream&, Node*) const;
	void Copy(Node*, Node*);
	friend std::ostream& operator<< <T> (std::ostream&, const MyStack2<T>&);
};
#include "MyStack2.h"
template <typename T>
MyStack2<T>::MyStack2(const MyStack2& s)
{
	size = 0;
	*this = s;
}

template <typename T>
void MyStack2<T>::Copy(Node* node, Node* p) // push nodes (all before <p>) in "right" order 
{
	if (node->pNext && node->pNext != p)
		Copy(node->pNext, p);
	push(node->m_data);


}

template <typename T>
MyStack2<T>& MyStack2<T>::operator=(const MyStack2& s)
{
	if (this != &s)
	{
		Node* thisNode = m_pHead;
		Node* otherNode = s.m_pHead;

		size_t comSize = 0;
		if (size && s.size)
		{
			comSize = size < s.size ? size : s.size;
			for (size_t i = 0; i < comSize - 1; i++)
				otherNode = otherNode->pNext;
			// Now <otherNode> points to the last node in <s> that should be pushed in our list
			Copy(s.m_pHead, otherNode->pNext); // push extra nodes
		}
		else
			Copy(otherNode, s.m_pHead); // push all nodes from <s> to our list in "right" order


		for (size_t i = 0; i < comSize; i++)
		{
			thisNode->m_data = otherNode->pNext->m_data; // rewrite data in existing nodes
			thisNode = thisNode->pNext;
			otherNode = otherNode->pNext;
		}
	}

	return *this;
}

template <typename T>
void MyStack2<T>::push(const T& data)
{
	Node* node = new Node(data);
	node->pNext = m_pHead;
	m_pHead = node;
	size++;
}

template <typename T>
T MyStack2<T>::top() const
{
	if (!m_pHead)
		throw std::out_of_range("Error! MyStack2 is empty.");
	else
		return m_pHead->m_data;
}

template <typename T>
void MyStack2<T>::pop()
{
	if (!m_pHead)
		throw std::out_of_range("Error! MyStack2 is empty.");
	else
	{
		Node* tmp = m_pHead->pNext;
		delete m_pHead;
		m_pHead = tmp;
		size--;
	}
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const MyStack2<T>& stack)
{
	if (stack.m_pHead)
	{
		stack.Print(o, stack.m_pHead);
		o << stack.m_pHead->m_data;
	}
	return o;
}

template <typename T>
void MyStack2<T>::Print(std::ostream& o, Node* node) const
{
	node = node->pNext;
	if (node)
	{
		Print(o, node);
		o << node->m_data;
	}
}

template <typename T>
MyStack2<T>::~MyStack2()
{
	Node* tmp = m_pHead;
	for (size_t i = 0; i < size; i++)
	{
		m_pHead = tmp->pNext;
		delete tmp;
		tmp = m_pHead;
	}
}
