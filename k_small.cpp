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

void smallest (int a[],int low,int high,int k)
{
    if(low<high)
    {
        int part = partition(a, low, high);

    if(part==k)
    {
        for(int i=0;i<k;i++)
        {
            cout<<a[i]<<",";

        }
    }

    if(k<part)
    {
        smallest(a,low,part-1,k);
    }
    if(k>part)
    {
        smallest(a,part+1,high,k);
    }
}
}
int main()
{
    int a[8] = {6, 2, 7, 4, 8, 1, 9, 0};

smallest(a,0,7,3);

    

    return 0;
}