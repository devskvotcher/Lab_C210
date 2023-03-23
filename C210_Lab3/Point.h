#pragma once
#include <iostream>
#include <fstream>
class Point
{
	int m_x;
	int m_y;
public:
	Point();  //Конструктор по умолчанию
	Point(int x, int y);  //Конструктор с параметрами
	//Point(const Point& other); //Конструктор копирования
	int GetPointX() const; //Геттер для х
	int GetPointY() const; //Геттер для y
	//~Point();
	bool operator==(const Point& p) const;
	bool operator<(const Point& other) const;
	friend std::ostream& operator<< (std::ostream& out, const Point& point);
	friend std::ostream& operator<< (std::ostream& out, const Point* point);
	friend std::istream& operator>> (std::ifstream& in, Point& point);
	//	friend class Circle;
};

