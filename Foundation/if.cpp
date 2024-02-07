#include <iostream>

using namespace std;

int main(){

    int user_input;

    // you can also use bool data type to store true of false values as you can see below

    bool check_value = true;

    if (check_value){
        cout << "This statement will always be executed as the value of check_value is True" << endl;
    }

    cout << "Enter a number" << endl;
    cin >> user_input;

    if (1){
        cout << "This part of code will always execute" << endl;
    }

    if (0){
        // This part of code will never be executed
    }

    if (user_input == 15){

        // true or false can also be used here for checking the conditionality of the statements
        cout << "This part wil only execute if the user input is 15" << endl;
    }

    if (user_input > 10){
        cout << "True" << endl;
    }
    else if (user_input > 5){
        cout << "user_input is greater than 5" << endl;
    }
    else{
        cout << "The user input is not greater than 10" << endl;
    }

    // to check multiple conditions at once you can use && operator

    if (2 > 0 && 2 > 1){
        cout << "Multiple conditions are true" << endl;
    }

    // to check if one of the conditions are true you can use the || operator

    if (2 < 0 || 2 < 5){
        cout << "One of the conditions are true" << endl;
   }

   // you can also use != to check for not equals to
   /*

   In table form, the precedence order for Boolean operators and comparison operators is
    !
    ==, <, >, <=, =>, !=
    &&
    ||
    
   */

}