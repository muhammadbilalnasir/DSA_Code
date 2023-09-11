#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int *array;
    int *array2;
    int top;
    int top2;
    stack(int x)
    {
        size = x;
        array = new int[size];
        array2 = new int[size];
        top = top2 = -1;
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
    void set_second_array()
    {
        array2[++top2] = -1;
    }
    void push_second_array(int x)
    {
        array2[++top2] = x;
    }
    int pop_second_array()
    {
        return array2[top2--];
    }
    bool isEmpty2()
    {
        return top2 == -1;
    }
    void check_smallest_element()
    {
        if (isEmpty())
        {
            return;
        }
        else
        {
            int a = pop();
            tell_smallest_element(a, -1);
            check_smallest_element();
            push(a);
        }
    }
    void tell_smallest_element(int x, int smallest)
    {
        if (isEmpty2())
        {
            cout << "the smallest element next in row to " << x << " is " << smallest << endl;
            push_second_array(x);
            return;
        }
        else
        {
            if (array2[top2] < x && array2[top2] > smallest)
            {
                smallest = array2[top2];
            }
            int a = pop_second_array();
            tell_smallest_element(x, smallest);
            push_second_array(a);
        }
    }
};
int main()
{
    int opt;
    stack s1(10);
    do
    {
        cout << "1 to push\n2 to pop\n3 to display\n4 to tell about smallest element next to it in the stack\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int value;
            cout << "enter value\n";
            cin >> value;
            s1.push(value);
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            s1.display();
            break;
        case 4:
            s1.set_second_array();
            s1.check_smallest_element();
            break;
        }
    } while (opt != 0);
}