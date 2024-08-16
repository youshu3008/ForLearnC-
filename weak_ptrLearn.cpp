#include <iostream>
#include <memory>
#include <vector>

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};

class Subject {
    std::vector<std::weak_ptr<Observer>> observers;
public:
    void addObserver(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void notifyObservers() {
        for(auto it = observers.begin(); it != observers.end();) {
            if(auto obs = it->lock()) {  // 提升 weak_ptr 为 shared_ptr
                obs->update();
                ++it;
            } else {
                it = observers.erase(it);  // 删除已被销毁的观察者
            }
        }
    }
};

class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << "Observer updated\n";
    }
};

int main() {
    auto subject = std::make_shared<Subject>();
    auto observer1 = std::make_shared<ConcreteObserver>();
    auto observer2 = std::make_shared<ConcreteObserver>();

    subject->addObserver(observer1);
    subject->addObserver(observer2);

    subject->notifyObservers();  // 通知所有观察者

    observer1.reset();  // 销毁一个观察者
    subject->notifyObservers();  // 只通知剩余的观察者

    return 0;
}
