#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    bool last; // Проверка на то, что элемент - последний
};

void Append(Node** head, int new_data) {
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

void DisplayList(Node* list) {
    if (!list) {
        std::cout << "Список пуст";
        return;
    }

    while (list->last == 0) {
        std::cout << list->data;
        list = list->next;
        std::cout << " <-> ";
    }
    std::cout << list->data << "\n";
}

void ReversedDisplayList(Node* list) {
    if (!list) {
        std::cout << "Список пуст";
        return;
    }

    if (list->last == 1) {
        std::cout << list->data << "\n";
        return;
    }

    list = list->prev;
    while (list->prev->last != 1) {
        std::cout << list->data;
        list = list->prev;
        std::cout << " <-> ";
    }
    std::cout << list->data << "\n";
}

// Удаление узла по значению
void DeleteNode(Node* list, int value) {
    // Доходим до нужного узла
    Node* element = list;
    while (element->data != value) {
        element = element->next;
    }
    
    // Меняем поле next предыдущего узла на следующий после найденного элемента узел
    element->prev->next = element->next;
    element->next->prev = element->prev;
    if (element->last == 1) {
        element->prev->last = 1;
    }
    delete element;
}

int ListCount(Node* head) {
    int c = 0;
    if (!head) {
        return 0;
    }

    if (head->last == 1) {
        return 1;
    }

    while (head->last == 0) {
        c++;
        head = head->next;
    }
    return c + 1;
}

void Insert(Node** head, int before, int x) {
    if (!(*head)) {
        std::cout << "Список пуст";
        return;
    }

    Node* curr = *head;
    // Дойдем до элемента, перед которым нужно вставить x
    while (curr->last != 1 && curr->data != before) {
        curr = curr->next;
    }

    if (curr->data != before) {
        std::cout << "Элемент не найден\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;
    newNode->last = 0;
    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;

    if (curr == *head) {
        *head = newNode;
    }
}

int main() {
    std::cout << "Создадим список из 1,2,3,4:\n";
    Node* list = nullptr;
    Append(&list,1);
    Append(&list,2);
    Append(&list,3);
    Append(&list,4);
    Append(&list,5);
    DisplayList(list);

    std::cout << "Удалим 2:\n";
    DeleteNode(list, 2);
    DisplayList(list);

    std::cout << "Вставим перед тройкой шестерку:\n";
    Insert(&list, 3, 6);
    DisplayList(list);

    std::cout << "Подсчет кол-ва узлов: " << ListCount(list) << "\n";

    std::cout << "Вывод списка в обратном порядке:\n";
    ReversedDisplayList(list);
    return 0;
}