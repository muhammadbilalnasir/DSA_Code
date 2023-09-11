#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next = NULL;
};

Node *head = NULL;
void insert_at_end()
{
    Node *current = new Node;
    cout << "enter value\n";
    cin >> current->val;
    if (head == NULL)
    {
        head = current;
        head->next = current;
    }
    else
    {
        Node *trans = head;
        while (trans->next != head)
        {
            trans = trans->next;
        }
        current->next = trans->next;
        trans->next = current;
    }
}
void insert_at_start()
{
    Node *current = new Node;
    cout << "enter value\n";
    cin >> current->val;
    if (head == NULL)
    {
        head = current;
        head->next = current;
    }
    else
    {
        Node *trans = head;
        while (trans->next != head)
        {
            trans = trans->next;
        }
        current->next = head;
        trans->next = current;
        head = current;
    }
}
void delete_from_end()
{
    if (head == NULL)
    {
        cout << "already empty\n";
    }
    else
    {
        Node *prev = NULL;
        Node *trans = head;
        while (trans->next != head)
        {
            prev = trans;
            trans = trans->next;
        }
        if (trans == head)
        {
            delete trans;
            head = NULL;
        }
        else
        {
            prev->next = head;
            delete trans;
        }
    }
}
void delete_from_start()
{
    if (head == NULL)
    {
        cout << "already empty\n";
    }
    else
    {
        Node *trans = head;
        while (trans->next != head)
        {
            trans = trans->next;
        }
        if (trans == head)
        {
            delete trans;
            head = NULL;
        }
        else
        {
            trans->next = head->next;
            delete head;
            head = trans->next;
        }
    }
}
void display()
{
    if (head == NULL)
    {
        cout << "already empty\n";
    }
    else
    {
        Node *p = head;
        while (p->next != head)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << p->val << endl;
        cout << "\n";
    }
}
void finding_if_circular_or_not()
{
    Node *p = head;
    while (p->next != head && p->next != NULL)
    {
        p = p->next;
    }
    if (p->next == head)
    {
        cout << "circular\n";
    }
    else
    {
        cout << "not circular\n";
    }
}
int main()
{
    int opt;
    do
    {
        cout << "PRESS 0 TO EXIT THE PROGRAM\n";
        cout << "1 TO INSERT AT START\n";
        cout << "2 TO INSERT AT END\n";
        cout << "3 TO DELETE FROM START\n";
        cout << "4 TO DELETE FROM END\n";
        cout << "5 TO DISPLAY\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            insert_at_start();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            delete_from_start();
            break;
        case 4:
            delete_from_end();
            break;
        case 5:
            display();
            break;
        case 6:
            finding_if_circular_or_not();
            break;
        }
    } while (opt != 0);

    return 0;
}