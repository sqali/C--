#include <iostream>
#include <string>

using namespace std;

int passing_1d_array(int array[])
{
    // For a single dimensional array you do not need to specify the size of the array while receiving it in a function, just use the above syntax
    // unlike changes made to variables within a function that do not affect the original variables
    // changes made to arrays are reflected in the original arrays in C++
    // If you pass the array by values then the original arrays will not be affected unlike pass by reference or pointer where it affects
    // the original array
    /*In C++, arrays cannot be passed by value directly to functions.
      When you try to pass an array by value, it decays into a pointer to its first element, effectively becoming a pointer.
    */
   array[3] = 89;

   return 0;

}

int passing_2d_array(int array_2D[][2])
{
    // if you pass in a multi-dimensional array, you need to give every size except the first
    return 0;
}

int main(){
    int array[5]; // this will create an array of size 5 not 6 and the index will be from 0 to 4

    // declaring 2D arrays
    int array_2D[2][2]; // array of size 4

    // taking input for the multi-dimensional array

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter each number of the matrix";
            cin >> array_2D[i][j];
        }
    }

    // printing the 2D array

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << array_2D[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i <= 4; i++)
    {
        array[i] = i;
    }

    // to print the elements of the array you need to use the loop
    for (int i = 0; i <= 4 ; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n";

    // cout not does not print the array in C++ instead it prints the memory address of the first element of the array
    cout << array << endl;

    // To iterate over each character of a string

    string my_name = "Qaiser";

    for (int i = 0; i < my_name.length(); i++)
    {
        cout << my_name[i] << " ";
    }

    cout << endl;

    // Operations on string

    // Unlike python or Java, strings are mutable in C++

    for (int i = 0; i < my_name.length(); i++)
    {
        if (i == 3)
        {
            my_name[i] = 'd';

            // This will only work if you use the single quotations in 'd' not "d" because
            // since you are assigning a single character and not string to it
        }

    }

    cout << my_name << endl;

    passing_1d_array(array);

    for (int i = 0; i <= 4 ; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
    cout << "You can see that the changes in the 1D array have reflected" << endl;

    passing_2d_array(array_2D);

}