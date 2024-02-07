#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
/*
STL, or the Standard Template Library, is a powerful set of C++ template classes and functions designed to provide general-purpose solutions for common programming problems. 
It offers a wide range of data structures, algorithms, and utilities that help developers write efficient, concise, and maintainable code.

*/

void ordered_map()
{
    std::map<std::string, int> ageMap;

    // Inserting key-value pairs
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;

    // Accessing elements
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;

}

/* Notes on ordered map
Best Practices:
    Use find() to check if a key exists before accessing it to avoid accidental key insertion.
    Prefer emplace() for inserting elements as it avoids unnecessary copies.
    Benefits:
    Fast look-up: Provides logarithmic time complexity for element retrieval, insertion, and deletion.
    Ordered keys: Maintains keys in sorted order, enabling operations like lower_bound() and upper_bound().
    Associative access: Allows access to elements using keys rather than indices.

*/

void sorting_stl()
{
    std::vector<int> nums = {5, 2, 8, 3, 1};

    // Sorting
    std::sort(nums.begin(), nums.end()); // this is how you use the sorting algorithm in C++

    // Finding element
    auto it = std::find(nums.begin(), nums.end(), 3);
    if (it != nums.end()) {
        std::cout << "Found: " << *it << std::endl;
    }
}

void iterator_stl()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};

    // Using iterators for traversal
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/*
Best Practices:
    Prefer range-based for loops when possible for better readability and safety.
    Be cautious with invalidated iterators after modifying containers.
Benefits:
    Uniform interface: Provides a consistent way to traverse elements across different containers.
    Flexibility: Supports various traversal patterns like forward, reverse, and bidirectional.
    Interoperability: Enables interoperability with standard algorithms and other STL components.
*/


int main()
{
    return 1;
}