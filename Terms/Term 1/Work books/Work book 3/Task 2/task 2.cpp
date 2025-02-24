#include <iostream>
#include <string>
#include <numeric>

int* create_number(std::string s) {
    int* num = new int[s.length()];
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        num[i] = ch - '0';
    }
    return num;
}

void align(int*& array1, int& len1, int*& array2, int& len2) {
    // Определяем новую длину для обоих массивов
    int new_len = std::max(len1, len2) + 1;

    // Создаем новые массивы с увеличенной длиной
    int* new_array1 = new int[new_len];
    int* new_array2 = new int[new_len];

    // заполняем новые массивы нулями
    for (int i = 0; i < new_len; i++) {
        new_array1[i] = 0;
        new_array2[i] = 0;
    }

    // Копируем старые значения в новые массивы с учетом смещения
    for (int i = 0; i < len1; i++) {
        new_array1[new_len - len1 + i] = array1[i];
    }

    for (int i = 0; i < len2; i++) {
        new_array2[new_len - len2 + i] = array2[i];
    }

    // Освобождаем старые массивы
    delete[] array1;
    delete[] array2;

    // Обновляем указатели на новые массивы и их длины
    array1 = new_array1;
    array2 = new_array2;
    len1 = len2 = new_len;
}


void add(int*& array1, int*& array2, int len) {
    int* new_array1 = new int[len];
    int* new_array2 = new int[len];
    new_array2[len - 1] = 0;
    for (int i = len - 1; i >= 0; i--) {
        new_array1[i] = (array1[i] + array2[i]) % 2;
        if (i > 0) {
            if (array1[i] + array2[i] == 2) {
                new_array2[i - 1] = 1;
            } 
            else {
                new_array2[i - 1] = 0;
            }
        }
    }
    
    // Освобождаем старые массивы
    delete[] array1;
    delete[] array2;

    // Обновляем указатели на новые массивы
    array1 = new_array1;
    array2 = new_array2;
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
    
    // "Выравнивание чисел"
    align(num1, num1_len, num2, num2_len);
    
    for (int i = 0; i < num1_len; i++) {
        std::cout << num1[i] << " ";
    }
    
    std::cout<< std::endl;
    
    for (int i = 0; i < num2_len; i++) {
        std::cout << num2[i] << " ";
    }
    
    std::cout<< std::endl;
    std::cout<< std::endl;
    
    int sum;// Сумма элементов второго числа (для проверки на окончание сложения)
    for (int i = 0; i < num2_len; i++) {
        sum = sum + num2[i];
    }
    
    while (sum != 0) {
        sum = 0;
        add(num1, num2, num1_len);
        
        for (int i = 0; i < num1_len; i++) {
            std::cout << num1[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < num2_len; i++) {
            std::cout << num2[i] << " ";
        }
        std::cout << std::endl << std::endl;
        
        for (int i = 0; i < num2_len; i++) {
            sum = sum + num2[i];
        }
        
    }
    
    

    
    delete[] num1;
    delete[] num2;
    return 0;

}