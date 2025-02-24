#include <iostream>
#include <cmath>
#include <ctime>

int fact(int x) {
    if (x < 2) {
        return 1;
    }
    return fact(x - 1) * x;
}

int square(int x) {
    int s = sqrt(x);
    if (s * s != x) {
        return -1;
    }
    else {
        return s;
    }
}

int main() {
    srand(time(0));
    int n = rand() % 10000, count = 0;
    int* Arr = new int[n];

    for (int i = 0; i < n; i++) {
        Arr[i] = rand() % 32000;
    }

    // Нечетные
    count = 0;
    std::cout << "Число нечетных чисел: ";
    for (int i = 0; i < n; i++) {
        if (Arr[i] % 2 != 0) {
            count++;
        }
    }
    std::cout << count << std::endl;
    
    
    // Квадрат четных
    count = 0;
    std::cout << "Число квадратов четных чисел: ";
    for (int i = 0; i < n; i++) {
        if (square(Arr[i]) % 2 == 0) {
            count++;
        }
    }
    std::cout << count << std::endl;

    // Кратны 3 и не кратны 5
    count = 0;
    std::cout << "Кол-во чисел кратных 3 и не кратных 5: ";
    for (int i = 0; i < n; i++) {
        if (Arr[i] % 3 == 0 && Arr[i] % 5 != 0) {
            count++;
        }
    }
    std::cout << count << std::endl;

    // Первое условие
    count = 0;
    std::cout << "Кол-во чисел, удовлетворяющих 1-ому условию: ";
    for (int i = 0; i < n; i++) {
        if ((pow(2, i) < Arr[i]) && (Arr[i] < fact(i))) {
            count++;
        }
    }
    std::cout << count << std::endl;

    // Второе условие
    count = 0;
    std::cout << "Кол-во чисел, удовлетворяющих 2-ому условию: ";
    for (int i = 0; i < n; i++) {
        if (2 * Arr[i] < (Arr[i - 1] + Arr[i + 1])) {
            count++;
        }
    }
    std::cout << count << std::endl;

    // Четные порядковые, но нечетное значение
    count = 0;
    std::cout << "Кол-во чисел, с четным порядковым номером, но нечетным значением: ";
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0 && Arr[i] % 2 != 0) {
            count++;
        }
    }
    std::cout << count << std::endl;
    
    return 0;
}