#include <iostream>
using namespace std;
void increment(int *a);
int main()
{
    int x = 5;
    int *p = &x;
    increment(p);
    cout << x << endl;
}

void increment(int *a)
{
    (*a)++;
    cout << *a << endl;
}