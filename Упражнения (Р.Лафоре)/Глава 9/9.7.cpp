#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Counter
{
protected: // заметьте, что тут не следует использовать private
    unsigned int count; // счетчик
public:
    Counter() : count() // конструктор без параметров
    { }
    Counter(int c) : count(c) // конструктор с одним параметром
    { }
    unsigned int get_count() const // получение значения
    {
        return count;
    }
    Counter operator++() // оператор увеличения
    {
        return Counter(++count);
    }
};
///////////////////////////////////////////////////////////
class CountDn : public Counter
{
public:
    CountDn() : Counter() // конструктор без параметров
    { }
    CountDn(int c) : Counter(c) // конструктор с одним параметром
    { }
    CountDn operator--() // оператор уменьшения
    {
        return CountDn(--count);
    }
};
///////////////////////////////////////////////////////////
class CounterMod : public CountDn
{
public:
    CounterMod() : CountDn() // конструктор без параметров
    { }
    CounterMod(int c) : CountDn(c) // конструктор с одним параметром
    { }
    CounterMod operator--(int) // оператор уменьшения
    {
        return CounterMod(count--);
    }
    CounterMod operator++(int) // оператор увеличения
    {
        return CounterMod(count++);
    }
    using Counter::operator++;
    using CountDn::operator--;
};
///////////////////////////////////////////////////////////
int main()
{
    CounterMod c;
    c++;
    cout << c.get_count();
    c--;
    cout << c.get_count();
    ++c;
    cout << c.get_count();
    --c;
    cout << c.get_count();
    return 0;
}