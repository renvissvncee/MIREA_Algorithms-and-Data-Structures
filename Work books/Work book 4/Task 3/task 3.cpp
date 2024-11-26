#include <iostream>

double func(double x) {
    return (0.25*x*x*x) + x - 2;
}

double f(double L, double R, double E) {
    if (R-L < E) {
        return (R+L)/2;
    }
    if ((func((R+L)/2) * func(R)) < 0) {
        return f((R+L)/2, R, E);
    }
    else {
        return f(L, (R+L)/2, E);
    }
}

int main() {
    std::cout << f(0, 3, 0.001);
    return 0;
}