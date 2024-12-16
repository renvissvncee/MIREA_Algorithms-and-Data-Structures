#include <iostream>
#include <ctime>

int main() {
    srand(time(0));
    int len = rand() % 10000;
    int count = 0, sum = 0;
    int Arr[len];

    for (int i = 0; i < len; i++) {
        Arr[i] = rand();
    }

    for (int i = 0; i < len; i++) {
        if (Arr[i] % 5 == 0 && Arr[i] % 7 != 0) {
            count++;
            sum += Arr[i];
        }
    }

    std::cout << "Количество: " << count << "\nСумма: " << sum;

    return 0;
}