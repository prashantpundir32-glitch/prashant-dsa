#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Heap
{
public:

    // Insert nodes level by level
    Node* insert(Node* root, int value)
    {
        Node* newNode = new Node(value);

        if (root == nullptr)
            return newNode;

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if (temp->left == nullptr)
            {
                temp->left = newNode;
                return root;
            }
            else
            {
                q.push(temp->left);
            }

            if (temp->right == nullptr)
            {
                temp->right = newNode;
                return root;
            }
            else
            {
                q.push(temp->right);
            }
        }

        return root;
    }

    // Heapify a subtree using its root
    void heapify(Node* root)
    {
        if (root == nullptr)
            return;

        Node* largest = root;

        if (root->left != nullptr &&
            root->left->data > largest->data)
        {
            largest = root->left;
        }

        if (root->right != nullptr &&
            root->right->data > largest->data)
        {
            largest = root->right;
        }

        if (largest != root)
        {
            swap(root->data, largest->data);

            heapify(largest);
        }
    }

    // Build the max heap
    void buildHeap(Node* root)
    {
        if (root == nullptr)
            return;

        buildHeap(root->left);
        buildHeap(root->right);

        heapify(root);
    }

    // Find the last node in level order
    Node* getLastNode(Node* root)
    {
        if (root == nullptr)
            return nullptr;

        queue<Node*> q;
        q.push(root);

        Node* temp = nullptr;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }

        return temp;
    }

    // Find the parent of a given node
    Node* getParent(Node* root, Node* target)
    {
        if (root == nullptr || root == target)
            return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if (temp->left == target || temp->right == target)
                return temp;

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }

        return nullptr;
    }

    // Heap sort using the binary tree
    void heapSort(Node*& root)
    {
        buildHeap(root);

        while (root != nullptr)
        {
            Node* last = getLastNode(root);

            // Move the maximum value to the last node
            swap(root->data, last->data);

            // If only the root remains
            if (last == root)
            {
                delete root;
                root = nullptr;
                break;
            }

            // Remove the last node
            Node* parent = getParent(root, last);

            if (parent->left == last)
                parent->left = nullptr;
            else
                parent->right = nullptr;

            delete last;

            // Restore the max heap
            buildHeap(root);
        }
    }

    // Display the tree level by level
    void display(Node* root)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }

        cout << endl;
    }

    // Free all nodes
    void deleteTree(Node* root)
    {
        if (root == nullptr)
            return;

        deleteTree(root->left);
        deleteTree(root->right);

        delete root;
    }
};

int main()
{
    Heap h;
    Node* root = nullptr;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = h.insert(root, value);
    }

    cout << "\nOriginal binary tree: ";
    h.display(root);

    h.buildHeap(root);

    cout << "Max heap: ";
    h.display(root);

    h.heapSort(root);

    cout << "After heap sort: ";
    h.display(root);

    return 0;
}