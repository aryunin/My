/*=======================================
Name: QuestGame.cpp
Author: Yunin Artem (Artemiiik)
Date: 09.06.2021
Version: 1.0
Copiright: freeware
Description:
A simple console game based 
on multiple-choice questions
=======================================*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

//================================================================================================

/// <summary>
/// Один уровень представляет собой действие,
/// приводящее к ситуации, и саму ситуацию непосредственно
/// </summary>
struct Level
{
	string action; // действие
	string situation; // ситуация

	// Конструктор с двумя строками
	Level(const string& _action, const string& _situation) : action(_action), situation(_situation)
	{ }
};

/// <summary>
/// Одна вершина представляет k-арное дерево с данными в виде уровня Level
/// </summary>
struct Node
{
	Level data; // данные
	vector <Node*> child; // потомки

	// Конструктор с аргументом Level
	explicit Node(const Level& _Level) : data{ _Level }
	{ }
	// Конструктор копирования
	Node(const Node& _Node) : data{ _Node.data }
	{
		vector<Node*>::const_iterator it;
		for (it = _Node.child.cbegin(); it != _Node.child.cend(); it++)
			child.push_back(new Node{ **it }); // вектор потомков заполняется копиями потомков копируемой вершины
	}
	// Оператор присваивания
	Node& operator=(const Node& _Node)
	{
		data = _Node.data;
		vector<Node*>::const_iterator it;

		// Сначала очищаем вектор
		for (it = child.cbegin(); it != child.cend(); it++)
			delete* it; // каждый элемент представлен в виде динамической памяти, сначала очищаем память
		child.clear(); // затем удаляем все указатели

		// Затем заполняем его копиями детей
		for (it = _Node.child.cbegin(); it != _Node.child.cend(); it++)
			child.push_back(new Node{ **it });

		// Возвращаем текующую структуру
		return *this;
	}
	// Деструктор
	~Node()
	{
		vector<Node*>::const_iterator it;
		for (it = child.cbegin(); it != child.cend(); it++)
			delete* it;
		child.clear();
	}
};

//================================================================================================

/// <summary>
/// Класс, отвечающий за считывание сюжетных данных из файла
/// и последующее хранение их
/// </summary>
class GameData
{
private:
	Node* root{ nullptr }; // корень дерева
public:
	// Конструктор по умолчанию
	GameData() : root{ nullptr }
	{ }
	// Конструктор копирования 
	GameData(const GameData& _GameData) 
	{ 
		(_GameData.root == nullptr) ? root = nullptr : root = new Node{ *(_GameData.root) };
	}
	// Оператор присваивания 
	GameData& operator=(const GameData& _GameData)
	{
		delete root;
		(_GameData.root == nullptr) ? root = nullptr : root = new Node{ *(_GameData.root) };
		return *this;
	}
	// Деструктор 
	~GameData()
	{
		delete root;
	}
	
	void readFile(const char* const, const char);

	friend class GamePlay;
};

/// <summary>
/// Чтение файла
/// </summary>
/// <param name="filePath">Путь к файлу</param>
/// <param name="codeSym">Кодовый символ</param>
void GameData::readFile(const char* const filePath, const char codeSym = '#')
{
	ifstream inf{ filePath };
	if (!inf.is_open()) throw 1; // проверка на существование файла
	
	// Чтение файла
	using PowNodePair = pair <int, Node*>; // пара степень вершины - указатель на вершину
	vector <PowNodePair> vertices; // массив вершин с их степенями
	string istr; // строка из файла
	while (getline(inf, istr))
	{
		// Наождение 2-х кодовых символов (1-между степенью и действием, 2-между действием и ситуацией)
		unsigned int firstCSPos{ istr.find(codeSym) };
		if (firstCSPos == string::npos) throw 2;
		unsigned int secondCSPos{ istr.find(codeSym, firstCSPos + 1) };
		if (secondCSPos == string::npos) throw 2;
		unsigned int excessCSPos{ istr.find(codeSym, secondCSPos + 1) };
		if (excessCSPos != string::npos) throw 2;

		// Преобразование степени вершины в int
		string powStr{ istr.substr(0, firstCSPos) }; 
		int vertPow{};
		try
		{
			vertPow = stoi(powStr);
		} 
		catch (invalid_argument) 
		{
			throw 2;
		}

		// Запись действия и ситуации в string
		string action{ istr.substr(firstCSPos + 1, secondCSPos - firstCSPos - 1) };
		string situation{ istr.substr(secondCSPos + 1, istr.length() - secondCSPos - 1) };

		Level lvl{ action, situation };
		
		// Запись данных в вектор
		vertices.push_back(PowNodePair{ vertPow, new Node{lvl} });
	}
	inf.close(); // закрытие файла

	// Заполнение дерева (установление связей)
	root = vertices[0].second;
	vector<PowNodePair>::const_iterator itPrnt{ vertices.cbegin() };
	vector<PowNodePair>::const_iterator itChild{ vertices.cbegin() + 1 };
	while(itPrnt != vertices.cend())
	{
		int prntPow = (*itPrnt).first; // степень родительской вершины
		Node* prnt = (*itPrnt).second; // указаиель на род. вершину
		// Установление связи между родительской вершиной и prntPow дочерними вершинами
		for (int i{ 0 }; i < prntPow; ++i, ++itChild)
		{
			(itChild == vertices.cend()) ? throw 2 : 0; // если неверно указана степень вершины, 
														// конец вектора может быть достигнут раньше - неверное заполнение файла
			Node* child = (*itChild).second; 
			prnt->child.push_back(child);
		}
		++itPrnt;
	}
}

//================================================================================================

/// <summary>
/// Класс, отвечающий за логику игры
/// </summary>
class GamePlay
{
private:
	GameData data;
public:
	// Конструктор c одним аргументом. Конструктор по умолчанию не предусмотрен концепцией
	explicit GamePlay(const GameData& _data) : data(_data)
	{ }
	// Конструктор копирования
	GamePlay(const GamePlay& _GamePlay) : data(_GamePlay.data)
	{ }
	// Оператор присваивания
	GamePlay& operator=(const GamePlay& _GamePlay) 
	{
		data = _GamePlay.data;
	}

	void play() const;
};

/// <summary>
/// Функция игры
/// </summary>
void GamePlay::play() const
{
	Node* currentNode = data.root; // получаем корневую вершину
	while (currentNode) // пока есть вершины
	{
		string situation{ (currentNode->data).situation };

		// Выводим ситуацию
		cout << "~" + situation + '\n';

		// Если нет вариантов ответа, конец игры
		if ((currentNode->child).size() == 0)
		{
			cout << "\n~Конец игры\n\n";
			break;
		}

		// Если варианты ответа есть, выводим их на выбор
		cout << "\n~Варианты ответа:\n";
		vector<Node*>::const_iterator itChild{ (currentNode->child).cbegin() };
		for (int i{ 0 }; itChild != (currentNode->child).cend(); i++)
		{
			string action{ ((*itChild)->data).action };

			cout << i << ") " + action + '\n';
			itChild++;
		}

		// Предлагаем выбрать вариант ответа
		cout << "\n~Введите выбранный вариант ответа: ";
		int response{};
		while (!(cin >> response) || cin.peek() != '\n' || response < 0 || (unsigned)response >= (currentNode->child).size())
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "~Такого варианта не существует. Попробуйте еще раз: ";
		}
		
		// Переход на новую вершину
		currentNode = (currentNode->child)[response];

		// Перед новой ситуацией пропускаем строку
		cout << '\n';
	}
}

//================================================================================================

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Чтение сюжетных данных
	GameData data; // сюжетные данные
	try 
	{
		data.readFile("Plot.txt"); // пробуем прочитать файл
	}
	catch (int code)
	{
		switch (code)
		{
		case 1:
			cerr << "ОШИБКА: сюжетный файл не найден!\n";
			return 1;
			break;
		case 2:
			cerr << "ОШИБКА: сюжетный файл заполнен неверно!\n";
			return 2;
			break;
		}
	}

	// Сама игра
	GamePlay game(data); // инициализируем игру нашим GameData
	game.play(); // начинаем игру
	
	system("pause");
}