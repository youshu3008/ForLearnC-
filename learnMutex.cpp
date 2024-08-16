#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <shared_mutex> // C++17 引入的读写锁

using namespace std;

int counter = 0;
atomic<int> counter2(0);
mutex mtx;
shared_mutex rwlock;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        // lock_guard<mutex> lock(mtx); 
        counter2++;
        counter++;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;
    std::cout << "Final counter2 value: " << counter2 << std::endl;
    return 0;
}
