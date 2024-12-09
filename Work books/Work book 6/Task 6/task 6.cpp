#include <iostream>
#include <ctime>

struct Node {
public:
    int key;
    Node* next;

};

Node* newNode(int key, Node* next_element) {
    Node* node = new Node;
    node->key = key;
    node->next = next_element;

    return node;
}

Node* constructList(int n) {
    if (n == 0) {
        Node* head = nullptr;
        return head;
    }
    else {
        std::srand(std::time(0));
        Node* head = newNode(rand(), nullptr);
        Node* last = head;
        
        
        for (int i = 0; i < n - 1; i++) {
            Node* new_node = newNode(rand(), nullptr);
            last->next = new_node;
            last = new_node;
        }
        return head;
    }
}

bool is_empty(Node* List) {
    if (List == nullptr) {
        return 1;
    }
    else {
        return 0;
    }
}

void PrintList(Node* head) {
    if (is_empty(head) == 0) {
        Node* curr = head;  
        while (curr) {
            std::cout << curr->key << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}

void add_middle(Node* Arr, int n, int key) {
    Node* curr_element = Arr; 
    int element = 0;
    while (element < n) {
        curr_element = curr_element->next;
        element++;
    }
    curr_element->next = newNode(key, curr_element->next);
}

void add_begin(Node*& Arr, int key) {
    Node* new_node = newNode(key, Arr);
    Arr = new_node;
}

void add_last(Node* Arr, int key) {
    Node* curr_element = Arr;
    while (curr_element->next != nullptr) {
        curr_element = curr_element->next;
    }
    curr_element->next = newNode(key, nullptr);
}

int QuantityOfList(Node* List) {
    int count = 0;
    Node* curr_element = List;
    while (curr_element) {
        count++;
        curr_element = curr_element->next;
    }
    return count;
}
    
Node* ExceptFirst(Node* List) {
    return List->next;
}

int main() {
    
}