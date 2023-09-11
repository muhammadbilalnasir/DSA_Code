//            REMOVING DUPLICATES IN A LINKED LIST

#include <iostream>
using namespace std;
struct node
{
    int id;
    node *next = NULL;
};

node *start = NULL;
node *last = NULL;

void delete_duplicate_node()
{
    node *temp = start;
    while (temp != NULL)
    {
        node *prev_address = temp;
        node *temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->id == temp2->id)
            {
                if (temp2 == last)
                {
                    cout << "last working\n";
                    last = prev_address;
                    last->next = NULL;
                    delete temp2;
                }
                else
                {
                    cout << "middle working\n";
                    prev_address->next = temp2->next;
                    delete temp2;
                }
            }
            prev_address = temp2;
            temp2 = temp2->next;
        }
        cout << "temp moving\n";
        temp = temp->next;
    }
}
void insert_at_end()
{
    node *current = new node;
    cout << "ENTER ID" << endl;
    cin >> current->id;

    if (start == NULL)
    {
        start = current;
        last = current;
    }
    else
    {
        last->next = current;
        last = current;
    }
}
void display()
{
    node *ptr = start;
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << "\n";
            cout << "THE ID OF THE STUDENT IS : " << ptr->id << endl;
            ptr = ptr->next;
        }
        cout << "\n";
    }
}
int main()
{
    cout << "**************************************" << endl;
    cout << "*             LINKED LIST            *" << endl;
    cout << "**************************************" << endl;
    cout << "\n";
    int option;
    do
    {
        cout << "PRESS\n1 TO INSERT\n";

        cout << "2 TO DISPLAY THE LIST\n";

        cout << "3 TO DELETE DUPLICATE NODES\n";

        cin >> option;
        switch (option)
        {

        case 1:
            insert_at_end();
            break;
        case 2:
            display();
            break;
        case 3:
            delete_duplicate_node();
            break;
        }

    } while (option != 0);
}
