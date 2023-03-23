// Контейнеры STL: 
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
#include "Template.h"
//class StudentGroups
//{
//	std::map<int, std::multiset<std::string>> groups;
//public:
//	void add_student(int group, const std::string& surname)
//	{
//		groups[group].push(surname);
//		std::sort(groups[group].begin(), groups[group].end());
//	}
//	friend std::ostream& operator<<(std::ostream& os, const StudentGroups& sg);
//};
#define stop __asm nop

//std::ostream& operator<<(std::ostream& os, const StudentGroups& sg)
//{
//	for (const auto& group : sg.groups)
//	{
//		os << "Group " << group.first << ": ";
//		for (const auto& surname : group.second)
//		{
//			os << surname << " ";
//		}
//		os << std::endl;
//	}
//	return os;
//
//}
int _tmain()
{
	setlocale(NULL, "Rus");
	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений
	// 
	//Функция использует шаблонный параметр Container, который должен быть контейнером типа 
	//std::stack, std::queue или std::priority_queue.
	//В зависимости от типа контейнера функция использует соответствующий метод для получения элементов из контейнера.
	//Для стека используется временный контейнер, в который элементы копируются из исходного контейнера
	//и из которого они выводятся в обратном порядке с помощью методов top и pop.
	//Для очереди и приоритетной очереди используется цикл for, который перебирает все элементы контейнера 
	//и выводит их на экран с помощью оператора << .

	std::stack<int> my_stack;
	my_stack.push(1);
	my_stack.push(2);
	my_stack.push(3);
	my_stack.push(4);
	my_stack.push(5);
	std::queue<int> my_queue;
	my_queue.push(1);
	my_queue.push(2);
	my_queue.push(3);
	my_queue.push(4);
	my_queue.push(5);
	std::priority_queue<int> my_priority_queue;
	my_priority_queue.push(1);
	my_priority_queue.push(2);
	my_priority_queue.push(3);
	my_priority_queue.push(4);
	my_priority_queue.push(5);

	print_adapter(my_stack);           // выводит "5 4 3 2 1\n"
	print_adapter(my_queue);           // выводит "1 2 3 4 5\n"
	print_adapter(my_priority_queue);  // выводит "5 4 3 2 1\n"

	

	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 
	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	std::vector<int> vec_copy(vec.rbegin(), vec.rend()); // создаем копию вектора
	std::stack<int, std::vector<int>> my_stack2{ vec_copy }; // создаем стек на основе копии вектора
	// выводим значения вектора и стека в одном цикле
	std::cout << "Vector: ";
	//for (auto&& element : vec)
	//{
	//	std::cout << element << ' ';
	//}
	print_container_impl(vec);
	std::cout << '\n';
	
	std::cout << "Stack: ";
	//while (!my_stack2.empty())
	//{
	//	std::cout << my_stack2.top() << ' ';
	//	my_stack2.pop();
	//}
	print_adapter(my_stack2);
	std::cout << '\n';
	


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	std::queue<Point*> my_deque;

	// создаем объекты Point с помощью оператора new и помещаем указатели на них в очередь
	my_deque.push(new Point(1, 2));
	my_deque.push(new Point(3, 4));
	my_deque.push(new Point(5, 6));

	// изменяем значения первого и последнего элементов посредством front() и back()
	(*my_deque.front()).SetPointX(10);
	my_deque.back()->SetPointY(20);
	//my_deque.back()->m_x = 10;  //Так почему-то не получилось
	//(*my_deque.front()).m_y =20; // И так тоже
	// выводим значения элементов очереди
	//for (auto&& element : my_deque)
	//{
	//	std::cout << *element << ' ';
	//}
	print_adapter(my_deque);
	std::cout << '\n';

	// удаляем объекты Point из очереди и освобождаем выделенную для них память
	while (!my_deque.empty())
	{
		delete my_deque.front();
		my_deque.pop();
	}



	stop



	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?
	const char* arr[] = { "b", "c", "d", "a" };
	std::priority_queue<const char*> pq(arr, arr + 4);

	std::cout << "Elements in priority queue: " << std::endl;
	while (!pq.empty()) {
		std::cout << pq.top() << " ";
		pq.pop();
	}

	//При выводе элементов из очереди, они будут выводиться в порядке убывания, 
	//т.к.приоритетная очередь всегда возвращает наибольший элемент.
	//Таким образом, вывод значений pq будет иметь следующий порядок : "d c b a".
	//Чтобы изменить порядок вывода элементов, можно передать компаратор в качестве 
	//третьего параметра в функцию - конструктор очереди с приоритетом.
	//Например, если мы хотим получить значения в порядке возрастания, 
	//то мы можем использовать компаратор std::greater<const char*>() 
	//вместо компаратора по умолчанию std::less<const char*>().

//	При вставке в приоритетную очередь сравниваются значения элементов, чтобы определить их приоритет.
	//Каким образом происходит сравнение зависит от выбранного компаратора.Если компаратор не указан, 
	//используется компаратор по умолчанию - std::less, который сравнивает значения элементов с помощью оператора < .
	//В случае с элементами типа const char*, при использовании компаратора по умолчанию, 
	//значения элементов сравниваются лексикографически - посимвольно слева направо.
	//Здесь компаратор CompareStringLength сравнивает две строки по их длинам - 
	//строка a будет считаться "больше" строки b, если ее длина больше длины строки b.


	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	// Необходимо определить операторы сравнения: < и ==
	std::set<Point> points;
	points.insert(Point(3, 5));
	points.insert(Point(1, 2));
	points.insert(Point(4, 7));
	points.insert(Point(2, 6));
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//Если мы попытаемся изменить значение элемента в множестве, это приведет к ошибке компиляции. 
	//Это связано с тем, что элементы в множестве не могут быть изменены непосредственно. 
	//Если мы хотим изменить значение элемента, мы должны сначала удалить его из множества, 
	//изменить значение и затем вставить элемент снова. 
	auto it = points.find({ 1, 2 }); // находим элемент в множестве
	if (it != points.end()) {
		points.erase(it); // удаляем элемент
		Point new_point = { 3, 4 }; // создаем новый элемент
		points.insert(new_point); // вставляем новый элемент
	}
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	std::set<int> set1{ 1, 2, 3, 4, 5 };
	std::set<int> set2{ 5, 2, 4, 1, 3 };

	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)
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
		//Дубликаты будут автоматически отсеяны, так как множество не может содержать повторяющиеся элементы.



	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
		std::map<const char*, std::pair<const char*, int>> employees{
	{"Иванов", {"Иванов", 50000}},
	{"Петров", {"Петров", 60000}},
	{"Сидоров", {"Сидоров", 55000}}
		};
	//б) заполните контейнер значениями посредством operator[] и insert()
	 std::map<const char*, std::pair<const char*, int>> employees2;
	 employees2["John"] = { "Smith", 50000 };
	 employees2["Jane"] = { "Doe", 60000 };
	 employees2.insert({ "Bob", {"Jones", 70000} });
	 employees2.insert({ "Alice", {"Johnson", 80000} });
	//в) распечатайте содержимое
	 for (auto it = employees.begin(); it != employees.end(); ++it) {
		 std::cout << it->first << ": " << it->second.first << ", " << it->second.second << std::endl;
	 }
	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
	 employees.erase("Иванова");
	 employees.insert({ "Петрова", {"Петрова", 50000} });
	stop
	

		
		//д) Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	//	std::vector<std::string> vec8{ "apple", "banana", "orange", "apple", "orange", "banana" };

	//std::map<std::string, int> str_count;
	//for (const auto& str : vec8) {
	//	auto it = str_count.find(str);
	//	if (it == str_count.end()) {
	//		str_count.insert({ str, 1 });
	//	}
	//	else {
	//		it->second++;
	//	}
	//}
	//Решить с помощью оператора индексирования для map, воспользоваться обычным итератором от begin до end, и не использовать auto

	//for (const auto& pair : str_count) {
	//	std::cout << pair.first << ": " << pair.second << std::endl;
//	}
std::vector<std::string> vec8{ "apple", "banana", "orange", "apple", "orange", "banana" };

	std::map<std::string, int> str_count;
	for (std::vector<std::string>::iterator it = vec8.begin(); it != vec8.end(); ++it) {
		str_count[*it]++;
	}

	for (std::map<std::string, int>::iterator it = str_count.begin(); it != str_count.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}




		//е) 
		//задан массив:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//создайте map, в котором каждой букве будет соответствовать совокупность 
		//лексиграфически упорядоченных слов, начинающихся с этой буквы.
		//Подсказка: не стоит хранить дубли одной и той же строки
	
		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
//	const char* words[] = { "Abba", "Alfa", "Beta", "Beauty"};
//	const int num_words = sizeof(words) / sizeof(words[0]);
//
//	std::map<char, std::set<std::string>> word_map;
//
//	// Заполнение map
//	for (int i = 0; i < num_words; ++i) {
//		const std::string word(words[i]);
//		if (word_map.find(word[0]) == word_map.end()) {
//			// Если ключа еще нет в map, создаем новую запись
//			word_map[word[0]] = std::vector<std::string>{ word };
//		}
//		else {
//			// Иначе добавляем слово в вектор значений по ключу
//			auto& vec = word_map[word[0]];
//			if (std::find(vec.begin(), vec.end(), word) == vec.end()) {
//				vec.push_back(word);
//				// Сортировка вектора для сохранения порядка
//				std::sort(vec.begin(), vec.end());
//			}
//		}
//	}
	const char* words[] = { "Abba", "Alfa", "Beta", "Beauty" };
	const int num_words = sizeof(words) / sizeof(words[0]);

	std::map<char, std::set<std::string>> word_map;

	for (int i = 0; i < num_words; ++i) {
	//	char key = words[i][0];
	//	std::string word = words[i];
		word_map[words[i][0]].insert(words[i]);
	}

	for (std::map<char, std::set<std::string>>::iterator it = word_map.begin(); it != word_map.end(); ++it) {
		std::cout << it->first << " - ";
		for (std::set<std::string>::iterator set_it = it->second.begin(); set_it != it->second.end(); ++set_it) {
			std::cout << *set_it << " ";
		}
		std::cout << std::endl;
	}

	// Вывод содержимого map
	for (const auto& kv : word_map) {
		std::cout << kv.first << ": ";
		for (const auto& word : kv.second) {
			std::cout << word << " ";
		}
		std::cout << std::endl;
	}

//	Cоздаеv пустую map с ключами типа char и значениями типа std::vector<std::string>.
	//Затем проходиv по массиву слов words, проверяет первую букву каждого слова и добавляет его в вектор значений
	//по соответствуюпо соответствующему ключу в map. Если слово уже есть в векторе значений, оно не добавляется еще раз.
//	После заполнения map цикл выводит содержимое каждого ключа и соответствующего ему вектора значений.
	// Bекторы значений уже отсортированы по алфавиту, так как мы добавляем новые слова только в отсортированный вектор.


		//ж)
		//создайте структуру данных, которая будет хранить информацию о студенческих группах.
		//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
		//фамилии могут дублироваться
		//Сами группы тоже должны быть упорядочены по номеру
		
	//StudentGroups groups;
	//groups.add_student(1, "Иванов");
	//groups.add_student(1, "Петров");
	//groups.add_student(1, "Сидоров");
	//groups.add_student(1, "Сидоров");
	//groups.add_student(1, "Сидоров");
	//groups.add_student(2, "Иванов");
	//groups.add_student(2, "Иванов");
	//groups.add_student(2, "Иванов");
	//groups.add_student(2, "Петров");
	//groups.add_student(2, "Сидоров");
		//номера 
	//
	//std::cout << groups << std::endl;
	std::map<int, std::multiset<std::string>> groups;

	// Добавление студентов в группы
	groups[101].insert("Ivanov");
	groups[101].insert("Petrov");
	groups[101].insert("Sidorov");
	groups[101].insert("Ivanov"); // дублирующаяся фамилия

	groups[102].insert("Smith");
	groups[102].insert("Johnson");
	groups[102].insert("Williams");
	groups[102].insert("Brown");

	// Вывод информации о группах и студентах на экран
	for (std::map<int, std::multiset<std::string>>::iterator it = groups.begin(); it != groups.end(); ++it) {
		std::cout << "Group " << it->first << ":" << std::endl;
		for (std::multiset<std::string>::iterator set_it = it->second.begin(); set_it != it->second.end(); ++set_it) {
			std::cout << "  " << *set_it << std::endl;
		}
	}


	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	std::multimap<std::string, std::string> eng_rus_dict;

	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	eng_rus_dict.insert(std::make_pair("strange", "чужой"));
	eng_rus_dict.insert(std::make_pair("strange", "странный"));
	eng_rus_dict.insert(std::make_pair("apple", "яблоко"));
	eng_rus_dict.insert(std::make_pair("book", "книга"));
	eng_rus_dict.insert(std::make_pair("book", "заказ"));
	//в) Выведите все содержимое словаря на экран
	std::cout << "Словарь:" << std::endl;
	for (const auto& entry : eng_rus_dict) {
		std::cout << entry.first << ": " << entry.second << std::endl;
	}
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()
	std::string key = "strange";
	auto range = eng_rus_dict.equal_range(key);

	std::cout << "Переводы для '" << key << "':" << std::endl;
	for (auto it = range.first; it != range.second; ++it) {
		std::cout << it->second << std::endl;
	}




   

  stop


	return 0;
}

