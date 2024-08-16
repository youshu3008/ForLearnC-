#include <iostream>
#include <thread>
#include <shared_mutex> // C++17 引入的读写锁
#include <vector>

int counter = 0;
std::shared_mutex rwlock; // 读写锁

// 读操作（允许多个线程同时进行）
void readCounter() {
    for (int i = 0; i < 5; ++i) {
        std::shared_lock<std::shared_mutex> lock(rwlock); // 读锁
        std::cout << "Read counter: " << counter << std::endl;
    }
}

// 写操作（只允许一个线程进行写操作，写期间阻塞其他读写线程）
void incrementCounter() {
    for (int i = 0; i < 5; ++i) {
        std::unique_lock<std::shared_mutex> lock(rwlock); // 写锁
        ++counter;
        std::cout << "Incremented counter to: " << counter << std::endl;
    }
}

int main() {
    // 创建多个读线程和写线程
    std::vector<std::thread> threads;

    // 创建2个写线程
    threads.emplace_back(incrementCounter);
    threads.emplace_back(incrementCounter);

    // 创建3个读线程
    threads.emplace_back(readCounter);
    threads.emplace_back(readCounter);
    threads.emplace_back(readCounter);

    // 等待所有线程完成
    for (auto &t : threads) {
        t.join();
    }
    system("pause");
    return 0;
}
