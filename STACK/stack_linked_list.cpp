#include <iostream>
using namespace std;

class sta
{
public:
    sta *start = NULL;
    int id;
    string name;
    int top = -1;
    sta *next;
    sta(string n, int i, sta *&ptr)
    {
        name = n;
        id = i;
        next = NULL;
        start = ptr;
    }
    void push(sta *&p)
    {
        if (start == NULL)
        {
            start = p;
        }
        else
        {
            p->next = start;
            start = p;
            top++;
        }
    }
    void pop()
    {
        if (start == NULL)
        {
            cout << "THE STACK IS EMPTY\n";
        }
        else
        {
            cout << "THE INFO THAT WAS DELETED IS : " << endl;
            cout << "\t\t" << start->id << endl;
            cout << "\t\t" << start->name << endl;
            start = start->next;
            top--;
        }
    }
    void display()
    {
        if (start == NULL)
        {
            cout << "STACK IS EMPTY\n";
        }
        else
        {
            sta *p = start;
            while (p != NULL)
            {
                cout << p->name << endl;
                cout << p->id << endl;
            }
        }
    }
};

sta *starting = NULL;

int main()
{
    int opt;
    int id;
    string name;
    do
    {
        cout << "PRESS 1 TO PUSH TO STACK\n";
        cout << "PRESS 2 TO POP FROM STACK\n";
        cout << "3 TO DISPLAY\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cin >> id;
            cin >> name;
            sta *current = new sta(name, id, starting);
            current->push(current);
            break;
        case 2:
            starting->pop();
            break;
        case 3:
            starting->display();
            break;
        default:
            break;
        }
    } while (opt != 0);

    return 0;
}