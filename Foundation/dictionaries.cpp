#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map> // required STL for using dictionaries
#include <map>

using namespace std;

void dictionaries()
{
    std::unordered_map<std::string, int> my_dict = {{"Orange", 120}}; // declared and intialized a dictionary named mydict

    // You can see above that have predefined the data types of keys and values in the dictionaries
    
    // Adding new key values pairs in the dictionary
    my_dict["Banana"] = 12;
    my_dict["Apple"] = 100;
    my_dict["Kiws"] = 323;

    // Iterating through a dictionary

    /*
    auto it = my_dict.begin();: Here, auto is a keyword used for type inference, 
    which means the compiler deduces the type of the variable it based on the type of the expression on the right side of the assignment. 
    my_dict.begin() returns an iterator that points to the beginning of the dictionary my_dict. So, it becomes an iterator pointing to the first element of the dictionary.

    it != my_dict.end(): This is the loop condition. It checks whether the iterator it has reached the end of the dictionary my_dict. 
    my_dict.end() returns an iterator pointing to the position just beyond the last element of the dictionary. So, the loop continues as long as it is not equal to my_dict.end().

    it->first: This accesses the key of the current key-value pair that the iterator it is pointing to.
    ", Value: ": Another string literal that separates the key and value in the output.
    it->second: This accesses the value associated with the key of the current key-value pair that the iterator it is pointing to.

    it: it is an iterator variable that is used to traverse through the elements of the dictionary my_dict. In C++, 
    iterators are objects that provide a way to access the elements of a container sequentially.

    ->: The arrow operator (->) is used to access members of a structure or class through a pointer or iterator. 
    It is essentially a shorthand for dereferencing a pointer or iterator and accessing a member of the object it points to.

    first and second: In the context of a std::unordered_map or std::map in C++, first and second are member variables of the std::pair objects stored in the dictionary. 
    Each element of the dictionary is a key-value pair, and first represents the key, while second represents the corresponding value.

    Putting it all together, it->first and it->second are used together to access the key and value of the current key-value pair that the iterator it is pointing to within 
    the dictionary my_dict. Here's how it works:

    it->first: This accesses the key of the current key-value pair pointed to by the iterator it. It's equivalent to (*it).first.

    it->second: This accesses the value associated with the key of the current key-value pair pointed to by the iterator it. It's equivalent to (*it).second.
    */

    for (auto it = my_dict.begin(); it != my_dict.end(); it++)
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    // checking if the key exists in the dictionary

    auto it = my_dict.find("Banana");

    if (it != my_dict.end())
    {
        cout << "Key found -> " << it->first;
    }
    else
    {
        cout << "Key was not found";
    }

    /*
    Understanding my_dict.begin() and my_dict.end():

    my_dict.begin() returns an iterator pointing to the first key-value pair in the dictionary.
    my_dict.end() returns an iterator pointing just past the last key-value pair in the dictionary, which acts as a sentinel value indicating the end of the container.
    auto it = my_dict.find("Banana");:

    The find() function searches the dictionary (my_dict) for the key "Banana".
    If the key is found, find() returns an iterator pointing to the key-value pair with the key "Banana".
    If the key is not found, find() returns an iterator equal to my_dict.end().
    Understanding the if condition:

    The if condition compares the iterator it returned by find() with my_dict.end().
    If it is equal to my_dict.end(), it means that the key "Banana" was not found in the dictionary.
    If it is not equal to my_dict.end(), it means that the key "Banana" was found, and it points to the key-value pair containing "Banana".
    Handling Subcases:

    Subcase 1: If it points to the key-value pair containing "Banana", the condition executes, indicating that the key was found.
    Subcase 2: If it equals my_dict.end(), the condition evaluates to false, indicating that the key was not found. This scenario is not misleading because find() 
    returns my_dict.end() only when the key is not found.
    Misleading Behavior:

    The find() function does not return an iterator pointing to the last key-value pair in the dictionary when the key is not found. Instead, it returns my_dict.end()
    which serves as an indicator that the key was not found.
    This behavior is consistent and not misleading. It allows users to reliably determine whether a key exists in the dictionary by comparing the returned iterator with my_dict.end().
    */
    

    // Handling collisions in the dictionary

    // removing a key value pair from dictionary - using erase function
    my_dict.erase("Banana");

}

int main()
{
    dictionaries();
}

/* Notes on collision and ordered map

In C++, collisions in hash-based containers like std::unordered_map are handled automatically by the container itself. 
When two different keys produce the same hash value, a collision occurs. The container resolves collisions by using techniques such as chaining or open addressing.

    Chaining: In chaining, the container maintains a linked list of elements for each hash bucket. 
        When a collision occurs, the new element is added to the linked list associated with the corresponding bucket.
    Open Addressing: In open addressing, the container probes for an alternative empty slot in the hash table when a collision occurs. 
        It uses a specific probing sequence to find the next available slot.

Both std::unordered_map and std::map handle collisions automatically, but they use different underlying data structures and collision resolution techniques.

#include <map>: This preprocessor directive includes the contents of the <map> header file, which defines the std::map class template. 
std::map is an associative container that maintains its elements in a sorted order based on the keys.
std::map vs. std::unordered_map:
std::map: Implements a balanced binary search tree (usually a red-black tree) to maintain its elements in sorted order. 
It does not rely on hashing and does not suffer from hash collisions. Instead, it maintains a sorted order based on the comparison operator provided or using the 
default < operator for the keys.
std::unordered_map: Implements a hash table data structure using hashing techniques for storage. 
It offers constant time complexity for average case lookups, insertions, and deletions. It relies on hashing, and collision resolution is handled internally by the container.


Yes, that's correct. In general, the time complexity to access a key in a std::map is 
(
log
⁡
�
)
O(logn), where 
�
n is the number of elements in the map. This complexity arises because std::map uses a balanced binary search tree (usually a red-black tree) to maintain its elements in sorted order based on the keys.

*/

/* Notes

Best practices when using dictionaries in C++:

    Choose the appropriate dictionary container based on your requirements. std::unordered_map offers constant time complexity for average case lookups, 
    while std::map offers logarithmic time complexity.
    Ensure that keys are unique within the dictionary. Inserting duplicate keys can lead to unexpected behavior.
    Use find() method to check if a key exists before accessing its value directly to avoid runtime errors.
    Consider using const references when iterating over the dictionary to avoid unnecessary copying.
    Be mindful of the memory overhead associated with dictionaries, especially if they contain large numbers of elements.

Benefits of using dictionaries in C++:

    Efficient key-value lookups: Dictionaries provide fast access to values based on their corresponding keys, making them ideal for associative data storage and retrieval.
    Flexibility: Dictionaries allow you to store heterogeneous data types as values, providing flexibility in designing data structures.
    Easy manipulation: You can easily insert, retrieve, and remove key-value pairs from dictionaries, facilitating dynamic data management in your programs.
    Enhanced readability: The use of dictionaries can lead to more readable and expressive code, especially when dealing with mappings between related data entities.

*/