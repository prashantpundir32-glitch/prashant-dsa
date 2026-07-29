#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    cout<<"enter the value of theta and initial velocity:";
    float theta, u;
    cin>>theta>>u;
    float g = 9.8;
    float theta_rad = theta * (3.14159 / 180.0);
    float max_height = (u * u * sin(theta_rad) * sin(theta_rad)) / (2 * g);
    float range = (u * u * sin(2 * theta_rad)) / g;
    float time_of_flight = (2 * u * sin(theta_rad)) / g;
    cout<<"Maximum height reached by the projectile: "<<max_height<<endl;
    cout<<"Horizontal range of the projectile: "<<range<<endl;
    return 0;
}