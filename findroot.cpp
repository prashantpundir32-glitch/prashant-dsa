// finding the roots of a quadratic equations

#include <iostream>
#include <cmath>
using namespace std;

void findRoots(int a, int b, int c){
    int d= b*b-4*a*c;
    float x=(-b+sqrt(d))/2*a;
    float y=(-b-sqrt(d))/2*a;

    if (d==0){
        cout<<"Both Roots are real and equal: "<<x<<endl;
        
    }
    else if (d>0){
        cout<<"Both roots are real and distinct: "<<x<<" ,"<<y<<endl;
    }
    else{
        cout<<"Roots are Imaginary"<<endl;
    }
}

int main() { 
    findRoots(1, 8, 12);
    return 0;
}
