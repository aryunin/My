#pragma once

class bMoney;

class sterling
{
private:
	unsigned long pounds;
	int shillings;
	int pense;
	static const unsigned char poundsymbol;
	static const unsigned char pointsymbol;
	static const double MAX_DBL;
	static const double dollar_exRate; // ���� � �������� �� 1 ���� ���������� � ������ �������
public:
	sterling();
	sterling(long, int, int);

	// ������������ ��������������
	sterling(double);
	sterling(bMoney);

	void toStandart();
	//sterling toStandart(sterling) const;
	void getSterling() const;
	void putSterling();
	operator double() const;
	sterling operator+(sterling);
	sterling operator-(sterling);
	sterling operator*(double);
	sterling operator/(double);
	sterling operator/(sterling);
};

