// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include "Point.h"
#include <iostream>
#include <tchar.h>

class StudentGroups
{
	std::map<int, std::vector<std::string>> groups;
public:
	void add_student(int group, const std::string& surname)
	{
		groups[group].push_back(surname);
		std::sort(groups[group].begin(), groups[group].end());
	}
	friend std::ostream& operator<<(std::ostream& os, const StudentGroups& sg);
};
#define stop __asm nop
template <typename Container>
void print_container(const Container& container)
{
	// ��� stack
	if constexpr (std::is_same_v<Container, std::stack<typename Container::value_type>>)
	{
		std::stack<typename Container::value_type> temp_container = container;
		while (!temp_container.empty())
		{
			std::cout << temp_container.top() << ' ';
			temp_container.pop();
		}
		std::cout << '\n';
	}
	// ��� queue � priority_queue
	else
	{
		for (auto&& element : container)
		{
			std::cout << element << ' ';
		}
		std::cout << '\n';
	}
}
std::ostream& operator<<(std::ostream& os, const StudentGroups& sg)
{
	for (const auto& group : sg.groups)
	{
		os << "Group " << group.first << ": ";
		for (const auto& surname : group.second)
		{
			os << surname << " ";
		}
		os << std::endl;
	}
	return os;

}
int _tmain()
{

	
	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
	//��������� ��������
	// 
	//������� ���������� ��������� �������� Container, ������� ������ ���� ����������� ���� 
	//std::stack, std::queue ��� std::priority_queue.
	//� ����������� �� ���� ���������� ������� ���������� ��������������� ����� ��� ��������� ��������� �� ����������.
	//��� ����� ������������ ��������� ���������, � ������� �������� ���������� �� ��������� ����������
	//� �� �������� ��� ��������� � �������� ������� � ������� ������� top � pop.
	//��� ������� � ������������ ������� ������������ ���� for, ������� ���������� ��� �������� ���������� 
	//� ������� �� �� ����� � ������� ��������� << .

//	std::stack<int> my_stack{ 1, 2, 3, 4, 5 };
//	std::queue<int> my_queue{1, 2, 3, 4, 5 };
	

//	print_container(my_stack);           // ������� "5 4 3 2 1\n"
//	print_container(my_queue);           // ������� "1 2 3 4 5\n"
//	print_container(my_priority_queue);  // ������� "5 4 3 2 1\n"

	


	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 

	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	std::vector<int> vec_copy = vec; // ������� ����� �������
	std::stack<int, std::vector<int>> my_stack{ vec_copy }; // ������� ���� �� ������ ����� �������
	// ������� �������� ������� � ����� � ����� �����
	std::cout << "Vector: ";
	for (auto&& element : vec)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';

	std::cout << "Stack: ";
	while (!my_stack.empty())
	{
		std::cout << my_stack.top() << ' ';
		my_stack.pop();
	}
	std::cout << '\n';
	


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?
	std::deque<Point*> my_deque;

	// ������� ������� Point � ������� ��������� new � �������� ��������� �� ��� � �������
	my_deque.push_back(new Point(1, 2));
	my_deque.push_back(new Point(3, 4));
	my_deque.push_back(new Point(5, 6));

	// �������� �������� ������� � ���������� ��������� ����������� front() � back()
	(*my_deque.front()).SetPointX(10);
	my_deque.back()->SetPointY(20);
	//my_deque.back()->m_x = 10;  //��� ������-�� �� ����������
	//(*my_deque.front()).m_y =20; // � ��� ����
	// ������� �������� ��������� �������
	for (auto&& element : my_deque)
	{
		std::cout << *element << ' ';
	}
	std::cout << '\n';

	// ������� ������� Point �� ������� � ����������� ���������� ��� ��� ������
	while (!my_deque.empty())
	{
		delete my_deque.front();
		my_deque.pop_front();
	}







	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?
	const char* arr[] = { "b", "c", "d", "a" };
	std::priority_queue<const char*> pq(arr, arr + 4);

	std::cout << "Elements in priority queue: " << std::endl;
	while (!pq.empty()) {
		std::cout << pq.top() << " ";
		pq.pop();
	}

	//��� ������ ��������� �� �������, ��� ����� ���������� � ������� ��������, 
	//�.�.������������ ������� ������ ���������� ���������� �������.
	//����� �������, ����� �������� pq ����� ����� ��������� ������� : "d c b a".
	//����� �������� ������� ������ ���������, ����� �������� ���������� � �������� 
	//�������� ��������� � ������� - ����������� ������� � �����������.
	//��������, ���� �� ����� �������� �������� � ������� �����������, 
	//�� �� ����� ������������ ���������� std::greater<const char*>() 
	//������ ����������� �� ��������� std::less<const char*>().

//	��� ������� � ������������ ������� ������������ �������� ���������, ����� ���������� �� ���������.
	//����� ������� ���������� ��������� ������� �� ���������� �����������.���� ���������� �� ������, 
	//������������ ���������� �� ��������� - std::less, ������� ���������� �������� ��������� � ������� ��������� < .
	//� ������ � ���������� ���� const char*, ��� ������������� ����������� �� ���������, 
	//�������� ��������� ������������ ����������������� - ����������� ����� �������.
	//����� ���������� CompareStringLength ���������� ��� ������ �� �� ������ - 
	//������ a ����� ��������� "������" ������ b, ���� �� ����� ������ ����� ������ b.


	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	// ���������� ���������� ��������� ���������: < � ==
	std::set<Point> points;
	points.insert(Point(3, 5));
	points.insert(Point(1, 2));
	points.insert(Point(4, 7));
	points.insert(Point(2, 6));
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������...
	//���� �� ���������� �������� �������� �������� � ���������, ��� �������� � ������ ����������. 
	//��� ������� � ���, ��� �������� � ��������� �� ����� ���� �������� ���������������. 
	//���� �� ����� �������� �������� ��������, �� ������ ������� ������� ��� �� ���������, 
	//�������� �������� � ����� �������� ������� �����. 
	auto it = points.find({ 1, 2 }); // ������� ������� � ���������
	if (it != points.end()) {
		points.erase(it); // ������� �������
		Point new_point = { 3, 4 }; // ������� ����� �������
		points.insert(new_point); // ��������� ����� �������
	}
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	std::set<int> set1{ 1, 2, 3, 4, 5 };
	std::set<int> set2{ 5, 2, 4, 1, 3 };

	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)
	int arr5[]{ 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
	std::set<int> set3{ 1, 2, 3 };

	for (int i = 0; i < sizeof(arr5) / sizeof(int); ++i) {
		set3.insert(arr5[i]);
	}

	std::cout << "set1 contains:";
	for (auto it = set3.begin(); it != set3.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
		//��������� ����� ������������� �������, ��� ��� ��������� �� ����� ��������� ������������� ��������.



	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
		std::map<const char*, std::pair<const char*, int>> employees{
	{"������", {"������", 50000}},
	{"������", {"������", 60000}},
	{"�������", {"�������", 55000}}
		};
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	 std::map<const char*, std::pair<const char*, int>> employees2;
	 employees2["John"] = { "Smith", 50000 };
	 employees2["Jane"] = { "Doe", 60000 };
	 employees2.insert({ "Bob", {"Jones", 70000} });
	 employees2.insert({ "Alice", {"Johnson", 80000} });
	//�) ������������ ����������
	 for (auto it = employees.begin(); it != employees.end(); ++it) {
		 std::cout << it->first << ": " << it->second.first << ", " << it->second.second << std::endl;
	 }
	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")
	 employees.erase("�������");
	 employees.insert({ "�������", {"�������", 50000} });
	stop
	

		
		//�) ����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������
		std::vector<std::string> vec8{ "apple", "banana", "orange", "apple", "orange", "banana" };

	std::map<std::string, int> str_count;
	for (const auto& str : vec8) {
		auto it = str_count.find(str);
		if (it == str_count.end()) {
			str_count.insert({ str, 1 });
		}
		else {
			it->second++;
		}
	}

	for (const auto& pair : str_count) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}




		//�) 
		//����� ������:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
		//��������������� ������������� ����, ������������ � ���� �����.
		//���������: �� ����� ������� ����� ����� � ��� �� ������
	
		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
	const char* words[] = { "Abba", "Alfa", "Beta", "Beauty"};
	const int num_words = sizeof(words) / sizeof(words[0]);

	std::map<char, std::vector<std::string>> word_map;

	// ���������� map
	for (int i = 0; i < num_words; ++i) {
		const std::string word(words[i]);
		if (word_map.find(word[0]) == word_map.end()) {
			// ���� ����� ��� ��� � map, ������� ����� ������
			word_map[word[0]] = std::vector<std::string>{ word };
		}
		else {
			// ����� ��������� ����� � ������ �������� �� �����
			auto& vec = word_map[word[0]];
			if (std::find(vec.begin(), vec.end(), word) == vec.end()) {
				vec.push_back(word);
				// ���������� ������� ��� ���������� �������
				std::sort(vec.begin(), vec.end());
			}
		}
	}

	// ����� ����������� map
	for (const auto& kv : word_map) {
		std::cout << kv.first << ": ";
		for (const auto& word : kv.second) {
			std::cout << word << " ";
		}
		std::cout << std::endl;
	}

//	C�����v ������ map � ������� ���� char � ���������� ���� std::vector<std::string>.
	//����� �������v �� ������� ���� words, ��������� ������ ����� ������� ����� � ��������� ��� � ������ ��������
	//�� �������������� ���������������� ����� � map. ���� ����� ��� ���� � ������� ��������, ��� �� ����������� ��� ���.
//	����� ���������� map ���� ������� ���������� ������� ����� � ���������������� ��� ������� ��������.
	// B������ �������� ��� ������������� �� ��������, ��� ��� �� ��������� ����� ����� ������ � ��������������� ������.


		//�)
		//�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
		//��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
		//������� ����� �������������
		//���� ������ ���� ������ ���� ����������� �� ������
		
	StudentGroups groups;
	groups.add_student(1, "������");
	groups.add_student(1, "������");
	groups.add_student(1, "�������");
	groups.add_student(1, "�������");
	groups.add_student(1, "�������");
	groups.add_student(2, "������");
	groups.add_student(2, "������");
	groups.add_student(2, "������");
	groups.add_student(2, "������");
	groups.add_student(2, "�������");
		//������ 
	//
	std::cout << groups << std::endl;


	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()




   

  stop

	return 0;
}

