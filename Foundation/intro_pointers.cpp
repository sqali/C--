#include <iostream>
#include <string>

using namespace std;

void reference()
{
  int a = 10;
  int &b = a; 

  // Initializing a reference is mandatory just declaring it and not initializing it will cause error, you can instead put the initialization as NULL
  // This is a reference to the integer z, unlike pointers it cannot be changed once assigned a value
  // It means b is a reference of a, just an alias
  // b is like an alternate variable to use

  cout << b << " - Checking if this is equal - " << a << endl;

  // If you change the value of a then the value of b will still point to the latest value of a (memory address)

  a = 15;

  cout << b << " - still equals to - " << a << endl;

  // If you want to change the value of b then it will also reflect for a

  b = 15;

  cout << b << " - still equals to - " << a << endl;

}

int pointer_array()
{

  int array[4] = {1,2,3,4};

  // You can notice below that we have not used the & operator to give the memory address to the pointer as C++ knows that this is the pointer to the 
  // memory address of the first element in the array and the subsequent elements to it

  int *p_pointer_to_array = array;

  cout << p_pointer_to_array << " -> This is the memory address of the array" << endl;

  // You can also iterate over the array if you have pointer to it as the memory address of the consecutive elements is + 1 and so on
  // Check the below example

  for (int i = 0; i < (sizeof(array)/sizeof(array[0])); i = i + 1)
  {
    p_pointer_to_array = array + i;
    cout << *p_pointer_to_array << " -> Memory address is " << p_pointer_to_array << endl;

  }

  return 1;
}

int use_pointers()
{

  int a = 10;
  int *p_pointer_to_a = &a;

  cout << p_pointer_to_a << " -> This is the memory address of the variable a" << endl;

  cout << *p_pointer_to_a << " -> If you put the star before the pointer variable it will give you the value stored in that address" << endl;

  return 1;
}

int main(){

    // Pointers are aptly named: they are variables that "point" to locations in memory

    /* A pointer, like a hyperlink, stores the location of some other data. Because a pointer can store the
    location (the address) of other data, you can use it to hold on to memory that you get from the
    operating system. In other words, your program can ask for more memory and can access that memory
    using pointers */

    /*
    An easy way to visualize computer memory is to think of an Excel spreadsheet. Spreadsheets are
    basically a large number of “cells” that can each store a piece of data. This, too, is what computer
    memory is: a large number of sequential pieces of data. Unlike Excel, in memory, each “cell” can store
    only a very small amount of data—1 byte, which can itself only store 256 possible values (0-255). Also
    unlike Excel, memory is organized “linearly” rather than in a grid. In fact, you can even think about
    memory as being a very long array of chars.
    Just as each cell in an Excel spreadsheet has a way to locate it (using its row number and column letter),
    each cell in memory has an address. This address is the value that a pointer stores, when it holds the
    location of memory
    */

   /*
    The word pointer can refer either to
    1) A memory address itself
    2) A variable that stores a memory address
   */

  /*
    The concept of ownership is part of the interface between a function and its users—it is not explicitly
    part of the language. When you write a function that takes a pointer, you should document whether the
    function takes ownership of the memory or not. C++ will not track this for you, and it will never free
    memory that you have explicitly allocated while your program is still running unless you explicitly
    request it
  */

    // Syntax to declare a pointer

    // <data_type> *<pntr_name>

    int a = 1;
    int *p_a = &a; // & is the address of operator

    cout << p_a << " This is same as the following address -> " << &a << endl;

    // Say if you have the pointer and you want to print the value stored in that particular address, use the below example
    // but if you print p_a it then prints the memory address of it
    // The code *p_pointer_to_integer says, “follow the pointer and get the value stored in the memory
    // that is pointed to”. In this case, since p_pointer_to_integer points to a, and a has the value 1, we
    // print the value 1

    cout << *p_a << endl;

    // You can also define variables in the below manner

    int x;
    int *p_pointer_to_integer = &x;
    *p_pointer_to_integer = 5; // x is now 5!
    cout << x << endl;

    /* A pointer stores an address, so when you use the bare pointer, you get that address back. You have to
    add something extra, the asterisk, in order to retrieve or modify the value stored at the address.
    A variable stores a value, so when you use the variable, you get its value. You have to add some extra,
    the ampersand, in order to retrieve the address of that variable.
    */

   /*
    Sometimes, though, you need to be able to say, “this pointer is explicitly NOT initialized yet.” C++ has a
    special value that you can use to mark a pointer as explicitly uninitialized: the value NULL. If you make a
    pointer point to NULL (store the value NULL), you know that it is uninitialized. Whenever you create a
    new pointer, first set it to NULL so that you can later check and see if it has been set to something
    usable or not
   */
    int *p_int = NULL; // Initialize pointer to NULL
    
    if (p_int != NULL) {
        *p_int = 5; // This line will not execute since p_int is NULL
    }

    // The above code initializes p_int to NULL, at this point p_int does not point to any valid memory address
    // so basically the point is that we need to assign NULL values to a pointer during its declaration is 
    // we are not initializing any value to it at that time
    // this ensure that we if accidentally use this we will not override a memory address that was assigned to it randomly during its declaration
    
    // use of reference

    // reference is a variable that refers to another variable, sharing the same backing memory. References,
    // however, are used just like regular variables. You can think of a reference as a stripped-down pointer
    // without needing to use special asterisk and ampersand syntax to use the referred-to value or when
    // assigning to the reference. A reference, unlike a pointer, must always refer to valid memory

    cout << "*********************" << endl;

    // Here, the actual memory of the ref variable holds a pointer to the memory of the x variable

    x = 5;
    int &ref = x;

    cout << &ref << endl;
    cout << ref << endl;

    // use_pointers();
    pointer_array();
    reference();

    return 1;
}