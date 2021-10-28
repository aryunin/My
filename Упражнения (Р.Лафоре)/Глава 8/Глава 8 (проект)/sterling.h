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
	static const double dollar_exRate; // Цена в долларах за 1 фунт стерлингов в старом формате
public:
	sterling();
	sterling(long, int, int);

	// Конструкторы преобразования
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

