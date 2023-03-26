#include "Point.h"
Point::Point()  //Конструктор по умолчанию
{
	m_x = 0;
	m_y = 0;
}
Point::Point(int x, int y)  //Конструктор с параметрами
{
	this->m_x = x;
	this->m_y = y;
}
//Point::Point(const Point& other) //Конструктор копирования
//{
//	this->m_x = other.m_x;
//	this->m_y = other.m_y;
//}
int Point::GetPointX() //Геттер для х
{
	return this->m_x;
}
int Point::GetPointY() //Геттер для y
{
	return this->m_y;
}
void Point::SetPointY(int c)
{
	this->m_y = c;
}
void Point::SetPointX(int c)
{
	this->m_x = c;
}
std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << point.m_x << " " << point.m_y;
	return out;
	//out << point.m_x<<" " << point.m_y;
	//return out;
}
std::ostream& operator<< (std::ostream& out, const Point* point)
{
	out << point->m_x << " " << point->m_y;
	return out;
	//out << point.m_x<<" " << point.m_y;
	//return out;
}
std::istream& operator>> (std::ifstream& in, Point& point)
{
	in >> point.m_x >> point.m_y;
	return in;
}
bool Point::operator==(const Point& p) const
{
	return (this->m_x == p.m_x) && (this->m_y == p.m_y);
}

bool Point::operator<(const Point& other) const
{
	
		if (m_x < other.m_x) {
			return true;
		}
		else if (m_x == other.m_x && m_y < other.m_y) {
			return true;
		}
		else {
			return false;
		}
	}

bool Point::is_in_range(int n, int m)
{
	return this->m_x >= n && this->m_x <= n && this->m_y >= m && this->m_y <= m;
}


//Point::~Point()
//{
//
//}
