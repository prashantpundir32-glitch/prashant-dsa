#include<iostream>
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
class BST
{
    public:
    
    node *insert(node *root,int value)
    {
        if(root==NULL)
        {
            return new node(value);
        }
        if(value<root->data)
        {
            root->left=insert(root->left,value);
        }
        else if(value >root->data)
        {
            root->right=insert(root->right,value);
        }
        return root;

    }
    node *deletenode(node*root,int key)
    {
        if(root==NULL)
        {
            return root;

        }
        if(key<root->data)
        {
            root->left=deletenode(root->left,key);

        }
        else if(key>root->data)
        {
            root->right=deletenode(root->right,key);
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left==NULL)
            {
                node *temp=root->right;
                delete root;
                return temp;
            }
             else if(root->right==NULL)
            {
                node *temp=root->left;
                delete root;
                return temp;                           
            }
            else
            {
                node *temp=root->right;
                while(temp->left!=NULL)
                {                     
                    temp=temp->left;
                }
                root->data=temp->data;
                root->right=deletenode(root->right,temp->data);
            }
        }
        return root;

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
    
    node *root;
    BST()
    {
        root=NULL;

    }
    
    void insertvalue(int value)
    {
        root=insert(root,value);
    }
    void deletevalue(int value)
    {
        root=deletenode(root,value);
    }
    void display()
    {
        inorder(root);
        cout<<endl;

    }
};
int main()
{
    BST tree;
    tree.insertvalue(50);
     tree.insertvalue(40);
      tree.insertvalue(20);
       tree.insertvalue(90);
        tree.insertvalue(70);
         tree.insertvalue(5);
          tree.insertvalue(2);
           tree.insertvalue(89);
           cout<<"bst after insertion "<<endl;
           tree.display();
  
           tree.deletevalue(90);
           tree.deletevalue(50);
           cout<<"bst after deletion"<<endl;
           tree.display();

           
           return 0;

}