#include <iostream>
#include <string>

using namespace std;

int main(){

    // expermenting with switch case

    int user_no = 3;

    // remember that case term requires integer numbers

    switch (user_no)
    {
        case 1:
            cout << "user number is 1" << endl;
            break;

        case 2:
            cout << "user number is 2" << endl;
            break;

        case 3:
            cout << "user number is 3" << endl;
            break;

        default:
            cout << "Error, no case statements executed";

    }

}