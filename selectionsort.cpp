#include<iostream>
using namespace std;
void print(int a[])
{
    for(int i=0;i<10;i++)
    {
    cout<<a[i]<<",";
    }

}
void selection(int a[],int n)
{
for(int i=0;i<n-1;i++)
{
    int smallestindex=i;

    for(int j=i+1;j<n;j++)
    {
   if(a[j]<a[smallestindex])
   {
    smallestindex=j;
   }
    }
    swap(a[i],a[smallestindex]);
}
}
int main()
{
    int a[10]={23,1,45,67,12,78,45,34,69,4};
 selection(a,10);
    print(a);
    return 0;


}