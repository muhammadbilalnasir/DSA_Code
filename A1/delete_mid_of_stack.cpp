#include <bits/stdc++.h>
using namespace std;

class stk
{
    stack<int> s1;

public:
    void push(int x)
    {
        s1.push(x);
    }
    void pop()
    {
        s1.pop();
    }
    int size_of_mid()
    {
        if (s1.size() % 2 == 0)
            return s1.size() / 2;
        else
            return (s1.size() / 2) + 1;
    }
    void delete_mid(int mid, int count)
    {
        if (count == mid)
        {
            cout << "the middle element being deleted is:" << s1.top();
            s1.pop();
            return;
        }
        else
        {
            int a = s1.top();
            s1.pop();
            count++;
            delete_mid(mid, count);
            s1.push(a);
        }
    }
    void display()
    {
        if (s1.empty())
        {
            return;
        }
        else
        {
            int a = s1.top();
            cout << a;
            s1.pop();
            display();
            s1.push(a);
        }
    }
    void delete_first_k_elements()
    {
        int k;
        cin >> k;
        int count = 0;
        int size = s1.size();
        reverse1(k, count, size);
    }
    void reverse1(int k, int count, int size)
    {
        if (k == count)
        {
            return;
        }
        else
        {
            int a = s1.top();
            s1.pop();
            count++;
            reverse1(k, count, size);
            cout << "the size of stack is : " << s1.size() << endl;
            reversingggg(a, s1.size(), size - k);
        }
    }
    void reversingggg(int x, int condition, int size)
    {
        // cout << condition << endl;
        if (size == condition)
        {
            cout << "A4\n";
            s1.push(x);
            return;
        }
        else
        {
            int a = s1.top();
            s1.pop();
            condition--;
            reversingggg(x, condition, size);
            s1.push(a);
        }
    }
};
int main()
{
    int opt;
    stk q1;
    do
    {
        cout << "1 to push\n2 to pop\n3 to delete mid\n4 to display\n";
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
        case 3:
            q1.delete_mid(q1.size_of_mid(), 1);
            break;
        case 4:
            q1.display();
            break;
        case 5:
            q1.delete_first_k_elements();
            break;
        }
    } while (opt != 0);
}