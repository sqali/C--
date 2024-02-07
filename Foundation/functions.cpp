#include <iostream>

using namespace std;

int add (int x, int y)
{
    return x + y;
}

int main(){

    int x,y;
    x = 10;
    y = 23;

    cout << add(x, y) << endl;

    int sum_of_values = add(x, y);
    cout << sum_of_values << endl;

    // In C++ you have the option of function overloading, you can use the same name for multiple functions as long as their arguments vary
    // The scope of variables is restricted to the particular function
    // Global variables are defined before main function and can be used widely
    // You can declare a function before defining it and can later define and use it

}