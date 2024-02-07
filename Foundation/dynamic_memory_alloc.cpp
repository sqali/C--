// Notes

/*

Dynamic allocation means requesting as much (or as little) memory as you need, while your program is
running. You program will calculate the amount of memory it needs instead of working with a fixed set
of variables with a particular size

*/

#include <iostream>
#include <string>

using namespace std;

void dma_1d()
{
    int *array = new int[5];

    // intializing values in the array

    int length = 5;

    for (int i = 0; i < length; i++)
    {
        array[i] = i * i;
    }

    // printing those values in the console

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << endl;
    }

    // now deallocating the memory of the array such that it frees the memory it has occupied

    delete[] array;

}

void dma_2d()
{
    int rows, cols;
    std::cout << "Enter number of rows and columns: ";
    std::cin >> rows >> cols;

    // Dynamic allocation of 2D array
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    // Accessing and using the dynamically allocated array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = i + j;
        }
    }

    // printing the pointers content 

    std::cout << "************************************************" << endl;

    for (int i = 0; i < rows; i++)
    {
        std::cout << arr[i] << endl;
    }

    std::cout << "************************************************" << endl;

    // to check what is contained in the first pointer that points to the first row of the matrix

    int *ptrCopy = arr[0];

    for (int i = 0; i < rows; i++) {
        std::cout << ptrCopy[i] << endl;
    }

    // Deallocating memory
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    /*
    [1,2,3
     4,5,6
     7,8,9]

    arr     -> [ptr1] -> [ptr2] -> [ptr3]  
           |         |         |     
           v         v         v     
           [0][0]    [1][1]    [2][2] 
           [0][1]    [1][1]    [2][2] 
           [0][2]    [1][1]    [2][2] 

    arr  - is an array that consists of list of pointers to pointers
    ptr1 - Each pointer in the array arr points to a row of the 2D array, not to columns

    ptr1 will point to - an array of [1,2,3
    ptr2 will point to - an array of [4,5,6]
    ptr3 will point to - an array of [7,8,9]

    In C++, a 2D array declared as int** arr represents an array of pointers to pointers, where each pointer points to an array of integers. When you access elements using the syntax arr[i][j], it might seem like you are directly accessing a 2D array, but in reality, you are accessing elements indirectly through pointer dereferencing.

    Here's how it works:

    Initialization and Memory Allocation:

    int** arr is declared, but it's important to understand that arr itself is a pointer to a pointer to an integer.
    When you dynamically allocate memory for a 2D array, you allocate memory for an array of pointers (rows), where each pointer points to an array of integers (columns).
    Accessing Elements:

    When you access elements using the syntax arr[i][j], it's actually a two-step process.
    arr[i] accesses the ith pointer in the array of pointers. This pointer points to the beginning of the ith row.
    Then, arr[i][j] accesses the jth element in the ith row.
    Here's a simplified explanation of how arr[i][j] works:

    arr[i] gives you a pointer to the beginning of the ith row.
    arr[i][j] then dereferences this pointer and accesses the jth element in that row.
    This double dereferencing process allows you to access elements in a way that resembles a traditional 2D array, even though you're technically dealing with a pointer to a pointer.

    So, even though arr is a list of pointers to pointers, the syntax arr[i][j] provides a convenient way to access and manipulate elements in the 2D array, hiding the details of pointer manipulation behind a more intuitive interface.

    */

}

void pointer_arithematics()
{
    int* ptr = new int[5]; // Allocating memory for an array of integers

    ptr[0] = 423;
    ptr[1] = 23;
    ptr[2] = 4;
    ptr[3] = 6; 
    ptr[4] = 5;

    // Incrementing pointer by one
    ptr++;

    std::cout << *ptr << endl;

    // Decrementing pointer by one
    ptr--;

    std::cout << *ptr << endl;

    // Adding an integer to the pointer
    ptr = ptr + 3;

    std::cout << *ptr << endl;

    // Subtracting an integer from the pointer
    ptr = ptr - 2;
    ptr--;

    std::cout << *ptr << endl;

    // Accessing values using pointer arithmetic
    int val = *(ptr + 2); // accessing the third element from the current pointer position
    delete[] ptr;  // make sure that when you are deleting or deallocating memory assigned to thi list of integers you use the same pointer address that was assigned to it initially as 
    // you have done some arithematic operations with it

}

int main()
{
    // dma_1d();
    // dma_2d();
    pointer_arithematics();
}

/* Notes

Best Practices:

    Always check for allocation failure: After allocating memory using new, check if the allocation was successful.
    Deallocate memory properly: Always use delete for single objects and delete[] for arrays to avoid memory leaks.
    Avoid dangling pointers: Ensure that pointers are not pointing to deallocated memory.
    Use smart pointers: Consider using std::unique_ptr or std::shared_ptr to manage dynamic memory automatically and reduce the risk of memory leaks.
    Minimize dynamic memory allocation: Use dynamic memory allocation only when necessary, as it can lead to fragmentation and decreased performance.
    Document memory ownership: Clearly document which part of the code is responsible for deallocating dynamically allocated memory to avoid confusion and bugs.
    Prefer standard containers: Whenever possible, prefer using standard containers like std::vector instead of managing dynamic memory manually.
    They provide safer and more convenient memory management.

*/