#include <iostream>
using namespace std;
void insert_at_start();
void insert_at_end();
void delete_from_start();
void delete_from_end();
void display();
void address_required_to_delete_from_end();
void insert_after_specific_node();
void delete_after_specific_node(int identifier);
void display_listinreverse();
void linked_list_reversal();

struct Student
{
    int id;
    string name;
    int age;
    Student *next;
};
Student *start = NULL;
Student *last = NULL;

int main()
{
    // struct Student stu;

    cout << "**************************************" << endl;
    cout << "*             LINKED LIST            *" << endl;
    cout << "**************************************" << endl;
    cout << "\n";
    int option;
    do
    {
        cout << "PRESS\n1 TO INSERT AT START\n";
        cout << "2 TO INSERT AT END\n";
        cout << "3 TO DELETE FROM START\n";
        cout << "4 TO DELETE FROM END\n";
        cout << "5 TO INSERT AFTER A SPECIFIC NODE\n";
        cout << "6 TO DELETE A SPECIFIC NODE\n";
        cout << "7 TO DISPLAY THE LIST\n";
        cout << "8 TO DISPLAY THE LIST IN REVERSE\n";
        cout << "9 TO REVERSE THE LIST\n";
        cin >> option;
        switch (option)
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
            int identifier;
            cout << "ENTER THE ID NUMBER : " << endl;
            cin >> identifier;
            delete_after_specific_node(identifier);
            break;
        case 7:
            display();
            break;
        case 8:
            display_listinreverse();
            break;
        case 9:
            linked_list_reversal();
            break;
        }
    } while (option != 0);

    return 0;
}

void insert_at_start()
{
    Student *current = new Student;
    cout << "ENTER ID, NAME AND AGE" << endl;
    cin >> current->id;
    cin >> current->name;
    cin >> current->age;
    if (start == NULL)
    {
        start = last = current;
    }
    else
    {
        current->next = start;
        start = current;
    }
}

void insert_at_end()
{

    Student *current = new Student;
    cout << "ENTER ID, NAME AND AGE" << endl;
    cin >> current->id;
    cin >> current->name;
    cin >> current->age;
    if (start == NULL)
    {
        start = current;
        last = current;
    }
    else
    {
        last->next = current;
        last = current;
        last->next = NULL;
    }
}

void delete_from_start()
{
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY" << endl;
    }
    else
    {
        if (start->next == NULL)
        {
            cout << "\t\t\tTHE INFORMATION THAT WAS DELETED FROM THE LINKED LIST IS AS FOLLOW" << endl;
            cout << "THE ID OF THE STUDENT IS : " << start->id << endl;
            cout << "\t\t\tNAME : " << start->name << endl;
            cout << "\t\t\tAGE : " << start->age << endl;
            start = last = NULL;
        }
        else
        {
            cout << "\t\t\tTHE INFORMATION THAT WAS DELETED FROM THE LINKED LIST IS AS FOLLOW" << endl;
            cout << "THE ID OF THE STUDENT IS : " << start->id << endl;
            cout << "\t\t\tNAME : " << start->name << endl;
            cout << "\t\t\tAGE : " << start->age << endl;
            start = start->next;
        }
    }
}

void delete_from_end()
{
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY" << endl;
    }
    else
    {
        if (start == last)
        {
            cout << "\t\t\tTHE INFORMATION THAT WAS DELETED FROM THE LINKED LIST IS AS FOLLOW" << endl;
            cout << "THE ID OF THE STUDENT IS : " << start->id << endl;
            cout << "\t\t\tNAME : " << start->name << endl;
            cout << "\t\t\tAGE : " << start->age << endl;
            start = last = NULL;
        }
        else
        {
            cout << "\t\t\tTHE INFORMATION THAT WAS DELETED FROM THE LINKED LIST IS AS FOLLOW" << endl;
            cout << "THE ID OF THE STUDENT IS : " << last->id << endl;
            cout << "\t\t\tNAME : " << last->name << endl;
            cout << "\t\t\tAGE : " << last->age << endl;
            address_required_to_delete_from_end();
        }
    }
}

void display()
{
    Student *ptr = start;
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
            cout << "\t\t\tTHE NAME OF THE STUDENT IS : " << ptr->name << endl;
            cout << "\t\t\tTHE AGE OF THE STUDENT IS : " << ptr->age << endl;
            ptr = ptr->next;
        }
        cout << "\n";
    }
}

void address_required_to_delete_from_end()
{
    Student *pointer = start;
    Student *address = NULL;
    while (pointer != last)
    {
        address = pointer;
        pointer = pointer->next;
    }
    cout << last << endl;
    address->next = NULL;
    last = address;
    cout << last << endl;
}

void delete_after_specific_node(int identifier)
{
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY" << endl;
    }
    else
    {
        Student *pointer = start;
        Student *address = NULL;
        if (identifier == start->id)
        {
            delete_from_start();
        }
        else if (identifier == last->id)
        {
            delete_from_end();
        }
        else
        {
            while ((pointer->next != NULL))
            {
                if (pointer->next == NULL)
                {
                    cout << "\t\t\tTHE ID WAS NOT FOUND" << endl;
                }
                else if (pointer->id == identifier)
                {
                    cout << "\t\t\tTHE INFORMATION THAT IS BEING DELETED IS : " << endl;
                    cout << "\t\t\tID : " << pointer->id << endl;
                    cout << "\t\t\tNAME : " << pointer->name << endl;
                    cout << "\t\t\tAGE : " << pointer->age << endl;
                    address->next = pointer->next;
                    break;
                }

                address = pointer;
                pointer = pointer->next;
            }
        }
    }
}

void insert_after_specific_node()
{
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY" << endl;
    }
    else
    {
        Student *current = new Student;
        int identifier;
        cout << "\t\t\tENTER THE ID AFTER WHICH U WANT TO INSERT THE NEW INFORMATION" << endl;
        cin >> identifier;
        Student *pointer = start;
        Student *address = start;
        if (identifier == last->id)
        {
            cout << "ENTER ID, NAME AND AGE" << endl;
            cin >> current->id;
            cin >> current->name;
            cin >> current->age;
            last->next = current;
            last = current;
        }
        else
        {
            while ((pointer->next != NULL))
            {

                if (pointer->id == identifier)
                {

                    cout << "ENTER ID, NAME AND AGE" << endl;
                    cin >> current->id;
                    cin >> current->name;
                    cin >> current->age;
                    cout << address << endl;
                    cout << pointer << endl;
                    current->next = pointer->next;
                    pointer->next = current;
                    cout << "end";
                    break;
                }

                pointer = pointer->next;
            }
        }
    }
}

void display_listinreverse()
{
    Student *ptr = start;
    Student *ptr2 = last;
    Student *address_ofsecondlast = NULL;

    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY\n";
    }
    else
    {
        if (start == last)
        {
            cout << "THE LINKED LIST HAS ONLY ONE NODE\n";
            cout << "THE ID OF THE STUDENT IS : " << start->id << endl;
            cout << "\t\t\tTHE NAME OF THE STUDENT IS : " << start->name << endl;
            cout << "\t\t\tTHE AGE OF THE STUDENT IS : " << start->age << endl;
            cout << "\n";
        }
        else
        {

            while (ptr2 != start)
            {
                if (ptr == ptr2)
                {
                    cout << "THE ID OF THE STUDENT IS : " << ptr2->id << endl;
                    cout << "\t\t\tTHE NAME OF THE STUDENT IS : " << ptr2->name << endl;
                    cout << "\t\t\tTHE AGE OF THE STUDENT IS : " << ptr2->age << endl;
                    cout << "\n";
                    ptr2 = address_ofsecondlast;
                    ptr = start;
                }
                address_ofsecondlast = ptr;
                ptr = ptr->next;
            }
            ptr = start;
            cout << "THE ID OF THE STUDENT IS : " << ptr->id << endl;
            cout << "\t\t\tTHE NAME OF THE STUDENT IS : " << ptr->name << endl;
            cout << "\t\t\tTHE AGE OF THE STUDENT IS : " << ptr->age << endl;
            cout << "\n";
        }
    }
}

void linked_list_reversal()
{
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY\n";
    }
    else
    {
        if (start == last)
        {
            cout << "\t\t\tTHE LINKED LIST HAS ONLY ONE NODE\n";
        }
        else
        {
            Student *ptr = start;
            Student *ptr2 = last;
            Student *address = NULL;
            while (ptr2 != start)
            {
                if (ptr == ptr2)
                {
                    ptr->next = address;
                    ptr2 = address;
                    ptr = start;
                }
                address = ptr;
                ptr = ptr->next;
            }
            start->next = NULL;
            start = last;
            last = ptr2;
        }
    }
}
