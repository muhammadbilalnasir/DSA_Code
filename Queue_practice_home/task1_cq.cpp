#include <iostream>
using namespace std;
class queue
{
public:
    int front;
    int rear;
    int *array;
    int size;
    queue(int x)
    {
        front = rear = -1;
        size = x;
        array = new int[size];
    }
    bool isFull()
    {
        return (rear + 1) % size == front;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    void enqueue(int x)
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
    void reverse_queue()
    {
        if (isEmpty())
        {
            return;
        }
        else
        {
            int a = dequeue();
            reverse_queue();
            enqueue(a);
        }
    }
    void check_negative_in_queue()
    {
        int front_of_array = array[front];
        int a = array[front];
        int b = array[front + 1];
        while (b != front_of_array)
        {
            checking(a, b);
            enqueue(dequeue());
            a = array[front];
            b = array[(front + 1) % size];
        }
        enqueue(dequeue());
    }
    void checking(int a, int b)
    {
        if (a < 0)
        {
            cout << a << " ";
        }
        else if (a > 0 && b < 0)
        {
            cout << b << " ";
        }
        else
            cout << "0 ";
    }
};
int main()
{
    queue q1(10);
    int opt;
    do
    {
        cout << "\n1 to enqueue\n2 to dequeue\n3 to display\n4 to reverse the queue\n";
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
            q1.reverse_queue();
            break;
        case 5:
            q1.check_negative_in_queue();
            break;
        }
    } while (opt != 0);
}