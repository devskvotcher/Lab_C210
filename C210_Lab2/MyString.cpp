#include "MyString.h"
MyString::MyString(const char* pStr)
{
	if (pStr)
		Construct(pStr);
	else
		m_pStr = nullptr;
}


MyString::~MyString(void)
{
	delete[] m_pStr;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other && other.m_pStr != nullptr)
	{
		size_t count = strlen(other.m_pStr) + 1;
		delete []m_pStr;
		m_pStr = new char[count];
		strcpy_s(m_pStr, count, other.m_pStr);
	}
	return *this;
}

MyString::MyString(const MyString& other)
{
	if (other.m_pStr)
		Construct(other.m_pStr);
	else
		m_pStr = nullptr;
}

void MyString::Construct(const char* pStr)
{
	size_t count = strlen(pStr) + 1;
	m_pStr = new char[count];
	strcpy_s(m_pStr, count, pStr);
}

MyString::MyString(MyString&& other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
}

MyString& MyString::operator=(MyString&& other)
{
	delete m_pStr;
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;

	return*this;
}

void MyString::sSwap(MyString& str2)
{
	char* tmp = this->m_pStr;
	
	this->m_pStr = str2.m_pStr;
	str2.m_pStr = tmp;
}

std::ostream& operator<<(std::ostream& o, const MyString& str)
{
	return o << str.m_pStr;
}