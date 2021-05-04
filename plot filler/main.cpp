#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> 
using namespace std;

/// <summary>
/// ввод нескольких строк, 
/// разделенных строкой-разделителем
/// </summary>
/// <param name="istr">поток ввода</param>
/// <param name="str">строка ввода</param>
/// <param name="sep_str">строка-разделитель</param>
void getphrase(istream& istr, string& str, const string &sep_str)
{
	string str_in{ "" }; // введенная строка

	// Построчный ввод
	getline(istr, str_in); // TODO: переделать алгоритм
	while (str_in != sep_str)
	{
		str += str_in + '\n';
		getline(istr, str_in);
	}

	// Удаление последнего символа переноса каретки
	str.erase(str.end() - 1);
}

int main()
{
	// Кодировка консоли - 1251
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// Открытие сюжетного файла Plot.txt
	ofstream outf("Plot.txt");

	// Заполнение файла
	cout << "~Заполните фразы:\n";
	bool response{ 1 };
	for (int i = 1; response; i++)
	{
		// Ввод ситуации
		cout << "\n~Введите ситуацию " << i << " (end - конец ввода):\n";
		string situation{ "" };
		getphrase(cin, situation, "end");

		// Ввод действия 
		cout << "~Введите действие, приводящее к ситуации " << i << " (end - конец ввода):\n";
		string action{ "" };
		getphrase(cin, action, "end");

		// Заполнение данных вершины в файле
		outf << "#" << i << "#\n" // код вершины
			<< situation // строка с ситуацией
			<< "\n*\n" // разделитель строки с ситуацией и строки с действием
			<< action << "\n" // строка с действием
			<< flush; // очистка буфера

		// Предложение продолжить
		cout << "~Желаете ли вы продолжить?(1-да/0-нет): ";
		(cin >> response).ignore();
	}

	// Ввод кода Прюфера TODO: проверить
	cout << "\n~Введите код Прюфера (формат x1,x2,...,xn):";
	response = 1;
	string prufer{ "" }; // строка с кодом
	for (int i = 1; response; i++)
	{
		// Ввод числа
		int x{ -1 };
		cout << "~Введите число x" << i << " : ";
		while (!(cin >> x) || cin.peek() != '\n' || x <= 0) // проверка на ввод числа (должно быть введено натуральное число)
		{
			cin.clear();
			cin.ignore();
			cout << "~Ошибка: неправильно введено число. Попробуйте еще: ";
		}
		cin.ignore();

		// Заполнение строки
		prufer += to_string(x) + ",";

		// Предложение продолжить
		cout << "~Желаете ли вы продолжить?(1-да/0-нет): ";
		(cin >> response).ignore();
	}
	prufer.erase(prufer.end() - 1); // удаление последней запятой

	// Запись кода Прюфера в файл
	outf << "\n#code#\n"
		<< prufer + "\n" 
		<< flush; // очистка буфера

	// Конечный вывод программы
	cout << endl;
	system("Pause");
}