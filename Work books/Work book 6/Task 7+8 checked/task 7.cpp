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

void add_last(Node*& Arr, int key) {
    if (Arr == nullptr) {add_begin(Arr, key);}
    else {
        Node* curr_element = Arr;
        while (curr_element->next != nullptr) {
            curr_element = curr_element->next;
        }
        curr_element->next = newNode(key, nullptr);
    }
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
    Node* curr_element1 = List1;
    Node* curr_element2 = List2;
    if (QuantityOfList(List1) > QuantityOfList(List2)) {
        return 0;
    }
    else {
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
}

bool TwoIdentical(Node* List) {
    Node* curr_element = List;
    while (curr_element) {
        Node* temp_element = curr_element->next;
        while(temp_element) {
            if (temp_element->key == curr_element->key) {
                return 1;
            }
            temp_element = temp_element->next;
        }
        if (curr_element->next->next) {curr_element = curr_element->next;}
        else {return 0;}
    }
    return 0;
}

void FirstToEnd(Node*& List) {
    Node* first_element = newNode(List->key, nullptr);
    Node* second_element = List->next;
    Node* curr_element = List;
    while (curr_element->next) {
        curr_element = curr_element->next;
    }
    curr_element->next = first_element;
    List = second_element;
}

void LastToBegin(Node*& Last) {
    Node* curr_element = Last;
    while (curr_element->next->next) {
        curr_element = curr_element->next;
    }
    Node* last_element = newNode(curr_element->next->key, Last);
    curr_element->next = nullptr;
    Last = last_element;
}

void MergeLists(Node* List1, Node* List2) {
    Node* curr_element = List2;
    Node* addList = constructList(0);
    while (curr_element->next) {
        add_last(addList, curr_element->key);
        curr_element = curr_element->next;
    }
    add_last(addList, curr_element->key);
    curr_element = List1;
    while (curr_element->next) {
        curr_element = curr_element->next;
    }
    curr_element->next = addList;
}

void ListReverse(Node*& List) {
    Node* temp_element = List->next->next;
    Node* curr_element = List->next;
    Node* prev_element = List;
    List->next = nullptr;
    while (temp_element->next) {
        curr_element->next = prev_element;
        prev_element = curr_element;
        curr_element = temp_element;
        temp_element = curr_element->next;
    }
    curr_element->next = prev_element;
    temp_element->next = curr_element;
    List = temp_element;
}

Node* NoRepeat(Node* List) {
    Node* Arr = new Node; 
    Arr = constructList(0);
    add_last(Arr, List->key);

    Node* curr_element = List->next;
    while(curr_element) {
        bool flag = 1;
        int curr_key = curr_element->key;

        Node* temp_element = Arr;
        while (temp_element) {
            int temp_key = temp_element->key;
            if (temp_key == curr_key) {
                flag = 0;
                break;
            }
            temp_element = temp_element->next;
        }

        if (flag == 1) {
            add_last(Arr, curr_key);
        }

        curr_element = curr_element->next;
    }
    return Arr;
}

void Shift(Node*& List, int n, char ch) {
    if (ch == 'l') {
        for (int i = 0; i < n; i++) {
            FirstToEnd(List);
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            LastToBegin(List);
        }
    }
}

int main() {
    Node* List1 = constructList(0);;
    Node* List2 = constructList(0);
    Node* List3 = constructList(0);

    for (int i = 0; i < 5; i++) {
        add_begin(List1, i);
        add_begin(List2, i);
        add_begin(List3, i);
    }
    add_begin(List3, rand());
    std::cout << "Списки:\n";
    PrintList(List1);
    PrintList(List2);
    PrintList(List3);
    std::cout << std::endl;

    std::cout << "Проверка на равенство\n";
    std::cout << is_equal(List1, List2) << " " << is_equal(List1, List3) << "\n\n";

    std::cout << "Проверка на вхождение\n";
    std::cout << is_include(List1, List2) << " " << is_include(List1, List3) << " " << is_include(List3, List1) << "\n\n";

    add_begin(List2, 0);
    std::cout << "Есть ли одинаковые элементы \n";
    std::cout << TwoIdentical(List1) << " " << TwoIdentical(List2) << "\n\n";

    std::cout << "Списки:\n";
    PrintList(List1);
    PrintList(List2);
    PrintList(List3);
    std::cout << std::endl;

    std::cout << "Первый в конец\n";
    FirstToEnd(List1);
    PrintList(List1);
    std::cout << std::endl;

    std::cout << "Последний в начало\n";
    LastToBegin(List1);
    PrintList(List1);
    std::cout << std::endl;

    std::cout << "Добавление к списку List1 списка List2\n";
    MergeLists(List1, List2);
    PrintList(List1);
    std::cout << std::endl;

    std::cout << "Перевернутые списки\n";
    ListReverse(List1);
    ListReverse(List2);
    PrintList(List1);
    PrintList(List2);
    std::cout << std::endl;

    std::cout << "Только первые вхождения\n";
    PrintList(NoRepeat(List1));
    PrintList(NoRepeat(List2));
    PrintList(NoRepeat(List3));
    std::cout << std::endl;

    std::cout << "Списки:\n";
    PrintList(List1);
    PrintList(List2);
    PrintList(List3);
    std::cout << std::endl;

    std::cout << "Циклический сдвиг\n";
    Shift(List2, 2, 'l');
    Shift(List3, 2, 'r');
    PrintList(List2);
    PrintList(List3);
    std::cout << std::endl;
}