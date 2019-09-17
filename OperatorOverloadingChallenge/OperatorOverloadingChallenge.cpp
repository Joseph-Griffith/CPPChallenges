/*
	Overload the following operators in a MyString class.

		-	- Unary minus. Returns the lowercase version of the object's string: -s1
		==	- Returns true if the two strings are equal: (s1 == s2)
		!=	- Returns true if the two strings are NOT equal: (s1 != s2)
		<	- Returns true if the lhs string is lexically less than the rhs string: (s1 < s2)
		>	- Returns true if the lhs string is lexically greater than the rhs string: (s1 > s2)
		+	- Concatenation. Returns an object that concatenates the lhs and rhs: s1 + s2
		+=	- Concatenate the rhs string to the lhs string and stor the result in lhs object: s1+= s2; Equivalent to s1 = s1 + s2
		*	- Repeat. Results in a string are copied n times: s2 * 3 E.g.

											s2 = "abc";
											s1 = s2 * 3;
											s1's result will be "abcabcabc";

		*=	- Repeat the string on the lhs n times and store the result back in the lhs object: s1 * 4 E.g.

											s1 = "abc";
											s1 * 4;
											s1's reult will be "abcabcabcabc";

	If you wish to overload the ++ and -- operators remember they have pre and post versions.
*/

#include "MyString.h"

int main()
{
	std::cout << std::boolalpha << std::endl;
	MyString a{ "frank" };
	MyString b{ "frank" };

	std::cout << (a == b) << std::endl; // True
	std::cout << (a != b) << std::endl; // False

	b = "george";
	std::cout << (a == b) << std::endl; // False
	std::cout << (a != b) << std::endl; // True
	std::cout << (a < b) << std::endl; // True
	std::cout << (a > b) << std::endl; // False

	MyString s1{ "FRANK" };
	s1 = -s1;
	std::cout << s1 << std::endl; // frank

	s1 = s1 + "*****";
	std::cout << s1 << std::endl; // frank*****

	s1 = s1 += "-----";
	std::cout << s1 << std::endl; // frank*****-----

	MyString s2{ "12345" };
	s1 = s2 * 3;
	std::cout << s1 << std::endl; // 123451234512345

	MyString s3{ "abcdef" };
	s3 *= 5;
	std::cout << s3 << std::endl; // abcdefabcdefabcdefabcdefabcdef

	MyString s = "Frank";
	++s;
	std::cout << s << std::endl; // FRANK

	s = -s;
	std::cout << s << std::endl; // frank

	MyString result;
	result = ++s;
	std::cout << s << std::endl; // FRANK
	std::cout << result << std::endl; // FRANK

	s = "Frank";
	s++;
	std::cout << s << std::endl; // FRANK

	s = -s;
	std::cout << s << std::endl; // frank
	result = s++;
	std::cout << s << std::endl; // FRANK
	std::cout << result << std::endl; // frank
}