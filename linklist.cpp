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
node *next;
public:
list()
{
    head=tail=NULL;
}
int search(int keyi)
{
    int index=0;

    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==keyi)
        {
return index;

        }
        temp=temp->next;

        index++;
    }
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
        head=newnode;

    }
}
void push_midle(int val,int pos)
{
   
    if(pos<0)
    {
        cout<<"INVALID OPERATION"<<endl;
        return;

    }
    if(pos==0)
    {
        push_front( val);

    }
    node *temp=head;
    for(int i=0; i<pos-1;i++)
    {
        temp=temp->next;
    }
    node *newnode= new node(val);
    

     newnode->next=temp->next;
     temp->next=newnode;


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
            l.push_midle(23,1);
            l.print();
            int n=l.search(23);
            cout<<endl;

            cout<<"N="<<n;

      return 0;
      

}