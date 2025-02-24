#include <iostream>

int Dijkstra(int x) {
    if (x == 1) {
        return 1;
    }
    else if (x % 2 == 0) {
        return Dijkstra(x / 2);
    }
    else {
        return Dijkstra((x - 1) / 2) + Dijkstra(((x - 1) / 2) + 1);
    }
}


int main() {
    int x;
    std::cout << "Введите число: ";
    std:: cin >> x;

    std::cout << Dijkstra(x);
    return 0;
}