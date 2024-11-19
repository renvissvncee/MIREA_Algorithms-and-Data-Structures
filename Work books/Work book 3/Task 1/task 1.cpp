#include <iostream>
#include <string>

int* create_number(std::string s) {
 int* num = new int[s.length()];
    for (int i = 0; i < s.length(); i++) {
    char ch = s[i];
    num[i] = ch - '0';
    }
 return num;
}

void align(int* array1, int len1, int* array2, int len2) {
    if (len1 > len2) {
        for (int i = 0; i < len2; i++) {
            array2[i+len1-len2] = array2[i];
        }
        for (int i = 0; i < len1-len2; i++) {
            array2[i] = 0;
        }
     }
    else {
        for (int i = 0; i < len1; i++) {
            array1[i+len2-len1] = array1[i];
        }
        for (int i = 0; i < len2-len1; i++) {
            array1[i] = 0;
        }
    }
}

bool compare(int* num1, int* num2, int len) {
 for (int i = 0; i < len; i++) {
 if (num1[i] < num2[i]) {
 return false;
        }
        else if (num1[i] > num2[i]) {
            return true;
        }
    }
    return false;
}

void plus(int* array1, int* array2, int len, int* x) {
    for (int i = 0; i < len; i++) {
        x[i] = 0;
    }
    int p = 0;
    for (int i = len-1; i >= 0; i--) {
        if (i - 1 >= 0) {
            x[i] = (p + array1[i-1] + array2[i-1]) % 10;
            p = (p + array1[i-1] + array2[i-1] ) / 10;
        }
        else {
            x[i] = p;
        }
    }
}

void minus(int* array1, int* array2, int len, int* x) {
    for (int i = 0; i < len; i++) {
        x[i] = 0;
    }
    for (int i = len; i >= 0; i--) {
        if (array1[i] < array2[i]) {
            int z = i - 1;
            while (array1[z] == 0) {
                z--;
            }
            array1[z] = array1[z] - 1;
            z++;
            while (array1[z] == 0 && z < i) {
                array1[z] = 9;
                z++;
            }
            x[i] = array1[i] - array2[i] + 10;
        }
        else {
            x[i] = array1[i] - array2[i];
        }
    }
}

int main() {
    std::string s;
    int num1_len, num2_len;
    // Создание первого числа
    std::cout << "Введите первое число: ";
    std::cin >> s;
    num1_len = s.length(); // длина 1-го числа
    int* num1 = create_number(s);
    
    // Второго
    std::cout << "Введите второе число: ";
    std::cin >> s;
    num2_len = s.length(); // длина 2-го числа
    int* num2 = create_number(s);
    
    if (num1_len != num2_len) {
        align(num1, num1_len, num2, num2_len);
        if (num1_len > num2_len) {
            num2_len = num1_len;
        }
        else {
            num1_len = num2_len;
        }
    }
    
    int res[num1_len + 1];
    plus(num1, num2, num1_len + 1, res);
    
    
    if (res[0] == 0) {
        for (int i = 1; i < num1_len + 1; i ++) {
            std::cout << res[i];
        }
    }
    else {
        for (int i = 0; i < num1_len + 1; i ++) {
            std::cout << res[i];
        }
    }
    
    std::cout << std::endl;
    
    if (compare(num1,num2, num1_len)) {
        // 1-ое число больше 2-го
        minus(num1, num2, num1_len, res);
    }
    else {
        minus(num2, num1, num1_len, res);
    }
    
    for (int i = 0; i < num1_len; i ++) {
            std::cout << res[i];
        }

    
    
    delete[] num1;
    delete[] num2;
    return 0;

}