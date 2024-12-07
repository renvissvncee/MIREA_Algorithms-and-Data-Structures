#include <iostream>

int main() {
    int len = rand() % 10000;
    int Arr[len];
    int count_two = 0, count_three = 0;

    for (int i = 0; i < len; i++) {
        Arr[i] = rand();
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