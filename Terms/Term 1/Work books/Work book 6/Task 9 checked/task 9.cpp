#include <stack>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::stack<char> st;
    std::ifstream file("text.txt");
    std::string str;
    while (std::getline(file, str)) {
        for (int i = 0; i < str.length(); i++) {
            st.push(str[i]);
        }

        while (!st.empty()) {
            std::cout << st.top();
            st.pop();
        }
        std::cout << "\n";
    }
    file.close();
    

    return 0;
}