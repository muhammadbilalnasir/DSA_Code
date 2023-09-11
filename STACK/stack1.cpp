#include <iostream>
using namespace std;

class sta
{
public:
    int *S;
    int top, size;
    sta()
    {
        top = -1;
        size = 10;
        S = new int[size];
    }
    sta(int si)
    {
        top = -1;
        size = si;
        S = new int[size];
    }
    bool isFULL()
    {
        if (top == size - 1)
            return true;

        else
            return false;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void push(int ele)
    {
        if (isFULL())
        {
            cout << "STACK IS FULL\n";
        }
        else
        {
            S[++top] = ele;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "THE STACK IS EMPTY\n";
        }
        else
        {
            cout << "THE VALUE THAT THAT WAS DELETED IS : " << S[top--] << endl;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "THE STACK IS EMPTY\n";
        }
        else
        {
            cout << "\n";
            for (int i = top; i >= 0; i--)
            {
                cout << S[i] << endl;
            }
            cout << "\n";
        }
    }
};

int main()
{

    int size, opt;
    cout << "\nenter size for the  stack\n";
    cin >> size;
    sta s1(size);
    do
    {
        cout << "PRESS\n1 TO PUSH TO STACK\n";
        cout << "2 TO POP FROM STACK\n";
        cout << "3 TO DISPLAY STACK\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int element;
            cout << "ENTER THE VALUE YOU WANT TO ADD TO STACK\n";
            cin >> element;
            s1.push(element);
            break;

        case 2:
            s1.pop();
            break;
        case 3:
            s1.display();
            break;
        }
    } while (opt != 0);

    return 0;
}