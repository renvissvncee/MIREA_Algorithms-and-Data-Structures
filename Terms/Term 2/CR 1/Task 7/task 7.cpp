#include <iostream>
#include <string>
#include <vector>

struct Node {
    std::string name;
    std::vector<std::string> phoneNumbers;
    Node* left;
    Node* right;
};
void addRecord(Node*& node, const std::string& name, const std::string& phoneNumber) {
    if (node == nullptr) {
        node = new Node{ name, {phoneNumber}, nullptr, nullptr };
        return;
    }

    if (node->name == name) {
        node->phoneNumbers.push_back(phoneNumber);
    }
    else if (node->name > name) {
        addRecord(node->left, name, phoneNumber);
    }
    else {
        addRecord(node->right, name, phoneNumber);
    }
}

void printRecords(Node* node) {
    if (node == nullptr) {
        return;
    }

    printRecords(node->left);
    std::cout << "Name: " << node->name << ", Phone Numbers: ";
    for (const auto& number : node->phoneNumbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    printRecords(node->right);
}

Node* searchRecord(Node* node, const std::string& name) {
    if (node == nullptr || node->name == name) {
        return node;
    }

    if (node->name > name) {
        return searchRecord(node->left, name);
    }
    return searchRecord(node->right, name);
}

void deleteRecord(Node*& node, const std::string& name) {
    if (node == nullptr) {
        return;
    }

    if (name < node->name) {
        deleteRecord(node->left, name);
    }
    else if (name > node->name) {
        deleteRecord(node->right, name);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->name = temp->name;
            node->phoneNumbers = temp->phoneNumbers;
            deleteRecord(node->right, temp->name);
        }
    }
}
