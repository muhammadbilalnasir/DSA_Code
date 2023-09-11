#include <iostream>
using namespace std;
void cheecking_greater_on_right_side(int *array, int value)
{
    // finding value if present in array
    bool check = false;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (array[i] == value)
        {
            check = true;
            break;
        }
    }
    if (check == true)
    {
        int index_of_high;
        bool check2;
        for (int j = i; j < 5; j++)
        {
            if (array[j] > array[i])
            {
                i = j;
                check2 = true;
            }
        }
        if (check2 == true)
        {
            cout << "the greatest value after value " << value << " in the array is " << array[i] << endl;
        }
        else
        {
            cout << "after this value no greater value exist\n";
        }
    }
}
void find_greatest_in_array_after_each_value(int *array)
{
    for (int i = 0; i < 5; i++)
    {
        bool check = false;
        int j;
        for (j = i + 1; j < 5; j++)
        {

            if (array[j] > array[i])
            {
                check = true;
                break;
            }
        }
        if (check == true)
        {
            cout << array[j] << " ";
        }
        else
        {
            cout << "-1 ";
        }
    }
}
int main()
{
    int array[5] = {13, 7, 6, 12, 11};
    cheecking_greater_on_right_side(array, 5);
    find_greatest_in_array_after_each_value(array);
}