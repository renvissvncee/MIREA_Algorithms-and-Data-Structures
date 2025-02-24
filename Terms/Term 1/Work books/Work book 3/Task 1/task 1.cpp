#include <iostream>
#include <string>

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

bool compare(std::string num1, std::string num2) {
    int len = num1.length();
    for (int i = 0; i < len; i++) {
        if ((num1[i] - '0') < (num2[i] - '0')) {
            return false;
        }
        else if ((num1[i] - '0') > (num2[i] - '0')) {
            return true;
        }
    }
    return false;
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
    int len = num1_copy.length();
    std::string s(len, '0');
    for (int i = 0; i < len; i++) {
        s[i] = '0';
    }
    for (int i = len - 1; i >= 0; i--) {
        if ((num1_copy[i] - '0') < (num2_copy[i] - '0')) {
            int z = i - 1;
            while (num1_copy[z] == '0' && z >= 0) {
                z--;
            }
            num1_copy[z] = ((num1_copy[z] - '0') - 1) + '0';
            z++;
            while (num1_copy[z] == '0' && z < i) {
                num1_copy[z] = '9';
                z++;
            }
            s[i] = ((num1_copy[i] - '0') - (num2_copy[i] - '0') + 10) + '0';
        }
        else {
            s[i] = ((num1_copy[i] - '0') - (num2_copy[i] - '0')) + '0';
        }
    }
    return remove(s);
}

int main() {
    std::string s1, s2;
    // Создание первого числа
    std::string num1;
    std::cout << "Введите первое число: ";
    std::cin >> s1;
    int num1_len;
    if (s1[0] == '-') {
        num1 = s1.substr(1, s1.length() - 1);
        num1_len = num1.length();
    }
    else {
        num1 = s1;
        num1_len = num1.length();
    }
    
    // Второго
    std::string num2;
    std::cout << "Введите второе число: ";
    std::cin >> s2;
    int num2_len;
    if (s2[0] == '-') {
        num2 = s2.substr(1, s2.length() - 1);
        num2_len = num2.length();
    }
    else {
        num2 = s2;
        num2_len = num2.length();
    }
    align(num1, num1_len, num2, num2_len);
    if (s1[0] == '-' && s2[0] == '-') {
        std::cout << "Сложение: -" << plus(num1, num2) << std::endl;
        std:: cout << "Вычитание: ";
        if (compare(num1, num2)) {
            std::cout << minus(num1, num2);
        }
        else {
            std::cout << minus(num2, num1);
        }
    }
    else if (s1[0] != '-' && s2[0] == '-') {
        std::cout << "Сложение: -";
        if (compare(num1, num2)) {
            std::cout << minus(num1, num2);
        }
        else {
            std::cout << minus(num2, num1);
        }
        std::cout << std::endl << "Вычитание: " << plus(num1, num2) << std::endl;
    }
    else if (s1[0] == '-' && s2[0] != '-') {
        std::cout << "Сложение: -";
        if (compare(num1, num2)) {
            std::cout << minus(num1, num2);
        }
        else {
            std::cout << minus(num2, num1);
        }
        std::cout << std::endl << "Вычитание: " << plus(num1, num2);
    }
    else {
        std::cout << "Сложение: " << plus(num1, num2) << std::endl;
        std:: cout << "Вычитание: ";
        if (compare(num1, num2)) {
            std::cout << minus(num1, num2);
        }
        else {
            std::cout << minus(num2, num1);
        }
    }

}