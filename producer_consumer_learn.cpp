#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> queue;
std::mutex mtx;
std::condition_variable cv;
bool done = false;

void producer(int numItems) {
    for (int i = 1; i <= numItems; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        queue.push(i);
        std::cout << "Produced: " << i << std::endl;
        lock.unlock();
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::unique_lock<std::mutex> lock(mtx);
    done = true;
    lock.unlock();
    cv.notify_one();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !queue.empty() || done; });
        while (!queue.empty()) {
            int item = queue.front();
            queue.pop();
            std::cout << "Consumed: " << item << std::endl;
        }
        if (done && queue.empty()) {
            break;
        }
    }
}

int main() {
    int numItems = 10;
    std::thread prod(producer, numItems);
    std::thread cons(consumer);
    prod.join();
    cons.join();
    return 0;
}
