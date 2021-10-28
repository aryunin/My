#include <iostream>
using namespace std;

double power(double num, int exp = 2);
double power(char num, int exp = 2);
double power(int num, int exp = 2);
double power(float num, int exp = 2);

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "2.222^2 = " << power(2.222) << endl
		<< "3.222^2 = " << power(3.222F) << endl
		<< "4^2 = " << power(static_cast<char>(4)) << endl
		<< "5^2 = " << power(5) << endl;
	return 0;
}


double power(double num, int exp)
{
	double powered_num = 1;
	for (int i = 0; i < exp; i++)
		powered_num *= num;
	return powered_num;
}

double power(char num, int exp)
{
	char powered_num = 1;
	for (int i = 0; i < exp; i++)
		powered_num *= num;
	return powered_num;
}

double power(int num, int exp)
{
	int powered_num = 1;
	for (int i = 0; i < exp; i++)
		powered_num *= num;
	return powered_num;
}

double power(float num, int exp)
{
	float powered_num = 1.0F;
	for (int i = 0; i < exp; i++)
		powered_num *= num;
	return powered_num;
}


