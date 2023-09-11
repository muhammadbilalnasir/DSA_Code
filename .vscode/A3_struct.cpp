#include <iostream>
using namespace std;

struct Student
{
    float CGPA;
    string name;
    string reg_no;
};

int main()
{
    int size = 3;
    Student s[3];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter cgpa, name , reg no in sequence" << endl;
        cin >> s[i].CGPA;
        cin >> s[i].name;
        cin >> s[i].reg_no;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "the students of the university are : " << endl;
        cout << s[i].CGPA << endl;
        cout << s[i].name << endl;
        cout << s[i].reg_no << endl;
    }

    return 0;
}