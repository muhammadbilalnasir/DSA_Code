#include <iostream>
using namespace std;
void update(int *p);
void getSum(int arr[], int n);
int main()
{
    // int x = 5;
    // cout << x << endl;
    // (&) operator represents the memoray address
    // cout << "the  address of 7 operator is : " << &x << endl;

    // int *p = &x;
    // cout<<p<<endl;
    // cout<<*p;
    // (*p)++;
    // cout << *p << endl;
    // (*p) = (*p) * 2;
    // cout << *p;

    // int *q = p;
    // cout << "the second pointer is : " << *q << endl;
    // cout << "the address of the second pointer is : " << q << endl;
    // *q = *q + 1;
    // cout << *q << endl;

    // int a = 56;
    // int *ptr = &a;
    // cout << *ptr << endl;
    // cout << "the address of pointer is : " << ptr << endl;
    // ptr = ptr + 1;
    // cout << "the address of pointer is after increment : " << ptr << endl;
    // cout << *ptr;

    int arr[5] = {1, 5, 8, 6, 2};
    int *ptr = arr;
    cout << "the address of 0 index is : " << ptr << endl;
    cout << "the address of 1 index is : " << (ptr + 1) << endl;
    cout << "the value at 1 index is : " << *(ptr + 1) << endl;
    cout << 2 [arr] << endl;

    char arr1[5] = {'a', 'b', 'c', 'd'};
    cout << arr1 << endl;

    char arr2[6] = "abcde";
    char *ptr1 = &arr1[0];
    cout << arr2 << endl;
    cout << ptr1 << endl;
    cout << *ptr1;

    int value = 420;
    int *pointer = &value;
    cout << "value before: " << *pointer << endl;
    update(pointer);
    cout << "value after : " << *pointer << endl;

    int array[5] = {2, 4, 6, 8, 10};
    getSum(array + 2, 3);
}

void update(int *p)
{
    (*p)++;
}

void getSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    cout << sum << endl;
}