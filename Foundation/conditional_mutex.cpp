#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv; // this is used to put conditions in the mutex/thread before execution so that the lock waits for a particular condition
bool ready = false;

/*
std::condition_variable: std::condition_variable is a synchronization primitive provided by the C++ Standard Library
It allows threads to wait until a certain condition is met before proceeding with their execution
In your code, the cv variable of type std::condition_variable is used to synchronize the threads based on the ready flag. When the ready flag becomes true
the waiting threads are notified through the condition variable
and they can proceed with their execution. You imported the <condition_variable> header file to use this synchronization primitive
*/

/*
Mutex: Think of a mutex as a lock on a resource. It prevents multiple threads from accessing the same resource simultaneously, which could lead to problems like data corruption.

Unique Lock: A unique lock is a tool that helps manage the mutex. It's like having a key to unlock and lock the mutex.
Scoped Locking: With a unique lock, you don't have to remember to unlock the mutex manually. It automatically unlocks the mutex when it's no longer needed.
It's like having a key that automatically locks the door when you leave the room.

Exception Safety: Unique locks are also safe to use in case something unexpected happens, like an exception being thrown.
Even if an exception occurs, the unique lock ensures that the mutex is properly released, preventing deadlocks or resource leaks.
*/

void printId(int id) {
    std::unique_lock<std::mutex> lock(mtx);

    /*
     It's not a variable or a function but rather a type that you can use to create objects.

    When you write std::unique_lock<std::mutex> lock(mtx);, you are declaring a variable named lock of type std::unique_lock<std::mutex>. 
    This variable lock is an instance of the std::unique_lock class template.

    Here's a breakdown of the line:

    std::unique_lock: This specifies the type of the variable lock.
    <std::mutex>: This is a template parameter indicating that std::unique_lock should be specialized for use with a std::mutex.
    lock: This is the name of the variable being declared.
    (mtx): This part initializes the std::unique_lock object lock with the std::mutex object mtx. This constructor call locks the mutex mtx immediately upon construction.
    So, in essence, std::unique_lock is a class template, and lock is an object of type std::unique_lock<std::mutex>.
    It's used to manage the locking and unlocking of the mutex mtx within its scope.
    */

    while (!ready) {
        cv.wait(lock);
    }
    std::cout << "Thread " << id << " is printing." << std::endl;
}

int main()
{
    std::thread t1(printId, 1);
    std::thread t2(printId, 2);

    std::this_thread::sleep_for(std::chrono::seconds(7)); // makes the main function wait or sleep for the specified seconds
    ready = true;

    cv.notify_all();

    t1.join();
    t2.join();

    return 0;

    // You may observe that sometimes it prints the thread 1 or thread 2 first, this is because it depends which thread acquires the lock first which is not guaranteed
}