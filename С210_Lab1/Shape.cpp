#include "Shape.h"
#include <iostream>
#include "List.h"
Shape::Shape(COLOR x)
{
	this->color = x;    
}

void Shape::Getsquare()
{
   //Пустой чисто виртуальный метод
}


//Нужно закоментить для чисто вирутальной функции
void Shape::Inflate(int x)
{
}
bool Shape::operator==(const Shape& pc)
{
    return pc.color == this->color;
}
std::ostream& Shape::operator<<(std::ostream& out)
{
    out << this->GetColor(color);
    return out;
}
const char* Shape::GetColor(COLOR color)
{
    const char* tmp = nullptr;
    switch (color)
    {
    case 0:
        tmp = "RED";
        break;
    case 1:
        tmp = "GREEN";
        break;
    case 2:
        tmp = "BLUE";
        break;
    case 3:
        tmp = "BLACK";
        break;
    case 4:
        tmp = "WHITE";
        break;    
    }
    return tmp;
}
Shape::COLOR& Shape::GetNumberOfColor(std::string c)
{
    COLOR col=Shape::BLACK;
    
    if ( c == "RED")
    {
        col = Shape::RED;
        
    }
    else if (c == "GREEN")
    {
        col = Shape::GREEN;
    }
    else if(c == "BLUE")
    {
        col = Shape::BLUE;
    }
    else if(c == "BLACK")
    {
        col = Shape::BLACK;
    }
    else
    {
        col = Shape::WHITE;
    }
    
    return col;
}
std::istream& operator>> (std::istream& in, const char* c)
{
   // in << Shape::GetNumberOfColor(c);
        return in;
}
Shape::~Shape()
{
}
Rect::Rect():Shape(color)    //Конструктор по умолчанию
{
    this->m_B_x = 0;
    this->m_B_y = 0;
    this->m_D_x = 0;
    this->m_D_y = 0;
}
Rect::Rect(unsigned int m_B_x, unsigned int m_B_y, unsigned int m_D_x, unsigned int m_D_y, COLOR color) :Shape(color)    //Конструктор по умолчанию
{
    this->m_B_x = m_B_x;
    this->m_B_y = m_B_y;
    this->m_D_x = m_D_x;
    this->m_D_y = m_D_y;    
}
Rect::Rect(const Rect& rect) : Shape(rect)                   //Конструктор копирования
{
    this->m_B_x = rect.m_B_x;
    this->m_B_y = rect.m_B_y;
    this->m_D_x = rect.m_D_x;
    this->m_D_y = rect.m_D_y;
}

//Площадь прямоугольника
void Rect::Getsquare()
{
    std::cout <<"Площадь прямогульника=" << this->m_B_x * m_D_x + m_D_y * m_B_y << std::endl;
}

Shape& Rect::Clone() const
{
    Rect *rect = new Rect(*this);
    return *rect;
}

void Rect::Print(std::ostream& out)
{

    out <<"R"<<" " << this->m_B_x << " " << this->m_B_y << " " << this->m_D_x << " " << this->m_D_y <<" "<<this->GetColor(color) << std::endl;
}
bool Rect::operator==(const Shape& pc) 
{
    if (typeid(Rect) == typeid(pc))
    {
        Rect* tmp = dynamic_cast<Rect *>(const_cast<Shape*>(&pc));

        if (tmp->color == this->color && tmp->m_B_x == this->m_B_x && tmp->m_B_y == this->m_B_y && tmp->m_D_x == this->m_D_x && tmp->m_D_y == this->m_D_y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
Rect::~Rect()
{
   
}

void Rect::Inflate(int x)
{
    this->m_B_x = m_B_x + x;
    this->m_B_y = m_B_y + x;
    this->m_D_x = m_D_x + x;
    this->m_D_y = m_B_y + x;
}

Circle::Circle() :Shape(color)
{
    this->m_x = 0;
    this->m_y = 0;
    this->m_radius = 0;
}

Circle::Circle(unsigned int r, unsigned int x, unsigned int y, COLOR color) :Shape(color)    //Конструктор по умолчанию
{
    this->m_radius = r;
    this->m_x = x;
    this->m_y = y;
}
Circle::Circle(const Circle& circle):Shape(circle)                    //Конструктор копирования
{
    this->m_radius = circle.m_radius;
    this->m_x = circle.m_x;
    this->m_y = circle.m_y;
}

Circle::Circle(const Rect& r):Shape(r)
{
    
    int AB=r.m_B_x+ r.m_B_y;
    int AC= r.m_D_x+r.m_D_y;
    this->m_radius = (sqrt(pow(AB, 2) + pow(AC, 2)))/2;
    this->m_x = AB - m_radius;
    this->m_y = AC - m_radius;
}
Shape& Circle::Clone() const
{
    Shape* circle = new Circle(*this);
    return *circle;
}

//Площадь круга
void Circle::Getsquare()
{

}

Circle::~Circle()
{

}
bool Circle::operator==(const Shape& pc)
{
    if (typeid(Circle) == typeid(pc))
    {
        Circle* tmp = dynamic_cast<Circle*>(const_cast<Shape*>(&pc));

        if (tmp->color == this->color && tmp->m_radius == this->m_radius && tmp->m_x == this->m_x && tmp->m_y == this->m_y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}


void Circle::Print(std::ostream& out)
{
    out <<"C"<<" " << this->m_radius << " " << this->m_x << " " << this->m_y <<" " <<this->GetColor(color)<< std::endl;
}
void Circle::Inflate(int x)
{
    this->m_radius = m_radius + x;
}


