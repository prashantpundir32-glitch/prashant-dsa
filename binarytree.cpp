
#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Insertion
node* inserti(node* root, int value)
{
    node* newnode = new node(value);

    if(root == NULL)
    {
        return newnode;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* current = q.front();
        q.pop();

        if(current->left == NULL)
        {
            current->left = newnode;
            return root;
        }
        else
        {
            q.push(current->left);
        }

        if(current->right == NULL)
        {
            current->right = newnode;
            return root;
        }
        else
        {
            q.push(current->right);
        }
    }

    return root;
}

// Create Binary Tree
node* createbinarytree()
{
    int value;

    cout << "Enter the value (-1 for no node): ";
    cin >> value;

    if(value == -1)
    {
        return NULL;
    }

    node *newnode = new node(value);

    cout << "Enter the left child of " << value << endl;
    newnode->left = createbinarytree();

    cout << "Enter the right child of " << value << endl;
    newnode->right = createbinarytree();

    return newnode;
}

// Inorder Traversal
void inorder(node *root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Deletion Helper Function
void deleteDeepest(node* root, node* deepest)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* current = q.front();
        q.pop();

        if(current->left)
        {
            if(current->left == deepest)
            {
                delete current->left;
                current->left = NULL;
                return;
            }

            q.push(current->left);
        }

        if(current->right)
        {
            if(current->right == deepest)
            {
                delete current->right;
                current->right = NULL;
                return;
            }

            q.push(current->right);
        }
    }
}

// Deletion Function
node* deletion(node* root, int value)
{
    if(root == NULL)
    {
        cout << "Tree is empty!" << endl;
        return NULL;
    }

    // If the root is the only node
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == value)
        {
            delete root;
            return NULL;
        }

        cout << "Value not found!" << endl;
        return root;
    }

    queue<node*> q;
    q.push(root);

    node* target = NULL;
    node* current = NULL;

    // Find the node to delete and the deepest rightmost node
    while(!q.empty())
    {
        current = q.front();
        q.pop();

        if(current->data == value)
        {
            target = current;
        }

        if(current->left)
        {
            q.push(current->left);
        }

        if(current->right)
        {
            q.push(current->right);
        }
    }

    if(target == NULL)
    {
        cout << "Value not found!" << endl;
        return root;
    }

    // Replace target's data with deepest node's data
    int deepestValue = current->data;

    target->data = deepestValue;

    // Delete the deepest rightmost node
    deleteDeepest(root, current);

    cout << "Node deleted successfully!" << endl;

    return root;
}

int main()
{
    node *root = createbinarytree();

    cout << "\nInorder Traversal of the Binary Tree:" << endl;
    inorder(root);

    root = inserti(root, 67);

    cout << "\n\nBinary Tree after insertion:" << endl;
    inorder(root);

    int value;

    cout << "\n\nEnter the value you want to delete: ";
    cin >> value;

    root = deletion(root, value);

    cout << "\nBinary Tree after deletion:" << endl;
    inorder(root);

    return 0;
}
