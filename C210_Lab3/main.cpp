//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

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
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 

	vector<int> vInt;
	std::cout << "Размер вектора=" <<vInt.size() << std::endl;
	
	
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте

	//vInt.front()=1;
	vInt.push_back(1);
	std::cout<<"First element"<<vInt.front() << std::endl;
	
	

	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
	for (size_t i = 0; i < 10 /*vInt.size()*/; i++)
	{
		vInt.push_back(rand()%10);
		printVectorInfo(vInt);
	}


	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?
	vector<double> vDouble1(10);
	for (size_t i = 0; i < vDouble1.size(); i++)
	{
		printVectorInfo(vDouble1);
	}

	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 
	std::vector<MyString> vec(5, "A"); // создаем вектор из 5 элементов типа MyString, инициализированных строкой "A"
	std::cout << "Original vector:" << std::endl;
	for (int i = 0; i < vec.size(); i++) {
		std::cout << "Element " << i << ": " << vec[i] << std::endl; // выводим элементы вектора
	}

	vec.at(2) = "B"; // изменяем значение элемента с индексом 2 с помощью функции at()
	vec[4] = "C"; // изменяем значение элемента с индексом 4 с помощью оператора индексирования []

	std::cout << "Modified vector:" << std::endl;
	for (int i = 0; i < vec.size(); i++) {
		std::cout << "Element " << i << ": " << vec[i] << std::endl; // выводим измененные элементы вектора
	}

	// попытка обратиться к элементам за границами вектора
//	std::cout << vec.at(5) << std::endl; // вызовет исключение std::out_of_range
//	std::cout << vec[6] << std::endl; // результат неопределен, так как мы обращаемся за границы вектора




	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	double dMas[5] = { 1.2, 2.3, 3.4, 4.5, 5.6 }; // создаем и инициализируем массив вещественных чисел
	std::vector<double> vDouble3(dMas, dMas + 5); // создаем вектор и копируем элементы массива вектор

	std::cout << "Array elements:" << std::endl;
	for (int i = 0; i < 5; ++i) {
		std::cout << dMas[i] << " "; // выводим элементы массива
	}
	std::cout << std::endl;

	std::cout << "Vector elements:" << std::endl;
	for (int i = 0; i < vDouble3.size(); ++i) {
		std::cout << vDouble3[i] << " "; // выводим элементы вектора
	}
	std::cout << std::endl;

	

	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 
	std::vector<double> vDouble4; 

	vDouble4.assign(vDouble3.begin() + 2, vDouble3.begin() + 5); // копируем элементы [2,5) из vDouble3 в vDouble4

	std::cout << "vDouble3 elements:" << std::endl;
	for (int i = 0; i < vDouble3.size(); ++i) {
		std::cout << vDouble3[i] << " "; // выводим элементы vDouble3
	}
	std::cout << std::endl;

	std::cout << "vDouble4 elements:" << std::endl;
	for (int i = 0; i < vDouble4.size(); ++i) {
		std::cout << vDouble4[i] << " "; // выводим элементы vDouble4
	}
	std::cout << std::endl;


//*
	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	// а) Если вектор vPoint1 инициализируется с начальным размером 3, 
	// то для каждого элемента будет вызван конструктор по умолчанию для класса Point.
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).
	std::vector<Point> vPoint2(5, Point(1, 1));


	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	
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

	//Подсказка: для вывода на печать значений скорее всего Вам понадобится
		//а) специализация Вашей шаблонной функции
		//б) или перегрузка operator<< для Point*

	}//Какие дополнительные действия нужно предпринять для такого вектора?


	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
		
	{
		size_t n = 10;
		vector<int> v(n);
		v.resize(n / 2);
		if (v.capacity() == n)
		{
			//Изначально вектор v был создан с емкостью n и размером n(так как используется
			//конструктор vector<int> v(n); , который создает вектор размером n и заполняет 
			//его значениями по умолчанию).
			//Затем вызывается v.resize(n / 2); , который изменяет размер вектора до n / 2,
			//то есть 5, но емкость вектора не изменяется, 
			//поэтому он по - прежнему занимает n позиций в памяти.
			//Таким образом, if (v.capacity() == n) вернет true.
		}
	}
		

		
	{
		int n = 10;
		size_t m = 10;
		vector<int> v(n);
		v.reserve(m);
		if (v.capacity() == m)
		{
			//Если m равно n, то условие if (v.capacity() == m) вернет true.
			//Если m больше n, то v.capacity() вернет значение m и условие также вернет true.
			//Если m меньше n, то v.capacity() вернет значение не меньше n, поэтому 
			//условие if (v.capacity() == m) вернет false.
		}
	}
		

		
		{
		vector<int> v(3,5);
		v.resize(4,10); //значения?
		v.resize(5); //значения?
		//Изначально создается вектор v с тремя элементами, каждый из которых равен 5. 
		//Затем вызывается функция resize(4, 10), которая увеличивает размер вектора до 4 
		//и заполняет новый элемент значением 10. 
		//В итоге вектор будет иметь следующее содержимое : {5, 5, 5, 10}.
		//Затем вызывается функция resize(5), 
		//которая увеличивает размер вектора до 5 и 
		//заполняет новый элемент значением по умолчанию для типа элементов вектора
		}
		

	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов
		vector<int> v1;
		vector<int> v2;

		// резервируем память под 5 элементов
		v1.reserve(5);

		// заполняем первый вектор значениями
		for (int i = 1; i <= 5; i++) {
			v1.push_back(i);
		}

		// заполняем второй вектор значениями
		for (int i = 1; i <= 5; i++) {
			v2.push_back(i * 2);
		}
		printVectorInfo(v1);
		printVectorInfo(v2);	



	//!!! shrink_to_fit - Уменьшение емкости вектора.
	//Для любого вектора из предыдущего задания требуется уменьшить емкость
	//до size.
		size_t size = 2;
		v1.resize(size);
		v2.resize(size);
		v1.shrink_to_fit();
		v2.shrink_to_fit();
		printVectorInfo(v1);
		printVectorInfo(v2);
	

	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам
	//с помощью:
		int ar[] = { 11, 2, 4, 3, 5 };
		std::vector<std::vector<int>> vv;

		for (const int& num : ar) {
			std::vector<int> row(num, num);
			vv.push_back(row);
		}

		std::cout << vv << std::endl;
	//std::cout<<vv<<std::endl;
		//Распечать оепартор вывода в поток для вектора, а не для вектора вектора.
		//Печать вектора
	 stop

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//Вставка элемента последовательности insert().
	//Реализуйте функцию, которая должна вставлять новый элемент
		//в начало вектора только при условии, что в векторе такого
		 //значения еще нет.
	//Проверьте работоспособность функции - в вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого символа еще нет.
		 //например: vChar2 - abc 
		 //При попытке вставить 'a' попытка должна быть проигнорирована
		 //При попытке вставить 'q' vChar2 - qabc 

	 std::vector<char> vChar2{ 'a', 'b', 'c' };
	 insert(vChar2, 'a'); // игнорируется, так как 'a' уже есть в векторе
	 insert(vChar2, 'q'); // вставляется в начало, так как 'q' не было в векторе
	 for (auto c : vChar2) {
		 std::cout << c << " ";
	 }
	 std::cout << std::endl; // выводит "q a b c "
	 stop
	

	//Реализуйте функцию, которая должна вставлять новый элемент
		 //перед каждым элементом вектора
	//Проверьте работоспособность функции - вставьте перед каждым элементом вектора vChar2 букву 'W'
	/* insertBeforeEach(vChar2, 'W');
	 for ( auto elem : vChar2) 
	 {
		 std::cout << elem << " ";
	 }
	 std::cout << std::endl; */
	 //Нужно использовать функцию insert, без вспомогательных контейнеров, вставить в нужные позиции W
	 std::vector<char> vChar7 = { 'A', 'B', 'C', 'D', 'E' };
	 insertBeforeEach(vChar7, 'W');

	 for (typename std::vector<char>::const_iterator it = vChar7.begin(); it != vChar7.end(); ++it) {
		 std::cout << *it << " ";
	 }
	 std::cout << std::endl;
///
///////////////////////////////////////////////////////////////////
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
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
//Убрать использование алгоритмов
//Использовать erase()
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

	//Удаление элемента последовательности erase()
	//Напишите функцию удаления из любого вектора всех дублей 
		 //Например: было - "qwerrrrty12222r3", стало - "qwerty123"

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
	//Создайте новый вектор таким образом, чтобы его элементы стали
	//копиями элементов любого из созданных ранее векторов, но расположены
	//были бы в обратном порядке

	std::vector<int> vec3{ 1, 2, 3, 4, 5 };
	std::vector<int> reversedVec = reverseCopy(vec3);
	for (const auto& elem : reversedVec) {
		std::cout << elem << " "; // выводит "5 4 3 2 1"
	}




///////////////////////////////////////////////////////////////////

	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
	//push_front, insert()
	std::list<Point> ptList1;

	// добавление элементов в конец списка
	ptList1.push_back(Point(1, 2));
	ptList1.push_back(Point(3, 4));

	// добавление элементов в начало списка
	ptList1.push_front(Point(5, 6));
	ptList1.push_front(Point(7, 8));

	// вставка элемента в середину списка
	std::list<Point>::iterator it = ptList1.begin();
	it++; // переходим ко второму элементу списка
	ptList1.insert(it, Point(9, 10));

	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.
	std::vector<int> vec5 = { 1, 2, 3, 4, 5 };
	std::list<std::string> lst2 = { "Hello", "world", "!" };

	printContainer(vec5, std::cout);
	printContainer(lst2, std::cout);

	//Сделайте любой из списков "реверсивным" - reverse()
	lst2.reverse();

	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке 
	std::vector<Point> vPoint = { {1, 2}, {3, 4},{2,3},{-1,-3}, {5, 6}, {7, 8} ,{-9,-200} };

	std::list<Point> ptList2;
	for (auto it = vPoint.rbegin(); it != vPoint.rend(); ++it) {
		ptList2.push_back(*it);
	}
	printContainer(ptList2, std::cout);


	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка

	ptList1.sort();
	ptList2.sort();
	
	printContainer(ptList2, std::cout);

	stop

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит с каждым списком.
		//При использовании метода merge() двух отсортированных списков, 
		//они объединяются в один отсортированный список, 
		//а их исходные элементы перемещаются в новый список.
		//То есть, после операции объединения списки ptList1 и ptList2 
		//будут пустыми.
		ptList1.merge(ptList2);
	printContainer(ptList1, std::cout);
	stop

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подумайте: что должно быть перегружено в классе Point?
		//оператор сравнения
		Point p(2, 3);//
	ptList1.remove(p);
//	ptList1.remove(Point(2, 3));
	printContainer(ptList1, std::cout);
	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if(). 
	ptList1.remove_if(isNegative);
	printContainer(ptList1, std::cout);
	//Исключение из списка подряд расположенных дублей - unique(). 
	ptList1.unique();
	//printContainer(ptList2, std::cout);

///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque
	stop

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать
	std::vector<Point> vec6{ Point(1, 2), Point(3, 4), Point(5, 6) };
	std::deque<Point> deq;
	deq.assign(vec6.begin(), vec6.end());
//	printContainer(deq);


	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'
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