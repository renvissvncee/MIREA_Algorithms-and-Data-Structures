#include <iostream>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
    char color;
};

Node* CreateNode(int value, Node* parent = nullptr) {
    Node* newNode = new Node;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->key = value;
    newNode->color = 'r';
    newNode->parent = parent;
    return newNode;
}

void RightTurn(Node*& root) {
    if (root) {
        Node* tempNode_tree = root;
        Node* tempNode_son;
        if (root->left->right) {
            tempNode_son = root->left->right;
            tempNode_son->parent = tempNode_tree;
        }
        else {
            tempNode_son = nullptr;
        }
        root = root->left;
        root->parent = tempNode_tree->parent;
        tempNode_tree->parent = root;
        tempNode_tree->left = tempNode_son;
        root->right = tempNode_tree;
    }
}

void LeftTurn(Node*& root) {
    if (root) {
        Node* tempNode_tree = root;
        Node* tempNode_son;
        if (root->right->left) {
            tempNode_son = root->right->left;
            tempNode_son->parent = tempNode_tree;
        }
        else {
            tempNode_son = nullptr;
        }
        root = root->right;
        root->parent = tempNode_tree->parent;
        tempNode_tree->parent = root;
        tempNode_tree->right = tempNode_son;
        root->left = tempNode_tree;
    }
}

void SetBalance(Node*& node, Node*& root) {
    if (node->parent == nullptr) {
        node->color = 'b';
        return;
    }

    if (node->parent->color == 'r') {
        Node* f = node->parent;
        Node* g = f->parent;
        Node* u;
        std::cout << "\n" << node->key << " " << f->key << " " << g->key << "\n";
        if (g->left && g->left != f) {
            u = g->left;
        }
        else if (g->left && g->left == f) {
            u = g->right;
        }
        else {
            u = nullptr;
        }

        // Случай 1ы
        if (u && u->color == 'r') {
            f->color = 'b';
            u->color = 'b';
            if (g->parent) {
                g->color = 'r';
            }
            SetBalance(g, root);
            return;
        }

        // "Левый" случай
        if (g->left == f) {
            // Случай 2
            if ((!u || u->color == 'b') && (f->left == node)) {
                f->color = 'b';
                g->color = 'r';
                if (g->parent) {
                    RightTurn(g->parent->left == g ? g->parent->left : g->parent->right);
                }
                else {
                    RightTurn(root);
                }
                return;
            }

            // Случай 3
            if ((!u || u->color == 'b') && (f->right == node)) {
                node->color = 'b';
                g->color = 'r';
                // Левый и правый поворот (с учетом того, что в функцию поворота на вход
                //подается указатель на "ребенка", а не просто его копия)
                LeftTurn((f->parent)->left);
                if (g->parent) {
                    RightTurn(g->parent->left == g ? g->parent->left : g->parent->right);
                }
                else {
                    RightTurn(root);
                }
            }
        }
        // "Правый" (симметричный "левому") случай
        if (g->right == f) {
            // Случай 2
            if ((!u || u->color == 'b') && (f->right == node)) {
                f->color = 'b';
                g->color = 'r';
                if (g->parent) {
                    LeftTurn(g->parent->left == g ? g->parent->left : g->parent->right);
                }
                else {
                    LeftTurn(root);
                }
                return;
            }

            // Случай 3
            if ((!u || u->color == 'b') && (f->left == node)) {
                node->color = 'b';
                g->color = 'r';
                RightTurn((f->parent)->left);
                if (g->parent) {
                    LeftTurn(g->parent->left == g ? g->parent->left : g->parent->right);
                }
                else {
                    LeftTurn(root);
                }
                return;
            }
        }
    }
}

void insertNode (Node** root, Node* parent, int value, Node*& tree) {
    if (!(*root)) {
        (*root) = CreateNode(value, parent);
        SetBalance((*root), tree);
        return;
    }
    if (value < (*root)->key) {
        insertNode(&((*root)->left), (*root), value, tree);
        return;
    }
    else if (value > (*root)->key) {
        insertNode(&((*root)->right), (*root), value, tree);
        return;
    }
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        std::cout << root->key << "(" << root->color << ") ";
        inOrder(root->right); 
    }
}

int main() {
    Node* tree = nullptr;
    std::vector<int> Arr = {4, 38, 29, 48, 22, 30, 36, 33, 5, 37};
    for (int i = 0; i < Arr.size(); i++) {
        insertNode(&tree, nullptr, Arr[i], tree);
    }

    inOrder(tree);
    //insertNode(&tree, nullptr, 5);
    //inOrder(tree);
    //std::cout << "\n";

    return 0;
}