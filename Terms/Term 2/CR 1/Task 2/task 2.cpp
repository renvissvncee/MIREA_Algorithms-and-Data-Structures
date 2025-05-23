#include <iostream>

struct Node {
    int data;
    Node* next;
};

void append(Node** head, int new_data) {
    Node* new_node = new Node();    
    Node* last = *head;
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head == nullptr) {
        *head = new_node;
        return;
    }

    // Находим последний узел в списке, чтобы после него добавить новый элемент
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

void display_list(Node* list) {
    while (list != nullptr) {
        std::cout << list->data;
        list = list->next;

        if (list != nullptr) {
            std::cout << " -> ";
        }
    }
}

std::pair<Node*, Node*> list_split(Node* list, int sep) {
    // Есть 3 указателя: первый (list) указывает на элемент исходного списка, который мы рассматриваем
    // Второй будет указывать на начало списка, в котором все числа меньше sep
    // Второй будет указывать на начало списка, в котором все числа больше либо равны sep
    Node* new_list1 = nullptr;
    Node* new_list2 = nullptr;

    while (list != nullptr) {
        // Каждый раз, "рассматривая" новый элемент исходного списка, будем создавать указатель
        // на этот элемент для того, чтобы после копирования значения исходного элемента в 
        // один из новых списков, удалить этот элемент в исходном списке.
        Node* temp_element = list;
        if (list->data < sep) {
            append(&new_list1, list->data);
        }
        else {
            append(&new_list2, list->data);
        }

        // Переходим "рассматривать" следующий элемент
        list = list->next;
        // и удаляем прошлый
        delete temp_element;
    }

    return {new_list1, new_list2};
}

int main() {
    Node* list = NULL;
    for (int i = 0; i < 20; i++) {
        append(&list, i);
    }
    
    std::cout << "Список: " << "\n";
    display_list(list);

    int X;
    std::cout << "\nВведите разделитель: ";
    std::cin >> X;

    std::pair<Node*, Node*> pair_of_lists = list_split(list, X);
    display_list(pair_of_lists.first);
    std::cout << std::endl;
    display_list(pair_of_lists.second);

    return 0;
}