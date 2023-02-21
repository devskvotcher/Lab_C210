#include <iostream>
#include "List.h"
int main()
{
	setlocale(LC_ALL, "Rus");
	List ls;
	List ls1;
	List ls2;
	ls.push_back(Circle(96, 4, 3, Shape::BLACK));
	ls.push_back(Rect(2, 4, 5, 5, Shape::BLACK));
	ls.push_back(Rect(22, 1, 2, 14, Shape::WHITE));
	ls.push_back(Rect(81, 9, 4, 19, Shape::BLUE));
	ls.push_back(Circle(1, 4, 3, Shape::BLACK));
	ls.push_back(Circle(23, 4, 24, Shape::BLACK));
	ls.push_back(Circle(12, 4, 36, Shape::BLACK));
	ls.push_back(Circle(52, 4, 6, Shape::BLACK));
	ls.push_back(Circle(42, 4, 1, Shape::WHITE));
	ls.push_back(Circle(2, 4, 2, Shape::BLUE));
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
	//ls1 = ls;
	List cmp1;
	List cmp2;
	cmp1.push_back(Circle(52, 54, 56, Shape::BLUE));
	cmp2.push_back(Circle(52, 54, 56, Shape::BLUE));
	cmp2.push_back(Circle(2, 4, 6, Shape::BLUE));

    cmp2 = cmp1;
	cmp2 = ls1;
	std::cout << ls1 << std::endl;
////	cmp1 = ls1;
	ls.sort();
	std::cout <<"ќтстортированный список\n" << ls << std::endl;
//ƒо этого момента все норм, если списки одинаковые, то все работает
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