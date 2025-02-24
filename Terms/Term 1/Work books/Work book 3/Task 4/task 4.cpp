#include <iostream>
#include <string>
#include <numeric>
#include <cmath>

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

std::string column_mult(std::string array1, std::string array2) {
    int len = array1.length();

    std::string s(len*2, '0');

    for (int i = len - 1; i >= 0; i--) {

        std::string inter(len + (len - i - 1), '0');
        
        int k = array2[i] - '0';
        int p = 0;  
        for (int j = len - 1; j >= 0; j--) {
            inter[j] = ((p + (array1[j] - '0')*k) % 10) + '0';
            p = (p + (array1[j] - '0')*k) / 10;
        }
        s = plus(s, inter);
    }
    return s;
}


int main() {
    std::string num1, num2;
    // Создание первого числа
    std::cout << "Введите первое число: ";
    std::cin >> num1;
    int num1_len = num1.length();
    
    // Второго
    std::cout << "Введите второе число: ";
    std::cin >> num2;
    int num2_len = num2.length();

    
    // "Выравнивание чисел"
    align(num1, num1_len, num2, num2_len);
    
    std::cout << column_mult(num1, num2);

    return 0;

}