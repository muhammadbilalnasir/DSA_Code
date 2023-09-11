#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next = NULL;
};
Node *start = NULL;
Node *start2 = NULL;
void insert_at_end(Node *&head)
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
void insert_at_start(Node *&head)
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
void delete_from_end(Node *&head)
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
void delete_from_start(Node *&head)
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
void display(Node *&head)
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

void sorting_the_list(Node *&head)
{
    Node *head2 = NULL;
    while (head->next != head)
    {
        Node *highest_value = head;
        Node *trans = head;
        while (trans->next != head)
        {
            trans = trans->next;
        }
        Node *prev = trans;
        Node *prev_address = trans;
        trans = head;
        while (trans->next != head)
        {
            if (highest_value->val < trans->val)
            {
                prev_address = prev;
                highest_value = trans;
            }
            prev = trans;
            trans = trans->next;
        }
        if (highest_value == head)
        {
            prev_address->next = head->next;
            head = prev_address->next;
        }
        else
        {
            prev_address->next = highest_value->next;
        }
        if (head2 == NULL)
        {
            head2 = highest_value;
            head2->next = highest_value;
        }
        else
        {
            Node *p = head2;
            while (p->next != head2)
            {
                p = p->next;
            }
            highest_value->next = p->next;
            p->next = highest_value;
        }
    }
    Node *prev = NULL;
    Node *p = head2;
    Node *last_head = NULL;
    while (p->next != head2)
    {
        p = p->next;
    }
    last_head = p;
    p = head2;
    while (p->next != head2)
    {
        if (head->val > p->val)
        {
            break;
        }
        prev = p;
        p = p->next;
    }
    if (p == head2)
    {
        head->next = p->next;
        last_head->next = head;
        head2 = head;
    }
    else
    {
        head->next = p;
        prev->next = head;
    }

    head = head2;
}
int main()
{
    int opt;
    do
    {
        cout << "******************************\n";
        cout << "PRESS 0 TO EXIT THE PROGRAM\n";
        cout << "1 TO INSERT AT START OF LL1\n";
        cout << "2 TO INSERT AT END OF LL1\n";
        cout << "3 TO DELETE FROM START OF LL1\n";
        cout << "4 TO DELETE FROM END OF LL1\n";
        cout << "5 TO DISPLAY OF LL1\n";
        cout << "6 TO INSERT AT START OF LL2\n";
        cout << "7 TO INSERT AT END OF LL2\n";
        cout << "8 TO DELETE FROM START OF LL2\n";
        cout << "9 TO DELETE FROM END OF LL2\n";
        cout << "10 TO DISPLAY OF LL2\n";
        cout << "11 TO SORT LL1\n";
        cout << "12 TO SORT LL2\n";
        cout << "******************************\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            insert_at_start(start);
            break;
        case 2:
            insert_at_end(start);
            break;
        case 3:
            delete_from_start(start);
            break;
        case 4:
            delete_from_end(start);
            break;
        case 5:
            display(start);
            break;
        case 6:
            insert_at_start(start2);
            break;
        case 7:
            insert_at_end(start2);
            break;
        case 8:
            delete_from_start(start2);
            break;
        case 9:
            delete_from_end(start2);
            break;
        case 10:
            display(start2);
            break;
        case 11:
            sorting_the_list(start);
            break;
        case 12:
            sorting_the_list(start2);
            break;
        }
    } while (opt != 0);

    return 0;
}