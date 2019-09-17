/*
	Write a C++ function named ApplyAll that expects two arrays of integers and their sizes and
	dynamically allocates a new array of integers whose size is the product of the 2 array sizes.

	The function should loop through the array 2 and mutliply each element across each element of array 1 and store the product in the newly created array.

	The function should return a pointer to the newly allocated array.

	You can also write a print function that expects a pointer to an array of integers and its size and display the elements in the array.

	For example,

	Below is the output from the following code which would be in main:

		const size_t array1Size{5};
		const size_t array2Size{3};

		int array1[]{ 1, 2, 3, 4, 5 };
		int array2[]{ 10, 20, 30, };

		std::cout << "Array 1: ";
		Print(array1, 5);

		std::cout << "Array 2: ";
		Print(array2, 3);

		int* results = ApplyAll(array1, 5, array2, 3);
		constexpr size_t resultsSize{array1Size * array2Size}
		Std::cout << "Result: ";
		Print(results, 15);

		Output
		----------------------
		Array 1: [ 1 2 3 4 5 ]
		Array 2: [ 10 20 30 ]
		Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/

#include <iostream>

// Dynamically creates a new array on the heap that is the product of each of second arrays elements multiplied by all of the first arrays elements
int* ApplyAll(const int*, size_t, const int*, size_t);

// Prints out the content of an array to the console
void Print(const int*, size_t);

int main()
{
	const size_t array1Size{ 5 };
	const size_t array2Size{ 3 };

	int array1[]{ 1, 2, 3, 4, 5 };
	int array2[]{ 10, 20, 30, };

	std::cout << "Array 1: ";
	Print(array1, array1Size);

	std::cout << "Array 2: ";
	Print(array2, array2Size);

	int* results = ApplyAll(array1, array1Size, array2, array2Size);
	constexpr size_t resultsSize{ array1Size * array2Size };
	std::cout << "Result: ";
	Print(results, resultsSize);

	delete[] results;
}

int* ApplyAll(const int* const array1, size_t array1Size, const int* const array2, size_t array2Size)
{
	int* newArrayPtr{ nullptr };
	newArrayPtr = new int[array1Size * array2Size];

	int newArrayIndex{ 0 };

	for (size_t i = 0; i < array2Size; i++)
	{
		for (size_t j = 0; j < array1Size; j++)
		{
			newArrayPtr[newArrayIndex] = array2[i] * array1[j];

			newArrayIndex++;
		}
	}
	return newArrayPtr;
}

void Print(const int* const array, size_t size)
{
	std::cout << "[ ";

	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}

	std::cout << "]" << std::endl;
}