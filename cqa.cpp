#include <iostream>
using namespace std;

class CircularQueue
{
    int a[5];
    int front, rear;

public:

    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        // Queue is full
        if ((rear + 1) % 5 == front)
        {
            cout << "Queue is Full" << endl;
            return;
        }

        // First element
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % 5;
        }

        a[rear] = value;
        cout << value << " inserted" << endl;
    }

    void dequeue()
    {
        // Queue is empty
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Deleted element: " << a[front] << endl;

        // Only one element was present
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % 5;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue elements: ";

        int i = front;

        while (true)
        {
            cout << a[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % 5;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

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