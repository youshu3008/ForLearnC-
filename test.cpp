#include <iostream>
#include <vector>

std::vector<std::vector<int>> constructDeterminant(int x) {
    if (abs(x) > 40) {
        return {{-1}};
    }

    for (int a = 1; a <= 20; a++) {
        for (int b = 1; b <= 20; b++) {
            if (a * b - a - b == x) {
                return {{a, b}, {a + x, b}};
            }
        }
    }

    return {{-1}};
}

int main() {
    int x;
    std::cout << "请输入整数x：";
    std::cin >> x;

    std::vector<std::vector<int>> determinant = constructDeterminant(x);

    if (determinant[0][0] == -1) {
        std::cout << -1 << std::endl;
    } else {
        for (const auto& row : determinant) {
            for (int num : row) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}