#include <iostream>
#include <ctime>

struct Node {
public:
    int key;
    Node* next;
};

Node* newNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->next = nullptr;

    return node;
}

Node* constructList(int n) {
    std::srand(time(0));
    if (n == 0) {
        Node* head = nullptr;
        return head;
    }
    Node* head = newNode(rand());
    Node* last = head;
    for (int i = 0; i < n - 1; i++) {
        Node* new_node = newNode(rand());
        last->next = new_node;
        last = new_node;
    }
    return head;
}

void PrintList(Node* head) {
    Node* curr = head;  
    while (curr) {
        std::cout << curr->key << " ";
        curr = curr->next;
    }
}
    
int main() {
    srand(time(0));
    int len = rand();
    Node* List = constructList(len);

    int sum = 0;
    Node* curr = List;
    for (int i = 0; i < len; i++) {
        sum += List->key;
    }
    std::cout << sum;
    return 0;
}