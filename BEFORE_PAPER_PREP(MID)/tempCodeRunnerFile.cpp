#include <iostream>
#include <stack>

using namespace std;

class q
{
public:
    stack<int> s1, s2;
    void enqueue(int x)
    {
        s1.push(x);
    }
    void dequeue()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        cout << "dequeuing the first element that was " << s2.top() << endl;
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void display()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        while (!s2.empty())
        {
            cout << s2.top() << " ";
            s1.push(s2.top());
            s2.pop();
        }
    }
};

int main()
{
    int opt;
    q q1;
    do
    {
        cout << "1 to enqueue\n2 to dequeue\3 to display\nUSING STACK\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int x;
            cout << "enter value\n";
            cin >> x;
            q1.enqueue(x);
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