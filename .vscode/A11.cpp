#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    Student *next = NULL;
};
Student *begining = NULL;
Student *ending = NULL;
Student *begining_2 = NULL;
Student *ending_2 = NULL;

void insert_at_start(Student *&start, Student *&last);
void insert_at_end(Student *&start, Student *&last);
void delete_from_start(Student *&start, Student *&last);
void delete_from_end(Student *&start, Student *&last);
void address_required_to_delete_from_end(Student *&start, Student *&last);
void display(Student *&start);
void merge_2_linked_List();
void sorting_the_list();

int main()
{
    int opt, opt2;
    do
    {
        cout << "PRESS\n1 FOR LINKED LIST 1\n";
        cout << "2 FOR LINKED LIST 2\n";
        cout << "3 TO MERGE THE LINKED LIST\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "PRESS 1 TO INSERT AT START OF LL 1\n";
            cout << "PRESS 2 TO INSERT AT END OF LL 1\n";
            cout << "PRESS 3 TO DELETE FROM START OF LL 1\n";
            cout << "PRESS 4 TO DELETE FROM END OF LL 1\n";
            cout << "PRESS 5 TO DISPLAY THE LIST\n";
            cout << "PRESS 6 TO SORT THE LIST\n";
            cin >> opt2;
            if (opt2 == 1)
            {
                insert_at_start(begining, ending);
            }
            else if (opt2 == 2)
            {
                insert_at_end(begining, ending);
            }
            else if (opt2 == 3)
            {
                delete_from_start(begining, ending);
            }
            else if (opt2 == 4)
            {
                delete_from_end(begining, ending);
            }
            else if (opt2 == 5)
            {
                display(begining);
            }
            else if (opt2 == 6)
            {
                sorting_the_list();
            }

            break;
        case 2:
            cout << "PRESS 1 TO INSERT AT START OF LL 2\n";
            cout << "PRESS 2 TO INSERT AT END OF LL 2\n";
            cout << "PRESS 3 TO DELETE FROM START OF LL 2\n";
            cout << "PRESS 4 TO DELETE FROM END OF LL 2\n";
            cout << "PRESS 5 TO DISPLAY THE LIST\n";
            cin >> opt2;
            if (opt2 == 1)
            {
                insert_at_start(begining_2, ending_2);
            }
            else if (opt2 == 2)
            {
                insert_at_end(begining_2, ending_2);
            }
            else if (opt2 == 3)
            {
                delete_from_start(begining_2, ending_2);
            }
            else if (opt2 == 4)
            {
                delete_from_end(begining_2, ending_2);
            }
            else if (opt2 == 5)
            {
                display(begining_2);
            }
            break;
        case 3:
            merge_2_linked_List();
            break;
        }
    } while (opt != 0);
}

void insert_at_start(Student *&start, Student *&last)
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

void insert_at_end(Student *&start, Student *&last)
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

void delete_from_start(Student *&start, Student *&last)
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
            cout << "THE ID OF THE STUDENT IS : " << start->id << endl;
            cout << "\t\t\tNAME : " << start->name << endl;
            cout << "\t\t\tAGE : " << start->age << endl;
            start = start->next;
        }
    }
}

void delete_from_end(Student *&start, Student *&last)
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
            address_required_to_delete_from_end(start, last);
        }
    }
}

void address_required_to_delete_from_end(Student *&start, Student *&last)
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

void display(Student *&start)
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
void merge_2_linked_List()
{
    if (begining == NULL || begining_2 == NULL)
    {
        cout << "MERGING NOT POSSIBLE AS ONE OF THE LINKED LIST IS EMPTY\n";
    }
    else
    {
        Student *address = NULL;

        while (begining_2 != ending_2)
        {
            Student *ptr = begining;
            while (ptr != NULL)
            {
                if (begining_2->id < ptr->id)
                {
                    cout << "\t\t\t\tworking2\n";
                    break;
                }
                address = ptr;
                ptr = ptr->next;
            }
            if (ptr == begining)
            {
                cout << "\t\t\t\tworking3\n";
                address = begining_2->next;
                begining_2->next = begining;
                begining = begining_2;
                begining_2 = address;
                cout << "\t\t\t\tworking3end\n";
            }
            else if (ptr == NULL)
            {
                cout << "\t\t\t\tworking4\n";
                address = begining_2->next;
                ending->next = begining_2;
                ending = begining_2;
                ending->next = NULL;
                begining_2 = address;
                cout << "\t\t\t\tworking4end\n";
            }
            else
            {
                cout << "\t\t\t\tworking5\n";
                address->next = begining_2;
                address = begining_2->next;
                begining_2->next = ptr;
                begining_2 = address;
                cout << "\t\t\t\tworking5end\n";
            }
            ptr = begining;
            address = NULL;
        }
        Student *ptr = begining;
        address = NULL;
        while (ptr != NULL)
        {
            if (begining_2->id < ptr->id)
            {
                break;
            }
            address = ptr;
            ptr = ptr->next;
        }
        if (ptr == begining)
        {
            cout << "\t\t\t\tworking3\n";
            address = begining_2->next;
            begining_2->next = begining;
            begining = begining_2;
            begining_2 = address;
            cout << "\t\t\t\tworking3end\n";
        }
        else if (ptr == NULL)
        {
            cout << "\t\t\t\tworking4\n";
            address = begining_2->next;
            ending->next = begining_2;
            ending = begining_2;
            ending->next = NULL;
            begining_2 = address;
            cout << "\t\t\t\tworking4end\n";
        }
        else
        {
            cout << "\t\t\t\tworking5\n";
            address->next = begining_2;
            address = begining_2->next;
            begining_2->next = ptr;
            begining_2 = address;
            cout << "\t\t\t\tworking5end\n";
        }
        begining_2 = NULL;
        ending_2 = NULL;
    }
}

void sorting_the_list()
{
    if (begining == NULL)
    {
        cout << "\t\t\tSORTING NOT POSSIBLE\n";
    }
    else
    {
        Student *start = NULL;
        Student *last = NULL;

        Student *prev_address = NULL;

        while (begining != ending->next)
        {
            Student *p = begining;
            Student *min_id = begining;
            Student *p3 = NULL;
            while (p != NULL)
            {
                if (min_id->id > p->id)
                {
                    prev_address = p3;
                    min_id = p;
                }
                p3 = p;
                p = p->next;
            }
            if (min_id == begining)
            {
                if (start == NULL)
                {
                    begining = begining->next;
                    start = last = min_id;
                    min_id->next = NULL;
                }
                else
                {
                    begining = begining->next;
                    last->next = min_id;
                    last = min_id;
                    min_id->next = NULL;
                }
            }
            else if (min_id == ending)
            {
                if (start == NULL)
                {
                    start = last = min_id;
                    min_id->next = NULL;
                    prev_address->next = NULL;
                    ending = prev_address;
                }
                else
                {
                    last->next = min_id;
                    min_id->next = NULL;
                    prev_address->next = NULL;
                    ending = prev_address;
                    last = min_id;
                }
            }
            else
            {
                if (start == NULL)
                {
                    prev_address->next = min_id->next;
                    start = last = min_id;
                    min_id->next = NULL;
                }
                else
                {
                    prev_address->next = min_id->next;
                    last->next = min_id;
                    min_id->next = NULL;
                    last = min_id;
                }
            }
        }

        begining = start;
        ending = last;
    }
}