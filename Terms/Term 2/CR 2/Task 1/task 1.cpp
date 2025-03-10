#include <iostream>

struct Node {
    int key;
    int balance;
    Node* left;
    Node* right;
};

// Создание узла дерева
Node* createNode(int value, int balance_value, Node* left = nullptr, Node* right = nullptr) {
    Node* newNode = new Node;
    newNode->key = value;
    newNode->balance = balance_value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

// Прохождение по каждому узлу дерева и нахождение его высоты
int height(Node* root) {
    if (root) {
        return std::max(height(root->left), height(root->right)) + 1;
    }
    else {return -1;} 
}

// Прохождение по каждому узлу дерева и нахождение его "баланса"
void CheckBalance(Node* root) {
    if (!root->left && !root->right) {
        root->balance = 0;
    }
    else if (root->left && !root->right){
        root->balance = height(root->left) + 1;
        CheckBalance(root->left);
    }
    else if (!root->left && root->right){
        root->balance = height(root->right) + 1;
        CheckBalance(root->right);
    }
    else {
        root->balance = abs(height(root->right) - height(root->left));
        CheckBalance(root->left);
        CheckBalance(root->right);
    }

}

// Симметричный обход дерева
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        std::cout << root->key << "(" << root->balance << ") ";
        inOrder(root->right); 
    }
}

int main() {
    // Создадим дерево
    Node* root = createNode(30, 0,createNode(20, 0, createNode(10, 0, createNode(5, 0)), createNode(25, 0)),
    createNode(40, 0, nullptr, createNode(50, 0)));

    std::cout << "Дерево до установки 'баланса' каждого узла (он указан в скобках):\n";
    inOrder(root);

    std::cout << "\nДерево после установки 'баланса' каждого узла (он указан в скобках):\n";
    CheckBalance(root);
    inOrder(root);

    return 0;
}