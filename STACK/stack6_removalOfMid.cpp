#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;
    int opt;
    do
    {
        cout << "1 to push\n2 to pop\n3 to peek\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int no;
            cout << "enter number\n";
            cin >> no;
            st.push(no);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            cout << st.size() << endl;
            int a = st.top();
            cout << a << endl;
            break;
        }
    } while (opt != 0);
}