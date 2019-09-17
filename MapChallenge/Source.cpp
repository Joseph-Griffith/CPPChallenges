/*
	Using std::set and std::map

	This challenge has 2 parts
	We will be reading words from a text file provided to you
	The text file is named "words.txt" and contains the first few paragraphs from the book "The wonderful wizard of Oz" by L. Frank Baum

	Part1:
	For part 1 of this challenge, you are to display each unique word
	in the file and immediately following each word display the number of times it occurs in the text file.

	The words should be displayed in ascending order

	Here is a sample listing of the first few words

	Word	Count
	=============================
	Aunt		5
	Dorothy		8
	Dorothy's	1
	Em			5
	Even		1
	From		1

	Please use a map with <string, int> Key/Value pairs

	================================================================================================

	Part 2:
	For part 2 of this challenge, you are to display each unique word in the file and immediatly
	following each word, display the line numbers in which that word appears

	The words should be displayed in ascending order and the line numbers for each word should
	be displayed in ascending order
	If a word appears more than once on a line, then the line number should only appear once

	Here is a sample listing of the first few words:

	Word	  Occurencies
	================================
	Aunt	  [ 2 7 25 29 48 ]
	Dorothy   [ 1 7 15 29 39 43 47 51 ]
	Dorothy's [ 31 ]
	Em		  [2 7 25 30 48 ]
	Even	  [ 19 ]
	From	  [ 50 ]

	Please use a map of <string, set<int>> Key/Value pairs
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

// Used for Part1
// Display the word and count from the 
// std::map<std::string, int>

void display_words(const std::map<std::string, int>& words)
{
	std::cout << std::setw(12) << std::left << "\nWord"
		<< std::setw(7) << std::right << "Count" << std::endl;
	std::cout << "===================" << std::endl;
	for (auto pair : words)
		std::cout << std::setw(12) << std::left << pair.first
		<< std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurences from the 
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>>& words)
{
	std::cout << std::setw(12) << std::left << "\nWord"
		<< "Occurrences" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	for (auto pair : words)
	{
		std::cout << std::setw(12) << std::left << pair.first
			<< std::left << "[ ";
		for (auto i : pair.second)
			std::cout << i << " ";
		std::cout << "]" << std::endl;
	}
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string& s)
{
	std::string result;
	for (char c : s)
	{
		if (c == '.' || c == ',' || c == ';' || c == ':')
			continue;
		else
			result += c;
	}
	return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file

void part1()
{
	std::map<std::string, int> words;
	std::string line;
	std::string word;
	std::ifstream in_file{ "words.txt" };
	if (in_file)
	{

		while (std::getline(in_file, line))
		{
			line = clean_string(line);

			std::istringstream iss{ line };

			while (iss >> word)
			{
				
				words[word]++; // If the word isn't in the map this creates it otherwise it increases the value
			}
		}

		in_file.close();
		display_words(words);
	}
	else
	{
		std::cerr << "Error opening input file" << std::endl;
	}
}

// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2()
{
	std::map<std::string, std::set<int>> words;
	std::string line;
	std::string word;
	std::ifstream in_file{ "words.txt" };
	if (in_file)
	{
		int line_number{ 0 };

		while (std::getline(in_file, line))
		{
			line_number++;

			line = clean_string(line);

			std::istringstream iss{ line };

			while (iss >> word)
			{
				words[word].insert(line_number);
			}
		}

		in_file.close();
		display_words(words);
	}
	else
	{
		std::cerr << "Error opening input file" << std::endl;
	}
}

int main()
{
	part1();
	part2();
	return 0;
}