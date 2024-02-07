// iostream is an include statement that tells the compiler to put code from the header file called iostream into our program before creating
// the executable, this header file comes with your compiler and allows you to perform input and output, using #include takes everything
// from the header file and pastes it into your program, by including these you gain access to many functions provided by the compiler

#include <iostream>

// Tells the compiler that the this is a function called main that returns an intger

using namespace std;

void name_calling()
{
    cout << "This is a function that prints my name - Qaiser and returns nothing\n";
}

void multiple_names()
{
    cout << "This is a function that prints my name - Qaiser2 and returns nothing\n";
    cout << "This is a function that prints my name - Qaiser3 and returns nothing\n";
    cout << "This is a function that prints my name - Qaiser4 and returns nothing\n";
}

int main()
{
    // count (C out object is present in the iostream header file that will display the text provided to it)
    // << is the insertion operators to indicate what to output
    // cout << results in a function call with text as an argument to the function
    // cout << "Hi, I am qaiser" << endl is basically the equivalent of \n
    cout << "Hey, I am alive!!\n";
    name_calling();
    multiple_names();
}