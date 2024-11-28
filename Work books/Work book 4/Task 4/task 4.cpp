#include <iostream>

int f(int x) {
    if (x < 10) {
        return x;
    }
    return (x % 10) + f(x / 10);
}

int main() {
    int x;
    std::cout << "Введите число: ";
    std::cin >> x;
    
    std::cout << f(x);

    return 0;
}