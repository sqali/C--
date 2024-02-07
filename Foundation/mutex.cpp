#include <iostream>
#include <thread> // You can measure the execution time of your code using this header file
#include <mutex> // for synchronization - mutual exclusion is the full form here
#include <condition_variable>

std::mutex mtx; // mutex is used for preventing a specific piece of code from being used by another thread, basically it prevents parallelism of a particular pience of code
int sharedData = 0;

void incrementSharedData() {
    mtx.lock(); // Acquire the mutex lock
    sharedData++; // Manipulate the shared data
    mtx.unlock(); // Release the mutex lock
}


int main()
{
    std::thread t1(incrementSharedData);
    std::thread t2(incrementSharedData); // t2 will wait till the execution of t1 is complete as it will release the mutex lock so the t2 can proceed

    t1.join();
    t2.join();

    std::cout << "Shared data: " << sharedData << std::endl;

    return 0;
}