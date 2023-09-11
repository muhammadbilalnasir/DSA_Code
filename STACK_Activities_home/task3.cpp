#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int *array;
    int top;
    stack(int x)
    {
        size = x;
        array = new int[size];
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
    void insert_in_a_sorted_order(int x)
    {
        if (isFull())
        {
            cout << "no more space available in stack\n";
        }
        else
        {
            if (isEmpty() || x > array[top])
            {
                push(x);
                return;
            }
            else
            {
                int a = pop();
                insert_in_a_sorted_order(x);
                push(a);
            }
        }
    }
};
int main()
{
    int opt;
    stack s1(10);
    do
    {
        cout << "1 to insert to stack in sorted order\n2 to pop\n3 to display\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int value;
            cout << "enter value\n";
            cin >> value;
            s1.insert_in_a_sorted_order(value);
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            s1.display();
            break;
        }
    } while (opt != 0);
}