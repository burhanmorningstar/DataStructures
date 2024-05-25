#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <sstream>

// Düğüm yapısı
struct Node {
    int studentID;
    std::string name;
    std::string surname;
    Node* left;
    Node* right;

    Node(int id, const std::string& n, const std::string& s) 
        : studentID(id), name(n), surname(s), left(nullptr), right(nullptr) {}
};

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BinaryTree::insert(int id, const std::string& name, const std::string& surname) {
    Node* newNode = new Node(id, name, surname);
    if (root == nullptr) {
        root = newNode;
    } else {
        Node* current = root;
        Node* parent = nullptr;
        while (true) {
            parent = current;
            if (id < current->studentID) {
                current = current->left;
                if (current == nullptr) {
                    parent->left = newNode;
                    return;
                }
            } else {
                current = current->right;
                if (current == nullptr) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

void BinaryTree::inorderTraversal() {
    inorderTraversal(root);
}

void BinaryTree::inorderTraversal(Node* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        std::cout << node->studentID << " " << node->name << " " << node->surname << std::endl;
        inorderTraversal(node->right);
    }
}

void BinaryTree::preorderTraversal() {
    preorderTraversal(root);
}

void BinaryTree::preorderTraversal(Node* node) {
    if (node != nullptr) {
        std::cout << node->studentID << " " << node->name << " " << node->surname << std::endl;
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void BinaryTree::postorderTraversal() {
    postorderTraversal(root);
}

void BinaryTree::postorderTraversal(Node* node) {
    if (node != nullptr) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->studentID << " " << node->name << " " << node->surname << std::endl;
    }
}

bool BinaryTree::search(int id) {
    Node* current = root;
    while (current != nullptr) {
        if (current->studentID == id) {
            std::cout << "Found: " << current->name << " " << current->surname << std::endl;
            return true;
        } else if (id < current->studentID) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    std::cout << "Student ID " << id << " not found." << std::endl;
    return false;
}

bool BinaryTree::deleteNode(int id) {
    root = deleteNode(root, id);
    return root != nullptr;
}

Node* BinaryTree::deleteNode(Node* root, int id) {
    if (root == nullptr) return root;

    if (id < root->studentID) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->studentID) {
        root->right = deleteNode(root->right, id);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->studentID = temp->studentID;
        root->name = temp->name;
        root->surname = temp->surname;
        root->right = deleteNode(root->right, temp->studentID);
    }
    return root;
}

Node* BinaryTree::findMin(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void BinaryTree::depthFirstSearch(int id) {
    std::stack<Node*> stack;
    stack.push(root);
    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();
        if (current->studentID == id) {
            std::cout << "Found: " << current->name << " " << current->surname << std::endl;
            return;
        }
        if (current->right) stack.push(current->right);
        if (current->left) stack.push(current->left);
    }
    std::cout << "Student ID " << id << " not found." << std::endl;
}

void BinaryTree::breadthFirstSearch(int id) {
    std::queue<Node*> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node* current = queue.front();
        queue.pop();
        if (current->studentID == id) {
            std::cout << "Found: " << current->name << " " << current->surname << std::endl;
            return;
        }
        if (current->left) queue.push(current->left);
        if (current->right) queue.push(current->right);
    }
    std::cout << "Student ID " << id << " not found." << std::endl;
}

void BinaryTree::writeToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        writeToFile(file, root);
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void BinaryTree::writeToFile(std::ofstream& file, Node* node) {
    if (node != nullptr) {
        file << node->studentID << "\t" << node->name << "\t" << node->surname << std::endl;
        writeToFile(file, node->left);
        writeToFile(file, node->right);
    }
}
