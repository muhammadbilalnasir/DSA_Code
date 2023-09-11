#include <iostream>
using namespace std;
class queue
{
public:
    int front;
    int rear;
    char *array;
    int size;
    queue(int x)
    {
        front = rear = -1;
        size = x;
        array = new char[size];
    }
    bool isFull()
    {
        return (rear + 1) % size == front;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    void enqueue(char x)
    {
        if (isFull())
        {
            cout << "is full\n";
        }
        else
        {
            if (isEmpty())
            {
                front = 0;
                rear = 0;
                array[rear] = x;
            }
            else
            {
                rear = (rear + 1) % size;
                array[rear] = x;
            }
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "is empty\n";
            return 0;
        }
        else
        {
            int a = array[front];
            if (front == rear)
            {

                front = rear = -1;
            }
            else
            {

                front = (front + 1) % size;
            }
            return a;
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
            for (int i = front; i <= rear; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
    void check_the_char()
    {
        string a;
        cout << "enter the string";
        cin >> a;
        bool check;
        for (int i = 0; i < a.size(); i++)
        {

            check = false;
            for (int j = 0; j <= rear; j++)
            {
                if (a[i] == array[j])
                {
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                cout << a[i] << " ";
                enqueue(a[i]);
            }
            else
            {
                cout << " # ";
            }
        }
    }
};

int main()
{
    queue q1(100);
    int opt;
    do
    {
        cout << "\n1 to enqueue\n2 to dequeue\n3 to display\n4 to check the string\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int x;
            cout << "enter value ";
            cin >> x;
            q1.enqueue(x);
            break;
        case 2:
            q1.dequeue();
            break;
        case 3:
            q1.display();
            break;
        case 4:
            q1.check_the_char();
            break;
        }
    } while (opt != 0);
}
