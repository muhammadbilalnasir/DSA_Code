#include <iostream>
using namespace std;
class queue
{
public:
    int front;
    int rear;
    int size;
    int *array;
    queue(int x)
    {
        size = x;
        rear = -1;
        front = -1;
        array = new int[size];
    }
    bool isFull()
    {
        return front == (rear + 1) % size;
    }
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }
    void enqueue_front(int value)
    {
        if (isFull())
        {
            cout << "no space available\n";
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
                array[front] = value;
            }
            else
            {
                if (front == 0)
                {
                    front = size - 1;
                    array[front] = value;
                }
                else
                {
                    array[--front] = value;
                }
            }
        }
    }
    void enqueue_rear(int value)
    {
        if (isFull())
        {
            cout << "no space available\n";
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
                array[rear] = value;
            }
            else
            {
                rear = (rear + 1) % size;
                array[rear] = value;
            }
        }
    }
    int dequeue_front()
    {
        if (isEmpty())
        {
            cout << "the queue is empty\n";
        }
        else
        {
            int a = array[front];
            if (front == rear)
            {
                cout << "this order was completed : " << array[front] << endl;
                front = rear = -1;
            }
            else
            {
                cout << "this order was completed : " << array[front] << endl;
                front = (front + 1) % size;
            }
            return a;
        }
    }
    int dequeue_back()
    {
        if (isEmpty())
        {
            cout << "the queue is empty\n";
        }
        else
        {
            int a = array[rear];
            if (front == rear)
            {
                cout << "this order was completed : " << array[front] << endl;
                front = rear = -1;
            }
            else
            {
                if (rear == 0)
                {
                    cout << "this order was completed  : " << array[rear] << endl;
                    rear = size - 1;
                }
                else
                {
                    cout << "this order was completed  : " << array[rear] << endl;
                    rear--;
                }
            }
            return a;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "the queue is empty\n";
        }
        else
        {
            int i = front;
            cout << "\n";
            while (i != rear)
            {
                cout << array[i] << " ";
                i = (i + 1) % size;
            }
            cout << array[rear] << endl;
        }
    }
    void reverse_elements(int count, int k)
    {
        if (count == k)
        {
            return;
        }
        else
        {
            int a = dequeue_front();
            count++;
            reverse_elements(count, k);
            enqueue_rear(a);
        }
    }
    void reverse_first_k_element()
    {
        int k;
        cout << "enter how many elements to be reversed\n";
        cin >> k;
        if (k > size)
        {
            cout << "not possible\n";
        }
        else
        {

            reverse_elements(0, k);
            cout << "loopworking\n";
            int i = (front + k) % size;
            int j = (rear + 1) % size;
            while (i != j)
            {
                enqueue_rear(dequeue_front());
                i = (i + 1) % size;
            }
        }
    }
};
int main()
{
    int opt;
    int size;
    cout << "enter size\n";
    cin >> size;
    queue q1(size);
    cout << "****************************\n";
    cout << "*   DOUBLE ENDED QUEUE     *\n";
    cout << "****************************\n";
    do
    {
        cout << "PRESS 0 TO EXIT\n1 TO ENQUEUE FROM FRONT\n2 TO ENQUEUE FROM BACK\n3 TO DEQUEUE FROM FRONT\n4 TO DEQUEUE FROM BACK\n5 TO DISPLAY QUEUE\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int value;
            cout << "enter value\n";
            cin >> value;
            q1.enqueue_front(value);
            break;
        case 2:
            cout << "enter value\n";
            cin >> value;
            q1.enqueue_rear(value);
            break;
        case 3:
            q1.dequeue_front();
            break;
        case 4:
            q1.dequeue_back();
            break;
        case 5:
            q1.display();
            break;
        case 6:
            q1.reverse_first_k_element();
            break;
        }
    } while (opt != 0);
}