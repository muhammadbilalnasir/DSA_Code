#include <iostream>
#include <string>
using namespace std;
class sta
{
private:
    int tos;
    char *values;
    int size;

public:
    sta(int x)
    {
        size = x;
        tos = -1;
        values = new char[size];
    }
    void push(char x)
    {
        if (tos == size - 1)
            cout << "\nStack overflow condition";
        else
            values[++tos] = x;
    }
    char pop()
    {
        if (tos == -1)
        {
            cout << "\nStack Underflow condition";
            return ' ';
        }
        else
            return values[tos--];
    }
};
using namespace std;
int main()
{
    char str[] = "I Love Programming";
    int len = sizeof(str);
    sta s1(len);
    for (int i = 0; i < len; i++)
        s1.push(str[i]);
    for (int i = 0; i < len; i++)
        cout << s1.pop();
}