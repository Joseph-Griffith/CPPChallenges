/*
	This challenge is about using a collection (list) of integers and allowing the user
	to select options from a menu to perform operations on the list.

	Your program should display a menu to the user as follows:

	P - Print numbers
	A - Add a number
	M - Display mean of numbers
	S - Display the smallest number
	L - Display the largest number
	Q - Quit

	Enter your choice:

	The program should only accept valid choices from the user, both upper and lowercase selection should be allowed.
	If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
	displayed again.

	If the user enters "P" or "p", you should display all of the elements (ints  in the list.
	If the list is empty you should display "[] - the list is empty"
	If the list is not empty then all the list elements should be displayed inside square brackets seperated by a space.

	If the user enters "A" or "a" then you should prompt the user for an integer to add to the list
	which you will add to the list and then display it was added. For example, if the user enters 5
	you should display, "5 added".
	Duplicate list entries are ok.

	If the user enters 'M' or 'm' you should calculate the mean or average of the elements in the list and display it.
	If the list is empty you should display "Unable to calculate the mean - no data"

	If the user enters 'S' or 's' you should display the smallest element in the list.
	For example, if the list contains [2, 4, 5, 1], you should display, "The smallest number is 1"
	If the list is empty you should display, "Unable to determine the smallest number - list is empty"

	If the user enters 'L' or 'l' you should display the largest element in the list
	For example, if the list contains [2, 4, 5, 1], you should display, "The largest number is 5"
	If the list is empty you should display, "Unable to determine the largest number - list is empty"

	If the user enters 'Q' or 'q' then you should display "Goodbye" and the program should terminate.

	Additional functionality if you wish to extend the program:

	- Search for a number in the list and if found display the number of times it occurs in the list
	- Clearing out the list (make it empty again) (Hint - The vector class has a .clear() method)
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

// Passed in the reference to the list in all of the following functions to save on memory as copies of the vectors won't be created

void DisplayWelcomeScreen();
void DisplayMainMenu();
char GetUserSelection();
void PrintNumbers(const std::vector<int>&);
void AddNumber(std::vector<int>&);
void MeanOfNumbers(const std::vector<int>&);
void SmallestNumber(const std::vector<int>&);
void LargestNumber(const std::vector<int>&);
void SearchForNumber(const std::vector<int>&);
void ClearList(std::vector<int>&);

// Displays the welcome screen
void DisplayWelcomeScreen()
{
	std::cout << "Welcome to LISTS - A bunch of random things you can do to a list!" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
}

// Displays the main menu
void DisplayMainMenu()
{
	std::cout << "\nPlease make a selection" << std::endl;
	std::cout << "P - Print numbers" << std::endl;
	std::cout << "A - Add a number" << std::endl;
	std::cout << "M - Display mean of numbers" << std::endl;
	std::cout << "S - Display the smallest number" << std::endl;
	std::cout << "L - Display the largest number" << std::endl;
	std::cout << "O - Search for a number" << std::endl;
	std::cout << "C - Clear the current list" << std::endl;
	std::cout << "Q - Quit" << std::endl;
}

// Returns the user selection
char GetUserSelection()
{
	std::cout << "\nEnter your choice: ";
	char selection;
	std::cin >> selection;
	return std::toupper(selection);
}

// Prints the integers in the passed in vector
void PrintNumbers(const std::vector<int>& list)
{
	if (list.size() <= 0)
	{
		std::cout << "\n[] - the list is empty" << std::endl;
		return;
	}

	std::cout << "\n[ ";

	for (auto number : list)
	{
		std::cout << number << " ";
	}

	std::cout << "]" << std::endl;
}

// Add an integer provided by the user to the passed in vector
void AddNumber(std::vector<int>& list)
{
	do
	{
		int userNum{};

		// Reset input
		std::cin.clear();
		std::cin.ignore(256, '\n');

		std::cout << "\nPlease enter the number you would like to add to the list: ";
		std::cin >> userNum;

		if (std::cin.fail())
		{
			std::cout << "\nInvalid - Please enter an integer" << std::endl;
			continue;
		}

		list.push_back(userNum);

		std::cout << "\n" << userNum << " added to list" << std::endl;

	} while (std::cin.fail());

	return;
}

// Calculates and returns the mean/average of the integers currently in the passed in vector
void MeanOfNumbers(const std::vector<int>& list)
{
	int total{};

	if (list.size() <= 0)
	{
		std::cout << "\nUnable to calculate the mean - no data" << std::endl;
		return;
	}

	for (auto number : list)
	{
		total += number;
	}

	std::cout << "\nThe mean of the list is " << static_cast<double>(total) / static_cast<double>(list.size()) << std::endl;
}

// Returns the smallest integer in the passed in vector
void SmallestNumber(const std::vector<int>& list)
{
	if (list.size() <= 0)
	{
		std::cout << "\nUnable to determine the smallest number - list is empty" << std::endl;
		return;
	}

	int smallestNum{ list.at(0) };

	for (auto number : list)
	{
		if (number < smallestNum)
		{
			smallestNum = number;
		}
	}

	std::cout << "\nThe smallest number is " << smallestNum << std::endl;
}

// Returns the largest integer in the passed in vector
void LargestNumber(const std::vector<int>& list)
{
	if (list.size() <= 0)
	{
		std::cout << "\nUnable to determine the largest number - list is empty" << std::endl;
		return;
	}

	int largestNum{ list.at(0) };

	for (auto number : list)
	{
		if (number > largestNum)
		{
			largestNum = number;
		}
	}

	std::cout << "\nThe largest number is " << largestNum << std::endl;
}

// Searches and returns the number of times an integer, provided by the user, appears in the passed in vector
void SearchForNumber(const std::vector<int>& list)
{
	int totalTimes{};

	do
	{
		int userNum{};

		// Reset input
		std::cin.clear();
		std::cin.ignore(256, '\n');

		std::cout << "\nPlease enter the number you would like to for: ";
		std::cin >> userNum;

		if (std::cin.fail())
		{
			std::cout << "\nInvalid - Please enter an integer" << std::endl;
			continue;
		}

		for (auto number : list)
		{
			if (number == userNum)
			{
				totalTimes++;
			}
		}

		std::cout << "\nThe number " << userNum << " appears " << totalTimes << " time/s in the current list" << std::endl;

	} while (std::cin.fail());
}

// Clears all integers from the passed in vector
void ClearList(std::vector<int>& list)
{
	list.clear();
	std::cout << "\nThe list has been cleared" << std::endl;
}

int main()
{
	char selection{};
	std::vector<int> list{};

	DisplayWelcomeScreen();

	do
	{
		DisplayMainMenu();
		selection = GetUserSelection();

		switch (selection)
		{
			case 'P':
				{
					PrintNumbers(list);
					break;
				}

			case 'A':
				{
					AddNumber(list);
					break;
				}

			case 'M':
				{
					MeanOfNumbers(list);
					break;
				}

			case 'S':
				{
					SmallestNumber(list);
					break;
				}

			case 'L':
				{
					LargestNumber(list);
					break;
				}

			case 'O':
				{
					SearchForNumber(list);
					break;
				}

			case 'C':
				{
					ClearList(list);
					break;
				}

			case 'Q':
				std::cout << "\nGoodbye" << std::endl;
				break;

			default:
				std::cout << "\nUnknown selection, please try again" << std::endl;
				break;
		}

	} while (selection != 'Q');
}