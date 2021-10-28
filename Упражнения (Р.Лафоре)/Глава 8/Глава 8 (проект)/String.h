#pragma once
#include <iostream>
#include <string.h> // ��� ������� strcpy, strcat
#include <stdlib.h> // ��� ������� exit
class String // ��� ����� ��� �����
{
private:
	enum { SZ = 80 }; // ������������ ������ ������
	char str[SZ]; // ������ ��� ������
public:
	// ����������� ��� ����������
	String()
	{
		strcpy_s(str, "");
	}
	// ����������� � ����� ����������
	String(const char s[])
	{
		strcpy_s(str, s);
	}
	// ����������� � ����� ����������
	void display() const
	{
		std::cout << str;
	}
	// �������� ��������
	String operator+(String) const;
	String operator+=(String);
};