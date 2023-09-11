#include <iostream>
using namespace std;
class stack
{
public:
    int top;
    char *array;
    int size;
    stack(int x)
    {
        size = x;
        top = -1;
        array = new char[size];
    }
    void push(char x)
    {
        array[++top] = x;
    }
    char pop()
    {
        return array[top--];
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << array[i] << " , ";
        }
    }
    string reverse_string(string x)
    {
        for (int i = 0; i < x.size(); i++)
        {
            push(x[i]);
        }
        string b = "";
        for (int i = 0; i < x.size(); i++)
        {
            b = b + pop();
        }
        return b;
    }
};
int main()
{
    string a;
    cout << "enter string\n";
    cin >> a;
    stack s1(a.size());
    string b = s1.reverse_string(a);
    cout << b << endl;
    if (a == b)
    {
        cout << "palindrome\n";
    }
    else
    {
        cout << "not palindrome\n";
    }
}