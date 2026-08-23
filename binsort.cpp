#include<iostream>
using namespace std;

int max(int a[], int n)
{
    int greatest = a[0];

    for(int i = 1; i < n; i++)
    {
        if(greatest < a[i])
        {
            greatest = a[i];
        }
    }

    return greatest;
}

void bin(int a[], int n)
{
    int great = max(a, n);

    int bini[great + 1] = {0};

  
    for(int i = 0; i < n; i++)
    {
        bini[a[i]]++;
    }

   
    for(int i = 0; i <= great; i++)
    {
        while(bini[i] > 0)
        {
            cout << i << ",";
            bini[i]--;
        }
    }
}

int main()
{
    int a[10] = {23,4,3,4,6,7,9,21,23,8};

    bin(a, 10);

    return 0;
}