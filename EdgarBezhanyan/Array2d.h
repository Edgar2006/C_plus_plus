#pragma once
class Array2d
{
public:
	Array2d();


	void Call();
	int* indexArr(char** arr, int row, char* findString, int count);
	int findCollisonElements(char** arr, int row, char* findString);
	bool CheckStringCollison(char * col, char* findString);
	int rowInput();
	int findStringSizeInput();
	char* findStringInput(int size);
	char randChar();
	int* randColSize(int row);
	char** createArr(int rows, int* cols);
	void printArr2d(char** arr, int row, int* col);
	void printArr(int* arr, int row);
	void deleteArr2d(char** arr, int row);

};

