//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

#include <iostream>
#include <vector>
#include "MyString.h"
#include "Point.h"
#include <list>
#include <deque>
#pragma warning(disable: 4786)


using namespace std;	

#define	  stop __asm nop

template<typename T>
void printVectorInfo(const std::vector<T>& vec) {
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	std::cout << "Max size: " << vec.max_size() << std::endl;
	std::cout << "Elements:" << std::endl;
	for (auto elem : vec) {
		std::cout << elem << std::endl;
	}
}
void insert(std::vector<char>& vec, char value)
{
	if (std::find(vec.begin(), vec.end(), value) == vec.end())
	{
		vec.insert(vec.begin(), value);
	}
}
template<typename T>
void insertBeforeEach(std::vector<T>& vec, const T& val) 
{
	for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); it += 2)
	{
		it = vec.insert(it, val);
	}
}
//std::vector<char> removeRepeating(const std::vector<char>& vec) {
//	std::vector<char> result;
//	char prevChar = '\0';
//	for (const auto& currChar : vec) {
//		if (currChar != prevChar) {
//			result.push_back(currChar);
//			prevChar = currChar;
//		}
//	}
//	return result;
//}
void removeRepeating(std::vector<char>& vec) {
	typename std::vector<char>::iterator it = vec.begin();

	while (it != vec.end()) {
		typename std::vector<char>::iterator next = it + 1;

		if (next == vec.end() || *it != *next) {
			++it;
		}
		else {
			while (next != vec.end() && *it == *next) {
				++next;
			}
			it = vec.erase(it, next);
		}
	}
}
void removeDuplicates(std::vector<char>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		for (size_t j = i + 1; j < vec.size(); ) {
			if (vec[j] == vec[i]) {
				vec.erase(vec.begin() + j);
			}
			else {
				++j;
			}
		}
	}
}
template<typename T>
std::vector<T> reverseCopy(const std::vector<T>& vec) 
{
	std::vector<T> result(vec.rbegin(), vec.rend());
	return result;
}
template <typename Container>
void printContainer(const Container& cont, std::ostream& out)
{
	out << "Container type: " << typeid(cont).name() << std::endl;
	for (auto& element : cont) {
		out << element << " ";
	}
	out << std::endl;
}
bool isNegative(const Point &p) 
{
	return p.GetPointX() < 0 || p.GetPointY() < 0;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vv) {
	//for (const auto& row : vv) {
		for (const auto& elem : vv) {
			os << elem << ' ';
		}
		os << '\n';
	//}
	return os;
}
int main()
{
	srand(time(NULL));
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 

	vector<int> vInt;
	std::cout << "������ �������=" <<vInt.size() << std::endl;
	
	
	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������

	//vInt.front()=1;
	vInt.push_back(1);
	std::cout<<"First element"<<vInt.front() << std::endl;
	
	

	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	//
	//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	//������� ��� "���������" � �������� ��������� �� �������.
	for (size_t i = 0; i < 10 /*vInt.size()*/; i++)
	{
		vInt.push_back(rand()%10);
		printVectorInfo(vInt);
	}


	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?
	vector<double> vDouble1(10);
	for (size_t i = 0; i < vDouble1.size(); i++)
	{
		printVectorInfo(vDouble1);
	}

	//������ �������� ���� MyString � ��������� �������� - 5 ���������
	//� �������������� ������� �������� ������� "A"
	//C ������� ������� at() � ����� � ������� ���������
	//�������������� []  �������� �������� �����-���� ���������.
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. 
	std::vector<MyString> vec(5, "A"); // ������� ������ �� 5 ��������� ���� MyString, ������������������ ������� "A"
	std::cout << "Original vector:" << std::endl;
	for (int i = 0; i < vec.size(); i++) {
		std::cout << "Element " << i << ": " << vec[i] << std::endl; // ������� �������� �������
	}

	vec.at(2) = "B"; // �������� �������� �������� � �������� 2 � ������� ������� at()
	vec[4] = "C"; // �������� �������� �������� � �������� 4 � ������� ��������� �������������� []

	std::cout << "Modified vector:" << std::endl;
	for (int i = 0; i < vec.size(); i++) {
		std::cout << "Element " << i << ": " << vec[i] << std::endl; // ������� ���������� �������� �������
	}

	// ������� ���������� � ��������� �� ��������� �������
//	std::cout << vec.at(5) << std::endl; // ������� ���������� std::out_of_range
//	std::cout << vec[6] << std::endl; // ��������� �����������, ��� ��� �� ���������� �� ������� �������




	//������ ������������ - vDouble3, ������� �������� ������ ���������
	// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
	//����� ������� � �������������������!
	double dMas[5] = { 1.2, 2.3, 3.4, 4.5, 5.6 }; // ������� � �������������� ������ ������������ �����
	std::vector<double> vDouble3(dMas, dMas + 5); // ������� ������ � �������� �������� ������� ������

	std::cout << "Array elements:" << std::endl;
	for (int i = 0; i < 5; ++i) {
		std::cout << dMas[i] << " "; // ������� �������� �������
	}
	std::cout << std::endl;

	std::cout << "Vector elements:" << std::endl;
	for (int i = 0; i < vDouble3.size(); ++i) {
		std::cout << vDouble3[i] << " "; // ������� �������� �������
	}
	std::cout << std::endl;

	

	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [2,5) ������� vDouble3. 
	std::vector<double> vDouble4; 

	vDouble4.assign(vDouble3.begin() + 2, vDouble3.begin() + 5); // �������� �������� [2,5) �� vDouble3 � vDouble4

	std::cout << "vDouble3 elements:" << std::endl;
	for (int i = 0; i < vDouble3.size(); ++i) {
		std::cout << vDouble3[i] << " "; // ������� �������� vDouble3
	}
	std::cout << std::endl;

	std::cout << "vDouble4 elements:" << std::endl;
	for (int i = 0; i < vDouble4.size(); ++i) {
		std::cout << vDouble4[i] << " "; // ������� �������� vDouble4
	}
	std::cout << std::endl;


//*
	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?
	// �) ���� ������ vPoint1 ���������������� � ��������� �������� 3, 
	// �� ��� ������� �������� ����� ������ ����������� �� ��������� ��� ������ Point.
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).
	std::vector<Point> vPoint2(5, Point(1, 1));


	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	
	{
		std::vector<Point*> vpPoint(5);
		for (int i = 0; i < 5; i++)
		{
			vpPoint[i] = new Point(i, i);
		}
		for (int i = 0; i < 5; i++)
		{
			std::cout << vpPoint[i] << std::endl;
		}
		
		for (int i = 0; i < 5; i++) {
			delete vpPoint[i];
		}
		vpPoint.clear();

	//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
		//�) ������������� ����� ��������� �������
		//�) ��� ���������� operator<< ��� Point*

	}//����� �������������� �������� ����� ����������� ��� ������ �������?


	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
		
	{
		size_t n = 10;
		vector<int> v(n);
		v.resize(n / 2);
		if (v.capacity() == n)
		{
			//���������� ������ v ��� ������ � �������� n � �������� n(��� ��� ������������
			//����������� vector<int> v(n); , ������� ������� ������ �������� n � ��������� 
			//��� ���������� �� ���������).
			//����� ���������� v.resize(n / 2); , ������� �������� ������ ������� �� n / 2,
			//�� ���� 5, �� ������� ������� �� ����������, 
			//������� �� �� - �������� �������� n ������� � ������.
			//����� �������, if (v.capacity() == n) ������ true.
		}
	}
		

		
	{
		int n = 10;
		size_t m = 10;
		vector<int> v(n);
		v.reserve(m);
		if (v.capacity() == m)
		{
			//���� m ����� n, �� ������� if (v.capacity() == m) ������ true.
			//���� m ������ n, �� v.capacity() ������ �������� m � ������� ����� ������ true.
			//���� m ������ n, �� v.capacity() ������ �������� �� ������ n, ������� 
			//������� if (v.capacity() == m) ������ false.
		}
	}
		

		
		{
		vector<int> v(3,5);
		v.resize(4,10); //��������?
		v.resize(5); //��������?
		//���������� ��������� ������ v � ����� ����������, ������ �� ������� ����� 5. 
		//����� ���������� ������� resize(4, 10), ������� ����������� ������ ������� �� 4 
		//� ��������� ����� ������� ��������� 10. 
		//� ����� ������ ����� ����� ��������� ���������� : {5, 5, 5, 10}.
		//����� ���������� ������� resize(5), 
		//������� ����������� ������ ������� �� 5 � 
		//��������� ����� ������� ��������� �� ��������� ��� ���� ��������� �������
		}
		

	//�������� ��� "������" ������� � ����������
	//������ (�� ������ � ���� �� ����) ����. 
	//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
	//��� ���������� � ������� push_back.
	//������ ������ ������ ��������� ���������� ����������� push_back.
	//
	//�������� ������, ������� �������� � �������� ���������
		vector<int> v1;
		vector<int> v2;

		// ����������� ������ ��� 5 ���������
		v1.reserve(5);

		// ��������� ������ ������ ����������
		for (int i = 1; i <= 5; i++) {
			v1.push_back(i);
		}

		// ��������� ������ ������ ����������
		for (int i = 1; i <= 5; i++) {
			v2.push_back(i * 2);
		}
		printVectorInfo(v1);
		printVectorInfo(v2);	



	//!!! shrink_to_fit - ���������� ������� �������.
	//��� ������ ������� �� ����������� ������� ��������� ��������� �������
	//�� size.
		size_t size = 2;
		v1.resize(size);
		v2.resize(size);
		v1.shrink_to_fit();
		v2.shrink_to_fit();
		printVectorInfo(v1);
		printVectorInfo(v2);
	

	//�������� "����������� �������" - ������� ��������
	//����� ���������� ������ int ar[] = {11,2,4,3,5};
	//�������� ������ �������� ��������� �������:
	//������ vv[0] - �������� 11 ��������� �� ��������� 11
	//vv[1] - �������� 2,2
	//vv[2] - �������� 4,4,4,4
	//...
	//������������ ���������� ������ ����������� ������� �� �������
	//� �������:
		int ar[] = { 11, 2, 4, 3, 5 };
		std::vector<std::vector<int>> vv;

		for (const int& num : ar) {
			std::vector<int> row(num, num);
			vv.push_back(row);
		}

		std::cout << vv << std::endl;
	//std::cout<<vv<<std::endl;
		//��������� �������� ������ � ����� ��� �������, � �� ��� ������� �������.
		//������ �������
	 stop

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//������� �������� ������������������ insert().
	//���������� �������, ������� ������ ��������� ����� �������
		//� ������ ������� ������ ��� �������, ��� � ������� ������
		 //�������� ��� ���.
	//��������� ����������������� ������� - � ������ vChar2 �������� � ������ ������� ������ ������ ���
	//�������, ��� � ������� ������ ������� ��� ���.
		 //��������: vChar2 - abc 
		 //��� ������� �������� 'a' ������� ������ ���� ���������������
		 //��� ������� �������� 'q' vChar2 - qabc 

	 std::vector<char> vChar2{ 'a', 'b', 'c' };
	 insert(vChar2, 'a'); // ������������, ��� ��� 'a' ��� ���� � �������
	 insert(vChar2, 'q'); // ����������� � ������, ��� ��� 'q' �� ���� � �������
	 for (auto c : vChar2) {
		 std::cout << c << " ";
	 }
	 std::cout << std::endl; // ������� "q a b c "
	 stop
	

	//���������� �������, ������� ������ ��������� ����� �������
		 //����� ������ ��������� �������
	//��������� ����������������� ������� - �������� ����� ������ ��������� ������� vChar2 ����� 'W'
	/* insertBeforeEach(vChar2, 'W');
	 for ( auto elem : vChar2) 
	 {
		 std::cout << elem << " ";
	 }
	 std::cout << std::endl; */
	 //����� ������������ ������� insert, ��� ��������������� �����������, �������� � ������ ������� W
	 std::vector<char> vChar7 = { 'A', 'B', 'C', 'D', 'E' };
	 insertBeforeEach(vChar7, 'W');

	 for (typename std::vector<char>::const_iterator it = vChar7.begin(); it != vChar7.end(); ++it) {
		 std::cout << *it << " ";
	 }
	 std::cout << std::endl;
///
///////////////////////////////////////////////////////////////////
	//�������� �������, ������� ������ ������� ������ ������������� ������������������.
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
	/* std::vector<char> vec1 = { 'q','q', 'w', 'e', 'r', 'r', 'r', 'r', 't', 'y', '1', '2', '2', '2', '2', 'r', '3', '3'};
	 std::cout << "Original vector: ";
	 for (const auto& ch : vec) {
		 std::cout << ch;
	 }
	 std::cout << std::endl;
	 vec1 = removeRepeating(vec1);
	 std::cout << "Vector with repeating sequences removed: ";
	 for (const auto& ch : vec1) {
		 std::cout << ch;
	 }
	 std::cout << std::endl; */
//������ ������������� ����������
//������������ erase()
	 //std::vector<char> vec1 = { 'q', 'q', 'w', 'e', 'r', 'r', 'r', 'r', 't', 'y', '1', '2', '2', '2', '2', 'r', '3', '3' };
	 std::vector<char> vec1 = { 'q','q','q', 'w','w', 'e', 'r', 'r', 'r', 'r', 't', 'y', '1', '2', '2', '2', '2', 'r', '3','3' };
	 std::cout << "Original vector: ";
	 for (typename std::vector<char>::const_iterator it = vec1.begin(); it != vec1.end(); ++it) {
		 std::cout << *it;
	 }
	 std::cout << std::endl;

	 removeRepeating(vec1);
	 std::cout << "Vector with repeating sequences removed: ";
	 for (typename std::vector<char>::const_iterator it = vec1.begin(); it != vec1.end(); ++it) {
		 std::cout << *it;
	 }
	 std::cout << std::endl;
	stop

///////////////////////////////////////////////////////////////////

	//�������� �������� ������������������ erase()
	//�������� ������� �������� �� ������ ������� ���� ������ 
		 //��������: ���� - "qwerrrrty12222r3", ����� - "qwerty123"

		std::vector<char> vec2 = { 'q', 'w', 'e', 'r', 'r', 'r', 'r', 't', 'y', '1', '2', '2', '2', '2', 'r', '3' };
	std::cout << "Original vector: ";
	for (const auto& ch : vec2) {
		std::cout << ch;
	}
	std::cout << std::endl;
	removeDuplicates(vec2);
	std::cout << "Vector with duplicates removed: ";
	for (const auto& ch : vec2) {
		std::cout << ch;
	}
	std::cout << std::endl;

	

///////////////////////////////////////////////////////////////////
	//�������� ����� ������ ����� �������, ����� ��� �������� �����
	//������� ��������� ������ �� ��������� ����� ��������, �� �����������
	//���� �� � �������� �������

	std::vector<int> vec3{ 1, 2, 3, 4, 5 };
	std::vector<int> reversedVec = reverseCopy(vec3);
	for (const auto& elem : reversedVec) {
		std::cout << elem << " "; // ������� "5 4 3 2 1"
	}




///////////////////////////////////////////////////////////////////

	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()
	std::list<Point> ptList1;

	// ���������� ��������� � ����� ������
	ptList1.push_back(Point(1, 2));
	ptList1.push_back(Point(3, 4));

	// ���������� ��������� � ������ ������
	ptList1.push_front(Point(5, 6));
	ptList1.push_front(Point(7, 8));

	// ������� �������� � �������� ������
	std::list<Point>::iterator it = ptList1.begin();
	it++; // ��������� �� ������� �������� ������
	ptList1.insert(it, Point(9, 10));

	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.
	std::vector<int> vec5 = { 1, 2, 3, 4, 5 };
	std::list<std::string> lst2 = { "Hello", "world", "!" };

	printContainer(vec5, std::cout);
	printContainer(lst2, std::cout);

	//�������� ����� �� ������� "�����������" - reverse()
	lst2.reverse();

	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� 
	std::vector<Point> vPoint = { {1, 2}, {3, 4},{2,3},{-1,-3}, {5, 6}, {7, 8} ,{-9,-200} };

	std::list<Point> ptList2;
	for (auto it = vPoint.rbegin(); it != vPoint.rend(); ++it) {
		ptList2.push_back(*it);
	}
	printContainer(ptList2, std::cout);


	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������

	ptList1.sort();
	ptList2.sort();
	
	printContainer(ptList2, std::cout);

	stop

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� � ������ �������.
		//��� ������������� ������ merge() ���� ��������������� �������, 
		//��� ������������ � ���� ��������������� ������, 
		//� �� �������� �������� ������������ � ����� ������.
		//�� ����, ����� �������� ����������� ������ ptList1 � ptList2 
		//����� �������.
		ptList1.merge(ptList2);
	printContainer(ptList1, std::cout);
	stop

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ������ ���� ����������� � ������ Point?
		//�������� ���������
		Point p(2, 3);//
	ptList1.remove(p);
//	ptList1.remove(Point(2, 3));
	printContainer(ptList1, std::cout);
	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if(). 
	ptList1.remove_if(isNegative);
	printContainer(ptList1, std::cout);
	//���������� �� ������ ������ ������������� ������ - unique(). 
	ptList1.unique();
	//printContainer(ptList2, std::cout);

///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque
	stop

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������
	std::vector<Point> vec6{ Point(1, 2), Point(3, 4), Point(5, 6) };
	std::deque<Point> deq;
	deq.assign(vec6.begin(), vec6.end());
//	printContainer(deq);


	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'
	std::deque<MyString> strings;
	MyString a;
	strings.push_back("Apple");
	strings.push_front("Banana");
	strings.insert(strings.begin() + 1, "Apricot");
	strings.push_back("Orange");
	strings.push_front("Avocado");
	strings.insert(strings.end() - 1, "Mango");

	std::cout << "Before removing 'A' and 'a' strings:" << std::endl;
	for (const auto& str : strings) {
		std::cout << str << std::endl;
	}
	a.removeAStrings(strings);
	std::cout << "After removing 'A' and 'a' strings:" << std::endl;
	for (const auto& str : strings) {
		std::cout << str << std::endl;
	}

	return 0;
}