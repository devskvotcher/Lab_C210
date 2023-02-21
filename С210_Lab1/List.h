#pragma once
#include "Node.h"
class List
{
	Node Head;
	Node Tail;
	size_t m_size;
public:
	List();
	List(List&& other);
	List(const List& other);
	List &operator=(const List& other);
	List& operator=(List&& other);
	void push_front(const Shape& pc);
	void push_back(const Shape& pc);
	bool RemoveOne(const Shape& pc);
	bool RemoveAll(const Shape& pc);
	void sortByArea();
	void sortByColor();
	void sort();
	~List();
	friend std::ostream& operator<< (std::ostream& out, const List& list);
	friend std::istream& operator>> (std::istream& in, const List& list);
	void WriteFile();
	List& ReadFromFile();
	void Clean();
	//friend class Node;
};

