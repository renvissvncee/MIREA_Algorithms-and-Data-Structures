#include <iostream>
#include <string>
#include <utility>
template <typename T>
class Hash_Table {
private:
    int size = 1; // размер хеш-таблицы
    int quantity = 0; // кол-во элементов в хеш-таблице
    int* amounts; // кол-во элементов в ячейке хэш-таблицы    
    T*** table;

    // увеличение кол-ва ячеек хеш-таблицы в 2 раза
    void increase() {
        int* new_amounts = new int[size * 2];
        T*** new_table = new T**[size * 2]();
                                                                                    
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr) {
                for (int j = 0; j < amounts[i]; j++) {
                    add_element(table[i][j][0], [i][j][1]);
                    new_amounts[hash_function(Arr[i][j][0])]++;
                }i
            }
        }

        delete[] amounts;
        amounts = new_amounts;

        delete[] Arr;
        table = newArr;
    }

    // увеличение кол-ва элементов в массиве на 1
    void add(int*& Arr, int len) {
        int* newArr = new int[len + 1];
        // в новый список добавляем элементы (индекс может поменяться)
        for (int i = 0; i < len; i++) {
            newArr[i] = Arr[i];
        }

        delete[] Arr;
        Arr = newArr;
    }

    unsigned int hash_function(char *s) {
        unsigned int h = 0; 
        char *p; 

        for (p = s; *p != '\0'; p++) { 
            h = h * 31 + (unsigned int)*p; 

        }

        return h % size; 
    }

    unsigned int hash_function(int key) {
        return key % size;
    }

public:

    Hash_Table() {
        size = 1;
        quantity = 0;
        amounts = new int[size];
        table = new T**[size]();
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr) {
                delete[] table[i];  // Освобождаем память для массива из двух элементов
            }
        }
        delete[] table;  // Освобождаем память для массива указателей
    }

    void add_element(T key, std::string value) {
        unsigned int index = hash_function(key);
        if (quantity == size) {
            increase();
        }

        add(table[index], amounts[index]);
        amounts[index]++;
        quantity++;
    }
    
}

int main() {

    return 0;
}