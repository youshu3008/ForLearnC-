#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

// 消息队列类
class MessageQueue {
public:
    void push(int message) {
        std::lock_guard<std::mutex> lock(mtx);
        queue.push(message);
        cv.notify_all();  // 通知消费者有新消息
    }

    int pop() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [=] { return !queue.empty(); });
        int message = queue.front();
        queue.pop();
        return message;
    }

private:
    std::queue<int> queue;
    std::mutex mtx;
    std::condition_variable cv;
};

void producer(MessageQueue &mq) {
    for (int i = 0; i < 5; ++i) {
        mq.push(i);
        std::cout << "Produced: " << i << std::endl;
        std::cout << "Produced: sleep for 1 second " << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void consumer(MessageQueue &mq) {
    for (int i = 0; i < 5; ++i) {
        int message = mq.pop();
        std::cout << "Consumed: " << message << std::endl;
    }
}

int main() {
    MessageQueue mq;
    std::thread producerThread(producer, std::ref(mq));
    std::thread consumerThread(consumer, std::ref(mq));

    producerThread.join();
    consumerThread.join();

    return 0;
}
