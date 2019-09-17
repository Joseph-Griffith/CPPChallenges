#define _CRT_SECURE_NO_WARNINGS

#include "MyString.h"
#include <string>
#include <cstring>
#include <cctype>

//////////////////
// Constructors //
//////////////////

// no-args constructor
MyString::MyString()
	:str{ nullptr }
{
	str = new char[1]; // char array with a size of 1
	*str = '\0';
}

// Overloaded constructor
MyString::MyString(const char* s)
	:str{ nullptr }
{
	if (s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		str = new char[std::strlen(s) + 1];
		strcpy(str, s);
	}
}

// Copy constructor
MyString::MyString(const MyString& source)
	:str{ nullptr }
{
	str = new char[std::strlen(source.str) + 1];
	std::strcpy(str, source.str);
}

// Move constructor
MyString::MyString(MyString&& source) noexcept
	:str{ source.str }
{
	source.str = nullptr;
}



/////////////////
// Destructors //
/////////////////

MyString::~MyString()
{
	delete[] str;
}



////////////////////
// Member methods //
////////////////////

void MyString::Display() const
{
	if (str == nullptr)
	{
		std::cout << str << " : nullptr";
	}
	else
	{
		std::cout << str << " : " << GetLength() << std::endl;
	}
}

int MyString::GetLength() const
{
	return std::strlen(str);
}

const char* MyString::GetStr() const
{
	return str;
}

MyString& MyString::operator=(const MyString& rhs)
{
	if (str == rhs.str)
	{
		return *this;
	}

	delete[] str;

	str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(str, rhs.str);

	return *this;
}

MyString& MyString::operator=(MyString&& rhs) noexcept
{
	if (str == rhs.str)
	{
		return *this;
	}

	delete[] str;

	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}



////////////////////
// Friend methods //
////////////////////

// Output
std::ostream& operator<<(std::ostream& os, const MyString& rhs)
{
	os << rhs.str;
	return os;
}

// Input
std::istream& operator>>(std::istream& in, MyString& rhs)
{
	char* buff = new char[1000];
	in >> buff;
	rhs = MyString{ buff };
	delete[] buff;
	return in;
}

// Comparison operator (equal)
bool operator==(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.str, rhs.str) == 0;
}

// Comparison operator (not equal)
bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !operator==(lhs, rhs);
}

// Less than
bool operator<(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.str, rhs.str) < 0;
}

// Greater than
bool operator>(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.str, rhs.str) > 0;
}

// Make lowercase
MyString operator-(const MyString& obj)
{
	char* buff = new char[std::strlen(obj.str) + 1];
	std::strcpy(buff, obj.str);

	for (size_t i = 0; i < std::strlen(buff); i++)
	{
		buff[i] = std::tolower(buff[i]);
	}

	MyString temp{ buff };
	delete[] buff;
	return temp;
}

// Concatenate
MyString operator+(const MyString& lhs, const MyString& rhs)
{
	char* buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
	std::strcpy(buff, lhs.str);
	std::strcat(buff, rhs.str);

	MyString temp{ buff };
	delete[] buff;
	return temp;
}

// Concatenate to current
MyString operator+=(MyString& lhs, const MyString& rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

// Multiply
MyString operator*(const MyString& lhs, int n)
{
	char* buff = new char[std::strlen(lhs.str) * n + 1];
	std::strcpy(buff, lhs.str);

	for (int i = 0; i < n - 1; i++)
	{
		std::strcat(buff, lhs.str);
	}

	MyString temp{ buff };
	delete[] buff;
	return temp;
}

// Mutiply current
MyString operator*=(MyString& lhs, int n)
{
	lhs = lhs * n;
	return lhs;
}

// Make uppercase
MyString operator++(MyString& obj)
{
	for (size_t i = 0; i < std::strlen(obj.str); i++)
	{
		obj.str[i] = std::toupper(obj.str[i]);
	}

	return obj;
}

// Post make uppercase
MyString operator++(MyString& obj, int)
{
	MyString temp{ obj };
	++obj;
	return temp;
}
