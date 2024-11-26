#include <iostream>
#include <cmath>

int f(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a > b) {
        return f(a - b, b);
    }
    if (b > a) {
        return f(a , b - a);
    }
}

int main() {
    int a, b;
    std::cout << "Введите числа через пробел: ";
    std::cin >> a >> b;
    
    std::cout << "НОД: " << f(abs(a), abs(b));

    return 0;
}