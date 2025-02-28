#include <iostream>

struct Node {
    int data;
    Node* next;
};

void Append(Node** list, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next == nullptr;
    if (!(*list)) {
        *list = newNode;
        return;
    }

    Node* curr = *list;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
} 

int ListCount(Node* head) {
    int c = 0;
    if (!head) {
        return 0;
    }

    if (head->next == nullptr) {
        return 1;
    }

    while (head->next != nullptr) {
        c++;
        head = head->next;
    }
    return c + 1;
}


void ListsAlignment(Node* list1, Node* list2) {
    if (ListCount(list1) > ListCount(list2)) {
        for (int i = 0; i < ListCount(list1) - ListCount(list2); i++) {
            Append(&list2, 0);
        }
    }
    else {
        for (int i = 0; i < ListCount(list2) - ListCount(list1); i++) {
            Append(&list1, 0);
        }
    }

}

Node* ListSummation(Node* list1, Node* list2) {
    int hyphenation = 0;
    int curr_sum;
    //if (curr_sum > 9) {

    //}
}

void DisplayList(Node* list) {
    if (!list) {
        std::cout << "Список пуст";
        return;
    }

    while (list->next != nullptr) {
        std::cout << list->data;
        list = list->next;
        std::cout << " <-> ";
    }
    std::cout << list->data << "\n";
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    Append(&list1, 1);
    Append(&list1, 1);
    Append(&list1, 1);

    DisplayList(list1);
    DisplayList(list2);

    return 0;
}