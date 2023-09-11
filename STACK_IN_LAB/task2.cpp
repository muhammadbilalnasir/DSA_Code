#include <iostream>

using namespace std;
class sta
{
private:
    int tos;
    char values[];

public:
    sta(int x)
    {
        tos = -1;
        values[x];
    }
    void push(char x)
    {
        if (tos == 9)
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
int main()
{
    sta *myStack;
    myStack = new sta(10);
    myStack->push('B');
    myStack->push('S');
    myStack->push('S');
    myStack->push('E');
    myStack->push('3');
    myStack->push('Z');
    cout << myStack->pop();
    cout << myStack->pop();
    cout << myStack->pop();
    cout << myStack->pop();
    cout << myStack->pop();
    cout << myStack->pop();
    cout << myStack->pop();
}