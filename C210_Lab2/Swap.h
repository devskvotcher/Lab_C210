#pragma once
#include "MyString.h"
 
template <typename T>
void Swap(T& x, T& y)
{
	T tmp = std::move(x);
	x = std::move(y);
	y = std::move(tmp);
}

template <>
inline void Swap(MyString& str1, MyString& str2)
{
	str1.sSwap(str2);
	//char* tmp = str1.m_pStr;
	////char* tmp = new char[strlen(str1.m_pStr)+1];
	////strcpy(tmp, str2.m_pStr)
	//str1.m_pStr = str2.m_pStr;
	//str2.m_pStr = tmp;
	//delete tmp;
}