#pragma once
#include <string>
#include <iostream>
#include <deque>

class MyString
{
	char* m_pStr;
public:
	MyString(const char* pStr = nullptr);
	MyString(const MyString&); // not using for swap (not efficient)
	MyString(MyString&&);
	~MyString(void);
	MyString& operator=(const MyString&); // not using for swap (not efficient)
	MyString& operator=(MyString&&);
	void sSwap(MyString& str2);
	//friend void Swap<MyString>(MyString&, MyString&);
	friend std::ostream& operator<<(std::ostream&, const MyString&);
	void removeAStrings(std::deque<MyString>& strings);	
private:
	void Construct(const char*);
};