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
void swapping_of_nodes();
void delete_duplicate_node();

struct Student
{
    int id;
    string name;
    int age;
    Student *next = NULL;
};
Student *start = NULL;
Student *last = NULL;

void reverse_recursive(Student *p);

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
        cout << "10 TO SWAP ANY 2 NODES \n";
        cout << "11 TO REVERSE BY RECURSION\n";
        cout << "12 TO DELETE DUPLICATE NODES\n";

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
        case 10:
            swapping_of_nodes();
            break;
        // case 11:
        //     Student *p = start;
        //     reverse_recursive(p);
        //     if (start != NULL)
        //     {
        //         start = last;
        //         last = p;
        //         last->next = NULL;
        //     }
        //     break;
        case 12:
            delete_duplicate_node();
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
            while ((pointer != NULL))
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
            while ((pointer != NULL))
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

void swapping_of_nodes()
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
            int id1, id2;
            cout << "ENTER THE ID OF THE STUDENT\n";
            cin >> id1;
            cout << "ENTER THE ID WITH WHICH YOU WANT TO SWAP\n";
            cin >> id2;
            Student *ptr = start;
            Student *ptr2 = NULL;
            Student *add_of_prevfirst = NULL;
            Student *add_of_first = NULL;
            Student *add_of_prevsecond = NULL;
            Student *add_of_second = NULL;
            while (ptr != NULL)
            {
                if (ptr->id == id1)
                {
                    add_of_prevfirst = ptr2;
                    add_of_first = ptr;
                    break;
                }

                ptr2 = ptr;
                ptr = ptr->next;
            }
            ptr = start;
            ptr2 = NULL;
            while (ptr != NULL)
            {
                if (ptr->id == id2)
                {
                    add_of_prevsecond = ptr2;
                    add_of_second = ptr;
                    break;
                }
                ptr2 = ptr;
                ptr = ptr->next;
            }
            if (add_of_first == NULL || add_of_second == NULL)
            {
                cout << "\t\t\tSWAPPING NOT POSSIBLE AS ID GIVEN IS NOT MATCHING\n";
            }
            else if (add_of_first == add_of_second)
            {
                cout << "\t\t\tSWAPPING NOT POSSIBLE AS BOTH THE ID'S GIVEN BELONG TO THE SAME NODE\n";
            }

            else
            {
                if ((add_of_first == start) && (add_of_second == last))
                {
                    cout << "1 TAB EXECUTED\n";
                    add_of_second->next = add_of_first->next;
                    add_of_prevsecond->next = add_of_first;
                    add_of_first->next = NULL;
                    start = add_of_second;
                    last = add_of_first;
                }
                //
                else if ((add_of_first == last) && (add_of_second == start))
                {
                    cout << "2 TAB EXECUTED\n";
                    add_of_first->next = add_of_second->next;
                    add_of_prevfirst->next = add_of_second;
                    add_of_second->next = NULL;
                    start = add_of_first;
                    last = add_of_second;
                }

                // first with second
                else if ((add_of_prevfirst == NULL) && (add_of_first == add_of_prevsecond) && (add_of_first == start))
                {
                    cout << "3 TAB EXECUTED\n";
                    add_of_first->next = add_of_second->next;
                    add_of_second->next = add_of_first;
                    start = add_of_second;
                }
                // first with any other except last
                else if ((add_of_first == start))
                {
                    cout << "4 TAB EXECUTED\n";
                    ptr = add_of_first->next;
                    add_of_prevsecond->next = add_of_first;
                    add_of_first->next = add_of_second->next;
                    add_of_second->next = ptr;
                    start = add_of_second;
                }
                // 2 node considered as first(consecutive)
                else if ((add_of_second == start) && (add_of_second == add_of_prevfirst))
                {
                    cout << "5 TAB EXECUTED\n";
                    add_of_second->next = add_of_first->next;
                    add_of_first->next = add_of_second;
                    start = add_of_first;
                }
                // 2 node considered as first(with any node except last)
                else if (add_of_second == start)
                {
                    cout << "6 TAB EXECUTED\n";
                    ptr = add_of_first->next;
                    add_of_prevfirst->next = add_of_second;
                    add_of_first->next = add_of_second->next;
                    add_of_second->next = ptr;
                    start = add_of_first;
                }
                // last node with the previous
                else if ((add_of_first == last) && (add_of_prevfirst == add_of_second))
                {
                    cout << "7 TAB EXECUTED\n";
                    add_of_prevsecond->next = add_of_first;
                    add_of_first->next = add_of_second;
                    add_of_second->next = NULL;
                    last = add_of_second;
                }
                // last node with any node(except first)
                else if (add_of_first == last)
                {
                    cout << "8 TAB EXECUTED\n";
                    add_of_prevsecond->next = add_of_first;
                    add_of_first->next = add_of_second->next;
                    add_of_prevfirst->next = add_of_second;
                    add_of_second->next = NULL;
                    last = add_of_second;
                }
                // reverse (address of second = last ) orde r(consective)
                else if ((add_of_second == last) && (add_of_first == add_of_prevsecond))
                {
                    cout << "9 TAB EXECUTED\n";
                    add_of_prevfirst->next = add_of_second;
                    add_of_second->next = add_of_first;
                    add_of_first->next = NULL;
                    last = add_of_first;
                }
                // reverse order(in between)
                else if (add_of_second == last)
                {
                    cout << "10 TAB EXECUTED\n";
                    add_of_prevfirst->next = add_of_second;
                    add_of_second->next = add_of_first->next;
                    add_of_prevsecond->next = add_of_first;
                    add_of_first->next = NULL;
                    last = add_of_first;
                }

                // two consecutive value(in order)
                else if (add_of_first == add_of_prevsecond)
                {
                    cout << "11 TAB EXECUTED\n";
                    ptr = add_of_second->next;
                    add_of_prevfirst->next = add_of_second;
                    add_of_second->next = add_of_first;
                    add_of_first->next = ptr;
                }
                // two consecutive value(in reverse order)
                else if (add_of_second == add_of_prevfirst)
                {
                    cout << "12 TAB EXECUTED\n";
                    ptr = add_of_first->next;
                    add_of_prevsecond->next = add_of_first;
                    add_of_first->next = add_of_second;
                    add_of_second->next = ptr;
                }
                // in between (the first and last node except consecutive)
                else
                {
                    cout << "13 TAB EXECUTED\n";
                    ptr = add_of_first->next;
                    ptr2 = add_of_second->next;

                    add_of_prevfirst->next = add_of_second;
                    add_of_second->next = ptr;
                    add_of_prevsecond->next = add_of_first;
                    add_of_first->next = ptr2;
                }
            }
        }
    }
}

void reverse_recursive(Student *p)
{
    if (start == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY\n";
    }
    else
    {

        if (p == last)
        {
            return;
        }
        else
        {
            Student *x = p;
            p = p->next;
            reverse_recursive(p);
            p->next = x;
        }
    }
}
void delete_duplicate_node()
{
    Student *temp = start;
    int count = 1;
    while (temp != NULL)
    {
        Student *prev_address = temp;
        Student *temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->id == temp2->id)
            {
                if (temp2 == last)
                {
                    cout << "last working ";
                    cout << prev_address->id << " + " << prev_address->age << endl;
                    cout << "count is : " << count << endl;
                    last = prev_address;
                    last->next = NULL;
                    delete temp2;
                }
                else
                {
                    cout << "delete from middle working ";
                    cout << prev_address->id << " + " << prev_address->age << endl;
                    cout << "count is : " << count << endl;
                    prev_address->next = temp2->next;
                    delete temp2;
                }
            }
            prev_address = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
        count++;
    }
}