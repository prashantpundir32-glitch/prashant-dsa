#include <iostream>
using namespace std;

class queuei
{
    int a[100];
    int r = -1;
    int f = -1;

public:

    void enqueue(int val)
    {
        r = r + 1;
        a[r] = val;
    }

    void dequeue()
    {
        if (f == r)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        f = f + 1;

        cout << "Dequeued element is " << a[f] << endl;

        a[f] = 0;
    }

    void display()
    {
        if (f == r)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Queue elements are: ";

            for (int i = f + 1; i <= r; i++)
            {
                cout << a[i] << " ,";
            }

            cout << endl;
        }
    }
};

int main()
{
    queuei q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(7);
    q.enqueue(1);
    q.enqueue(9);
    q.enqueue(1);
    q.enqueue(0);

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}