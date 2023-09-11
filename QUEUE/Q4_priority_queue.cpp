#include <iostream>
using namespace std;
class queue
{
public:
    int size;
    int front;
    int rear;
    int *age_array;
    queue(int x)
    {
        size = x;
        front = rear = -1;
        age_array = new int[size];
    }
    bool isFull()
    {
        return front == (rear + 1) % size;
    }
    bool isEmpty()
    {
        return (front == -1) && (rear == -1);
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "dequeue not possible as array is empty\n";
        }
        else
        {
            cout << "the following order is completed of the person of age : "
                 << age_array[front] << endl;
            if (front == rear)
            {

                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
        }
    }
    void enqueue()
    {
        if (isFull())
        {
            cout << "the queue is full\n";
        }
        else
        {
            int age;
            cout << "enter age of the customer\n";
            cin >> age;
            if (isEmpty())
            {
                front = rear = 0;
                age_array[front] = age;
            }
            else
            {
                if (age >= age_array[front])
                {
                    if (front == 0)
                    {
                        front = size - 1;
                        age_array[front] = age;
                    }
                    else
                    {
                        front--;
                        age_array[front] = age;
                    }
                }
                else if (age <= age_array[rear])
                {
                    rear = (rear + 1) % size;
                    age_array[rear] = age;
                }
                else
                {
                    int index = front;
                    while (index != rear)
                    {
                        if (age > age_array[index])
                        {
                            break;
                        }

                        index = (index + 1) % size;
                    }
                    cout << index << endl;
                    right_shift(index);
                    age_array[index] = age;
                }
            }
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
                cout << age_array[i] << " ";
                i = (i + 1) % size;
            }

            cout << age_array[rear] << endl;
            cout << front << endl;
            cout << rear << endl;
        }
    }
    void right_shift(int starting_point)
    {

        int ending = rear;
        while (ending != starting_point)
        {
            int move_by_one = (ending + 1) % size;
            age_array[move_by_one] = age_array[ending];
            if (ending == 0)
            {
                ending = size - 1;
            }
            else
            {
                ending--;
            }
        }
        age_array[(starting_point + 1) % size] = age_array[starting_point];
        rear = (rear + 1) % size;
    }
};
int main()
{
    int size, opt;
    cout << "enter size\n";
    cin >> size;
    queue q1(size);
    do
    {
        cout << "PRESS 0 TO EXIT\n1 TO ENQUEUE\n2 TO DEQUEUE\n3 TO DISPLAY\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            q1.enqueue();
            break;
        case 2:
            q1.dequeue();
            break;
        case 3:
            q1.display();
            break;
        }
    } while (opt != 0);
}