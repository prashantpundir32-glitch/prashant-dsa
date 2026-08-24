#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class circularQueue
{
    node *front;
    node *rear;

public:

    circularQueue()
    {
        front = rear = NULL;
    }

    void enqueue(int val)
    {
        node *newnode = new node(val);

        // Queue is empty
        if (front == NULL)
        {
            front = rear = newnode;
            rear->next = front;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
            rear->next = front;
        }
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        // Only one node
        if (front == rear)
        {
            cout << "Dequeued element is " << front->data << endl;

            delete front;
            front = rear = NULL;
        }
        else
        {
            node *temp = front;

            cout << "Dequeued element is " << front->data << endl;

            front = front->next;
            rear->next = front;

            delete temp;
        }
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        node *temp = front;

        cout << "Queue elements are: ";

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != front);

        cout << endl;
    }
};

int main()
{
    circularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}