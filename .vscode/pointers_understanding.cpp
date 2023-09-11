#include <iostream>
using namespace std;
int main()
{
    char a = 'c';
    string b = "hello world";
    string *ptr = &b;
    cout << "the size of the string b is : " << sizeof(b) << endl;
    cout << "the address of the string b is : " << ptr << endl;
    cout << "the size of the pointer of string b is : " << sizeof(ptr) << endl;
    cout << "the address of char is : " << (void *)&a << endl;
}