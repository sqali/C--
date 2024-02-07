#include <iostream>
#include <thread>
#include <chrono> // You can measure the execution time of your code using this header file
#include <mutex> // for synchronization - mutual exclusion is the full form here

void store_numbers()
{   
    int array[1000];

    for (int i = 0; i < 1000; i++)
    {
        array[i] = i;
    }
    std::cout << "store_numbers() completed." << std::endl;
}

void store_numbers2()
{   
    int array2[1000];

    for (int i = 1000; i < 2000; i++)
    {
        array2[1000-i] = i;
    }
    std::cout << "store_numbers2() completed." << std::endl;
} 

int main()
{
    // Create two threads, one for each function
    auto start = std::chrono::steady_clock::now();

    std::thread t1(store_numbers);
    std::thread t2(store_numbers2);

    // Join the threads with the main thread
    t1.join();
    t2.join();

    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); // duration cast function is used to convert the duration to a specified duration type - milliseconds
    
    // The two functions will be executed simultaneously
    std::cout << "Both threads have completed." << std::endl;

    // Print the duration
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl; // duration.count() returns the count in milliseconds using duration object's count variable
}