#include<iostream>
using namespace std;
class node{
public:
int data;
node *next;
node *prev;

public:
node(int val)
{
    data=val;
  prev=  next=NULL;

}
};
class list
{
    public:
node *head;
node *tail;
node *next;
public:
list()
{
    head=tail=NULL;
}

void print()
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<",";

        temp=temp->next;

    }
    cout<<endl;

}
void push_back(int val)
{
    node *newnode= new node(val);
    if(head==NULL)
    {
        head=tail=newnode;
    }
    else
    {
            newnode->prev=tail;
        tail->next=newnode;
    
     tail  =newnode;
    

    }
}
void push_front(int val)
{
    node *newnode= new node(val);
    if(head==NULL)
    {
        head=tail=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;

    }
}


void pop_front()
{
   
    if(head==NULL)
    {
      cout<<"list is empty"<<endl;

      return;


    }
    else
    {
        node *temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;



    }
}
void pop_back()
{
   
    if(head==NULL)
    {
      cout<<"list is empty"<<endl;

      return;


    }
    else
    {
        node *temp=head;
    while(temp->next!=tail)
    {
        temp=temp->next;

    }
    temp->next=NULL;
    tail->prev=NULL;
        delete tail;
        tail=temp;




    }
}

};
int main()
{
    list  l;

    l.push_front(2);
     l.push_front(4);
      l.push_front(5);
       l.push_back(5);

      l.print();
  
    l.pop_front();
            l.print();
            l.pop_back();
            l.print();
         
      return 0;
      

}
