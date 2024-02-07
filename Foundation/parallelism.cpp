#include <iostream>
#include <thread>
#include <future> // <future> is for asynchronous execution and retrieval of results.

/*
asynchronously" means that the calculation of the factorial of 6 (factorial(6)) is performed independently of the main thread of execution.
Instead of waiting for the calculation to complete before proceeding, the main thread continues its execution while the factorial calculation occurs in the background.
*/

int factorial(int n) 
{
    int res = 1;
    for (int i = n; i > 1; --i) {
        res *= i;
    }
    return res;
}


int main()
{
    std::future<int> fut = std::async(factorial, 50);
    std::cout << "Result is ->> " << fut.get() << std::endl;
    return 0;
}

/*
std::future<int> fut = std::async(factorial, 6);:
std::async is a function template that runs a function asynchronously (potentially in a separate thread) and returns a std::future object.
In this line, factorial is the function to be executed asynchronously, and 6 is the argument passed to the factorial function.
std::future<int> is a template class representing a future result of an asynchronous operation. Here, it's specified that the future will hold an integer result.
fut is a variable of type std::future<int> that will hold the future result of the asynchronous operation.
std::cout << "Result: " << fut.get() << std::endl;:
fut.get() retrieves the result of the asynchronous operation. This call will block until the result becomes available.
Once the result is available, it's printed to the standard output stream using std::cout.
*/

/*Benefits and Best practices of concurrency and multi threading*
 Best Practices:
    Synchronization: Use synchronization primitives like mutexes and condition variables to avoid data races and ensure proper synchronization between threads.
    Avoid Deadlocks: Be cautious about locking order and minimize the scope of critical sections to prevent deadlocks.
    Resource Management: Properly manage resources shared between threads to prevent resource leaks.
    Exception Handling: Use exception handling mechanisms to handle errors gracefully in multithreaded code.
    Avoid Excessive Multithreading: Creating too many threads can lead to overhead and decreased performance. Use thread pools or task-based parallelism where appropriate.

2. Benefits of Concurrency and Multithreading:
    Improved Performance: Multithreading enables programs to utilize multiple CPU cores efficiently, leading to improved performance and responsiveness.
    Enhanced Scalability: Concurrent programs can scale better to handle larger workloads and take advantage of modern hardware with multiple cores.
    Asynchronous Programming: Concurrency allows for asynchronous programming models, enabling tasks to run independently and asynchronously, improving overall program efficiency.
    Better User Experience: Multithreading can lead to a more responsive user interface by offloading time-consuming tasks to background threads
    while keeping the main thread free to handle user interactions.
*/