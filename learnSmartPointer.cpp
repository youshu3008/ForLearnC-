#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> sp = std::make_shared<int>(20);
    std::shared_ptr<int> wp1 = sp;  // 创建一个 shared_ptr
    std::weak_ptr<int> wp = sp;  // 创建一个 weak_ptr，不增加引用计数
    std::cout << "Reference count: " << sp.use_count() << std::endl;  // 输出 1

    if (auto spt = wp.lock()) { // 尝试提升为 shared_ptr
        std::cout << "Value: " << *spt << std::endl;
    } else {
        std::cout << "Object has been destroyed" << std::endl;
    }

    return 0;
}


