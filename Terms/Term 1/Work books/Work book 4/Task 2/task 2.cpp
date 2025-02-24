#include <iostream>

int fib(int n) {
    if (n < 3) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    std::cout << "Введите номер числа Фибоначчи: ";
    std::cin >> n;
    std::cout << n << "-ое число Фибоначчи: " << fib(n);
    return 0;
}