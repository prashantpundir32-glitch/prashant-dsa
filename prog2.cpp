#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"enter the three value of the quadratic equation:";
    cin>>a>>b>>c;
    float d = (b*b) - (4*a*c);
    float root1,root2;
    if(d>0)
    {
        root1 = (-b + sqrt(d))/(2*a);
        root2 = (-b - sqrt(d))/(2*a);
        cout<<"The roots are real and different."<<endl;
        cout<<"Root 1: "<<root1<<endl;
        cout<<"Root 2: "<<root2<<endl;
    }
    else if(d==0)
    {
        root1 = root2 = -b/(2*a);
        cout<<"The roots are real and same."<<endl;
        cout<<"Root 1: "<<root1<<endl;
    }
    else
    {
        float realPart = -b/(2*a);
        float imaginaryPart = sqrt(-d)/(2*a);
        cout<<"The roots are complex and different."<<endl;
        cout<<"Root 1: "<<realPart<<" + "<<imaginaryPart<<"i"<<endl;
        cout<<"Root 2: "<<realPart<<" - "<<imaginaryPart<<"i"<<endl;
    }
    return 0;
}