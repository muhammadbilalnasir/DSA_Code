// #include <iostream>
// using namespace std;
// int main()
// {
//     int x[4] = {3, 5, 9, 8};
//     int i;

//     for (int i = 0; i < 4; i++)
//     {
//         cout << "\n Address of value " << x[i] << " at index " << i << " is : " << &x[i] << endl;
//     }

//     cout << "\n Address of array x :" << x;
//     cout << "\n value at array index 0 is : " << *x;

//     cout << "\n Address of 1 index is " << &x[1];
//     cout << "\n value at array index 1 is : " << x[1];

//     cout << "\n Address of 2 index is " << &x[2];
//     cout << "\n value at array index 2 is : " << x[2];
// }

#include <iostream>
using namespace std;
int main()
{
    int x[4] = {25, 96, 28, 36};
    int *ptr = x;
    cout << *ptr << endl;
    (ptr)++;
    *ptr = 120;
    cout << *ptr << endl;
    (ptr)--;
    for (int i = 0; i < 4; i++)
    {
        cout << *ptr << endl;
        (ptr)++;
    }
    return 0;
}