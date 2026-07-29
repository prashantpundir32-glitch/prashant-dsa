#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, i, num, pos, del;

    // Input array
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Insert at beginning
    cout << "\nEnter number to insert at beginning: ";
    cin >> num;

    for(i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = num;
    n++;

    cout << "Array after inserting at beginning: ";
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Insert in middle
    cout << "\n\nEnter position to insert (1 to " << n + 1 << "): ";
    cin >> pos;

    cout << "Enter number to insert: ";
    cin >> num;

    for(i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = num;
    n++;

    cout << "Array after inserting in middle: ";
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Insert at end
    cout << "\n\nEnter number to insert at end: ";
    cin >> num;

    arr[n] = num;
    n++;

    cout << "Array after inserting at end: ";
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Delete a number
    cout << "\n\nEnter number to delete: ";
    cin >> del;

    int found = 0;

    for(i = 0; i < n; i++)
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
        cout << "Number not found.";
    }
    else
    {
        cout << "Array after deletion: ";
        for(i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}