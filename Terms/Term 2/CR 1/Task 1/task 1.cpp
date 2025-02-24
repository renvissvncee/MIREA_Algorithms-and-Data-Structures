#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void append(Node** head, int new_data) {
    Node* new_node = new Node();    
    Node* last = *head;
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head == nullptr) {
        new_node->prev = nullptr;
        *head = new_node;
        return;
    }

    // Находим последний узел в списке, чтобы после него добавить новый элемент
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

bool is_break(Node* list) {
    if (list == nullptr || list->next = nullptr) {return false;} 
    // Создаем два указателя, один из которых за одну итерацию переходит в следующий
    // элемент (т.е. медленный), а другой переходит сразу 2 элемента, а не один
    // (т.е. быстрый). Если в списке будет "перескок", то эти указатели войдут в цикл
    // и неизбежно в какой-то момент станут указывать на один и тот же элемент.
    Node* slow_ptr = list;
    Node* fast_ptr = list;

    while (fast_ptr->next != nullptr && fast_ptr->next->next != nullptr) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (fast_ptr == slow_ptr) {return true;}
    }
    // Если медленный указатель не вошел в "цикл", то значит перескока не было.
    return false;
}

int main() {
    Node* list = NULL;
    append(&list, 3);
    return 0;
}