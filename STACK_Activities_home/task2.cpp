
//                           INSERTING A ELEMENT IN THE START OF THE LIST
//                           DELETING FROM START OF STACK
//                           REVERSING THE STACK

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
    void insert_at_start(int x)
    {
        if (isEmpty())
        {
            push(x);
            return;
        }
        else
        {
            if (!isFull())
            {
                int a = pop();
                insert_at_start(x);
                push(a);
            }
        }
    }
    void delete_from_start()
    {
        if (top == 0)
        {
            pop();
        }
        else
        {
            if (!isEmpty())
            {
                int a = pop();
                delete_from_start();
                push(a);
            }
        }
    }
    void reverse_a_stack()
    {
        if (isEmpty())
        {
            return;
        }
        else
        {
            int a = pop();
            reverse_a_stack();
            insert_at_start(a);
        }
    }
    void sorting_a_stack()
    {
        if (isEmpty())
        {
            return;
        }
        else
        {
            int a = pop();
            sorting_a_stack();
            insert_in_sorted_order_by_babbar(a);
        }
    }

    // my code with iterative approach and for loop

    void insert_in_sorted_order(int x)
    {
        if (isEmpty())
        {
            push(x);
        }
        else
        {
            int i;
            int move = top;
            for (i = 0; i <= top; i++)
            {
                if (x < array[i])
                {
                    cout << "index of x is" << i << " x is" << x << endl;
                    break;
                }
            }
            for (int j = move; j >= i; j--)
            {
                array[j + 1] = array[j];
            }
            array[i] = x;
            top++;
        }
    }
    // recursive
    void insert_in_sorted_order_by_babbar(int x)
    {
        if (isEmpty() || x > array[top])
        {
            push(x);
            return;
        }
        else
        {

            int a = pop();
            insert_in_sorted_order_by_babbar(x);
            push(a);
        }
    }
};

int main()
{
    int size, opt;
    cout << "\nenter size for the  stack\n";
    cin >> size;
    stack s1(size);
    do
    {
        cout << "PRESS\n1 TO PUSH TO STACK\n";
        cout << "2 TO POP FROM STACK\n";
        cout << "3 TO DISPLAY STACK\n";
        cout << "4 TO INSERT AT START\n";
        cout << "5 TO DELETE FROM START\n";
        cout << "6 TO REVERSE THE STACK\n";
        cout << "7 TO SORT THE STACK\n";
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
        case 4:
            int x;
            cout << "enter value to insert at start\n";
            cin >> x;
            s1.insert_at_start(x);
            break;
        case 5:
            s1.delete_from_start();
            break;
        case 6:
            s1.reverse_a_stack();
            break;
        case 7:
            s1.sorting_a_stack();
            break;
        }
    } while (opt != 0);

    return 0;
}