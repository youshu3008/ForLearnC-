#include <iostream>
#include <utility>  // std::forward

void targetFunction(int& x) {
    std::cout << "Lvalue reference called with " << x << std::endl;
}

void targetFunction(int&& x) {
    std::cout << "Rvalue reference called with " << x << std::endl;
}

template <typename T>
void wrapper(T&& arg) {
    targetFunction(std::forward<T>(arg));  // 使用 std::forward 完美转发
}

int main() {
    int a = 10;

    wrapper(a);        // Lvalue, calls targetFunction(int&)
    wrapper(20);       // Rvalue, calls targetFunction(int&&)

    return 0;
}
/*
模板参数推导:

wrapper 函数使用了 模板参数推导（Template Argument Deduction），当传递左值时，T 推导为 int&，当传递右值时，T 推导为 int。
std::forward:

std::forward<T>(arg) 根据 T 的类型精确地转发参数。如果 T 是左值引用类型，它会将 arg 转发为左值引用。如果 T 是非引用类型（即右值），它会将 arg 转发为右值。
完美转发的作用
完美转发的主要作用是避免参数属性的丢失，保留参数的原始类型信息，从而避免不必要的拷贝构造或移动构造。它在编写泛型代码时特别有用，比如在实现工厂函数或其他需要转发参数的函数模板时。

总结
完美转发是将参数精确地传递给另一个函数的技术，保留其所有属性（如左值/右值、引用性等）。
std::forward 是实现完美转发的核心工具，它根据模板参数的类型正确地传递参数。
用途: 完美转发用于编写泛型代码，避免参数属性丢失，提高代码效率和灵活性。

*/