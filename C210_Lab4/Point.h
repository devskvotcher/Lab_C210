#pragma once
#include <iostream>
#include <fstream>
class Point
{
	int m_x;
	int m_y;
public:
	Point();  //����������� �� ���������
	Point(int x, int y);  //����������� � �����������
	//Point(const Point& other); //����������� �����������
	int GetPointX(); //������ ��� �
	int GetPointY(); //������ ��� y
	void SetPointX(int c);
	void SetPointY(int c);
	//~Point();
	bool operator==(const Point& p);
	bool operator <(const Point& other);
	friend std::ostream& operator<< (std::ostream& out, const Point& point);
	friend std::istream& operator>> (std::ifstream& in, Point& point);
	//	friend class Circle;
};
