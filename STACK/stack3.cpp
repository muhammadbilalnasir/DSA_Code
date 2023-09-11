#include <iostream>
#include <string>
using namespace std;
class linked_list
{
public:
    char insert;
    linked_list *next;
};
linked_list *start = NULL;
class stack
{
public:
    int top;
    stack()
    {
        top = -1;
    }
    void push(char a)
    {
        linked_list *current = new linked_list;
        current->insert = a;
        if (start == NULL)
        {
            start = current;
            top++;
        }
        else
        {
            current->next = start;
            start = current;
            top++;
        }
    }
    bool pop()
    {
        bool true_not = true;
        if (top == -1)
        {
            top--;
            true_not = false;
        }
        else if (top == 0)
        {
            delete start;
            start = NULL;
            top--;
        }
        else
        {
            start = start->next;
            top--;
        }
        return true_not;
    }
};
int main()
{
    stack s1;
    string a;
    cout << "enter the string with braces \"{\" for push and \"}\" to pop" << endl;
    cin >> a;
    for (int i = 0; i < a.size(); i++)
    {
        char b = a[i];
        if (b == '{')

        {
            s1.push(b);
        }
        else if (b == '}')
        {
            bool a = s1.pop();
            if (a == false)
            {
                break;
            }
        }
    }
    cout << s1.top << endl;
    if (s1.top == -1)
    {
        cout << "equal" << endl;
    }
    else if (s1.top >= 0)
    {
        cout << "not equal\n";
    }
    else
    {
        cout << "poping not possible as stack is empty\n";
    }

    return 0;
}