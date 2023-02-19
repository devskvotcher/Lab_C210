#include "List.h"
#include "Node.h"
#include "Shape.h"
#include <string>
#include <sstream>
#include <fstream>
List::List():m_size(0)
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	m_size = 0;
}
List::List(const List& other) :m_size(other.m_size)   //конструктор копирования
{
	//Подготовка к копированию
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	//Копирование
	Node* pThis = &Head;
	Node* pOther = other.Head.pNext;
	for (size_t i = 0; i < m_size; i++)
	{
		pThis = new Node(pThis, pOther->figure);  
		pOther = pOther->pNext;					  
	}											
}
List::List(List&& other) :m_size(other.m_size)    //Move конструктор копирования
{
	if (other.m_size == 0)
	{
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
	}
	else
	{
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;
		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
	
}
List& List::operator=(const List& other)
{
	Node* p = this->Head.pNext;
	Node* p1 = other.Head.pNext;
	if (this->m_size == other.m_size)
	{
		for (p1; p1 != &other.Tail; p1 = p1->pNext, p = p->pNext)
		{
			*p->figure = *p1->figure;
		}
	}
	
	else if (this->m_size > other.m_size)
	{
		for (p1; p1 != &other.Tail; p1 = p1->pNext, p = p->pNext)
		{
			p->figure = p1->figure;			
		}
		for (p == &other.Tail; p != &this->Tail; p = p->pNext)
		{
			Node* temp = p->pNext;
			delete p;
			p = temp;
		}
	}
	else if(this->m_size < other.m_size)
	{

		for (p; p != &this->Tail; p1 = p1->pNext, p = p->pNext)
		{
			p->figure = p1->figure;
		}
		for (p1 = &this->Tail; p1 != &other.Tail; p1 = p1->pNext)
		{
			//Почему-то возвращает null и в отладчике только pPrev, а pNext == null
			if (typeid(p1->figure) == typeid(Rect))
			{				
				Rect* tmp = dynamic_cast<Rect*>(p1->figure);//const_cast<Shape*>(&pc));
				this->push_back(*tmp);
			}
			else
			{
				Circle* tmp = dynamic_cast<Circle*>(p1->figure);//const_cast<Shape*>(&pc));
				this->push_back(*tmp);
			}
			//this->push_front(*p1->figure);
		}
	}

	
	return *this;
}

List& List::operator=(List&& other)
{
	if (this == &other)
	{
		return *this;
	}		
	this->Clean();
	this->Head.pNext = other.Head.pNext;
	this->Tail.pPrev = other.Tail.pPrev;
	this->Head.pNext->pPrev = &other.Head;
	this->Tail.pPrev->pNext = &other.Tail;
	this->m_size = 0;

	return *this;
}
//
List::~List()
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
}


void List::push_front(const Shape &pc)
{
	Node* ptr = new Node(&Head,&pc);    
	this->m_size++;
}

void List::push_back(const Shape &pc)
{	
	Node* ptr = new Node(Tail.pPrev, &pc);   
	this->m_size++;
}
bool List::RemoveOne(const Shape& pc)
{
	Node* p = Head.pNext;
	while (p != &Tail)
	{
		if (*p->figure == pc)   //Нужно перегрузить оператор на равенство в классе Circle
		{
			m_size--;
			delete p;
			return true;
		}
		p = p->pNext;
	}
	return false;
}
bool List::RemoveAll(const Shape& pc)
{
	int tmp = m_size;
	Node* p = Head.pNext;
	while (p != &Tail)
	{
		if (*p->figure == pc)   //Нужно перегрузить оператор на равенство в классе Circle
		{
			m_size--;
			p = p->pNext;
			delete p->pPrev;			
		}
		else
		{
			p = p->pNext;
		}
	}

	if (tmp>m_size)
	{
		return true;
	}
	else
	{
		return false;
	}	
}
//void List::sort()
//{
//	Node* pT = &Tail;
//	Node* p = Head.pNext;
//	Node* max = nullptr;
//
//	for (size_t i = m_size-1; i > 0; i--)
//	{
//		float MAX_area = 0;
//			while (p != pT)
//			{
//				float area = 3.14*pow(p->m_data.GetR(),2);
//				
//				if (area > MAX_area)
//				{
//					MAX_area = area;
//					max = p;
//				}
//				p = p->pNext;
//			}
//			Circle tmp = max->m_data;
//			max->m_data = pT->pPrev->m_data;
//			pT->pPrev->m_data = tmp;
//			p = Head.pNext;
//
//			pT = pT->pPrev;
//	}
//}
//Оно все равно не работает, однако хоть ошибок не возникает, если сделать поля всех классов public))
//Но вряд ли это хорошо
std::ostream& operator<< (std::ostream& out,const List& list)
{
	Node* p = list.Head.pNext;
	if (p == &list.Tail)
	{
		out << "Список пуст" << std::endl;
	}
	while (p != &list.Tail)
	{
		//if (typeid(p->figure) == typeid(Rect))
		/*if(dynamic_cast<Rect *>(p->figure))
		{
			out << p->figure->m_B_x << " " << p->figure->m_B_y << " " << p->figure->m_D_x << " " << p->figure->m_D_y << std::endl;;
		}
		else
		{
			out << p->figure->m_radius << " " << p->figure->m_x << " " << p->figure->m_y << " " << std::endl;
		}	*/
		p->figure->Print(out);
		p = p->pNext;
	}

	return out;
}
void List::WriteFile()
{
	std::string filename;
	std::cout << "Введите название файла=";
	std::cin >> filename;
	std::ofstream file(filename,std::ios::out);
	if (file.is_open())
	{
		/*if (typeid(*this) == typeid(Rect*))
		{
			file << "R" << " " << *this;
		}
		else
		{
			file << "C" << " " << *this;
		}*/
		file << *this;		
		file.close();
	}
	else
	{
		std::cout << "Неудачное открытие файла" << std::endl;
	}
}

std::istream& operator>> (std::istream& in, const List& list)
{
	int x, y, r;
	std::cout << "Введите координату х точки=";
	in >> x;
	std::cout << "\nВведите координату y точки=";
	in >> y;
	std::cout << "\nВведите радиус круга=";
	in >> r;
	//Point tmp1(x, y);
	////Circle* tmp = new Circle(tmp1, r);
	////list.push_back(*tmp);
	//list.push_back(Circle(Point(x,y),r));
	//std::cout << "\nОбъект успешно добавлен в список\n";
	return in;
}

List& List::ReadFromFile()
{

	std::string name_file;
	std::cout << "Введите имя входного текстового файла, содержащего текст для анализа: ";
	//getline(std::cin, name_file);
	std::cin >> name_file;
	std::ifstream fin(name_file, std::ios_base::in);
	if (fin.is_open())
	{
		std::string line;
		std::string type;
		int x = 0;
		int y = 0;
		int z = 0;
		int p = 0;
		std::string c;
		Shape::COLOR col;
		while (!fin.eof())
		{
			getline(fin, line);
			std::stringstream in(line);
//Как отличить объекты? Ведь передаваемые параметры разные?
			while (in >>type>>x>>y>>z)
			{
				
				if (type == "R")
				{
					in >> p >> c;
					Rect* r =  nullptr;
					col = r->GetNumberOfColor(c);
					r = new Rect(x, y, z, p, col);
					this->push_back(*r);
					delete r;
				}
				else
				{
					in >> c;
					Circle* circl= nullptr;
					col = circl->GetNumberOfColor(c);
					circl = new Circle(x, y, z, col);
					this->push_back(*circl);
					delete circl;
				}				
			}
		}
		fin.close();
		
	}
		return *this;
}
void List::Clean()
{
	while (this->Head.pNext != &this->Tail)
	{
		delete this->Head.pNext;
	}
	std::cout << "Список очищен от значений" << std::endl;
}



