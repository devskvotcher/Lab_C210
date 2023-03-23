#include "Point.h"
Point::Point()  //Конструктор по умолчанию
{
	m_x = 0;
	m_y = 0;
}
Point::Point(int x, int y)   //Конструктор с параметрами
{
	this->m_x = x;
	this->m_y = y;
}
//Point::Point(const Point& other) //Конструктор копирования
//{
//	this->m_x = other.m_x;
//	this->m_y = other.m_y;
//}
int Point::GetPointX() const //Геттер для х
{
	return this->m_x;
}
int Point::GetPointY() const //Геттер для y
{
	return this->m_y;
}
std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << point.m_x << " " << point.m_y;
	return out;
	//out << point.m_x<<" " << point.m_y;
	//return out;
}
std::istream& operator>> (std::ifstream& in, Point& point)
{
	in >> point.m_x >> point.m_y;
	return in;
}
bool Point::operator==(const Point& p)
{
	return (this->m_x == p.m_x) && (this->m_y == p.m_y);
}
bool Point::operator<(const Point& other) const 
{
	if (m_x < other.m_x) return true;
	else if (m_x > other.m_x) return false;
	else return m_y < other.m_y;
}
//Point::~Point()
//{
//
//}
