#include <iostream>
#include <string>

using namespace std;

// Here we have created our own variable type that can store multiple values together

struct spaceship{
    int x;
    int y;
    string name;
};

int pass_by_value(spaceship myship){

    myship.x = 435;

    return 0;

}

int pass_by_ref(spaceship &myship){
    
    myship.x = 0;
    return 0;
}

int main(){

    // Here you declare the custom structure which is mandatory
    spaceship myship;

    myship.x = 234;
    myship.y = 34;
    myship.name = "Qaiser";

    // cout does not know how to handle custom structure so you have to specify the value of the individual members to cout
    // if you use the following line it will throw an error - cout << myship << endl;

    // You can also create an array and then store a structure in each array elements

    cout << myship.x << endl;

    // Passing structures into functions
    // You can pass structures using pass by value or pass by reference (using pointers)
    // Pass by value will make sure that any changes within the function will not affect the values in the original structure
    // Pass by reference will make sure that any changes wihtin the function will change the original structure

    pass_by_value(myship);

    cout << myship.x << " You can see that the changes have not reflected in the original structure " << endl;

    pass_by_ref(myship);

    cout << myship.x << " You can see that the changes have reflected here " << endl;

}