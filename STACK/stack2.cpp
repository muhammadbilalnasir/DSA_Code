#include <iostream>
using namespace std;
class stak
{
public:
    int *arr;
    int size;
    int top1, top2;
    stak()
    {
        size = 10;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int ele)
    {
        top1++;
        if (top1 == top2 || top1 == size - 1)
        {
            cout << "STACK IS FULL \n";
            top1--;
        }
        else
        {
            arr[top1] = ele;
        }
    }
    void push2(int ele)
    {
        top2--;
        if (top1 == top2 || top2 == 0)
        {
            cout << "STACK IS FULL \n";
            top2++;
        }
        else
        {
            arr[top2] = ele;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "STACK 1 IS EMPTY\n";
            cout << top1 << endl;
        }
        else
        {
            cout << "THE VALUE THAT THAT WAS DELETED FROM STACK 1 IS : " << arr[top1--] << endl;
        }
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "STACK 2 IS EMPTY\n";
            cout << top2 << endl;
        }
        else
        {
            cout << "THE VALUE THAT THAT WAS DELETED FROM STACK 2 IS : " << arr[top2++] << endl;
        }
    }

    void display1()
    {
        if (top1 == -1)
        {
            cout << "STACK IS EMPTY\n";
        }
        else
            cout << "\n";
        {
            for (int i = top1; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
            cout << "\n";
        }
    }
    void display2()
    {
        if (top2 == size)
        {
            cout << "STACK IS EMPTY\n";
        }
        else
        {
            cout << "\n";
            for (int i = top2; i <= size - 1; i++)
            {
                cout << arr[i] << endl;
            }
            cout << "\n";
        }
    }
};

int main()
{
    int size, opt, ele;
    // cout << "\nenter size for the  stack\n";
    // cin >> size;
    stak stack1;
    do
    {
        cout << "PRESS\n1 TO PUSH TO STACK 1\n";
        cout << "2 TO POP FROM STACK 1\n";
        cout << "3 TO DISPLAY STACK 1\n";
        cout << "4 TO PUSH TO STACK 2\n";
        cout << "5 TO POP FROM STACK 2\n";
        cout << "6 TO DISPLAY STACK 2\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "ENTER THE VALUE YOU WANT TO ADD TO STACK 1\n";
            cin >> ele;
            stack1.push1(ele);
            break;

        case 2:
            stack1.pop1();
            break;
        case 3:
            stack1.display1();
            break;
        case 4:
            cout << "ENTER THE VALUE YOU WANT TO ADD TO STACK 2\n";
            cin >> ele;
            stack1.push2(ele);
            break;

        case 5:
            stack1.pop2();
            break;
        case 6:
            stack1.display2();
            break;
        }
    } while (opt != 0);
}