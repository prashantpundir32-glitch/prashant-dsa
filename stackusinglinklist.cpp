#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

class stack
{
    public:
    node *head;
    node *tail;

stack()
{
    head=tail=NULL;

} 
void push(int val)
{
    node *newnode=new node(val);
    if(head==NULL)
    {
        head=tail=newnode;

    } 
    else{
        tail->next=newnode;
        tail=newnode;
}
}
void pop()
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
void print()
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<",";
        temp=temp->next;

    }
}
};
int main()
{
    stack s;
    s.push(12);
      s.push(15);
        s.push(1);
          s.push(10);
            s.push(13);
              s.push(15);
                s.push(2);
                 s.push(12);  
 s.push(5);
 s.print();
 cout<<endl;
 
s.pop();
s.pop();
s.print();
return 0;

}