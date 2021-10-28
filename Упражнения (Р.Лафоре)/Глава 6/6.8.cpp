#include <iostream>
#include <Windows.h>
using namespace std;

class custom
{
private:
	static unsigned int obj_count;
	unsigned int obj_number;
public:
	custom() : obj_number(++obj_count)
	{ }
	void show_number()
	{
		cout << "Мой порядковый номер: " << obj_number << endl;
	}
};

unsigned int custom::obj_count = 0;

int main()
{
	SetConsoleOutputCP(1251);
	custom obj1, obj2, obj3;
	obj1.show_number();
	obj2.show_number();
	obj3.show_number();
	return 0;
}
