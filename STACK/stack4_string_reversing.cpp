#include <iostream>
using namespace std;
class stack
{
public:
    int top;
    int size;
    char *array;
    stack(int s)
    {
        top = -1;
        size = s;
        array = new char[size];
    }
    void push(char a)
    {
        array[++top] = a;
    }
    char pop()
    {
        return array[top--];
    }
};
int main()
{
    cout << "\nenter string" << endl;
    string insert;
    cin >> insert;
    int size;
    size = insert.size();
    stack s2(size);
    for (int i = 0; i < size; i++)
    {
        // char ch = insert[i];
        s2.push(insert[i]);
    }
    string reverse;
    reverse = "";
    for (int i = 0; i < size; i++)
    {
        // char ch = s2.pop();
        reverse = reverse + s2.pop();
    }
    cout << "\nbefore reversal : " << insert << endl;
    cout << "after reversal : " << reverse << endl;

    if (insert == reverse)
    {
        cout << "\npalindrome\n";
    }
    else
    {
        cout << "not palindrome\n";
    }

    return 0;
}