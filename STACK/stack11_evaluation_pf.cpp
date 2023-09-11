#include <iostream>
#include <string>
using namespace std;
class stack
{
public:
    int top;
    int *array;
    int size;
    stack(int x)
    {
        size = x;
        array = new int[size];
        top = -1;
    }

    void push(int x)
    {
        array[++top] = x;
    }
    int pop()
    {
        return array[top--];
    }
    bool is_empty()
    {
        return top == -1;
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << array[i] << " ";
        }

        cout << "\n";
    }

    void evaluation_of_postfix(string x)
    {
        if (x.size() == 0)
        {
            cout << "evaluation not possible\n";
        }
        else
        {
            bool check = true;
            for (int i = 0; i < x.size(); i++)
            {
                if (x[i] == '*' || x[i] == '/' || x[i] == '+' || x[i] == '-')
                {
                    check = check_greaterThan1();
                    if (check == true)
                    {
                        int operand2 = pop();
                        int operand1 = pop();
                        if (x[i] == '*')
                        {
                            push(operand1 * operand2);
                        }
                        else if (x[i] == '/')
                        {
                            push((operand1 / operand2));
                        }
                        else if (x[i] == '+')
                        {
                            push((operand1 + operand2));
                        }
                        else if (x[i] == '-')
                        {
                            push((operand1 - operand2));
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    int a = int(x[i] - '0');

                    if (a >= 0 && a <= 9)
                    {
                        push(a);
                    }
                    else
                    {
                        check = false;
                        break;
                    }
                }
                display();
            }
            if (check == false)
            {
                cout << "evaluation not possible as the given postfix is not correct\n";
            }
            else if (top == 0)
            {
                cout << "the answer after evaluation is : " << pop() << endl;
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

    do
    {
        cout << "press 1 to evaluate postfix expression\n";
        cin >> opt;
        switch (opt)
        {
        case 1:

            cout << "enter the string to evaluate postfix expression\n";
            cin >> a;
            stack s1(a.size());
            s1.evaluation_of_postfix(a);
        }
    } while (opt != 0);
}
