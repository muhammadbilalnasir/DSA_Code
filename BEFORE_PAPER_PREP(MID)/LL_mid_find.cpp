#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next = NULL;
};
Node *head = NULL;
Node *tail = NULL;
void insert_at_end()
{
    Node *current = new Node;
    cout << "enter value\n";
    cin >> current->val;
    if (head == NULL)
    {
        head = tail = current;
    }
    else
    {
        tail->next = current;
        tail = current;
    }
}
void insert_at_start()
{
    Node *current = new Node;
    cout << "enter value\n";
    cin >> current->val;
    if (head == NULL)
    {
        head = tail = current;
    }
    else
    {
        current->next = head;
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
        Node *prv = NULL;
        Node *trans = head;
        while (trans != tail)
        {
            cout << "working\n";
            prv = trans;
            trans = trans->next;
        }
        if (trans == head)
        {
            delete trans;
            head = tail = NULL;
        }
        else
        {
            tail = prv;
            delete prv->next;
            prv->next = NULL;
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
        if (trans == tail)
        {
            delete trans;
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            delete trans;
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
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << "\n";
    }
}
int find_middle(Node *p, int count)
{
    if (p == NULL)
    {
        return count;
    }
    else
    {
        count = count + 1;
        p = p->next;
        find_middle(p, count);
    }
}
void print_middle_info()
{
    Node *p = head;
    int mid = find_middle(p, 0);
    int count = 1;
    cout << "bedore" << mid << endl;
    mid = mid / 2 + 1;
    cout << "after" << mid << endl;
    while (count != mid)
    {
        count++;
        p = p->next;
    }
    cout << "the value in the middle is : " << p->val << " " << endl;
}

void first_k_elements(Node *p, int count, int k)
{
    if (count == k)
    {
        return;
    }
    else
    {
        Node *prev = p;
        p = p->next;
        count++;
        first_k_elements(p, count, k);
        p->next = prev;
    }
}
void reverse()
{
    Node *p = head;
    int count = 1;
    int k;
    cin >> k;
    while (count != k)
    {
        count++;
        p = p->next;
    }
    if (p->next == NULL)
    {
        first_k_elements(head, 1, k);
        tail = head;
        head = p;
        tail->next = NULL;
    }
    else
    {
        Node *link_create = p->next;
        first_k_elements(head, 1, k);
        head->next = link_create;
        head = p;
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
            print_middle_info();
            break;
        case 7:
            reverse();
        }
    } while (opt != 0);

    return 0;
}
