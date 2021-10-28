#include "Distance.h"

Distance Distance::operator+(Distance d2) const
{
	int f = feet + d2.feet; // ���������� ����
	float i = inches + d2.inches; // ���������� �����
	if (i >= 12.0) // ���� ������ ����� ������ 12
	{
		i -= 12.0; // �� ��������� ����� �� 12
		f++; // � ����������� ���� �� 1
	}
	return Distance(f, i); // ������� � ���������� ��������� ����������
}

Distance Distance::operator-(Distance d2) const
{
	int f = feet - d2.feet; // �������� ����
	float i = inches - d2.inches; // �������� �����
	if (i < 0.0) // ���� ������ ����� ������ 0
	{
		i += 12.0; // �� ����������� ����� �� 12
		f--; // � ��������� ���� �� 1
	}
	return Distance(f, i); // ������� � ���������� ��������� ����������
}

