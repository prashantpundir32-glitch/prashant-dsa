#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node*right;
    node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;

    }

};
class BST
{
node * root;
BST()
{
    root==NULL;

}
node * insert(node*root,int key)
{
    if(root==NULL)
    {
        return new node(key);
    }
    if(key<root->data)
    {
        root->left=insert(root->left,key);

    }
     if(key>root->data)
    {
        root->right=insert(root->right,key);

    }
    return root;

}
node *search(node*root ,int key)
{
    if(root==NULL||root->data==key)
    {
        return root;
    }
     if(key>root->data)
    {
        return search(root->right,key);

    }
    if(key<root->data)
    {
        return search(root->left,key);
    }

}
node *delete(node *root,key)
{
    if(root==NULL)
    {
   retun root;
    }
     if(key<root->data)
    {
        root->left=delete(root->left,key);

    }
    elseif(key>root->data)
    {
        root->right=delete(root->right,key);

    }
else
{
    if(root->left==NULL&&root->right==NULL)
    {
        delete rooot;
        return NULL;
    }
    if(root->left==NULL)
    {
        node * temp=root->right;
        delete root;
        return temp;
    }
     if(root->right==NULL)
    {
        node * temp=root->left;
        delete root;
        return temp;
    }
    else
    {
        node *temp=root->right;
        while(temp->left!=NULL)
        {
            temp->=tmep->left;

        }
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
}
return root;

}
void insert(int k)
{
    root=insert(root,k);
}
void delete(int k)
{
    root=delete(root,k);
}
void search(int k)
{
    root=search(k);
    if(root!=NULL)
    {
        cout<<"the given number is present"<<endl;

    }
}
void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void display()
{
    inorder(root);
}
};
int main
{
    BST t;
    t.insert(10);
    t.insert(90);
    t.insert(70);
    t.insert(20);
    t.insert(10);
    t.insert(50);
    t.insert(30);
    t.insert(2);
    t.display();

t.search(30);
t.display();
t.delete(20);
t.delete(15);
t.display();
return 0;
}