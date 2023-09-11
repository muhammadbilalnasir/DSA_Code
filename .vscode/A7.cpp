#include <iostream>
using namespace std;
struct ab
{
    int x;
    string c;
};
int main()
{
    int x;
    cout << "Enter" << endl;
    cin >> x;
    ab myobj;
    ab obj2;
    cout << "Enter for object 2" << endl;
    cin >> obj2.c;
    cout << obj2.c << endl;
    cout << "Enter fro object1" << endl;
    cin >> myobj.c;
    cout << myobj.c << endl;
    ab *ptr = new ab;
    cout << ptr << endl;

    return 0;
}