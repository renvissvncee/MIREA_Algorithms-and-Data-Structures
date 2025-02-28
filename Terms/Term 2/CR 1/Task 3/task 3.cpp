#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    bool last; // Проверка на то, что элемент - последний
};

void append(Node** head, int new_data) {
    Node* new_node = new Node();    
    new_node->data = new_data;
    new_node->last = 1;

    if (*head == nullptr) {
        new_node->prev = nullptr;
        new_node->next = nullptr;
        *head = new_node;
        return;
    }

    // Находим последний узел в списке, чтобы после него добавить новый элемент
    Node* element = *head;
    element->prev = new_node;
    new_node->next = element;
    while (element->last == 0) {
        element = element->next;
    }
    element->next = new_node;
    element->last = 0;
    new_node->prev = element;
}

void display_list(Node* list) {
    if (list->last == 1) {
        std::cout << list->data;
    }
    else {
        while (list->last == 0) {
            std::cout << list->data;
            list = list->next;
            std::cout << " <-> ";
        }
        std::cout << list->data << "\n";

    }
}

// Удаление узла по значению
void delete_element(Node* list, int value) {
    // Доходим до нужного узла
    Node* element = list;
    while (element->data != value) {
        element = element->next;
    }
    
    // Меняем поле next предыдущего узла на следующий после найденного элемента узел
    element->prev->next = element->next;
    if (element->last == 1) {
        element->prev->last = 1;
    }
    delete element;
}

bool is_circular(Node* list) {
    Node* first_element = list;
    Node* last_element = list;

    while (last_element->last == 0 && last_element->next) {
        last_element = last_element->next;
    } 
    if (last_element->next == first_element && first_element->prev == last_element) {
        return true;
    }
    return false;
}

int main() {
    std::cout << "Список:\n";
    Node* list = nullptr;
    append(&list,1);
    append(&list,2);
    append(&list,3);
    append(&list,4);
    display_list(list);

    std::cout << "Удалим элемент 2:\n";
    delete_element(list, 2);
    display_list(list);

    std::cout << "Список цикличен?: ";
    std::cout << is_circular(list);
    return 0;
}