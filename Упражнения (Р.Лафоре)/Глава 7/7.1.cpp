#include <iostream>
#include <windows.h>
using namespace std;

void reversit(char[]);

int main()
{
	SetConsoleOutputCP(1251);
	char str[] = "Аргентина манит негра";
	reversit(str);
	cout << str;
	return 0;
}

void reversit(char str[])
{
	int len = strlen(str);
	char tmp;
	for (int i = 0; i < len / 2; i++)
	{
		char tmp = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = tmp;
	}
}