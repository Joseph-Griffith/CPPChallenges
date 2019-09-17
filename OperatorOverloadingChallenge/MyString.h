#pragma once

#include <iostream>

class MyString
{
	friend std::ostream& operator<<(std::ostream& os, const MyString& rhs);
	friend std::istream& operator>>(std::istream& in, MyString& rhs);
	friend bool operator==(const MyString& lhs, const MyString& rhs);
	friend bool operator!=(const MyString& lhs, const MyString& rhs);
	friend bool operator<(const MyString& lhs, const MyString& rhs);
	friend bool operator>(const MyString& lhs, const MyString& rhs);
	friend MyString operator-(const MyString& obj);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend MyString operator+=(MyString& lhs, const MyString& rhs);
	friend MyString operator*(const MyString& lhs, int n);
	friend MyString operator*=(MyString& lhs, int n);
	friend MyString operator++(MyString& obj);
	friend MyString operator++(MyString& obj, int);

private:
	char* str;

public:
	// Constructors
	MyString();
	MyString(const char* s);
	MyString(const MyString& source);
	MyString(MyString&& source) noexcept;

	// Destructor
	~MyString();

	// Member methods
	void Display() const;
	int GetLength() const;
	const char* GetStr() const;
	MyString& operator=(const MyString& rhs);
	MyString& operator=(MyString&& rhs) noexcept;
};
