#include <iostream>
#include <Windows.h>
using namespace std;
///////////////////////////////////////////////////////////
class Stack
{
protected: // Замечание: использовать private нельзя
    enum { MAX = 6 }; // размер стека
    int st[MAX]; // данные, хранящиеся в стеке
    int top; // индекс последнего элемента в стеке
public:
    Stack() // конструктор
    {
        top = -1;
    }
    void push(int var) // помещение числа в стек
    {
        st[++top] = var;
    }
    int pop() // извлечение числа из стека
    {
        return st[top--];
    }
};
///////////////////////////////////////////////////////////
class Stack2 : public Stack
{
public:
    void push(int var) // помещение числа в стек
    {
        if (top >= MAX - 1) // если стек полон, то ошибка
        {
            cout << "\nОшибка: стек полон"; exit(1);
        }
        Stack::push(var); // вызов функции push класса Stack
    }
    int pop() // извлечение числа из стека
    {
        if (top < 0) // если стек пуст, то ошибка
        {
            cout << "\nОшибка: стек пуст\n"; exit(1);
        }
        return Stack::pop(); // вызов функции pop класса Stack(можно без return)
    }
};

struct Pair
{
    int x;
    int y;
};

class PairStack : public Stack2
{
public:
    void push(Pair p1)
    {
        Stack2::push(p1.x);
        Stack2::push(p1.y);
    }
    Pair pop()
    {
        Pair result = { Stack2::pop(), Stack2::pop() };
        swap(result.x, result.y);
        return result;
    }
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleOutputCP(1251);

    Pair p1 = { 1,2 };
    Pair p2 = { 3,4 };
    Pair p3 = { 5,6 };

    PairStack s1;
    s1.push(p1); // поместим в стек несколько чисел
    s1.push(p2);
    s1.push(p3);

    Pair r1 = s1.pop();
    Pair r2 = s1.pop();
    Pair r3 = s1.pop();

    cout << endl << r1.x << r1.y; // заберем числа из стека
    cout << endl << r2.x << r2.y;
    cout << endl << r3.x << r3.y;
    //cout << endl << s1.pop().x << s1.pop().y; // ой, а данных-то больше нет
    cout << endl;
    return 0;
}