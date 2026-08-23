#include<iostream>
using namespace std;
void print(int a[])
{
    for(int i=0;i<10;i++)
    {
    cout<<a[i]<<",";
    }

}
void insertionsort(int a[],int n)
{
for(int i=1;i<n;i++)

{
int curent=a[i];
int prev=i-1;
while(prev>=0&&a[prev]>curent)
{
    a[prev+1]=a[prev];
    a[prev]=curent;
    prev--;
} 
}
}
int main()
{
    int a[10]={23,1,45,67,12,78,45,34,69,4};
 insertionsort(a,10);
    print(a);
    return 0;


}