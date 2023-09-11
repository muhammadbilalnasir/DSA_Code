#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct node
{
    string mountain_name;
    double height;
    string mountain_range;
    string country;
    node *next = NULL;
    node *prev = NULL;
};

node *head = NULL;
node *tail = NULL;

void addnode(string name, double h, string range, string country)
{
    node *current = new node;
    current->mountain_name = name;
    current->height = h;
    current->mountain_range = range;
    current->country = country;
    if (head == NULL)
    {
        head = tail = current;
    }
    else
    {
        tail->next = current;
        current->prev = tail;
        tail = current;
    }
}
void print()
{
    node *ptr = head;
    cout << "Mountain Name , Height, Mountain range, Country\n"
         << endl;
    if (head != NULL)
    {
        while (ptr != NULL)
        {

            cout << ptr->mountain_name << " , " << ptr->height << " metres"
                 << " , " << ptr->mountain_range << " , " << ptr->country << endl;
            cout << "\n";
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}
void found_mountain_by_contry()
{
    string name;
    bool check;
    cout << "enter name of the country\n";
    cin >> name;
    node *ptr = head;
    while (ptr != NULL)
    {

        if (ptr->country.find(name) != string::npos)
        {
            check = true;
            cout << ptr->mountain_name << " , " << ptr->height << " metres"
                 << " , " << ptr->mountain_range << " , " << ptr->country << endl;
            cout << "\n";
        }
        ptr = ptr->next;
    }
    if (!check)
    {
        cout << "this country mountains are not in the data set\n";
    }
}
void find_mountain_by_range()
{
    double range, low_range;
    cout << "enter the range betwwen which the mountains can be shown\n lower range\n";
    cin >> low_range;
    bool check;
    cout << "upper range\n";
    cin >> range;
    int total;
    node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->height < range && ptr->height > low_range)
        {
            check = true;
            cout << ptr->mountain_name << " , " << ptr->height << " metres"
                 << " , " << ptr->mountain_range << " , " << ptr->country << endl;
            cout << "\n";
            total++;
        }
        ptr = ptr->next;
    }

    if (!check)
    {
        cout << "no mountain in this range\n";
    }
    else
    {
        cout << "total mountains that are available in the dataset belonging to the country are:" << total << endl;
    }
}
void delete_mountains_of_specific_region()
{
    string name;
    bool check;
    cout << "enter name of the country\n";
    cin >> name;
    int total_deletes = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        node *p2 = head;
        while (p2 != NULL)
        {
            if (p2->country.find(name) != string::npos)
            {
                if (p2 == head)
                {
                    p2 = p2->next;
                    delete head;
                    head = p2;
                }
                else if (p2 == tail)
                {
                    p2 = p2->prev;
                    delete tail;
                    p2 = tail;
                }
                else
                {
                    node *to_delete = p2;
                    p2->prev->next = p2->next;
                    p2->next->prev = p2->prev;
                    delete to_delete;
                }
                total_deletes++;
                break;
            }
            p2 = p2->next;
        }
        p2 = head;
        ptr = ptr->next;
    }
    cout << "the total number of mountains deleted are : " << total_deletes << endl;
}
int main()
{
    // reading data from file
    ifstream fin;
    fin.open("mountains.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
    while (!fin.eof())
    {
        // reading data and adding to vector
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            lineData.push_back(word);
        }

        // type casting duration from string to int
        stringstream s2(lineData[1]);
        double height;
        s2 >> height;

        // type casting from string to int
        // stringstream s3(lineData[8]);
        // int year;
        // s3 >> year;

        // adding data to linked list
        if (lines != 0)
        {
            addnode(lineData[0], height, lineData[3], lineData[4]);
        }
        // clearing vector
        lineData.clear();
        lines++;
    }
    // switch to ask user what to do
    int choice = 0;
    do
    {
        cout << "\n 1.Print information about all the top mountains" << endl;
        cout << "2.Print information about mountains from a country" << endl;
        cout << "3.Print information about mountains having a specific range" << endl;
        cout << "4.Delete mountains from a specific country" << endl;
        cout << "Select an option and 0 to exit:";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            print();
            break;
        }
        case 2:
            found_mountain_by_contry();
            break;
        case 3:
            find_mountain_by_range();
            break;
        case 4:
            delete_mountains_of_specific_region();
            break;
        }
    } while (choice != 0);
    return 0;
}