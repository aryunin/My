#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <iomanip>
using namespace std;
enum Suit { clubs, diamonds, hearts, spades };
// от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
/////////////////////////////////////////////////////////////
class card
{
private:
	int number;
	Suit suit;
public:
	card() // конструктор
	{ }
	void set(int n, Suit s) // установка значения
	{
		suit = s; number = n;
	}
	void display(); // показ карты
};
/////////////////////////////////////////////////////////////
void showCard(card[], int, int);
/////////////////////////////////////////////////////////////
void card::display()
{
	if (number >= 2 && number <= 10)
		cout << number;
	else
	{
		switch (number)
		{
		case jack: cout << 'J'; break;
		case queen: cout << 'Q'; break;
		case king: cout << 'K'; break;
		case ace: cout << 'A'; break;
		}
	}
	switch (suit)
	{
	case clubs: cout << static_cast<char>(5); break;
	case diamonds: cout << static_cast<char>(4); break;
	case hearts: cout << static_cast<char>(3); break;
	case spades: cout << static_cast<char>(6); break;
	}
}
/////////////////////////////////////////////////////////////
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	card deck[52];
	int j;
	cout << endl;
	for (j = 0; j < 52; j++) // создаем упорядоченную колоду карт
	{
		int num = (j % 13) + 2;
		Suit su = Suit(j / 13);
		deck[j].set(num, su);
	}
	srand(time(NULL)); // инициализируем генератор случайных чисел
	for (j = 0; j < 52; j++)
	{
		int k = rand() % 52; // выбираем случайную карту
		card temp = deck[j]; // и меняем ее с текущей
		deck[j] = deck[k];
		deck[k] = temp;
	}
	// показываем перемешанную колоду, разделенную на четырех игроков:
	int player = 1;
	while (player < 5)
	{
		int begin = (player - 1) * 13;
		cout << "Игрок " << player++ << ": ";
		showCard(deck, begin, begin + 13);
		cout << endl;
	}
	return 0;
}

void showCard(card deck[], int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		cout << setw(2);
		deck[i].display();
		cout << ' ';
	}
}