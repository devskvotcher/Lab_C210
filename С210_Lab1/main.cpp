#include <iostream>
#include "List.h"
int main()
{
	setlocale(LC_ALL, "Rus");
	List ls;
	List ls1;
	List ls2;
	ls.push_back(Circle(2, 4, 6, Shape::BLACK));
	ls.push_back(Rect(2, 4, 5, 6, Shape::BLACK));
	ls.push_back(Rect(2, 1, 2, 3, Shape::WHITE));
	ls.push_back(Rect(8, 9, 4, 2, Shape::BLUE));
	ls.push_back(Circle(2, 4, 6, Shape::BLACK));
	ls.push_back(Circle(2, 4, 6, Shape::BLACK));
	ls.push_back(Circle(2, 4, 6, Shape::BLACK));
	ls.push_back(Circle(2, 4, 6, Shape::BLACK));
	ls.push_back(Circle(2, 4, 6, Shape::WHITE));
	ls.push_back(Circle(2, 4, 6, Shape::BLUE));
	std::cout << ls << std::endl;
	ls1.push_back(Rect(3, 1, 2, 3, Shape::BLACK));
	ls1.push_back(Rect(5, 6, 7, 8, Shape::WHITE));
	ls1.push_back(Rect(1, 3, 4, 6, Shape::BLUE));
	ls1.push_back(Circle(12, 12, 12, Shape::BLACK));
	ls1.push_back(Circle(32, 34, 36, Shape::BLACK));
	ls1.push_back(Circle(32, 34, 36, Shape::BLACK));
	ls1.push_back(Circle(42, 44, 36, Shape::BLACK));
	ls1.push_back(Circle(42, 44, 46, Shape::WHITE));
	ls1.push_back(Circle(52, 54, 56, Shape::BLUE));
	ls1.push_back(Circle(2, 4, 6, Shape::BLUE));
	std::cout << ls1 << std::endl;
	ls1 = ls;

	std::cout << ls1 << std::endl;
//До этого момента все норм, если списки одинаковые, то все работает
	ls.push_back(Circle(2, 4, 6, Shape::WHITE));
	ls.push_back(Circle(2, 4, 6, Shape::BLUE));
	//ls1 = ls;
	std::cout << ls1 << std::endl;
	ls.RemoveAll(Circle(2, 4, 6, Shape::BLACK));
	std::cout << ls << std::endl;
	//ls.RemoveAll(Rect(2, 4, 5, 6, Shape::BLACK));
	std::cout << ls << std::endl;
	ls.WriteFile();
	List test;
	test.ReadFromFile();
	std::cout << test << std::endl;
	return 0;
}