/*=======================================
Name: QuestGame.cpp
Author: Yunin Artem (Artemiiik)
Date: 08.05.2021
Version: 
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


template<class T>
struct Node
{
	T data; // данные
	vector <Node*> child; // потомки

	// Конструктор с аргументом T
	explicit Node(T _data) : data{ _data }
	{ }
	// Конструктор копирования
	Node(const Node& _node) : data{ _node.data }
	{
		typename vector<Node*>::const_iterator it;
		for (it = _node.child.cbegin(); it != _node.child.cend(); it++)
			child.push_back(new Node{ **it });
	}
	// Оператор присваивания
	Node& operator=(const Node& _node)
	{
		data = _node.data;
		typename vector<Node*>::const_iterator it;
		// Сначала очищаем вектор
		for (it = child.begin(); it != child.end(); it++)
			delete* it; // каждый элемент представлен в виде динамической памяти, сначала очищаем память
		child.clear(); // затем удаляем все указатели
		// Затем заполняем его копиями детей
		for (it = _node.child.сbegin(); it != _node.child.сend(); it++)
			child.push_back(new Node{ **it });
		return *this;
	}
	// Деструктор
	~Node()
	{
		typename vector<Node*>::const_iterator it;
		for (it = child.cbegin(); it != child.cend(); it++)
			delete* it;
	}
};

template<class T>
class tGameData
{
private:
	Node<T>* root; // корневая вершина
public:
	// Конструктор по умолчанию
	tGameData() : root{ nullptr }
	{ }
	// Конструктор копирования TODO: test
	tGameData(const tGameData<T>& _data)
	{
		(_data.root == nullptr) ? root = nullptr : root = new Node{ *(_data.root) };
	}
	// Оператор присваивания TODO: test
	tGameData& operator=(const tGameData<T>& _data)
	{
		delete root;
		(_data.root == nullptr) ? root = nullptr : root = new Node{ *(_data.root) };
		return *this;
	}
	// Деструктор TODO: test
	~tGameData()
	{
		delete root;
	}


	T getNodeData() const
	{
		return root->data; // TODO: nullptr situation?
	}

	unsgined int getNodeChildCount()
	{
		return (root->child).size();
	}

	void gotoNextNode(const int childNum)
	{
		if (childNum >= (root->child).size() || childNum < 0)
			throw 1; // TODO: errors codes
		root = (root->child)[childNum];
	}
};











// TODO: comment
using level = pair<string, string>;

/// <summary>
/// 
/// </summary>
class GameData
{
private:
	Node<level>* root{ nullptr }; // корень дерева
public:
	// Конструктор по умолчанию
	GameData() : root{ nullptr }
	{ }
	// Конструктор копирования TODO: test
	GameData(const GameData& _data) 
	{ 
		(_data.root == nullptr) ? root = nullptr : root = new Node<level>{ *(_data.root) };
	}
	// Оператор присваивания TODO: test
	GameData& operator=(const GameData& _data)
	{
		delete root;
		(_data.root == nullptr) ? root = nullptr : root = new Node<level>{ *(_data.root) };
		return *this;
	}
	// Деструктор TODO: test
	~GameData()
	{
		delete root;
	}

	/// TODO: comment
	void readFile(const char* const, const char);

	friend class GamePlay;
};

/// TODO: comment
void GameData::readFile(const char* const filePath, const char codeSym = '#')
{
	ifstream inf{ filePath };
	if (!inf.is_open()) throw 1; // проверка на существование файла
	
	// Чтение файла
	using PowNodePair = pair <int, Node<level>*>; // пара степень вершины - указатель на вершину
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

		level lvl{ action, situation };
		
		// Запись данных в вектор
		vertices.push_back(PowNodePair{ vertPow, new Node<level>{lvl} });
	}
	inf.close(); // закрытие файла

	// Заполнение дерева (установление связей)
	root = vertices[0].second;
	vector<PowNodePair>::const_iterator itPrnt{ vertices.cbegin() };
	vector<PowNodePair>::const_iterator itChild{ vertices.cbegin() + 1 };
	while(itPrnt != vertices.cend())
	{
		int prntPow = (*itPrnt).first; // степень родительской вершины
		Node<level>* prnt = (*itPrnt).second; // указаиель на род. вершину
		// Установление связи между родительской вершиной и prntPow дочерними вершинами
		for (int i{ 0 }; i < prntPow; ++i, ++itChild)
		{
			(itChild == vertices.cend()) ? throw 2 : 0; // если неверно указана степень вершины, 
														// конец вектора может быть достигнут раньше - неверное заполнение файла
			Node<level>* child = (*itChild).second; 
			prnt->child.push_back(child);
		}
		++itPrnt;
	}
}

class GamePlay
{
private:
	GameData data;
public:
	// Конструктор c одним аргументом. Конструктор по умолчанию не предусмотрен концепцией
	explicit GamePlay(const GameData& _data) : data(_data)
	{ }
	
	// Конструктор копирования
	GamePlay(const GamePlay& _gamePlay) : data(_gamePlay.data)
	{ }

	void play() const;
};

void hyphenate(string& str, const int buffSize)
{	
	unsigned int i{ str.length()};
	while(i > 0)
	{
		if (str[i-1] == ' ')
		{
			str[i-1] = '\n';
			break;
		}
		--i;
	}
}

void GamePlay::play() const
{
	// Получаем размер консольного окна в символах
	HANDLE hWndCon{ GetStdHandle(STD_OUTPUT_HANDLE) };
	CONSOLE_SCREEN_BUFFER_INFO csbiData;
	GetConsoleScreenBufferInfo(hWndCon, &csbiData);
	int width{ csbiData.dwSize.X };

	Node<level>* currentNode = data.root; // получаем корневую вершину
	while (currentNode) // пока есть вершины
	{
		string situation{ (currentNode->data).second };
		hyphenate(situation, width-1);

		// Выводим ситуацию
		cout << "~" + situation + '\n';

		// Если нет вариантов ответа, конец игры
		if ((currentNode->child).size() == 0)
		{
			cout << "\n~Конец игры\n";
			// TODO: gameover()
			break;
		}

		// Если варианты ответа есть, выводим их на выбор
		cout << "\n~Варианты ответа:\n";
		vector<Node<level>*>::const_iterator itChild{ (currentNode->child).cbegin() };
		for (int i{ 0 }; itChild != (currentNode->child).cend(); i++)
		{
			string action{ ((*itChild)->data).first };
			hyphenate(action, width - 2);

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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GameData data;
	data.readFile("Plot.txt");

	GamePlay game(data);
	game.play();
	
	system("pause");
}