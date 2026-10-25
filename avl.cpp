
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data, height;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        height = 0;
        left = right = nullptr;
    }
};

class AVLTree {
    Node* root;

    int height(Node* node) {
        return (node == nullptr) ? -1 : node->height;
    }

    int balance(Node* node) {
        if (node == nullptr)
            return 0;

        return height(node->left) - height(node->right);
    }

    void updateHeight(Node* node) {
        node->height = 1 + max(height(node->left),
                               height(node->right));
    }

    Node* rightRotate(Node* z) {
        Node* y = z->left;
        Node* T2 = y->right;

        y->right = z;
        z->left = T2;

        updateHeight(z);
        updateHeight(y);

        return y;
    }

    Node* leftRotate(Node* z) {
        Node* y = z->right;
        Node* T2 = y->left;

        y->left = z;
        z->right = T2;

        updateHeight(z);
        updateHeight(y);

        return y;
    }

    // INSERTION
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node;

        updateHeight(node);

        int bf = balance(node);

        // LL
        if (bf > 1 && value < node->left->data)
            return rightRotate(node);

        // RR
        if (bf < -1 && value > node->right->data)
            return leftRotate(node);

        // LR
        if (bf > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (bf < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minNode(Node* node) {
        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    // DELETION
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr)
            return nullptr;

        if (value < node->data)
            node->left = deleteNode(node->left, value);

        else if (value > node->data)
            node->right = deleteNode(node->right, value);

        else {
            // Zero or one child
            if (node->left == nullptr ||
                node->right == nullptr) {

                Node* child = (node->left != nullptr)
                                  ? node->left
                                  : node->right;

                if (child == nullptr) {
                    delete node;
                    return nullptr;
                }

                Node* oldNode = node;
                node = child;
                delete oldNode;
            }
            // Two children
            else {
                Node* successor = minNode(node->right);
                node->data = successor->data;

                node->right = deleteNode(node->right,
                                         successor->data);
            }
        }

        if (node == nullptr)
            return nullptr;

        updateHeight(node);

        int bf = balance(node);

        // LL
        if (bf > 1 && balance(node->left) >= 0)
            return rightRotate(node);

        // LR
        if (bf > 1 && balance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RR
        if (bf < -1 && balance(node->right) <= 0)
            return leftRotate(node);

        // RL
        if (bf < -1 && balance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // SEARCHING
    Node* search(Node* node, int value) {
        if (node == nullptr || node->data == value)
            return node;

        if (value < node->data)
            return search(node->left, value);

        return search(node->right, value);
    }

    // PREORDER
    void preorder(Node* node) {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    void searchValue(int value) {
        if (search(root, value) != nullptr)
            cout << "Value found\n";
        else
            cout << "Value not found\n";
    }

    void showPreorder() {
        preorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    int choice, value;

    do {
        cout << "\n1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Preorder\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.remove(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                tree.searchValue(value);
                break;

            case 4:
                cout << "Preorder: ";
                tree.showPreorder();
                break;

            case 0:
                cout << "Program ended\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
