#include <iostream>
using namespace std;

void bucketSort(int a[], int n)
{
    int bucket[10][10];
    int count[10] = {0};

    // Put elements into buckets
    for(int i = 0; i < n; i++)
    {
        int index = a[i] / 10;
        bucket[index][count[index]] = a[i];
        count[index]++;
    }

    // Sort each bucket
  for(int i = 0; i < 10; i++)
{
    for(int j = 0; j < count[i] ; j++)
    {
        for(int k = j + 1; k < count[i]; k++)
        {
            if(bucket[i][j] > bucket[i][k])
            {
                int temp = bucket[i][j];
                bucket[i][j] = bucket[i][k];
                bucket[i][k] = temp;
            }
        }
    }
}
    // Put elements back into array
    int k = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            a[k] = bucket[i][j];
            k++;
        }
    }
}

int main()
{
    int a[8] = {29, 25, 3, 49, 9, 37, 21, 43};

    int n = 8;

    cout << "Before sorting: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    bucketSort(a, n);

    cout << "\nAfter sorting: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}