
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
        data=value;
        left=NULL;
        right=NULL;
    }
};

node* inserti(node* root, int value)
{
    node* newnode = new node(value);

    if(root==NULL)
    {
        return newnode;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* current=q.front();
        q.pop();

        if(current->left==NULL)
        {
            current->left=newnode;
            return root;
        }
        else
        {
            q.push(current->left);
        }

        if(current->right==NULL)
        {
            current->right=newnode;
            return root;
        }
        else
        {
            q.push(current->right);
        }
    }

    return root;
}

node* createbinarytree()
{
    int value;

    cout<<"Enter the value (-1 for no node): ";
    cin>>value;

    if(value==-1)
    {
        return NULL;
    }

    node *newnode=new node(value);

    cout<<"Enter the left child of "<<value<<endl;
    newnode->left=createbinarytree();

    cout<<"Enter the right child of "<<value<<endl;
    newnode->right=createbinarytree();

    return newnode;
}

void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node *root=createbinarytree();

    cout<<"Inorder Traversal of the Binary Tree:"<<endl;
    inorder(root);

    root=inserti(root,67);

    cout<<"\nBinary Tree after insertion:"<<endl;
    inorder(root);

    return 0;
}
