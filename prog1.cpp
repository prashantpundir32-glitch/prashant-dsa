#include<iostream>
using namespace std;
int main()
{
    int count =0;
    float speed ;
    cout<<"Enter the speed of the vehicle: ";
    cin>>speed;
    while(speed>0.001)
    {
        speed=speed/2;
        count++;
        
    }
    cout<<"Number of times the ball bounces back from the ground: "<<count<<endl;
}