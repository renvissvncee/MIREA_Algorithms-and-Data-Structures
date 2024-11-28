#include <iostream>

int Towers_of_Hanoi(int x) {
    if (x == 1) {
        return 1;
    }
    return (2 * Towers_of_Hanoi(x - 1)) + 1;
}

int main() {
    int x;
    std::cout << "Введите число колец: ";
    std:: cin >> x;

    std::cout << Towers_of_Hanoi(x);
    return 0;
}