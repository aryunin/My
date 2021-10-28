#pragma once
#include <iostream>
class Distance // ����� ���������� ��� �����
{
private:
	int feet;
	float inches;
public:
	// ����������� ��� ����������
	Distance() : feet(0), inches(0.0)
	{ }
	// ����������� � ����� �����������
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	// ��������� ���������� �� ������������
	void getdist()
	{
		std::cout << "\n������� ����: "; std::cin >> feet;
		std::cout << "������� �����: "; std::cin >> inches;
	}
	// ����� ����������
	void showdist()
	{
		std::cout << feet << "\'-" << inches << '\"';
	}
	// �������� ���� ����
	Distance operator+(Distance) const;
	Distance operator-(Distance) const;
};