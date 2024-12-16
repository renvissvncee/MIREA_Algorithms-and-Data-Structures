#include <iostream>

int main() {
    int len;
    std::cout << "Введите длину: ";
    std::cin >> len;
    int Arr[len];
    int count_two = 0, count_three = 0;
    
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < len; i++) {
        std::cin >> Arr[i];
    }

    for (int i = 0; i < len - 1; i++) {
        if (Arr[i] == 0 && Arr[i + 1] == 0) {
            count_two++;
        }     
    }

    for (int i = 0; i < len - 2; i++) {
        if (Arr[i] == 0 && Arr[i + 1] == 0 && Arr[i + 2] == 0) {
            count_three++;
        }     
    }

    std::cout << "Два идущих подряд: " << count_two << "\nТри идущих подряд: " << count_three;

    return 0;
}