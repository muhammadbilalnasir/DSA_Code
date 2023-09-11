#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next = NULL;
};
node *start = NULL;
node *last = NULL;

void insertion()
{
    node *current = new node;
    cout << "enter value\n";
    cin >> current->val;
    if (start == NULL)
    {
        start = last = current;
    }
    else
    {
        last->next = current;
        last = current;
    }
}
void display()
{

    node *p = start;
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
}
void deletion(int value, char criteria)
{

    node *p = start;
    if (criteria == 'L')
    {
        node *prev = NULL;
        while (p != NULL)
        {
            if (p->val <= value)
            {
                if (p == start)
                {
                    node *to_delete = p;
                    start = start->next;
                    p = start;
                    delete to_delete;
                }
                else if (p == last)
                {
                    last = prev;
                    delete last;
                }
                else
                {
                    node *to_delete = p;
                    prev->next = p->next;
                    p = p->next;
                    delete to_delete;
                }
            }
            else
            {
                prev = p;
                p = p->next;
            }
        }
    }
    else if (criteria == 'G')
    {
        node *prev = NULL;
        while (p != NULL)
        {
            if (p->val >= value)
            {
                if (p == start)
                {
                    node *to_delete = p;
                    start = start->next;
                    p = start;
                    delete to_delete;
                }
                else if (p == last)
                {
                    last = prev;
                    delete last;
                }
                else
                {
                    node *to_delete = p;
                    prev->next = p->next;
                    p = p->next;
                    delete to_delete;
                }
            }
            else
            {
                prev = p;
                p = p->next;
            }
        }
    }
}

int main()
{
    int opt;
    do
    {
        cout << "\n1 to insert at end\n2 to display\n3 to delete at a certain criteria\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            insertion();
            break;
        case 2:
            display();
            break;
        case 3:
            int value;
            char criteria;
            cout << "enter value and criteria\n";
            cin >> value;
            cin >> criteria;
            deletion(value, criteria);
            break;
        }
    } while (opt != 0);

    return 0;
};