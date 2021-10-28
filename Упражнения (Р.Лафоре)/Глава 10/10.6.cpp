#include <iostream>
using namespace std;

int compstr(const char*, const char*);

int main()
{
    const char* str1 = "aab";
    const char* str2 = "aaa";
    cout << compstr(str1, str2);
    return 0;
}

int compstr(const char* s1, const char* s2)
{
    const int min_strlen = (strlen(s1) < strlen(s2)) ? strlen(s1) : strlen(s2);
    for (int i = 0; i < min_strlen; i++)
    {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        else
            continue;
    }
    return 0; // Возвращает 0, если не было возвращения в цикле, т.е. строки равны
}