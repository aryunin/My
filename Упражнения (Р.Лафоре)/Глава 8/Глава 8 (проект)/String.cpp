#include "String.h"
#include <iostream>
#include <string.h> // ��� ������� strcpy, strcat
#include <stdlib.h> // ��� ������� exit

String String::operator+(String ss) const
{
	String temp; // ��������� ����������
	if (strlen(str) + strlen(ss.str) < SZ)
	{
		strcpy_s(temp.str, str); // �������� ���������� ������ ������
		strcat_s(temp.str, ss.str); // ��������� ���������� ������ ������
	}
	else
	{
		std::cout << "\n������������!";
		exit(1);
	}
	return temp; // ���������� ���������
}

String String::operator+=(String ss)
{
	if (strlen(str) + strlen(ss.str) < SZ)
		strcat_s(str, ss.str); // ��������� ���������� ������ ������
	else
	{
		std::cout << "\n������������!";
		exit(1);
	}
	String temp;
	strcpy_s(temp.str, str);
	return temp; // ���������� ���������
}
