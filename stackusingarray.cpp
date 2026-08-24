#include <iostream>
using namespace std;

class Stack
{
    int a[100];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top == 99)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            a[top] = value;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            cout << "Popped element is: " << a[top] << endl;
            top--;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Top element is: " << a[top] << endl;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack elements are: ";

            for (int i = top; i >= 0; i--)
            {
                cout << a[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.display();

    s.peek();

    s.pop();
    s.pop();

    s.display();

    return 0;
}