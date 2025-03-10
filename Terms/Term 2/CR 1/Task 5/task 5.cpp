#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
};

void Append(Node** list, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (!(*list)) {
        *list = newNode;
        return;
    }

    Node* curr = *list;
    while (curr->next) {
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


void ListsAlignment(Node** list1, Node** list2) {
    int diff = abs(ListCount(*list1) - ListCount(*list2));
    if (ListCount(*list1) > ListCount(*list2)) {
        for (int i = 0; i < diff; i++) {
            std::cout << i << "\n";
            Append(list2, 0);
        }
        return;
    }
    else {
        for (int i = 0; i < diff; i++) {
            Append(list1, 0);
        }
        return;
    }
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

Node* ListSummation(Node* list1, Node* list2) {
    int curr_sum, hyphenation = 0;
    Node* newNode = new Node;
    newNode = nullptr;

    if (ListCount(list2) > ListCount(list1)) {
        Node* tempNode = list1;
        list1 = list2;
        list2 = tempNode;
    }

    while (list2) {
        curr_sum = hyphenation + list2->data + list1->data;
        Append(&newNode, (curr_sum) % 10);
        hyphenation = (curr_sum) / 10;
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 == nullptr && list2 == nullptr) {
        Append(&newNode, hyphenation);
        return newNode;
    }
    while (list1) {
        curr_sum = hyphenation + list1->data;
        Append(&newNode, curr_sum % 10);
        hyphenation = (curr_sum) / 10;
        list1 = list1->next;
    }
    if (hyphenation != 0) {
        Append(&newNode, hyphenation);
        return newNode;
    }

    return newNode;
}

void ReversedDisplayList(Node* list) {
    std::vector<int> arr;
    if (!list) {
        std::cout << "Список пуст\n";
        return;
    }

    while (list) {
        arr.push_back(list->data);
        list = list->next;
    }
    int i = arr.size() - 1;
    while (i > 0) {
        std::cout << arr[i] << " -> ";
        i--;
    }
    std::cout << arr[i] << "\n";
}


int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    Append(&list2, 9);
    Append(&list2, 9);
    Append(&list1, 9);
    ReversedDisplayList(list1);
    std::cout << "+\n";
    ReversedDisplayList(list2);
    std::cout << "--------------------------\n";
    ReversedDisplayList(ListSummation(list1, list2));

    return 0;
}