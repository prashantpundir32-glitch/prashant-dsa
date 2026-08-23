#include<iostream>
using namespace std;
class node{
public:
int data;
node *next;


public:
node(int val)
{
    data=val;
    next=NULL;

}
};
class list
{
    public:
node *head;
node *tail;

public:
list()
{
    head=tail=NULL;
}

void print()
{
    cout<<head->data<<"->";
    node *temp;
    temp=head->next;

    while(temp!=head)
    {
        cout<<temp->data<<",";

        temp=temp->next;

    }
    cout<<temp->data;

    cout<<endl;

}
void push_back(int val)
{
    node *newnode= new node(val);
    if(head==NULL)
    {
        head=tail=newnode;
        tail->next=head;

    }
    else
    {
            newnode->next=head;
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
        tail->next=head;

    }
    else
    {
        newnode->next=head;

        head=newnode;
               tail->next=head;

    }
}


void pop_front()
{
   
    if(head==NULL)
    {
      cout<<"list is empty"<<endl;

      return;


    }
    if(head==tail)
    {
        head=tail=NULL;
    }
    else
    {
        node *temp=head;
        head=head->next;
       tail->next=head;
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
       if(head==tail)
    {
        head=tail=NULL;
    }
    else
    {
        node *temp=head;
    while(temp->next!=tail)
    {
        temp=temp->next;

    }
    temp->next=NULL;
   
        delete tail;
        tail=temp;
tail->next=head;




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