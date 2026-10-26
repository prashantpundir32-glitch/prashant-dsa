// write the program to count the height of the binay tree and sum of all nodes and number of nodes in binary tree

#include <iostream>
using namespace std;
class node
{
public:
    int data;
    int height;
    node* left;
    node* right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
        height = 0;
    }
};

void height(node* root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    root->height = max(leftHeight, rightHeight) + 1;
    return root->height;
}
void sumOfNodes(node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return root->data + leftSum + rightSum;
}
void countNodes(node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return 1 + leftCount + rightCount;
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << "Height of the binary tree: " << height(root) << endl;
    cout << "Sum of all nodes in the binary tree: " << sumOfNodes(root) << endl;
    cout << "Number of nodes in the binary tree: " << countNodes(root) << endl;

    return 0;
}
