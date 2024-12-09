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

    for (int i = 1; i < len; i++) {
        if (Arr[i] > Arr[i - 1]) {
            std::cout << "Неупорядоченный по убыванию";
            break;
        }
        else if (i == len - 1 && Arr[i] < Arr[i - 1]) {
            std::cout << "Упорядоченный по убыванию";
        }
    }
    return 0;
}