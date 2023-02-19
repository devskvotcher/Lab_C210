#pragma once
#include <iostream>

//������� ������, ������� ��������� ������� ����� ���������������.
class Shape
{
public:
    enum COLOR
    {
        RED, GREEN, BLUE, BLACK, WHITE
    };
protected:
   //unsigned int m_left, m_right, m_top, m_bottom; //������-���� ������, ������������ ������� ������
    COLOR color;	//������-���� ������, ������������ ���� ������
public:
    Shape(COLOR x);
    virtual void Getsquare();
    virtual Shape& Clone() const = 0;
    virtual void Print(std::ostream& out) = 0;
    virtual void Inflate(int x);
    virtual bool operator ==(const Shape& pc);
    std::ostream& operator<< (std::ostream& out);
    friend std::istream& operator>> (std::istream& in, const char* c);
    Shape::COLOR& GetNumberOfColor(std::string c);
    const char* GetColor(COLOR color);
    virtual ~Shape();
};
//������� ������, ������� ��������� ����������� ����� �������������.
class Rect:public Shape
{
    friend class Circle;
protected:
    unsigned int m_B_x, m_B_y, m_D_x, m_D_y;
public:
    Rect();
    Rect(unsigned int sideA, unsigned int sideB, unsigned int sideC, unsigned int sideD, COLOR color);    //����������� �� ���������
    Rect(const Rect& rect);     //����������� �����������
    void Getsquare() override;
    virtual Shape& Clone() const override;
    virtual void Print(std::ostream& out) override;
    virtual bool operator ==(const Shape& pc) override ;
    void Inflate(int x) override;
    virtual ~Rect();
};
//������� ������, ������� ��������� ����������� ����� ����.
class Circle :public Shape
{
    friend class Rect;
protected:
    unsigned int m_radius, m_x, m_y;
public:
    Circle();
    Circle(unsigned int r, unsigned int x, unsigned int y, COLOR color);   //����������� �� ���������
    Circle(const Circle& circle);                    //����������� �����������
    Circle(const Rect& r);
    virtual Shape& Clone() const override; 
    virtual void Print(std::ostream& out) override;
    void Getsquare() override;
    virtual bool operator ==(const Shape& pc) override;
    void Inflate(int x) override;
    virtual ~Circle();
};

