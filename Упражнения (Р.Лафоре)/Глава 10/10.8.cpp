#include <iostream>
using namespace std;

struct link // один элемент списка
{
    int data; // некоторые данные
    link* next; // указатель на следующую структуру
    link() : data(0), next(NULL) // Во избежание бесконечности циклов
    { }
};

class linklist // список
{
private:
    link* first;
public:
    linklist() // конструктор без параметров
    {
        first = new link;
    } // первый элемент есть, но он не заполнен
    void additem(int d); // добавление элемента
    void display(); // показ данных
};

void linklist::additem(int d) // добавление элемента
{
    link* current = first;
    while (current->next)
        current = current->next;
    current->data = d;
    current->next = new link;
}

void linklist::display()
{
    link* current = first; // начинаем с первого элемента
    while (current->next) // пока есть данные
    {
        cout << current->data << endl; // печатаем данные
        current = current->next; // двигаемся к следующему элементу
    }
}

int main()
{
    linklist li; // создаем переменную-список
    li.additem(25); // добавляем туда несколько чисел
    li.additem(36);
    li.additem(49);
    li.additem(64);
    li.display(); // показываем список
    return 0;
}