//                   delete repeating occuring elements

#include <iostream>
using namespace std;
struct node
{
    int val;
    node *next = NULL;
    node *prev = NULL;
};
node *head = NULL;
void insertion()
{
    node *current = new node;
    cout << "enter value\n";
    cin >> current->val;
    if (head == NULL)
    {
        head = current;
    }
    else
    {
        node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = current;
        current->prev = p;
    }
}
void display()
{
    node *p = head;
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
}

void delete_after_end(int value, int position)
{
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    node *tail = p;
    int count = 0;
    while (tail != NULL)
    {
        if (tail->val == value)
        {
            count++;
        }
        if (count == position)
        {
            break;
        }
        tail = tail->prev;
    }
    tail->next->prev = tail->prev;
    tail->prev->next = tail->next;
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
            int pos;
            cout << "enter value and pos from back\n";
            cin >> value;
            cin >> pos;
            delete_after_end(value, pos);
            break;
        }
    } while (opt != 0);
}