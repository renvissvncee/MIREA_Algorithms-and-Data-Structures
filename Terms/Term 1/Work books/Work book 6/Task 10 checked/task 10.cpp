#include <queue>
#include <fstream>
#include <ctime>
#include <string>
#include <iostream>

int main() {
    srand(time(0));

    std::ofstream out;  
    out.open("text.txt");  
    if (out.is_open()) {
        for (int i = 0; i < 50; i++) {
            out << rand() % 300 << std::endl;
        }
    }
    out.close();

    std::ifstream in("text.txt");
    std::queue<int> q1;
    std::queue<int> q2;
    std::string str;

    if (in) {
        while (std::getline(in, str)) {
            q1.push(stoi(str));
        }
    }
    in.close();

    while (!q1.empty()) {
        if (q1.front() < 10) {
            std::cout << q1.front() << " ";
            q1.pop();
        }
        else if (q1.front() > 99) {
            q1.pop();
        }
        else {
            q2.push(q1.front());
            q1.pop();
        }
    }

    while (!q2.empty()) {
        std::cout << q2.front() << " ";
        q2.pop();
    }


}