#include <iostream>
#include <stack>
using namespace std;

void insert_at_end(stack<int> &input)
{
    if (input.size() == 0)
    {
        int no;
        cout << "enter number\n";
        cin >> no;
        input.push(no);
        cout << "the increase or  not ? " << input.size() << endl;
        return;
    }
    else
    {
        int number = input.top();
        input.pop();
        insert_at_end(input);
        input.push(number);
        cout << "after return size : " << input.size() << endl;
    }
}
void display(stack<int> &input)
{
    if (input.size() == 0)
    {
        return;
    }
    else
    {
        int ni;
        ni = input.top();
        cout << ni << endl;
        input.pop();
        display(input);
        input.push(ni);
    }
}

int main()
{
    stack<int> input;
    int opt;
    do
    {
        cout << "1 to push\n2 to pop\n3 to insert at end\n4 to display\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int no;
            cout << "enter number\n";
            cin >> no;
            input.push(no);
            break;
        case 2:
            input.pop();
            break;
        case 3:
            cout << "the size before : " << input.size() << endl;
            insert_at_end(input);
            cout << "the size after : " << input.size() << endl;
            break;
        case 4:
            cout << "the size during display : " << input.size() << endl;
            display(input);
            break;
        }

    } while (opt != 0);
}
