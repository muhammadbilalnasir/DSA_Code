#include <iostream>
using namespace std;
struct stu
{
    int id;
    string name;
    string reg_no;
    stu *next = NULL;
};

stu *start = NULL;
stu *last = NULL;

void insert_sorted_order();
stu *creating_object();
void display();

int main()
{
    int opt;
    do
    {
        cout << "\nPRESS 1 TO INSERT TO LL IN SORTED ORDER\n";
        cout << "PRESS 2 TO DISPLAY\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            insert_sorted_order();
            break;
        case 2:
            display();
            break;
        }
    } while (opt != 0);

    return 0;
}
void insert_sorted_order()
{
    stu *current = creating_object();
    if (start == NULL)
    {
        start = last = current;
    }
    else
    {
        stu *p = start;
        stu *prev_address = NULL;
        while (p != NULL)
        {
            if (current->id < p->id)
            {
                break;
            }
            prev_address = p;
            p = p->next;
        }
        if (p == start)
        {
            current->next = start;
            start = current;
        }
        else if (p == NULL)
        {
            last->next = current;
            last = current;
        }
        else
        {
            current->next = prev_address->next;
            prev_address->next = current;
        }
    }
}

stu *creating_object()
{
    stu *temp = new stu;
    cout << "ENTER ID AND NAME AND REG NO : \n";
    cin >> temp->id;
    cin >> temp->name;
    cin >> temp->reg_no;
    return temp;
}

void display()
{
    if (start == NULL)
    {
        cout << "THE LINKED LIST IS EMPTY\n";
    }
    else
    {
        stu *ptr = start;
        while (ptr != NULL)
        {
            cout << "\t\tID : " << ptr->id << endl;
            cout << "\t\tNAME: " << ptr->name << endl;
            cout << "\t\tREEG NO: " << ptr->reg_no << endl;
            ptr = ptr->next;
        }
    }
}