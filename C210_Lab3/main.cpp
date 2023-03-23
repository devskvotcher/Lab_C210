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
void insertBeforeEach(std::vector<T>& vec, const T& val) {
	std::vector<T> newVec;
	for (const auto& elem : vec) {
		newVec.push_back(val);
		newVec.push_back(elem);
	}
	vec = newVec;
}
std::vector<char> removeRepeating(const std::vector<char>& vec) {
	std::vector<char> result;
	char prevChar = '\0';
	for (const auto& currChar : vec) {
		if (currChar != prevChar) {
			result.push_back(currChar);
			prevChar = currChar;
		}
	}
	return result;
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



	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).



	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{

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
	
	//std::cout<<vv<<std::endl;
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

	

	//���������� �������, ������� ������ ��������� ����� �������
		 //����� ������ ��������� �������
	//��������� ����������������� ������� - �������� ����� ������ ��������� ������� vChar2 ����� 'W'
	 insertBeforeEach(vChar2, 'W');
	 for ( auto elem : vChar2) 
	 {
		 std::cout << elem << " ";
	 }
	 std::cout << std::endl;


///////////////////////////////////////////////////////////////////
	//�������� �������, ������� ������ ������� ������ ������������� ������������������.
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
	 std::vector<char> vec1 = { 'q', 'w', 'e', 'r', 'r', 'r', 'r', 't', 'y', '1', '2', '2', '2', '2', 'r', '3' };
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
	std::vector<Point> vPoint = { {1, 2}, {3, 4}, {5, 6}, {7, 8} };

	std::list<Point> ptList2;
	for (auto it = vPoint.rbegin(); it != vPoint.rend(); ++it) {
		ptList2.push_back(*it);
	}


	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������

	ptList1.sort();
	ptList2.sort();
	


	stop

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� � ������ �������.
		//��� ������������� ������ merge() ���� ��������������� �������, 
		//��� ������������ � ���� ��������������� ������, 
		//� �� �������� �������� ������������ � ����� ������.
		//�� ����, ����� �������� ����������� ������ ptList1 � ptList2 
		//����� �������.
		ptList1.merge(ptList2);
	stop

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ������ ���� ����������� � ������ Point?
		//�������� ���������
		Point p(2, 3);
	ptList1.remove(p);

	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if(). 
	ptList1.remove_if(isNegative);
	ptList2.remove_if(isNegative);

	//���������� �� ������ ������ ������������� ������ - unique(). 
	ptList1.unique();
	stop

///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque

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




	return 0;
}