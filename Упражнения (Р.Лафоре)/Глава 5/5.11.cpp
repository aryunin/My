#include <iostream>
using namespace std;

struct sterling
{
	int pounds;
	int shillings;
	int pence;
};

sterling s_input();
void s_output(sterling s_out);
sterling s_add(sterling s1, sterling s2);

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите первую сумму в формате <pounds.shillings.pence>: ";
	sterling amount1 = s_input();
	cout << "Введите вторую сумму в формате <pounds.shillings.pence>: ";
	sterling amount2 = s_input();
	sterling s_sum = s_add(amount1, amount2);
	cout << "Складываем... Сумма: "; 
	s_output(s_sum);
	return 0;
}

sterling s_input()
{
	sterling s_in;
	char dummychar;
	cin >> s_in.pounds >> dummychar >> s_in.shillings >> dummychar >> s_in.pence;
	return s_in;
}

void s_output(sterling s_out)
{
	cout << s_out.pounds << '.' << s_out.shillings << '.' << s_out.pence << endl;
}

sterling s_add(sterling s1, sterling s2)
{
	sterling s_sum;
	s1.pence = s1.pounds * 240 + s1.shillings * 12 + s1.pence;
	s2.pence = s2.pounds * 240 + s2.shillings * 12 + s2.pence;
	s_sum.pence = s1.pence + s2.pence;
	s_sum.pounds = s_sum.pence / 240;
	s_sum.pence %= 240;
	s_sum.shillings = s_sum.pence / 12;
	s_sum.pence %= 12;
	return s_sum;
}