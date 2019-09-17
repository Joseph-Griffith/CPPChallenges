/*
	A Palindrome is a string that reads the same backwards or forwards
	Simple examples are:
		madam
		bob
		toot
		radar

	An entire phrase can also be a palindeome, for example:
		A Toyota's a toyota
		A Santa at NASA
		A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!

	For the purposes of this assignment we will only consider alpha characters and omit all other characters
	We will also not be considering case
	So, "A Santa at NASA" will be processed as "ASANTAATNASA"

	Your challenge is to write the following function:

		bool is_palindrome(const std::string& s)

	This function will expect a string and it must determine if that string is a palindrome and return true if it is, or false if it is not

	Some examples:

		is_palindrome("A Santa at NASA"); // Will return true
		is_palindrome("Hello"); // Will return false

	Please use a deque to solve this problem
*/

#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
	std::deque<char> d;
	std::deque<char> reverse_d;

	for (const auto& c : s)
	{
		if (std::isalpha(c))
		{
			d.push_back(std::toupper(c));
			reverse_d.push_front(std::toupper(c));
		}
	}

	return d == reverse_d;
}

int main()
{
	std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
		"avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
		"A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

	std::cout << std::boolalpha;
	std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
	for (const auto& s : test_strings)
	{
		std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
	}
	std::cout << std::endl;
	return 0;
}