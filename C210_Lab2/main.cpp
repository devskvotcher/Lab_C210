//����������

//�������: 
	//		������� �������,
	//		������� �������,


#include <tchar.h>
//#include <stdexcept>
#include "Swap.h"
#include "MyString.h"
#include <iostream>
#include "MyStack.h"
#include "MyStack2.h"
#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{

////////////////////////////////////////////////////////////////////////////
	//����. ������� �������.
	//�������� ������ ������� ������������ ������� ����
	//�������� - Swap(). ��������� ����������������� ����������
	//������� � ������� ������������ ���� ��������� ����.
	//��������� 1: ���������� ������� ���������� ��������� � .h-����.

	int iX = 1, iY = -1;
	std::cout << iX << "   " << iY << std::endl;
	Swap(iX, iY);
	std::cout << "Swap" << std::endl;
	std::cout << iX << "   " << iY << std::endl;
	double dX = 0.5, dY = -5.5;
	std::cout << dX << "   " << dY << std::endl;
	Swap(dX, dY);
	std::cout << "Swap" << std::endl;
	std::cout << dX << "   " << dY << std::endl;

	//��������� 2: ���������, ��� ����� �����������, ��� ����,
	//			����� ��������� ����� ������� � ��������� MyString
	//			�� ������ ���������, �� � ����������
	MyString str1("One"), str2("Two");
	std::cout << str1 << "   " << str2 << std::endl;
	Swap(str1, str2);
	std::cout << "Swap" << std::endl;
	std::cout << str1 << "   " << str2 << std::endl;
//
/////////////////////////////////////////////////////////////////////
	
	//����. ������� �������.
	//������� 1.
	//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
	// 
	//���������: 1. �������� ����� ���-�� ������� - ������� � ������� ���������
	//			 ��� �������� ��������������� ������������� � ������ ���������
	//			 �������� ������, 
	//			 2. ��� ������� ������������� ������� ����� ����� ���� �����������
	//			 ��������-��������� �������
	//			 3. ������������� ���������� �� ������ �������� "push" � "pop".
	//			 ���������� ��� ��������, ���������� operator<< ("push") � operator>> ("pop")
	//           ��� ����, ����� ������������� ���������� ���������� ���� �������� 
	//			 ������ ���� �� ������������ ���������� � ��������� ��������
	//			 4. ������������� ���������� operator[] ����� �������, ����� ������������
	//			 ��� ������/�������� �������� ������ ��� ���������, ������� �� ����������
	//           5. ������������ ����������� ������ �������� � ����� ���������
	
	//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
	//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
	//operator<< � operator>>, operator[]
	
	// ��������� �������� ���� ������ ����������� ���������
	
	{
		try {			
			MyStack< int, 5 > iStack;
			iStack << 1 << 2 << 3 << 4 << 5;						
			std::cout << iStack;
			//iStack << 6;				// ?
		
			int ar[5];
			iStack >> ar[0] >> ar[1] >> ar[2] >> ar[3] >> ar[4];
			std::cout << iStack;
			//iStack >> ar[0];			// ?
			
			MyStack< MyString, 10 > strStack;
			strStack << MyString("Aaa") << MyString("Bbb") << MyString("Ccc");
			MyString str("Ddd");
			strStack << str;
			std::cout << strStack;
			//
			str = strStack[1];
			strStack[2] = str;
			//strStack[5] = str;		// ?	
			std::cout << strStack;
			//
			MyString s1, s2;
			strStack >> s1 >> s2;
			std::cout << strStack;						
		}
		catch (std::out_of_range e) {
			std::cerr << e.what() << std::endl;
		}
	}
	//


	//������� 2. 
	// ���������� ������ ����� - MyStack2 ����� �������, ����� 
	//��� �������� ��������� ������������� ����������� ������.
	//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
	//������������
	// 
	//���������: 1. ������������� ���������� �� ������ �������� "push" � "pop". 
	//           ���������� ��� �������� � ������� ��������������� �������.	
	//			 2. operator[] ��� ������ ����� ������������� �� ����� (������?)
	//           3. ���� ����� ����������� ��� ���������������� �������� ������ (����������� �����������, 
	//			 �������� ������������, ...)

	// ��������� ����������������� �������������� ������� ������
	
	try {		
		MyStack2< MyString> s1;	
		s1.push(MyString("Aaa"));
		s1.push(MyString("Bbb"));
		s1.push(MyString("Ccc"));
		s1.push(MyString("Ddd"));
		std::cout <<"Right" << s1<<"Left\n";
		MyStack2< MyString> s2(s1);
		MyString str = s1.pop();
		s1.pop();
		std::cout << s1 << s2;

		s1 = s2;

		s1.pop();
		std::cout <<"s1" << s1;
		s2 = s1;

		std::cout <<"s2" << s2;
		MyStack2< MyString> s3(std::move(s1));
		std::cout << s3 << s1;

		s2.pop();
		s3 = std::move(s2);
		std::cout << s3 << s2;

		s2.pop();	
	}
	catch (std::out_of_range e) {
		std::cerr << e.what() << std::endl;
	}
    	

	return 0;
}

