#include <iostream>
using namespace std;
int si = -1;
int li = -1;
int arr[5];
int size = 5;
void insert_start(int number);
void insert_end(int number);
void delete_start();
void delete_end();
void display();
void right_shift();
void left_shift();

int main()
{
    int opt, number;
    do
    {
        cout << "\nENTER 1 TO INSERT AT START\n"
             << "2 TO INSERT AT END\n"
             << "3 TO DELETE FROM START\n"
             << "4 TO DELETE FROM END\n"
             << "5 TO DISPLAY\n"
             << "6 TO INSERT AFTER A SPECIFIC VALUE\n"
             << "7 TO DELETE A SPECIFIC VALUE\n"
             << "0 TO EXIT\n"
             << endl;
        cin >> opt;
        switch (opt)
        {

        case 1:
            cout << "enter the number\n";
            cin >> number;
            insert_start(number);
            break;
        case 2:
            cout << "enter the number\n";
            cin >> number;
            insert_end(number);
            break;
        case 3:
            delete_start();
            break;
        case 4:
            delete_end();
            break;

        case 5:
            display();
            break;
        }
    } while (opt != 0);
    return 0;
}

void display()
{
    cout << "si"
         << " = " << si << " ,";
    cout << "li"
         << " = " << li << endl;
    if (si == -1 && li == -1)
        cout << "\nTHE ARRAY IS EMPTY\n";
    else
    {
        for (int i = si; i <= li; i++)
        {
            cout << arr[i] << ",";
        }
        cout << "\n";
    }
}

void insert_start(int number)
{
    if (si == 0 && li == size - 1)
    {
        cout << "The array is full\n";
    }
    else
    {
        if (li == -1 && si == -1)
        {
            si = 0;
            li = 0;
            arr[li] = number;
        }
        else if (si > 0)
        {
            si--;
            arr[si] = number;
        }
        else if (si == 0)
        {
            right_shift();
            arr[si] = number;
        }
    }
}

void insert_end(int number)
{
    if (si == 0 && li == size - 1)
    {
        cout << "The array is full\n";
    }
    else
    {
        if (li == -1 && si == -1)
        {
            si = 0;
            li = 0;
            arr[li] = number;
        }
        else if (li < size)
        {
            li++;
            arr[li] = number;
        }
        else if (li == size - 1)
        {
            left_shift();
            li++;
            arr[li] = number;
        }
    }
}

void delete_start()
{
    if (si == -1 && li == -1)
    {
        cout << "THE ARRAY IS EMPTY" << endl;
    }
    else
    {
        cout << "the number that was deleted is : " << arr[si];
        if (si == 0 && li == 0)
        {
            si = li = -1;
        }
        else if (si >= 0)
        {
            si++;
        }
        else if (si == li)
        {
            si = li = -1;
        }
    }
}

void delete_end()
{
    if (si == -1 && li == -1)
    {
        cout << "THE ARRAY IS EMPTY" << endl;
    }
    else
    {
        cout << "the number that was deleted is : " << arr[li];
        if (si == 0 && li == 0)
        {
            si = li = -1;
        }
        else if (li >= 0)
        {
            li--;
        }
        else if (si == li)
        {
            si = li = -1;
        }
    }
}

void right_shift(int si, int li)
{

    for (int i = li; i >= si; i--)
    {
        arr[i + 1] = arr[i];
    }
    li++;
}

void left_shift(int si, int li)
{

    for (int i = si; i <= li; i++)
    {
        arr[i - 1] = arr[i];
    }
    li--;
}
