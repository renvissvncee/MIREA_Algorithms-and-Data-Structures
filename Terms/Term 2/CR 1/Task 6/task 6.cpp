#include <iostream>

// Структура узла двоичного дерева
struct Node {
    int data;
    Node* left;
    Node* right;
    int count;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->data = value;
    newNode->count = 1;
    return newNode;
}

// Функция добавления узла в дерево
void insertNode (Node** root, int value) {
    if (!*root) {
        *root = createNode(value);
        return;
    }
    if (value < (*root)->data) {
        insertNode(&((*root)->left), value);
        return;
    }
    else if (value > (*root)->data) {
        insertNode(&((*root)->right), value);
        return;
    }
    else {(*root)->count++;} // Если data проверяемого узла уже равна value, то увеличиваем count на 1
}

void preorder(Node* root) {
    if (root) {
        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int height(Node* tree, int c) {
    // Если корень поддерева существует, то функция возвращает максимум из
    // высоты левого и правого поддеревьев
    if (tree) {
        return std::max(height(tree->left, c + 1), height(tree->right, c + 1));
    }
    // Если поддерева нет, то функция возвращает высоту предыдущего поддерева
    else {return c - 1;}
}

bool search(Node* tree, int value) {
    if (tree) {
        // Если элемент больше данного узла, то проверяем его наличие той же функцией, но уже
        // в правом поддереве
        if (value > tree->data) {
            return search(tree->right, value);
        }
        else if (value < tree->data) {
            return search(tree->left, value);
        }
        else {
            return true;
        }
    }
    // Если так вышло, что при таком обходе дерева мы дошли до несуществующего узла,
    // значит, такого элемента нет
    else {return false;}
}

Node* max_node(Node* tree) {
    if (!tree->left && !tree->right) {return tree;}
    else if (tree->left && !tree->right) {return max_node(tree->left);}
    else if (!tree->left && tree->right) {return max_node(tree->right);}
    else {
        Node* max_left = max_node(tree->left);
        Node* max_right = max_node(tree->right);
        if (max_left->data > max_right->data)  {
            return max_left;
        }
        else {
            return max_right;
        }
    }
}

void delete_node(Node* tree, int value) {
    if (!tree) {
        std::cout << "Пустое дерево";
    }
    else if (!search(tree, value)){
        std::cout << "Элемента нет в дереве";
    }

    else {
        // Дойдем до искомого узла:
        Node* node = tree;
        Node* parent;
        while (node->data != value) {
            if (value > node->data) {
                parent = node;
                node = node->right;
            }
            else {
                parent = node;
                node = node->left;
            }
        }

        // Проверим 3 случая:
        // 1) У узла нет потомков
        if (node->left == nullptr && node->right == nullptr) {
            if (parent->right == node) {parent->right = nullptr;}
            else {parent->left = nullptr;}
            delete node;
        }

        // 2) У узла есть 2 потомка
        else if (node->left != nullptr && node->right != nullptr) {
            // 2.1) У левого потомка есть правое поддерево
            if (node->left->right) {
                // В этом случае нужно найти в этом правом поддереве 
                // наибольший элемент и вставить его вместо удаляемого узла.
                Node* max = max_node(node->left);
                node->data = max->data;
                delete max;
            }

            // 2.2) У левого потомка нет правого поддерева
            else {
                // В этом случае элемент заменяется на корень левого поддерева:
                // Создаются локальные указатели на потомков (левый, чтобы 
                // удалить узел, на который он указывает, после копирования 
                // значения в "удаляемый" элемент; правый, чтобы в новое
                // скопированное значение вставить правого предка "удаляемого" элемента)
                Node* newNode_left = node->left;
                Node* newNode_right = node->right;
                *node = *(node->left);
                node->right = newNode_right;
                delete newNode_left;
            }
        }

        // 3) У узла один потомок
        else {
            if (node->right) {
                Node* newNode = node->right;
                *node = *(node->right);
                delete newNode;
            }
            else {
                Node* newNode = node->left;
                *node = *(node->left);
                delete newNode;
            }
        }
    }
}

int main() {
    Node* tree = nullptr;
    insertNode(&tree, 4);
    insertNode(&tree, 3);
    insertNode(&tree, 2);
    insertNode(&tree, 1);
    insertNode(&tree, 6);
    insertNode(&tree, 5);
    insertNode(&tree, 7);
    preorder(tree);
    std::cout << std::endl;
    delete_node(tree, 6);
    preorder(tree);
    return 0;
}