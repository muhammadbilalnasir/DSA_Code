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
        array = new char[size];
        top = -1;
    }

    void push(char x)
    {
        array[++top] = x;
    }
    char pop()
    {
        return array[top--];
    }
    bool is_empty()
    {
        return top == -1;
    }

    int precedence(char x)
    {
        if (x == '(' || x == ')')
        {
            return 3;
        }
        else if (x == '/' || x == '*')
        {
            return 2;
        }
        else if (x == '+' || x == '-')
        {
            return 1;
        }
    }

    char postfix(char x)
    {
        if (x == '(')
        {
            cout << "first if\n";
            push(x);
            return '\0';
        }
        else
        {
            if (x == ')')
            {
                cout << "second if\n";
                while (array[top] != '(')
                {

                    cout << "third if ki else ka loop ka bhosda\n";
                    char a;
                    a = pop();
                    if (array[top] == '(')
                    {
                        pop();
                    }

                    return a;
                }
            }
            else
            {
                if (array[top] == '(')
                {
                    cout << "fourth if\n";
                    push(x);
                    return '\0';
                }
                else
                {
                    if (precedence(x) > precedence(array[top]))
                    {
                        cout << "fifth if\n";
                        push(x);
                        return '\0';
                    }
                    else if (precedence(x) <= precedence(array[top]))
                    {
                        cout << "sixth if else \n";
                        while (precedence(x) >= precedence(array[top]))
                        {
                            cout << "loop working\n";
                            char a;
                            a = pop();
                            return a;
                        }
                    }
                }
            }
        }
    }
};
int main()
{
    string a;
    cout << "enter string to convert to prefix" << endl;
    cin >> a;
    stack s1(a.size());
    string b = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(' || a[i] == ')' || a[i] == '/' || a[i] == '*' || a[i] == '+' || a[i] == '-')
        {
            char ans = s1.postfix(a[i]);
            b = b + ans;
        }
        else
        {
            b = b + a[i];
        }
    }
    cout << "INFIX STRING : " << a << endl;
    cout << "POSTFIX STRING : " << b << endl;
}