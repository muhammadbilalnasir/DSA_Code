#include <iostream>
using namespace std;
class stack
{
public:
    int top;
    char *array;
    int size;
    stack(int s)
    {
        top = -1;
        array = new char[size];
    }
    void push(char a)
    {
        array[++top] = a;
    }
    bool pop(char a)
    {
        bool tn = true;
        if (top == -1)
        {
            top--;
            tn = false;
        }
        else
        {
            if ((a == '}' && array[top] == '{') || (a == ']' && array[top] == '[') || (a == ')' && array[top] == '('))
            {
                top--;
            }
            else
            {
                tn = false;
            }
        }
        return tn;
    }
};
int main()
{
    bool check;
    string a;
    cout << "enter string contain braces \"{}[]()\" for starting and ending\n";
    cin >> a;
    stack s1(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '{' || a[i] == '[' || a[i] == '(')
        {
            s1.push(a[i]);
        }
        else if (a[i] == '}' || a[i] == ']' || a[i] == ')')
        {
            check = s1.pop(a[i]);
            if (check == false)
            {
                break;
            }
        }
    }
    cout << s1.top << endl;
    if (check == false)
    {
        cout << "\nclosing not possible as order does not match\n";
    }
    else if (s1.top == -1)
    {
        cout << "\nthe opening and closing braces are equal\n";
    }
    else if (s1.top >= 0)
    {
        cout << "\nthe opening braces are greater than the closing braces\n";
    }
    else
    {
        cout << "\nthe closing braces are greater than the opening braces\n";
    }

    return 0;
}