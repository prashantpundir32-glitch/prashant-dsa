#include <iostream>
using namespace std;

class Array
{
private:
    int arr[100];
    int n;

public:

    // Constructor
    Array()
    {
        n = 0;
    }

    // Input array
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter array elements: ";
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    // Insert at beginning
    void insertBeginning(int num)
    {
        for(int i = n; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[0] = num;
        n++;
    }

    // Insert at a given position
    void insertPosition(int pos, int num)
    {
        for(int i = n; i >= pos; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[pos - 1] = num;
        n++;
    }

    // Insert at end
    void insertEnd(int num)
    {
        arr[n] = num;
        n++;
    }

    // Delete an element
    void deleteElement(int del)
    {
        int found = 0;

        for(int i = 0; i < n; i++)
        {
            if(arr[i] == del)
            {
                found = 1;

                for(int j = i; j < n - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }

                n--;
                break;
            }
        }

        if(found == 0)
        {
            cout << "Number not found.\n";
        }
    }

    // Display array
    void display()
    {
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    Array A;

    // Input array
    A.input();

    // Insert at beginning
    int num;

    cout << "\nEnter number to insert at beginning: ";
    cin >> num;

    A.insertBeginning(num);

    cout << "Array after inserting at beginning: ";
    A.display();


    // Insert in middle / position
    int pos;

    cout << "\nEnter position to insert (1 to " << "100" << "): ";
    cin >> pos;

    cout << "Enter number to insert: ";
    cin >> num;

    A.insertPosition(pos, num);

    cout << "Array after inserting at position: ";
    A.display();


    // Insert at end
    cout << "\nEnter number to insert at end: ";
    cin >> num;

    A.insertEnd(num);

    cout << "Array after inserting at end: ";
    A.display();


    // Delete
    int del;

    cout << "\nEnter number to delete: ";
    cin >> del;

    A.deleteElement(del);

    cout << "Array after deletion: ";
    A.display();

    return 0;
}
