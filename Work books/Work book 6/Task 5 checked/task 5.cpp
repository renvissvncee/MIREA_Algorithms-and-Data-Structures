#include <iostream>
#include <ctime>

int main() {
    int len; 
    std::cout << "Введите длину массива: ";
    std::cin >> len;

    int* Arr = new int[len];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < len; i++) {
        std::cin >> Arr[i];
    }

    //for (int i = 0; i < len; i++) {
        //std::cout << Arr[i] << " ";
    //}

    int i = 1;
    while (i < len) {
        if (Arr[i] > Arr[i - 1]) {
            break;
        }
        i++;
    }

    if (i == len) {
        std::cout << "Упорядоченный по убыванию";
    }
    else {
        std::cout << "Не упорядоченный по убыванию";
    }

    return 0;
}