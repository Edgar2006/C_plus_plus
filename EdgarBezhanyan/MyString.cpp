#include "MyString.h"
#include <iostream>

void MyString::input()
{	
    std::cout << "Enter a string: ";

    char ch;
    while (std::cin.get(ch) && ch != '\n') {
		std::cout << ch;
    }
}

void MyString::print()
{
	std::cout << m_str << std::endl;
	std::cout << m_size << std::endl;
}

int MyString::getSize()
{
	return m_size;
}

char* MyString::get_m_str()
{
	return m_str;
}

MyString::~MyString()
{
	//delete[] m_str;
}
void MyString::set_m_str(char* m_str)
{
	this->m_str = m_str;
	this->m_size = strlen(m_str);
}
