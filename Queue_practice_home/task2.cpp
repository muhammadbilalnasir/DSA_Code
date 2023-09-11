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

    void printing_neg_number(int start, int end)
    {
        if (end == (rear + 1) % size)
        {

            return;
        }
        else
        {
            bool check;
            for (int i = start; i <= end; i = (i + 1) % size)
            {
                if (array[i] < 0)
                {
                    cout << array[i] << " ";
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                cout << " 0 ";
            }
            start = (start + 1) % size;
            end = (end + 1) % size;
            printing_neg_number(start, end);
        }
    }
};

int main()
{
    queue q1(10);
    int opt;
    do
    {
        cout << "\n1 to enqueue\n2 to dequeue\n3 to display\n";
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
            int k;
            cout << "enter k\n";
            cin >> k;
            int end = (q1.front + k - 1) % 10;
            q1.printing_neg_number(q1.front, end);
        }
    } while (opt != 0);
}
