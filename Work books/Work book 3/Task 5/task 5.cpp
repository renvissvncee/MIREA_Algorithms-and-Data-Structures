#include <iostream>
#include <string>
#include <numeric>
#include <cmath>

int* create_number(std::string s) {
    int* num = new int[s.length()];
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        num[i] = ch - '0';
    }
    return num;
}


std::string remove(const std::string& num) {
    std::string str;
    bool flag = 0;
    for (int i = 0; i < num.length(); i++) {
        if (flag == 1) 
        {
            str = str + num[i];
        }
        if (num[i] != '0' && flag == 0) {
            str = str + num[i];
            flag = 1;
        }
        if (flag == 0 && i == num.length() - 1) {
            return "0";
        }
    }
    return str;
}

void align(std::string& array1, int& len1, std::string& array2, int& len2) {
    // Определяем новую длину для обоих массивов
    int new_len = std::max(len1, len2) + 1;

    while (array1.length() < new_len) {
        array1 = '0' + array1;
    }
    while (array2.length() < new_len) {
        array2 = '0' + array2;
    }

    len1 = len2 = new_len;
}


void add(std::string& array1, std::string& array2) {
    int len = array1.length();
    std::string new_array1(len, '0');
    std::string new_array2(len, '0');
    new_array2[len - 1] = '0';
    for (int i = len - 1; i >= 0; i--) {
        int sum = (array1[i] - '0') + (array2[i] - '0');
        new_array1[i] = (sum % 10) + '0';
        if (i > 0) {
            new_array2[i - 1] = (sum / 10) + '0';
        }
    }
    array1 = new_array1;
    array2 = new_array2;
}


std::string plus(const std::string& num1, const std::string& num2) {
    std::string num1_copy = num1;
    std::string num2_copy = num2;
    int num1_len = num1_copy.length();
    int num2_len = num2_copy.length();
    
    // "Выравнивание чисел"
    align(num1_copy, num1_len, num2_copy, num2_len);

    int sum = 0;
    for (int i = 0; i < num2_len; i++) {
        sum += (num2_copy[i] - '0');
    }

    while (sum != 0) {
        sum = 0;
        add(num1_copy, num2_copy);
        for (int i = 0; i < num2_len; i++) {
            sum += (num2_copy[i] - '0');
        }
    }
    return remove(num1_copy);
}

std::string minus(const std::string& num1, const std::string& num2) {
    std::string num1_copy = num1;
    std::string num2_copy = num2;
    int num1_len = num1.length();
    int num2_len = num2.length();

    align(num1_copy, num1_len, num2_copy, num2_len);

    std::string res(num1_len, '0');

    for (int i = num1_len - 1; i >= 0; i--) {
        int f = num1_copy[i] - '0';
        int s = num2_copy[i] - '0';
        if (f < s) {
            int z = i - 1;
            while (z >= 0 && num1_copy[z] == '0') {
                num1_copy[z] = '9';
                z--;
            }
            if (z >= 0) {
                num1_copy[z] = (num1_copy[z] - '0' - 1) + '0';
            }
            f += 10;
        }
        res[i] = (f - s) + '0';
    }
    return remove(res);
}

void split(std::string s, std::string& A, std::string& B, std::string& X, int c) {
    if (c != -1) {
        while (s.length() != c) {
        s = '0' + s;
        }
    }
    if (s.length() == 1) {
        A = s;
        B = "0";
        X = "1";
    }
    else {
        X = "1";
        A = s.substr(0, s.length() / 2);
        B = remove(s.substr(s.length() / 2));
        for (int i = A.length(); i < s.length(); i++) {
            X = X + '0';
        }
    }
    
    if (A.length() != B.length()) {
        if (A.length() > B.length()) {
            B = '0' + B;
        }
        else {
            A = '0' + A;
        }
    }
    
     if (c != -1) {
        while (A.length() < c/2) {
            A = '0' + A;
        }
        while (B.length() < c/2) {
            B = '0' + B;
        }
    }
}

std::string mult(const std::string& num1, const std::string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    if (len1 == 1 && len2 == 1) {
        return std::to_string(std::stoi(num1) * std::stoi(num2));
    }
    else {
        std::string A, B, C, D, X;
        if (len1 == len2) {
            split(num1, A, B, X, -1);
            split(num2, C, D, X, -1);
        }
        else if (len1 > len2) {
            if (len1 % 2 == 0) {
                split(num1, A, B, X, -1);
                split(num2, C, D, X, len1);
            }
            else {
                split(num1, A, B, X, len1 + 1);
                split(num2, C, D, X, len1 + 1);
            }
        }
        else if (len1 < len2){
            if (len2 % 2 == 0) {
                split(num1, A, B, X, len2);
                split(num2, C, D, X, -1);
            }
            else {
                split(num1, A, B, X, len2 + 1);
                split(num2, C, D, X, len2 + 1);
            }
        }
        std::string AC = mult(A,C);
        std::string AC_X2 = AC;
        std::string BD = mult(B,D);
        std::string ABCD = mult(plus(A,B), plus(C,D));
        for (int i = 1; i < X.length(); i++) {
            AC_X2 = AC_X2 + '0' + '0';
        }
        std::string temp = minus(minus(ABCD, AC), BD);
        for (int i = 1; i < X.length(); i++) {
            temp = temp + '0';
        }
        return plus(plus(AC_X2,temp), BD);
    }
}


int main() {
    std::string s;
    // Создание первого числа
    std::cout << "Введите первое число: ";
    std::cin >> s;
    std::string num1_k = s;
    
    // Второго
    std::cout << "Введите второе число: ";
    std::cin >> s;
    std::string num2_k = s;

    std::cout << "Карацуба: " << mult(num1_k,num2_k) << std::endl;
    



    return 0;
}