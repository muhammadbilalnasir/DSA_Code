#include <bits/stdc++.h>

using namespace std;

class q
{
    queue<int> s1;

public:
    void push(int x)
    {
        s1.push(x);
    }
    void pop()
    {
        if (s1.empty())
        {
            cout << "empty\n";
        }
        else
        {
            int size = s1.size();
            for (int i = 1; i < size; i++)
            {
                s1.push(s1.front());
                s1.pop();
            }
            cout << "the element that is poped is" << s1.front() << endl;
            s1.pop();
        }
    }
};

int main()
{
    int opt;
    q q1;
    do
    {
        cout << "1 to push\n2 to pop\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int x;
            cout << "enter value\n";
            cin >> x;
            q1.push(x);
            break;
        case 2:
            q1.pop();
            break;
        }
    } while (opt != 0);
}