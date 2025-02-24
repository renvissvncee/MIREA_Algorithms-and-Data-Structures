#include <iostream>

int main() {
    int N;
    std::cout << "длина N массива A: ";
    std::cin >> N;
    int A[N], B[N];

    std::cout << "элементы массива A: ";
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int s;
    B[0] = A[0];
    for (int i = 1; i < N; i++) {
        B[i] = B[i-1] * A[i];
    }

    for (int i = 0; i < N; i++) {
        std::cout << B[i] << " ";
    }

    return 0;
}