#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string name;
    int age;
    int reg_no;
};

int main()
{
    Student s[3];
    for (int i = 0; i < 3; i++)
    {
        cout << " ENTER NAME, AGE, CGPA OF " << i + 1 << " STUDENT RESPECTIVELY" << endl;
        getline(cin >> ws, s[i].name);
        cin >> s[i].age;
        cin >> s[i].reg_no;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << s[i].name << " ";
        cout << +s[i].age << " ";
        cout << s[i].reg_no << " ";
        cout << "\n";
    }
}