#include <iostream>
using namespace std;
class node
{
public:
    int id;
    string name;
    node *next = NULL;
    void set(int a, string b)
    {
        name = b;
        id = a;
    }
};
class stack1
{
public:
    int top;
    node *start;
    stack1()
    {
        top = -1;
        start = NULL;
    }
    void push()
    {
        node *current = new node;
        cout << "enter name and id\n";
        int id;
        string name;
        cin >> name;
        cin >> id;
        current->set(id, name);
        if (start == NULL)
        {
            start = current;
        }
        else
        {
            current->next = start;
            start = current;
        }
    }
    void pop()
    {
        if (start == NULL)
        {
            cout << "the stack is empty\n";
        }
        else
        {

            cout << "the info that was deleted is : " << endl;
            cout << "\t\t" << start->id << endl;
            cout << "\t\t" << start->name << endl;
            start = start->next;
        }
    }
    void display()
    {
        if (start == NULL)
        {
            cout << "the stack is empty\n";
        }
        else
        {
            node *p = start;
            while (p != NULL)
            {
                cout << "\t\t" << p->id << endl;
                cout << "\t\t" << p->name << endl;
                p = p->next;
            }
        }
    }
};
int main()
{
    int opt;
    stack1 s1;
    do
    {
        cout << "PRESS 1 TO PUSH TO STACK\n";
        cout << "PRESS 2 TO POP FROM STACK\n";
        cout << "3 TO DISPLAY\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            s1.push();
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            s1.display();
            break;
        default:
            break;
        }
    } while (opt != 0);
}