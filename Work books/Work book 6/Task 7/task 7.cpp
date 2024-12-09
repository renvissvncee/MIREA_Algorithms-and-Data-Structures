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

bool is_equal(Node* List1, Node* List2) {
    if (QuantityOfList(List1) != QuantityOfList(List2)) {
        return 0;
    }
    else {
        Node* curr_element1 = List1;
        Node* curr_element2 = List2;
        while (curr_element1->key == curr_element2->key) {
            if (curr_element1->next && curr_element2->next) {
                curr_element1 = curr_element1->next;
                curr_element2 = curr_element2->next;
            }
            else {break;}
        }
        if (curr_element1->key == curr_element2->key) {return 1;}
        else {return 0;}
    }
}

bool is_include(Node* List1, Node* List2) {
    Node* curr_element1 = new Node;
    Node* curr_element2 = new Node;
    if (QuantityOfList(List1) > QuantityOfList(List2)) {
        curr_element1 = List2;
        curr_element2 = List1;
    }
    else {
        curr_element1 = List1;
        curr_element2 = List2;
    }

    while (curr_element1) {
        int key = curr_element1->key;
        Node* temp_element = curr_element2;
        while (temp_element) {
            if (key == temp_element->key) {
                break;
            }
            if (temp_element->next) {
                temp_element = temp_element->next;
            }
            else {break;}
        }
        if (temp_element->key != key) {
            return 0;
        }
        if (curr_element1->next) {
            curr_element1 = curr_element1->next;
        }
        else {break;}
    }
    return 1;
}

int main() {
    Node* List1 = new Node;
    Node* List2 = new Node;
    List1 = constructList(0);
    List2 = constructList(0);
    add_begin(List1, 1);
    add_begin(List1, 2);
    add_begin(List2, 2);
    add_begin(List2, 0);
    PrintList(List1);
    PrintList(List2);
    std::cout << is_include(List1, List2);

}