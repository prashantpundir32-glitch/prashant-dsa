#include<iostream>
using namespace std;

void print(int a[])
{
    for(int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
}

int partition(int a[], int low, int high)
{
    int pvt = a[low];
    int i = low + 1;
    int j = high;

    while(i < j)
    {
        while(a[i] < pvt)
        {
            i++;
        }

        while(a[j] > pvt)
        {
            j--;
        }

        if(i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } 

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int part = partition(a, low, high);

        quicksort(a, low, part - 1);
        quicksort(a, part + 1, high);
    }
}

int main()
{
    int a[8] = {6, 2, 7, 4, 8, 1, 9, 0};

    quicksort(a, 0, 7);

    print(a);

    return 0;
}