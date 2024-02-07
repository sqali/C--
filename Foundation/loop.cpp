#include <iostream>

using namespace std;

// three types of loops - while, for, do-while

int main(){

    int i = 1;
    int counter = 0;

    while (i == 1){
        cout << "the value of is still one" << endl;

        if (counter == 5){
            i = 56;
        }
        else{
            counter = counter + 1;
        }
    }

    // while loop to print numbers till 10

    i = 1;

    while (i < 11){
        cout << i << endl;
        i++;
    }

    // for loop syntax to print numbers till 10

    for (i = 1; i<=10; i++)
    {
        cout << i << endl;
    }

    // similar to python you can use break for breaking out of loops in c++
    // To skip a single iteration you can use continue same as python

}