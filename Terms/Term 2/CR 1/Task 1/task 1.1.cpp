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

    // Если список пустой
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
    if (list == nullptr || list->next == nullptr) {return false;} 

    // Создадим два указателя, которые указывают на два идущих подряд элемента
    Node* element1 = list;
    Node* element2 = list->next;

    while (element2 != nullptr && element2->next != nullptr) {
        // Если случится так, что предыдущий от element2 элемент указывает не на
        // element1, значит, произошел перескок
        if (element1 != element2->prev) {
            return true;
        }
        element1 = element1->next;
        element2 = element2->next;
    }
    return false;
}

int main() {
    Node* break_list = NULL;
    for (int i = 1; i < 6; i++) {
        append(&break_list, i);
    }

    // Проверим на "сломанность":
    std::cout << "Изначальный список сломан?: " << is_break(break_list) << "\n";

    // Сделаем так, чтобы 3 элемент указывал вперед не на 4-ый, а на 1-ый
    Node* broke_element = break_list->next->next->next;
    broke_element->next = break_list;
    std::cout << "Измененный список сломан?: " << is_break(break_list);
    
    return 0;
}