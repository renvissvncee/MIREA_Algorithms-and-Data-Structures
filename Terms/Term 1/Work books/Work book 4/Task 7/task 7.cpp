#include <iostream>

void add(int*& x, int len) {
    int* newArr = new int[len + 1];
    for (int i = 0; i < len; i++) {
        newArr[i] = x[i];
    }

    delete[] x;
    x = newArr;
}

int main() {
    int x;
    int* h[7] = {nullptr};
    int sizes[7] = {0};  

    std::cout << "Введите данные: ";
    for (int i = 0; i < 7; i++) {
        std::cin >> x;
        int index = x % 7;
        if (h[index] == nullptr) {
            add(h[index], 0);
            h[index][0] = x;
            sizes[index] = 1;
        }
        else {
            add(h[index], sizes[index]);
            h[index][sizes[index]] = x;
            sizes[index]++;
        }
    }

    std::cout << "Содержимое хэш-таблицы:\n";
    for (int i = 0; i < 7; i++) {
        std::cout << "Индекс " << i << ": ";
        if (h[i] != nullptr) {
            for (int j = 0; j < sizes[i]; j++) {
                std::cout << h[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 7; i++) {
        delete[] h[i]; 
    }

}