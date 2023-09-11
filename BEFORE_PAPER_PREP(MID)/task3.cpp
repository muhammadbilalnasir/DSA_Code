#include <iostream>
using namespace std;
int array[10];
int start = -1;
int rear = -1;

bool isFULL()
{
    return (start == 0 && rear == 9);
}
bool isEmpty()
{
    return (start == -1 && rear == -1);
}
void right_shift(int start1, int rear1)
{
    for (int i = rear1; i >= start1; i--)
    {
        array[i + 1] = array[i];
    }
}
void left_shift(int star1, int rear1)
{
    for (int i = star1; i <= rear1; i++)
    {
        array[i - 1] = array[i];
    }
}
void insert_at_end()
{
    if (isFULL())
    {
        cout << "no space\n";
    }
    else
    {
        int value;
        cout << "enter value\n";
        cin >> value;
        if (isEmpty())
        {
            start = rear = 0;
            array[rear] = value;
        }
        else
        {
            if (rear < sizeof(array) - 1)
            {
                array[++rear] = value;
            }
            else
            {
                left_shift(start, rear);
                array[rear] = value;
                start--;
            }
        }
    }
}
void display()
{
    if (isEmpty())
    {
        cout << "is empty\n";
    }
    else
    {
        for (int i = start; i <= rear; i++)
        {
            cout << array[i] << " ";
        }
        cout << "\n";
    }
}
void delete_from_start()
{
    if (isEmpty())
    {
        cout << "is empty\n";
    }
    else
    {
        if (start == rear)
        {
            start = rear = -1;
        }
        else
        {
            start++;
        }
    }
}
void delete_from_end()
{
    if (isEmpty())
    {
        cout << "is empty\n";
    }
    else
    {
        if (start == rear)
        {
            start = rear = -1;
        }
        else
        {
            rear--;
        }
    }
}
void insert_at_start()
{
    if (isFULL())
    {
        cout << "no space\n";
    }
    else
    {
        int value;
        cout << "enter value\n";
        cin >> value;
        if (isEmpty())
        {
            start = rear = 0;
            array[start] = value;
        }
        else
        {
            if (start > 0)
            {
                array[--start] = value;
            }
            else
            {
                right_shift(start, rear);
                array[start] = value;
                rear++;
            }
        }
    }
}
int main()
{
    int opt;
    do
    {
        cout << "1 to insert at start\n2 to insert at end\n3 to delete from start\n4 to delete from end\n5 to display\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            insert_at_start();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            delete_from_start();
            break;
        case 4:
            delete_from_end();
            break;
        case 5:
            display();
            break;
        }
    } while (opt != 0);
}