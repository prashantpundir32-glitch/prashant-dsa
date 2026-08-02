#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a[10];
    int n;
    n = 10;
    int sum;

    for(int i = 0; i < n; i++)
    {
        cout << "enter the value of :";
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            sum = i;

            for(int j = sum; j < n - 1; j++)
            {
                if(a[j] == 0)
                {
                    swap(a[j], a[j + 1]);
                }
            }
        }
    }

    cout << "the array after moving all the zeros to the end is:" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}