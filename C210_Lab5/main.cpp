// Iter_Alg.cpp : Defines the entry point for the console application.
//
//���������. ����������� ���������. ���������.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <tchar.h>
#include "Point.h"
#include <deque>
#include "Template.h"
using namespace std;	
#define	  stop __asm nop
class Predicat
{
	char c;
public:
	Predicat(char pre)
	{
		this->c = pre;
	}
	bool operator()(const std::string &str)
	{
		return  std::toupper(c) == std::toupper(str[0]);
	}
	
};
char to_lower(unsigned char c) 
{
	return std::tolower(c);
}

std::string& to_lower_case(std::string& input) 
{
	std::transform(input.begin(), input.end(), input.begin(), to_lower);
	return input;
}
bool is_even(const std::pair<const std::string, int>& p) {
	return ((p.second & 1) == 0);
}
bool is_odd(const std::pair<const std::string, int>& p) {
	return !is_even(p);
}
bool is_alpha(const char& c)
{
	return std::isalpha(static_cast<unsigned char>(c)) != 0;
}

bool compare_alpha(const std::string& a, const std::string& b)
{
	std::string::const_iterator it_a = std::find_if(a.begin(), a.end(), is_alpha);
	std::string::const_iterator it_b = std::find_if(b.begin(), b.end(), is_alpha);
	if (it_a == a.end() || it_b == b.end()) {
		return false;
	}
	return std::tolower(*it_a) < std::tolower(*it_b);
}
int _tmain(int argc, _TCHAR* argv[])
{
	
///////////////////////////////////////////////////////////////////

	//������� 1. ���������

	//����������� ���������. ����������� set<Point>. ���������, ���
	//����� ����������� � ������ Point. �������� ������, �������� �������� 
	//�������� ������� ��������� set, �� ����������� �� ��������
	std::set<Point> points;
	points.insert(Point(3, 1));
	points.insert(Point(1, 5));
	points.insert(Point(2, 3));
	points.insert(Point(1, 2));

	std::vector<Point> sorted_points;

	// ���������� ������� ���������� �� set � �������������� ����������� ����������
	for (std::set<Point>::reverse_iterator it = points.rbegin(); it != points.rend(); ++it) {
		sorted_points.push_back(*it);
	}

	// ����� ��������� �������
	for (std::vector<Point>::iterator it = sorted_points.begin(); it != sorted_points.end(); ++it) {
		std::cout << "Point(" << it->GetPointX() << ", " << it->GetPointY() << ")" << std::endl;
	}

	//��������� ���������. � ������� ostream_iterator �������� ����������
	//vector � set �� ����������� ������� �� �����.
	 // ����� ��������� ������� � �������������� ostream_iterator
	std::cout << "Vector elements: ";
	std::ostream_iterator<Point> vector_out(std::cout, ", ");
	std::copy(sorted_points.begin(), sorted_points.end(), vector_out);
	std::cout << std::endl;

	// ����� ��������� set � �������������� ostream_iterator
	std::cout << "Set elements: ";
	std::ostream_iterator<Point> set_out(std::cout, ", ");
	std::copy(points.begin(), points.end(), set_out);
	std::cout << std::endl;

	//��������� �������. � ������� ������������ ���������:
	//back_inserter()
	//front_inserter()
	//inserter()
	//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
	//����� �� ���������� ������� ����� ������������ � ������ �����������.
	//back_inserter: ������� �������� ������� � ������� ������ push_back ����������. 
	// ����� ������������ � ������������, ������� ������������ �������� push_back, ������ 
	// ��� vector, deque � list.
    // front_inserter: ������� �������� ������� � ������� ������ push_front ����������.
	//����� ������������ � ������������, ������� ������������ �������� push_front, ������ 
	//��� deque � list.
	// inserter : ������� �������� ������� � ������� ������ insert ����������.
	//����� ������������ � ������������, ������� ������������ �������� insert, ������ ��� 
	//set, map, list, vector, deque.

	std::vector<int> numbers = { 1, 2, 3, 4 };

	// ������������� back_inserter � ����������� std::vector
	std::vector<int> vector_result;
	std::copy(numbers.begin(), numbers.end(), std::back_inserter(vector_result));

	// ������������� front_inserter � ����������� std::deque
	std::deque<int> deque_result;
	std::copy(numbers.begin(), numbers.end(), std::front_inserter(deque_result));

	// ������������� inserter � ����������� std::list
	std::list<int> list_result;
	std::copy(numbers.begin(), numbers.end(), std::inserter(list_result, list_result.begin()));

	// ����� �����������
	std::cout << "Vector: ";
	for (std::vector<int> ::iterator it = vector_result.begin(); it != vector_result.end(); ++it) 
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Deque: ";
	//for (int num : deque_result) 
	for (std::deque<int> ::iterator it = deque_result.begin(); it != deque_result.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "List: ";
	//for (int num : list_result) 
	for (std::list<int> ::iterator it = list_result.begin(); it != list_result.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	stop
///////////////////////////////////////////////////////////////////

	//������� 2. ���������� ��������� (������������ ���� <algorithm>). ���������.

	// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
	//(������, vector, list...)
	//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
	//������������ �������� ���������
	//��������� : ������� ���������� ������� ���������� ��� ������
		std::vector<int> int_vector = { 1, 2, 3, 4, 5 };
	std::for_each(int_vector.begin(), int_vector.end(), print_element<int>);
	std::cout << std::endl;

	// ������ � std::list
	std::list<std::string> string_list = { "hello", "world", "C++", "for_each" };
	std::for_each(string_list.begin(), string_list.end(), print_element<std::string>);
	std::cout << std::endl;

	// ������ � ������� ��������
	double double_array[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	std::for_each(double_array, double_array + sizeof(double_array) / sizeof(double_array[0]), print_element<double>);
	std::cout << std::endl;


	stop

	//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
	//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
	//��� ������) � �������� ��������� � ������� ����������� ���������
		std::vector<Point> points2 = { Point(1, 2), Point(3, 4), Point(5, 6), Point(7, 8) };

	// ������������� ������� ��� ��������� ���������
	int dx = 2, dy = 3;
	std::for_each(points2.begin(), points2.end(), ChangeCoordinates<int>(dx, dy));

	// ����� �����������
	std::cout << "Modified points: ";
	std::for_each(points2.begin(), points2.end(), print_element<Point>);
	std::cout << std::endl;



	//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
	//��� ��������� �� ������� Point � ��������� ���������.
//��� ������������� ��������� find() � ���������� ���� Point, ����� ����������� �������� ��������� ==.

	std::vector<Point> points11 = { Point(1, 2), Point(3, 4), Point(5, 6), Point(7, 8), Point(5, 6) };

	Point target(5, 6);
	std::vector<Point>::iterator it = points11.begin();

	// ������������� ��������� find ��� ������ ��������� Point � ��������� ���������
	while ((it = std::find(it, points11.end(), target)) != points11.end()) {
		std::cout << "Found target at index " << std::distance(points11.begin(), it) << std::endl;
		++it;
	}
	
	
	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
	////�� ��������� �������� ��������� ������������������ �� �����������.
	//��� ������ ���� ���������� � ������ Point?
	// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
	//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!
	std::vector<Point> points5 = { Point(1, 2), Point(3, 4), Point(5, 6), Point(7, 8), Point(5, 6) };

	// ������������� ��������� sort ��� ���������� ������������������ ��������� Point
	std::sort(points5.begin(), points5.end());

	// ����� ��������������� ������������������
	for (std::vector<Point>::iterator it = points5.begin(); it != points5.end(); it++) {
		std::cout << *it << ' ';
	}

	std::cout << std::endl;
	std::list<Point> points7 = { Point(1, 2), Point(3, 4), Point(5, 6), Point(7, 8), Point(5, 6) };
	points7.sort();
	for (std::list<Point>::iterator it = points7.begin(); it != points7.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
	
	//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
	//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
	//[-n, +m].

	std::cout << std::endl;
	std::vector<Point> points9 = {Point(1, 2), Point(-3, 4), Point(5, -6), Point(7, 8), Point(5, 6)};
	std::vector <Point>::iterator it12 = points9.begin();
	std::vector <Point> new_points9;

	while (it12 != points9.end())
	{
		it12 = find_if(it12, points9.end(), Diapason(1, 7));
		if (it12 != points9.end())
		{
			new_points9.push_back(*it12);
			++it12;
		}
	}


	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
	//���������� �������������� �� �������� ������ �� ������ ���������.
	std::vector<Rect> rects{
		Rect(-1, -1, 2, 2), // dist = sqrt(2)
		Rect(-2, -2, 1, 1), // dist = sqrt(8)
		Rect(0, 0, 3, 3),   // dist = sqrt(18)
		Rect(1, -1, 1, 3),  // dist = sqrt(11)
	};
	std::sort(rects.begin(), rects.end(), CompareRectsByDistanceFromOrigin());
	for (const auto& r : rects) {
		std::cout << r << ", area = " << r.area() << std::endl;
	}






	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()
				std::string text = "Convert Me To Lowercase";
				to_lower_case(text);
				std::cout << "Converted string: " << text << std::endl;

		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
				std::list<std::string> input_strings;
				input_strings.push_back("Hello");
				input_strings.push_back("World");
				input_strings.push_back("Transform");
				input_strings.push_back("ToLower");

				std::set<std::string> lower_case_strings;

				//for (std::list<std::string>::const_iterator it = input_strings.begin(); it != input_strings.end(); ++it) {
				//	std::string lower_case_string;
				//	std::transform(it->begin(), it->end(), std::back_inserter(lower_case_string), to_lower);
				//	lower_case_strings.insert(lower_case_string);
				//}
				std::transform(input_strings.begin(),input_strings.end(), std::inserter(lower_case_strings, lower_case_strings.begin()), to_lower_case);
				std::cout << "Lower case strings in the set:" << std::endl;
				for (std::set<std::string>::const_iterator it = lower_case_strings.begin(); it != lower_case_strings.end(); ++it) {
					std::cout << *it << std::endl;
				}



		stop
	}
	
	{//copy_if
		//��� ������ � ���������� ���� string. � ������� copy_if() ���������
		//������� ������� ������, ������������ � ����� "�" ��� "�", ����� � "�"...
		//��� ���� ������� ����� � �������� ������� ������ �� �����!
		std::vector<std::string> words = {"Yes","antrekot","Bob" ,"apple", "Banana", "Carrot", "123", "Dog","qwe123", "elephant"};
		/*for (char c = 'A'; c <= 'Z'; c++) 
		{
			for (const std::string& word : words) 
			{
				if (!word.empty() && std::toupper(word[0]) == c) 
				{
					std::cout << word << '\n';
				}
			}
		}*/
		for (char c = 'A'; c <= 'Z'; c++)
		{
			std::vector<std::string>::iterator it = std::find_if(words.begin(), words.end(), Predicat(c));
			if (it != words.end())
			{
				std::copy_if(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "), Predicat(c));
				std::cout << "\n";
			}
		}


		stop

		//��� multimap, ���������� ����: "����� - ���������� ���� � ������"
		//pair<string, int>. � ������� copy_if ����������� ��� map-�: ������ -
		//� ������, ����������� ������ ���������� ����, 2-�� - ��������.
		std::multimap<string, int> month {
			{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};
		
		std::map<std::string, int> even_month, odd_month;
		std::copy_if(month.begin(), month.end(), std::inserter(even_month, even_month.end()), is_even);
		std::copy_if(month.begin(), month.end(), std::inserter(odd_month, odd_month.end()), is_odd);


		stop

			//������������ multimap � map-�, ��������� ���������� ���� ����� ������
			//�������, ��������� �������� ������ ���������� �� ������.
			//��� ����� ������� ������������� ��� ������ ����?
			std::cout << "Source multimap:";
		print_container(month);
		std::cout<<std::endl;
		std::cout << "Even Month map:";
		print_container(even_month);
		std::cout << std::endl;
		std::cout << "Odd Month map:";
		print_container(odd_month);
		std::cout << std::endl;

	
		stop
	}

	return 0;
}

