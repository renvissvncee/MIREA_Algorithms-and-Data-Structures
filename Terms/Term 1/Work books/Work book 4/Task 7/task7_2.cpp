#include <iostream>
#define size 7
uint64_t table[size];

int hash(int value) {
    return value % size;
}

void init() {
    for (int i = 0; i < size; i++) {
        table[i] = 0;
    }
}

void insert(int value) {
    int idx = hash(value);
    uint64_t *node = new uint64_t[2];
    node[0] = value;
    node[1] = table[idx];
    table[idx] = (uint64_t)node;
}

void print() {
    for (int i = 0; i < size; i++) {
        std::cout << i << ": ";
        if (table[i] == 0) {
            std::cout << "nullptr";
        } else {
            uint64_t cur = table[i];
            while (cur != 0) {
                uint64_t *node = (uint64_t *)cur;
                std::cout << node[0] << " -> ";
                cur = node[1];
            }
            std::cout << "nullptr";
        }
        std::cout << std::endl;
    }
}

int main() {
    init();
    int nums[] = {86, 90, 27, 29, 38, 30, 40};
    for (int num : nums) {
        insert(num);
    }
    print();
    return 0;
}
