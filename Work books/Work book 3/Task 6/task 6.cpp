#include <iostream>
#include <cmath>

double f(float A, float B, float x) {
    return A - B*x;
}

int main() {
    double A, B, E;
    std::cout << "Введите делимое: ";
    std::cin >> A;
    std::cout << std::endl;
    std::cout << "Введите делитель: ";
    std::cin >> B;
    std::cout << std::endl;

    std::cout << "Введите точность: ";
    std::cin >> E;
    std::cout << std::endl;

    double R = A, L = 0;
    int iter = 0; //кол-во итераций
    
    while (fabs(L - R) > E && iter < 10000) {
        iter++;
        double mid = L + (R-L)/2;
        if (f(A, B, mid) * f(A, B, L) > 0) {
            L = mid;
        } 
        else {
            R = mid;
        }
    }
    int q, r;
    if (f(A,B, floor(L)) < B) {
        q = floor(L);
        r = f(A, B, q);
    }
    else {
        q = ceil(L);
        r = f(A, B, q);
    }
    std::cout << "Частное: " << q << std::endl << "Остаток: " << r;
    return 0;
}