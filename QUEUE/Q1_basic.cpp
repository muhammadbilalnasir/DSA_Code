#include <iostream>
using namespace std;
class queue
{
public:
    int size;
    int *array;
    int top;
    queue(int x)
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
    void leftShift()
    {
        for (int i = 1; i <= top; i++)
        {
            array[i - 1] = array[i];
        }
        top--;
    }
    void enqueue()
    {
        if (isFull())
        {
            cout << "NO SPACE AVAILABLE FOR ENQUEUE\n";
        }
        else
        {
            int a;
            cout << "enter int to enter to the queue\n";
            cin >> a;
            array[++top] = a;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "QUEUE IS EMPTY\n";
        }
        else
        {
            if (top == 0)
            {
                cout << "THE FOLLOWING IS DEQUEUED : " << array[top--] << endl;
            }
            else
            {
                cout << "THE FOLLOWING IS DEQUEUED : " << array[0] << endl;
                leftShift();
            }
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "THE QUEUE IS EMPTY\n";
        }
        else
        {
            cout << " THE FOLLOWING ARE PRESENT IN THE QUEUE : ";
            for (int i = 0; i <= top; i++)
            {
                cout << array[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int size, opt;
    cout << "\nENTER SIZE FOR THE QUEUE\n";
    cin >> size;
    queue q1(size);
    do
    {
        cout << "\nPRESS 0 TO EXIT\n1 TO ENQUEUE TO QUEUE\n2 TO DEQUEUE FROM QUEUE\n3 TO DISPLAY THE QUEUE\n";
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