#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

// ---------- Class publication ---------- 
class publication
{
private:
    string title;
    float cost;
public:
    publication() : title("N/A"), cost(0) // Тест
    { }
    /*publication(string n, float c) : name(n), cost(c)
    { }*/
    void getdata();
    void putdata() const;
};

void publication::getdata()
{
    cout << "Введите название книги: ";
    getline(cin, title);
    cout << "Введите цену книги: ";
    cin >> cost;
}
void publication::putdata() const
{
    cout << "Книга: \"" << title << "\"\tЦена: " << cost;
}
// ---------------------------------------


// -------------- Class Date ------------- 
class Date
{
private:
    int day, mounth, year;
    char dummychar;
public:
    Date() : day(1), mounth(1), year(2000), dummychar('/')
    { }
    void getdate()
    {
        cin >> day >> dummychar >> mounth >> dummychar >> year;
    }
    void showdate() const
    {
        cout << day << dummychar << mounth << dummychar << year;
    }
};
// ---------------------------------------

// ---------- Class publication2 --------- 
class publication2 : publication
{
private:
    Date pub_date; // Протестировать конструктор без аргументов класса Date
public: 
    publication2() : publication()
    { }
    void getdata();
    void putdata() const;
};

void publication2::getdata()
{
    publication::getdata();
    cout << "Введите дату публикации в формате ДД/ММ/ГГГГ: ";
    pub_date.getdate();
}
void publication2::putdata() const
{
    publication::putdata();
    cout << "\tДата публикации: ";
    pub_date.showdate();
}
// ---------------------------------------

// ------------- Class book -------------- 
class book : public publication2
{
private:
    int pages;
public:
    book() : publication2(), pages(0)
    { }
    void getdata();
    void putdata() const;
};

void book::getdata()
{
    publication2::getdata();
    cout << "Введите количество страниц: ";
    cin >> pages;
    cin.ignore(256, '\n'); // для getline() в publication2
}
void book::putdata() const
{
    publication2::putdata();
    cout << "\tКол-во страниц: " << pages << endl;
}
// ---------------------------------------

// ------------- Class tape -------------- 
class tape : public publication2
{
private:
    float rec_time;
public:
    tape() : publication2(), rec_time(float(0.0))
    { }
    void getdata();
    void putdata() const;
};

void tape::getdata()
{
    publication2::getdata();
    cout << "Введите время записи: ";
    cin >> rec_time;
    cin.ignore(256, '\n'); // для getline() в publication2
}
void tape::putdata() const
{
    publication2::putdata();
    cout << "\tВремя записи: " << rec_time << endl;
}
// ---------------------------------------

// --------------- main() ---------------- 
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\tТест класса бумажной книги: " << endl;
    book tb;
    tb.getdata();
    tb.putdata();

    cout << "\n\tТест класса  аудиокниги: " << endl;
    tape ab;
    ab.getdata();
    ab.putdata();
    return 0;
}
