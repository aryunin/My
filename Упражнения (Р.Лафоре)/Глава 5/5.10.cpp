#include <iostream>
using namespace std;

int test();

int main()
{
	setlocale(LC_ALL, "Rus");
	int calls = 0;
	for (int i = 0; i < 256; i++)
	{
		calls = test();
		cout << "Функция сработала " << calls << " раз\n";
	}
	return 0;
}

int test()
{
	static int calls = 0;
	calls++;
	return calls;
}
