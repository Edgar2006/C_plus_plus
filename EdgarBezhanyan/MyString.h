#pragma once
class MyString
{

private:
	char* m_str = nullptr;
	int m_size = 2;

public:
	~MyString();
	void set_m_str(char* m_str);
	char* get_m_str();
	void input();
	void print();
	int getSize();

};




