// moving all the zeros as last elements

#include <iostream>
using namespace std;



void shiftZero(int arr[], int n){
    int pos=-1;
    for (int i=0; i<n; i++){
        if (arr[i]==0){
            pos=i;
            }
        
        if (pos==-1) cout<<"Element not found"<<endl;
        else {
            for (int i=pos; i<n-1; i++){
            arr[i]=arr[i+1];
            }
            n--;
        }
    }
        arr[n]=0;
        n++;
        for(int i=0; i<6; i++){
            cout<<arr[i]<<" ";
        }
}

int main() {
    int arr[6]={1,0,0,4,6,3};
    int n=6;
    shiftZero(arr, 6);
    return 0;
}
