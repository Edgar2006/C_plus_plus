#include <iostream>
#include "Array2d.h"

Array2d::Array2d()
{
}

void Array2d::Call()
{
	int row = rowInput();
	int* col = randColSize(row);
	char ** arr2d = createArr(row, col);
	printArr2d(arr2d, row, col);


	int size = findStringSizeInput();
	char* findString = findStringInput(size);
	int count = findCollisonElements(arr2d, row, findString);
	int* res = indexArr(arr2d, row, findString, count);


	printArr(res, count);
	
	deleteArr2d(arr2d, row);
	delete[] res;

	



}

int* Array2d::indexArr(char** arr, int row, char* findString, int count)
{
	int* res = new int[count];
	int iterator = 0;
	for (size_t i = 0; i < row; i++)
	{
		if (CheckStringCollison(arr[i], findString) == 1) {
			res[iterator] = i;
		}
	}
	return res;
}

int Array2d::findCollisonElements(char** arr, int row, char* findString)
{
	int count = 0;
	for (size_t i = 0; i < row; i++)
	{
		std::cout << "FFFFFFFFFFFF" << std::endl;
		if (CheckStringCollison(arr[i], findString) == 1) {
			count++;
		}
	}
	std::cout << "FFFFFFFFFFFF_" << count << std::endl;
	return count;
}

bool Array2d::CheckStringCollison(char* col, char* findString)
{
	bool b = 0;
	int j = 0;
	for (size_t i = 0;col[i] != '\0'; i++)
	{
		std::cout << "!ssadasda" << std::endl;

		if (findString[j] == '\0') {
			if (b) {
				return 1;
			}
			else {
				return 0;
			}
			if (col[i] == findString[j]) {
				b = 1;
				j++;
			}
			else {
				b = 0;
				j = 0;
			}
		}
	}
	return 0;
}

int Array2d::rowInput()
{
	std::cout << "Row size = ";
	int row;std::cin >> row;
	return row;
}

int Array2d::findStringSizeInput()
{
	std::cout << "Find string size = ";
	int size;std::cin >> size;
	return size;
}

char* Array2d::findStringInput(int size)
{
	std::cout << "Find string input = ";
	char* findString = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		char findStringChar;std::cin >> findStringChar;
		findString[i] = findStringChar;
	}
	findString[size] = '\0';
	std::cout << findString << std::endl;
	return findString;
}

char Array2d::randChar()
{
	const char ABC[]{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
	int index = rand() % (sizeof(ABC) - sizeof(ABC[0]) );
	char a = ABC[index];
	return a;
}

int * Array2d::randColSize(int row)
{
	int* col = new int[row];
	for (size_t i = 0; i < row; i++)
	{
		col[i] = (rand() % row) + 1;
	}
	return col;
}

char** Array2d::createArr(int rows, int* cols)
{
	char** arr = new char* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = new char[cols[i]];
		for (size_t j = 0; j < cols[i]; j++)
		{
			arr[i][j] = randChar();
		}
		arr[i][cols[i]] = '\0';
	}
	return arr;
}

void Array2d::printArr(int* arr, int row)
{
	std::cout << "____Result____" << std::endl;
	for (size_t i = 0; i < row; i++)
	{
		std::cout << "```````!ssadasda" << std::endl;

		std::cout << arr[i]<< " ";
	}
	std::cout << std::endl;
}

void Array2d::printArr2d(char** arr, int row, int* col)
{
	std::cout << "____ArrPrint" << std::endl;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col[i]; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Array2d::deleteArr2d(char** arr, int row)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
