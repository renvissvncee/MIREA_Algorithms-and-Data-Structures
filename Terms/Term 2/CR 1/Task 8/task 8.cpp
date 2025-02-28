#include <iostream>

struct Node {
    int KeyMin; // Минимальный ключ вершины.
    int KeyMax; // Максимальный ключ вершины.
    Node *Left; // Указатель на левое поддерево.
    Node *Right; // Указатель на правое поддерево.
};

Node* buildTree(int B, int E) {
    Node* newNode = new Node;
    newNode->KeyMax = std::max(B, E);
    newNode->KeyMin = std::min(B, E);
    if ((newNode->KeyMax - newNode->KeyMin) > 1) {
        newNode->Left = buildTree(newNode->KeyMin, (B + E) / 2);
        newNode->Right = buildTree((B + E) / 2, newNode->KeyMax);
    }
    else {
        newNode->Left = nullptr;
        newNode->Right = nullptr;
    }
    return newNode;
}

int count(Node* tree, int X) {
    int c = 0;
    if (tree && tree->KeyMax > X && tree->KeyMin < X) {
        c++;
        c += count(tree->Left, X);
        c += count(tree->Right, X);
    }
    return c;
}

void display(Node* root) {
    if (root) {
        std::cout << "(" << root->KeyMin << ";" << root->KeyMax << ") ";
        display(root->Left);
        display(root->Right);
    }
}

int main() {
    int b, r, X;
    std::cout << "Введите начало и конец интервала: ";
    std::cin >> b >> r;
    std::cout << "Построим дерево:\n";
    Node* tree = buildTree(b, r);
    display(tree);
    std::cout << "\nВведите точку X, которую нужно подсчитать: ";
    std::cin >> X;
    std::cout << "Кол-во точек X: ";
    std::cout << count(tree, X);
    return 0;
}