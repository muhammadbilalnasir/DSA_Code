#include <iostream>
using namespace std;
int main()
{
    int x = 0;
    int y = 10;
    while (x != y)
    {
        if (x == 5)
        {
            break;
        }
        cout << " hello";
        x++;
    }
    cout << endl;
    cout << "the value of x is " << x;
}