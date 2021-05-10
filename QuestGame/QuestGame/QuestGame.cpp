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

/// <summary>
/// 
/// </summary>
class GameData
{
private:
	struct Node; // вершина дерева формата действие-ситуаци€
	Node* root{ nullptr }; // корень дерева
public:
	//  онструктор по умолчанию
	GameData() : root{ nullptr }
	{ }
	//  онструктор копировани€
	GameData(const GameData&)
	{ } // TODO доделать
	//~GameData();

	GameData& operator=(const GameData&);

	void readFile(const char* const);
};

/// <summary>
/// ¬ершина дерева формата действие-ситуаци€
/// </summary>
struct GameData::Node
{
	string action{ "" }; // строка с действием
	string situation{ "" }; // строка с ситуацией
	vector <Node*> child; // массив потомков

	Node() : action(""), situation("")
	{ }
	Node(const string& act, const string& sit) : action(act), situation(sit)
	{ }
	// TODO: запретить конструкторы коп и операцию =?
};


/// <summary>
/// 
/// </summary>
/// <param name="s"></param>
void GameData::readFile(const char* const filePath)
{
	ifstream inf{ filePath };
	if (!inf.is_open()) throw 1; // проверка на существование файла
	
	// „тение файла
	using PowNodePair = pair <int, Node*>; // пара степень вершины - указатель на вершину
	vector <PowNodePair> vertices; // массив вершин с их степен€ми
	const char CODE_SYMBOL = '#'; // кодовый символ-разделитель
	string istr; // строка из файла
	while (getline(inf, istr))
	{
		// Ќаождение 2-х кодовых символов (1-между степенью и действием, 2-между действием и ситуацией)
		unsigned int firstCSPos{ istr.find(CODE_SYMBOL) };
		if (firstCSPos == string::npos) throw 2;
		unsigned int secondCSPos{ istr.find(CODE_SYMBOL, firstCSPos + 1) };
		if (secondCSPos == string::npos) throw 2;
		unsigned int excessCSPos{ istr.find(CODE_SYMBOL, secondCSPos + 1) };
		if (excessCSPos != string::npos) throw 2;

		// ѕреобразование степени вершины в int
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

		// «апись действи€ и ситуации в string
		string action{ istr.substr(firstCSPos + 1, secondCSPos - firstCSPos - 1) };
		string situation{ istr.substr(secondCSPos + 1, istr.length() - secondCSPos - 1) };
		
		// «апись данных в вектор
		vertices.push_back(PowNodePair{ vertPow, new Node{action, situation} });
	}
	inf.close(); // закрытие файла

	// «аполнение дерева (установление св€зей)
	root = vertices[0].second;
	vector<PowNodePair>::const_iterator itPrnt{ vertices.cbegin() };
	vector<PowNodePair>::const_iterator itChild{ vertices.cbegin() + 1 };
	while(itPrnt != vertices.cend())
	{
		int prntPow = (*itPrnt).first; // степень родительской вершины
		Node* prnt = (*itPrnt).second; // указаиель на род. вершину
		// ”становление св€зи между родительской вершиной и prntPow дочерними вершинами
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

class GamePlay
{

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GameData data;
	try
	{
		data.readFile("Plot.txt");
	}
	catch (int k)
	{
		cerr << "ERROR: code " << k << "!\n";
	}
	system("pause");
}