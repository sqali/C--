#include <iostream>
#include <string>
// To use the string data type you will have to use string header file in it as it is not implicitly built in the compiler

using namespace std;

// You need to define variables in advance to use them

int new_number;
int a,b,c,d; // you can also define multiple variables in the same line
char letter;
double number_with_decimals;
string username;

int main(){

    // taking input from a user

    int second_number;
    string my_new_name;
    username = "Qaiser";
    cout << username << "\n";

    // You can append two strings together using the + sign similar to python

    username = username + " is a good boy";
    cout << username << endl;

    // If the user enters a float type number for a integer type variable it will be truncated
    // If you use a variable without assigning it a value it will use a random value instead

    cout << "Enter a new number: ";
    cin >> second_number;

    cout << second_number << endl;
    new_number = 10;
    cout << new_number << endl;

    // Implementing getline function, it will take input of string till the character has been specified
    // e.g if we use , then it will take input till the ',', if space then till space if enter then \n

    cout << "Enter my_new_name: " << endl;
    getline(cin, my_new_name, ',');
    cout << my_new_name << endl;
    
    return 0;
}