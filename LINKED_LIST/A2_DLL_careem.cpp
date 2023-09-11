#include <iostream>
using namespace std;

struct Ride
{
    int ride_no;
    int km_of_ride;
    int amount;
    Ride *next = NULL;
    Ride *prev = NULL;
};

struct Captain
{
    int id;
    string name;
    Captain *next = NULL;
    Captain *prev = NULL;
    Ride *start = NULL;
};

Captain *starting = NULL;
Captain *ending = NULL;

Captain *creating_an_object();
void insert_at_end();
void insert_at_start();
void delete_from_start();
void delete_from_end();
void display();
void insert_after_a_specific_node();
void delete_a_specific_node();
Captain *return_address();
Ride *creating_an_ride_object();
void insert_rides();
void display_rides();
void delete_rides_of_captain();

int main()
{
    int opt;
    do
    {
        cout << "\nPRESS 0 TO EXIT THE PROGRAM\n";
        cout << "1 TO INSERT(CAPTAIN) AT START\n";
        cout << "2 TO INSERT(CAPTAIN) AT END\n";
        cout << "3 TO DELETE FROM START(CAPTAIN)\n";
        cout << "4 TO DELETE FROM END(CAPTAIN)\n";
        cout << "5 TO INSERT(CAPTAIN) AFTER A SPECIFIC NODE\n";
        cout << "6 TO DELETE A SPECIFIC NODE(CAPTAIN)\n";
        cout << "7 TO DISPLAY THE CAPTAIN\n";
        cout << "8 TO INSERT RIDES OF CAPTAIN\n";
        cout << "9 TO DISPLAY THE RIDE OF ANY CAPTAIN\n";
        cout << "10 TO DELETE THE RIDE OF ANY CAPTAIN\n";
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
            insert_after_a_specific_node();
            break;
        case 6:
            delete_a_specific_node();
            break;
        case 7:
            display();
            break;
        case 8:
            insert_rides();
            break;
        case 9:
            display_rides();
            break;
        case 10:
            delete_rides_of_captain();
            break;
        }
    } while (opt != 0);
    return 0;
}
Captain *creating_an_object()
{
    Captain *temp = new Captain;
    cout << "\nENTER ID , NAME OF THE CAPTAIN CAREEM\n";
    cin >> temp->id;
    cin >> temp->name;
    return temp;
}
void insert_at_end()
{
    Captain *current = creating_an_object();
    if (starting == NULL)
    {
        starting = ending = current;
    }
    else
    {
        ending->next = current;
        current->prev = ending;
        ending = current;
    }
}
void insert_at_start()
{
    Captain *current = creating_an_object();
    if (starting == NULL)
    {
        starting = ending = current;
    }
    else
    {
        current->next = starting;
        starting->prev = current;
        starting = current;
    }
}

void delete_from_start()
{
    if (starting == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY\n";
    }
    else
    {
        if (starting == ending)
        {
            delete starting;
            starting = ending = NULL;
        }
        else
        {
            starting = starting->next;
            delete starting->prev;
            starting->prev = NULL;
        }
    }
}

void delete_from_end()
{
    if (starting == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY\n";
    }
    else
    {
        if (starting == ending)
        {
            delete starting;
            starting = ending = NULL;
        }
        else
        {
            ending = ending->prev;
            delete ending->next;
            ending->next = NULL;
        }
    }
}

void display()
{
    if (starting == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY";
    }
    else
    {
        Captain *p = starting;
        while (p != NULL)
        {
            cout << "\n";
            cout << "THE ID OF THE CAPTAIN IS : " << p->id << endl;
            cout << "\t\t\tNAME : " << p->name << endl;
            p = p->next;
        }
    }
}

void insert_after_a_specific_node()
{
    int id;
    cout << "ENTER THE ID OF THE CAPTAIN" << endl;
    cin >> id;
    Captain *p = starting;
    while (p != NULL)
    {
        if (p->id == id)
        {
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "\t\t\tTHE FOLLOWING ID OF THE CAPTAIN DOES NOT EXIST\n";
    }
    else if (p == ending)
    {
        insert_at_end();
    }

    else
    {
        Captain *current = creating_an_object();
        current->next = p->next;
        current->prev = p;
        p->next = current;
        current->next->prev = current;
    }
}

void delete_a_specific_node()
{
    if (starting == NULL)
    {
        cout << "\t\t\tTHE LINKED LIST IS EMPTY\n";
    }
    else
    {
        int id;
        cout << "ENTER ID\n";
        cin >> id;
        Captain *p = starting;
        while (p != NULL)
        {
            if (p->id == id)
            {
                break;
            }
            p = p->next;
        }
        if (p == NULL)
        {
            cout << "\t\t\tTHE ID GIVEN DOES NOT EXIST\n";
        }
        else if (p == starting)
        {
            delete_from_start();
        }
        else if (p == ending)
        {
            delete_from_end();
        }
        else
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
        }
    }
}

Captain *return_address()
{

    int id;
    cout << "ENTER ID\n";
    cin >> id;
    Captain *p = starting;
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

Ride *creating_an_ride_object()
{
    cout << "ENTER RIDE NO, KM AND TOTAL AMOUNT OF THE TRIP\n";
    Ride *temp = new Ride;
    cin >> temp->ride_no;
    cin >> temp->km_of_ride;
    cin >> temp->amount;
    return temp;
}

void insert_rides()
{
    Captain *ptr = return_address();
    if (ptr == NULL)
    {
        cout << "\t\t\tTHE ID OF THE CAPTAIN DOES NOT EXIST\n";
    }
    else
    {
        // Ride *p = ptr->start;
        Ride *current = creating_an_ride_object();
        if (ptr->start == NULL)
        {
            ptr->start = current;
        }
        else
        {
            // while (p->next != NULL)
            // {
            //     p = p->next;
            // }
            // p->next = current;
            // current->prev = p;
            current->next = ptr->start;
            ptr->start->prev = current;
            ptr->start = current;
        }
    }
}

void display_rides()
{
    Captain *p = return_address();
    if (p == NULL)
    {
        cout << "\t\t\tTHE ID OF THE CAPTAIN DOES NOT EXIST\n";
    }
    else
    {
        cout << "\n\tCAPTAIN ID : " << p->id << endl;
        cout << "\n\tCAPTAIN NAME : " << p->name << endl;
        Ride *ptr = p->start;
        if (ptr == NULL)
        {
            cout << "\t\t\tTHE CAPTAIN DOES NOT HAVE ANY RIDES\n";
        }
        else
        {
            while (ptr != NULL)
            {
                cout << "\nTHE RIDE NUMBER IS : " << ptr->ride_no << endl;
                cout << "\t\tKM : " << ptr->km_of_ride << endl;
                cout << "\t\tTOTAL AMOUNT : " << ptr->amount << endl;
                ptr = ptr->next;
            }
            cout << "\n";
        }
    }
}

void delete_rides_of_captain()
{
    Captain *p = return_address();

    if (p == NULL)
    {
        cout << "\t\t\tTHE ID OF THE CAPTAIN DOES NOT EXIST\n";
    }
    else
    {
        Ride *ptr = p->start;
        if (ptr == NULL)
        {
            cout << "THE CAPTAIN HAS NO RIDES\n";
        }
        else
        {
            int ride_no;
            cout << "\t\t\tENTER RIDE NO TO BE DELETED\n";
            cin >> ride_no;

            while (ptr != NULL)
            {
                if (ptr->ride_no == ride_no)
                {
                    break;
                }
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {
                cout << "THE CAPTAIN " << p->name << " HAS NO RIDES OF THIS ID\n";
            }
            else if ((ptr == p->start) && (ptr->next == NULL))
            {
                cout << "CAPTAIN ID : " << p->id;
                cout << "CAPTAIN NAME : " << p->name << endl;
                cout << "\nTHE INFORMATION THAT WAS DELETED IS : \n";
                cout << "\t\tRIDE NO : " << ptr->ride_no << endl;
                cout << "\t\tKM : " << ptr->km_of_ride << endl;
                cout << "\t\tAMOUNT : " << ptr->amount << endl;
                ptr = NULL;
                p->start = ptr;
            }
            else if (ptr == p->start)
            {
                ptr = ptr->next;
                ptr->prev = NULL;
                delete p->start;
                p->start = ptr;
            }
            else if (ptr->next == NULL)
            {
                ptr->prev->next = NULL;
                delete ptr;
            }
            else
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                delete ptr;
            }
        }
    }
}