#include <iostream>
#include <cstdlib>
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
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << array[i] << " ";
        }

        cout << "\n";
    }
    string postfix(char x)
    {
        string temp = "";
        if (x == '(' || top == -1)
        {
            push(x);
        }
        else
        {
            if (x == ')')
            {
                while (array[top] != '(')
                {
                    string a;
                    a = pop();
                    temp = temp + a;
                }
                pop();
            }
            else
            {
                if (array[top] == '(')
                {
                    push(x);
                }
                else
                {
                    if (precedence(x) > precedence(array[top]))
                    {
                        push(x);
                    }
                    else if (precedence(x) <= precedence(array[top]))
                    {
                        while (top != -1 && precedence(x) <= precedence(array[top]))
                        {
                            if (array[top] == '(')
                            {
                                break;
                            }
                            string a;
                            a = pop();
                            cout << top << endl;
                            temp = temp + a;
                        }
                        push(x);
                        display();
                    }
                }
            }
        }
        display();
        return temp;
    }
    void evaluation_of_postfix(string x)
    {
        if (x.size() == 0)
        {
            cout << "evaluation not possible\n";
        }
        else
        {
            bool check;
            for (int i = 0; i < x.size(); i++)
            {
                if (x[i] == '*' || x[i] == '/' || x[i] == '+' || x[i] == '-')
                {
                    check = check_greaterThan1();
                    if (check == true)
                    {
                        int operand2 = pop() - 0;
                        int operand1 = pop() - 0;
                        if (x[i] == '*')
                        {
                            push(static_cast<char>(operand1 * operand2));
                        }
                        else if (x[i] == '/')
                        {
                            push(static_cast<char>(operand1 / operand2));
                        }
                        else if (x[i] == '+')
                        {
                            push(static_cast<char>(operand1 + operand2));
                        }
                        else if (x[i] == '-')
                        {
                            push(static_cast<char>(operand1 - operand2));
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    push(x[i]);
                }
                display();
            }
            if (check == false)
            {
                cout << "evaluation not possible as the given postfix is not correct\n";
            }
            else if (top == 0)
            {
                cout << "the answer after evaluation is : " + pop() << endl;
            }
        }
    }
    bool check_greaterThan1()
    {
        return top >= 1;
    }
};
int main()
{

    string a;
    string b = "";
    int opt;
    stack *s1 = NULL;
    do
    {
        cout << "press 1 to convert to postfix\n2 to evaluate postfix expression\n";
        cin >> opt;
        switch (opt)
        {
        case 1:

            cout << "enter string to convert to prefix" << endl;
            cin >> a;
            s1 = new stack(a.size());
            // stack s1(a.size());

            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] == '(' || a[i] == ')' || a[i] == '/' || a[i] == '*' || a[i] == '+' || a[i] == '-')
                {
                    string ans = s1->postfix(a[i]);
                    b = b + ans;
                }
                else
                {
                    b = b + a[i];
                }
            }
            cout << s1->top << endl;
            if (s1->top > -1)
            {
                while (s1->top != -1)
                {
                    b = b + s1->pop();
                }
            }
            cout << "INFIX STRING : " << a << endl;
            cout << "POSTFIX STRING : " << b << endl;
            break;
        case 2:
            cout << "enter the string to evaluate postfix expression\n";
            cin >> a;
            s1 = new stack(a.size());
            s1->evaluation_of_postfix(a);
        }
    } while (opt != 0);
}