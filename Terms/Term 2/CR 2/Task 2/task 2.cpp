#include <iostream>
#include <vector>

struct Node {
    int key;
    int balance;
    Node* left;
    Node* right;
};

Node* CreateNode(int value) {
    Node* newNode = new Node;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->key = value;
    newNode->balance = 0;
    return newNode;
}

void insertNode (Node** root, int value) {
    if (!(*root)) {
        *root = CreateNode(value);
        return;
    }
    if (value < (*root)->key) {
        insertNode(&((*root)->left), value);
        return;
    }
    else if (value > (*root)->key) {
        insertNode(&((*root)->right), value);
        return;
    }
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
        root->balance = height(root->right) - height(root->left);
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

void RightTurn(Node** root) {
    if (*root) {
        Node* tempNode_tree = *root;
        Node* tempNode_son;
        if ((*root)->left->right) {
            tempNode_son = (*root)->left->right;
        }
        else {
            tempNode_son = nullptr;
        }
        (*root) = (*root)->left;
        tempNode_tree->left = tempNode_son;
        (*root)->right = tempNode_tree;
    }
}

void LeftTurn(Node** root) {
    if (*root) {
        Node* tempNode_tree = *root;
        Node* tempNode_son;
        if ((*root)->right->left) {
            tempNode_son = (*root)->right->left;
        }
        else {
            tempNode_son = nullptr;
        }
        (*root) = (*root)->right;
        tempNode_tree->right = tempNode_son;
        (*root)->left = tempNode_tree;
    }
}

void SetBalance(Node** root) {
    if (!*root) {
        return;
    }
    if ((*root)->balance == -2 && (*root)->left->balance == -1) {
        RightTurn(root);
    }
    else if ((*root)->right && (*root)->balance == 2 && (*root)->right->balance == 1) {
        LeftTurn(root);
    }
    else if ((*root)->left && (*root)->left->right && (*root)->balance == -2 
            && (*root)->left->balance == 1 && (*root)->left->right->balance == -1) {
        LeftTurn(&((*root)->left));
        RightTurn(root);
    }
    else if ((*root)->right && (*root)->right->left && (*root)->balance == 2 
            && (*root)->right->balance == -1 && (*root)->right->left->balance == 1) {
        RightTurn(&((*root)->right));
        LeftTurn(root);
    }
    SetBalance(&((*root)->left));
    SetBalance(&((*root)->right));
}

void CreateTree(Node** root, std::vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        insertNode(root, arr[i]);
        CheckBalance(*root);
        SetBalance(root);
        CheckBalance(*root);
    }

}

int main() {
    // Создадим дерево
    Node* tree = nullptr;
    std::vector<int> arr = {1,2,3,4,5,6,7};
    CreateTree(&tree, arr);
    inOrder(tree);
    std::cout << "\n";

    return 0;
}