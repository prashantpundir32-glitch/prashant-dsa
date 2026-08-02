#include<iostream>
using namespace std;
int main()
{
   
    int a[10];
    cout<<"enter the value of the element of the array:";
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(a[i]==a[j])
            {
                
               cout<<"the first duplicate is:"<<a[i]<<endl;
               break;

            }
        }
    }
   
    return 0;
}