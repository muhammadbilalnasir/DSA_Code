
//                          redundant brackets
#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    char *array;
    int top;
    stack(int x)
    {
        size = x;
        array = new char[size];
        top = -1;
    }
    bool isFull()
    {
        return top == size - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(int x)
    {
        if (!isFull())
        {
            array[++top] = x;
        }
    }
    int pop()
    {
        if (!isEmpty())
        {
            return array[top--];
        }
    }
    void display()
    {
        if (!isEmpty())
        {
            for (int i = 0; i <= top; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }

    void redundant_brackets(string x)
    {
        bool check = true;
        int i = 0;
        for (int i = 0; i < size; i++)
        {
            if (x[i] == '(' || x[i] == '+' || x[i] == '-' || x[i] == '/' || x[i] == '*')
            {
                push(x[i]);
            }
            else
            {

                if (x[i] == ')')
                {
                    if (array[top] == '(')
                    {
                        cout << "A3\n";
                        check = false;
                        break;
                    }
                    else
                    {
                        cout << "else working\n";
                        while (array[top] != '(' || top == -1)
                        {
                            cout << "A4\n";
                            pop();
                        }
                        pop();
                        if (top < 0)
                        {
                            cout << "A5\n";
                            check = false;
                            break;
                        }
                    }
                }
            }
            display();
        }
        if (check == false)
        {
            cout << "redundant brackets\n";
        }
        else
            cout << "not redundant\n";
    }
};
int main()
{
    int opt;
    string x;
    cout << "enter the string\n";
    cin >> x;
    stack s1(x.size());
    s1.redundant_brackets(x);
}