#include <iostream>
#include <Windows.h>
using namespace std;
const int LEN = 80; // максимальная длина имени
///////////////////////////////////////////////////////////
class student // сведения об образовании
{
private:
    char school[LEN]; // название учебного заведения
    char degree[LEN]; // уровень образования
public:
    void getedu()
    {
        cout << " Введите название учебного заведения: ";
        cin >> school;
        cout << " Введите степень высшего образования\n";
        cout << " (бакалавр, магистр): ";
        cin >> degree;
    }
    void putedu() const
    {
        cout << "\n Учебное заведение: " << school;
        cout << "\n Степень: " << degree;
    }
};
///////////////////////////////////////////////////////////
class employee // некий сотрудник
{
private:
    char name[LEN]; // имя сотрудника
    unsigned long number; // номер сотрудника
public:
    void getdata()
    {
        cout << "\n Введите фамилию: "; cin >> name;
        cout << " Введите номер: "; cin >> number;
    }
    void putdata() const
    {
        cout << "\n Фамилия: " << name;
        cout << "\n Номер: " << number;
    }
};
///////////////////////////////////////////////////////////
class manager : private employee, private student // менеджер
{
private:
    char title[LEN]; // должность сотрудника
    double dues; // сумма взносов в гольф-клуб
public:
    void getdata()
    {
        employee::getdata();
        cout << " Введите должность: "; cin >> title;
        cout << " Введите сумму взносов в гольф-клуб: "; cin >> dues;
        student::getedu();
    }
    void putdata() const
    {
        employee::putdata();
        cout << "\n Должность: " << title;
        cout << "\n Сумма взносов в гольф-клуб: " << dues;
        student::putedu();
    }
};

class executive : private manager
{
private:
    float annual_bonus;
    int actions;
public:
    void getdata()
    {
        manager::getdata();
        cout << " Введите размер годовой премии (в $): "; cin >> annual_bonus;
        cout << " Введите количество акций (в штуках): "; cin >> actions;
    }
    void putdata() const
    {
        manager::putdata();
        cout << "\n Размер годовой премии: " << annual_bonus << '$';
        cout << "\n Количество акций: " << actions << " штук";
    }
};
///////////////////////////////////////////////////////////
class scientist : private employee, private student // ученый
{
private:
    int pubs; // количество публикаций
public:
    void getdata()
    {
        employee::getdata();
        cout << " Введите количество публикаций: "; cin >> pubs;
        student::getedu();
    }
    void putdata() const
    {
        employee::putdata();
        cout << "\n Количество публикаций: " << pubs;
        student::putedu();
    }
};
///////////////////////////////////////////////////////////
class laborer : public employee // рабочий
{
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    manager m1;
    scientist s1;
    laborer l1;
    executive e1;
    // введем информацию о нескольких сотрудниках
    cout << "Ввод информации о первом менеджере";
    m1.getdata();
    cout << "\nВвод информации об управляющем: ";
    e1.getdata();
    cout << "\nВвод информации о первом ученом";
    s1.getdata();
    cout << "\nВвод информации о первом рабочем";
    l1.getdata();
    // выведем полученную информацию на экран
    cout << "\nИнформация о первом менеджере";
    m1.putdata();
    cout << "\nИнформация об управляющем: ";
    e1.putdata();
    cout << "\nИнформация о первом ученом";
    s1.putdata();
    cout << "\nИнформация о первом рабочем";
    l1.putdata();
    cout << endl;
    return 0;
}