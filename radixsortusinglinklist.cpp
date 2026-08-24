#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Bucket
{
public:
    Node *front;
    Node *rear;

    Bucket()
    {
        front = NULL;
        rear = NULL;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int remove()
    {
        if (front == NULL)
            return -1;

        Node *temp = front;
        int value = temp->data;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;

        return value;
    }

    bool isEmpty()
    {
        return front == NULL;
    }
};

class RadixSort
{
    int a[100];
    int n;

public:

    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements: ";

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    int getMax()
    {
        int max = a[0];

        for (int i = 1; i < n; i++)
        {
            if (a[i] > max)
                max = a[i];
        }

        return max;
    }

    void sort()
    {
        int max = getMax();

        // Create 10 buckets for digits 0 to 9
        Bucket bucket[10];

        // Process each digit
        for (int place = 1; max / place > 0; place = place * 10)
        {
            // Put elements into buckets
            for (int i = 0; i < n; i++)
            {
                int digit = (a[i] / place) % 10;

                bucket[digit].insert(a[i]);
            }

            // Collect elements from buckets
            int index = 0;

            for (int i = 0; i < 10; i++)
            {
                while (!bucket[i].isEmpty())
                {
                    a[index] = bucket[i].remove();
                    index++;
                }
            }
        }
    }

    void display()
    {
        cout << "Sorted array: ";

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    RadixSort r;

    r.input();

    cout << "\nBefore sorting: ";
    r.display();

    r.sort();

    cout << "After sorting: ";
    r.display();

    return 0;
}