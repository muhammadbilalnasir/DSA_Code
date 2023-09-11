#include <iostream>
using namespace std;
int main()
{
    int x = 2;
    int y = 4;

    int *xp = &x;
    cout << "the address of xp is : " << xp << endl;
    cout << "the value at the address " << xp << " is " << *xp << endl;

    int *yp = &y;
    cout << "the address of yp is : " << yp << endl;
    cout << "the value at the address " << yp << " is " << *yp << endl;

    *xp = 3;
    cout << "the new value at the address " << xp << " is : " << *xp << endl;

    xp = yp;
    cout << "the address at xp now is : " << xp << endl;
    cout << "the address at yp now is : " << yp << endl;

    cout << "the value of x is now : " << *xp << endl;
    (xp)--;
    (xp)--;

    cout << "the new address of x is : " << xp << endl;
    cout << *xp << endl;

    return 0;
}