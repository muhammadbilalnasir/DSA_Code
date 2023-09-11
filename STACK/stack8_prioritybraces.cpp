#include <iostream>
using namespace std;
class stack
{
public:
    int top;
    char *q;
    int size;
    stack(int x)
    {
        top = -1;
        size = x;
        q = new char[size];
    }
    bool push(char x)
    {
        bool check;
        if (top == -1)
        {
            q[++top] = x;
            check = true;
        }
        else
        {
            if (x == '{')
            {
                if (q[top] == '{')
                {
                    q[++top] = x;
                    check = true;
                }
                else
                {
                    check = false;
                }
            }
            else if (x == '[')
            {
                if (q[top] == '{' || q[top] == '[')
                {
                    q[++top] = x;
                    check = true;
                }
                else
                {
                    check = false;
                }
            }
            else if (x == '(')
            {
                if (q[top] == '{' || q[top] == '[' || q[top] == '(')
                {
                    q[++top] = x;
                    check = true;
                }
                else
                {
                    check = false;
                }
            }
        }
        return check;
    }
    bool pop(char x)
    {
        bool check;
        if (top == -1)
        {
            cout << "POPING NOT POSSIBLE\n";
            top--;
            check = false;
        }
        else
        {
            if (x == '}' && q[top] == '{')
            {
                q[top--];
                check = true;
            }
            else if (x == ']' && q[top] == '[')
            {
                q[top--];
                check = true;
            }
            else if (x == ')' && q[top] == '(')
            {
                q[top--];
                check = true;
            }
            else
            {
                check = false;
            }
        }
        return check;
    }
};
int main()
{
    int size;
    string a;
    cout << "enter the string with braces in order to check priority and balance\n";
    cin >> a;
    size = a.size();
    stack s1(size);
    bool check = true;
    for (int i = 0; i < size; i++)
    {

        if (a[i] == '{' || a[i] == '[' || a[i] == '(')
        {
            check = s1.push(a[i]);
            cout << "push check : " << check << endl;
            if (check != true)
            {
                break;
            }
        }
        else if (a[i] == '}' || a[i] == ']' || a[i] == ')')
        {
            check = s1.pop(a[i]);
            cout << "pop check : " << check << endl;
            if (check != true)
            {
                break;
            }
        }
    }
    if (check == true && s1.top == -1)
    {
        cout << "the string is balanced\n";
    }
    else if (check == false && s1.top < -1)
    {
        cout << "unbalanced braces\n";
    }

    else
    {
        cout << "priority issues (unbalanced braces)\n";
    }
}