#include <iostream>
using namespace std;

struct sterling
{
	int pounds;
	int shillings;
	int pence;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	sterling old, modern;
	cout << "Введите количество фунтов и пенсов в современном формате <pounds.pence>: ";
	char dummychar;
	cin >> modern.pounds >> dummychar >> modern.pence;
	int tmp_pence = (modern.pence + modern.pounds * 100);
	old.pounds = tmp_pence / 12 / 20;
	old.shillings = tmp_pence / 12 % 20;
	old.pence = tmp_pence % 12 % 20;
	cout << "В старом формате это: " << old.pounds << dummychar << old.shillings << dummychar << old.pence << endl;
}