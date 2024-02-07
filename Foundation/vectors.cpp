#include <iostream>
#include <vector>

using namespace std;

void vector_2d()
{
    std::vector<std::vector<int>> vec_2d = {{12,23,45},{73,95,3},{45,7,2}}; // declaring and initializing a 2D vector

    // You can add more rows to this array
    vec_2d.push_back({1,4,6});

    // Similary you can delete the rows of this 2d array using pop back - the last row will be deleted

    for (int i = 0; i < vec_2d.size(); i++)
    {
        for (int j = 0; j < vec_2d[i].size(); j++)
        {
            cout << vec_2d[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    // Vectors are part of the STL - Standard template library and are dynamic arrays that can resize themselves automatically when elements are added or removed
    // They provide similar features to arrays but with additional flexibility and features

    std::vector<int> vec1 = {1,23,5,7,78,4}; // Declaring & initializing a vector called vec1 

    // Inserting elements in the vector
    vec1.push_back(45); // inserts element at the end of the vector, not possible to insert at a particular index
    vec1.push_back(32);

    // Deleting elements in the vector

    vec1.pop_back(); // always removes the last element of the vector, not possible to remove from a particular index

    // To remove or add elements at a particular index in the vectors you have to use the erase or insert function using iterators

    // iterating over the vectors

    for (int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << endl;
    }

    cout << "*************************************" << endl;
    vector_2d();

}

/* Notes

1. Best Practices When Using Vectors:

    Always include the <vector> header at the beginning of your program when using vectors.
    Prefer using push_back() to add elements to a vector rather than direct assignment, especially if the size is not predetermined.
    Use iterators or range-based for loops for accessing and iterating over elements whenever possible, rather than using raw indexing.
    Ensure to check the bounds of the vector before accessing elements using at() or size() to avoid runtime errors.
    Consider using reserve() to pre-allocate memory if you know the approximate size of the vector in advance, especially when dealing with large vectors to avoid frequent reallocations.

2. Benefits of Using Vectors:

    Dynamic Size: Vectors can resize themselves dynamically, allowing for flexible memory allocation and efficient use of memory.
    Efficient Insertion and Deletion: Vectors provide efficient insertion and deletion operations at the end of the container (using push_back() and pop_back()), 
    making them suitable for scenarios where elements need to be added or removed frequently.
    Standard Library Support: Vectors are part of the Standard Template Library (STL), providing a wide range of utility functions and algorithms that can be applied directly to vectors.
    Memory Management: Vectors manage memory allocation and deallocation automatically, reducing the likelihood of memory leaks and other memory-related issues compared to raw arrays.
    Safety and Convenience: Vectors provide safety features such as bounds checking (with at()) and size information (with size()), 
    which help prevent common programming errors. Additionally, they offer a more convenient interface for common operations compared to raw arrays.

*/