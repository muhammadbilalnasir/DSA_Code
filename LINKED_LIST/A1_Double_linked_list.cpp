#include <iostream>
using namespace std;

struct Stu
{
    int id;
    string name;
    Stu *next = NULL;
    Stu *prev = NULL;
};

Stu *start = NULL;
Stu *last = NULL;

Stu *create_new_object();
void insert_at_start();
void insert_at_end();
void delete_from_start();
void delete_from_end();
void display();
Stu *address_required(int id);
void insert_after_specific_node();
void delete_a_specific_node();
void display_in_reverse();

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
        cout << "5 TO INSERT AFTER A SPECIFI NODE\n";
        cout << "6 TO DELETE A SPECIFIC NODE\n";
        cout << "7 TO DISPLAY\n";
        cout << "8 TO DISPLAY IN REVERSE\n";
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
            insert_after_specific_node();
            break;
        case 6:
            delete_a_specific_node();
            break;
        case 7:
            display();
            break;
        case 8:
            display_in_reverse();
            break;
        }
    } while (opt != 0);

    return 0;
}

Stu *create_new_object()
{
    Stu *temp = new Stu;
    cout << "\nENTER ID, NAME\n";
    cin >> temp->id;
    cin >> temp->name;
    return temp;
}

void insert_at_start()
{
    Stu *current = create_new_object();
    if (start == NULL)
    {
        start = last = current;
    }
    else
    {
        current->next = start;
        start->prev = current;
        start = current;
    }
}

void insert_at_end()
{
    Stu *current = create_new_object();
    if (start == NULL)
    {
        start = last = current;
    }
    else
    {
        last->next = current;
        current->prev = last;
        last = current;
    }
}

void delete_from_start()
{
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY\n";
    }
    else
    {
        if (start == last)
        {
            delete start;
            start = last = NULL;
        }
        else
        {
            start = start->next;
            delete start->prev;
            start->prev = NULL;
        }
    }
}

void delete_from_end()
{
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY\n";
    }
    else
    {
        if (start == last)
        {
            delete start;
            start = last = NULL;
        }
        else
        {
            last = last->prev;
            delete last->next;
            last->next = NULL;
        }
    }
}
void display()
{
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY\n";
    }
    else
    {
        Stu *p = start;
        while (p != NULL)
        {
            cout << "\n";
            cout << "THE ID OS THE STUDENT IS : " << p->id << endl;
            cout << "\t\tNAME : " << p->name << endl;
            p = p->next;
        }
        cout << "\n";
    }
}

Stu *address_required(int id)
{
    Stu *p = start;
    while (p != NULL)
    {
        if (p->id == id)
        {
            break;
        }
        p = p->next;
    }
    return p;
}

void insert_after_specific_node()
{
    int id;
    cout << "ENTER THE ID NUMBER\n";
    cin >> id;
    Stu *ptr = address_required(id);
    if (ptr == NULL)
    {
        cout << "\t\t\tTHE ID ENTERED DOES NOT EXISTS\n";
    }
    else
    {
        if (ptr == last)
        {
            insert_at_end();
        }
        else
        {
            Stu *current = create_new_object();
            current->next = ptr->next;
            current->prev = ptr;
            ptr->next = current;
            current->next->prev = current;
        }
    }
}

void delete_a_specific_node()
{
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY\n";
    }
    else
    {
        int id;
        cout << "ENTER ID" << endl;
        cin >> id;
        Stu *p = address_required(id);
        if (p == start)
        {
            delete_from_start();
        }
        else if (p == last)
        {
            delete_from_end();
        }
        else
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
    }
}

void display_in_reverse()
{
    Stu *p = last;
    while (p != NULL)
    {
        cout << "\n";
        cout << "THE ID OS THE STUDENT IS : " << p->id << endl;
        cout << "\t\tNAME : " << p->name << endl;
        p = p->prev;
    }
    cout << "\n";
}