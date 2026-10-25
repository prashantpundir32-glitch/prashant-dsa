// finding duplicates

#include <iostream>
using namespace std;

void createArr(int arr[], int n){
    cout<<"Enter the elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

// void printArr(int arr[], int n){
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
// }
void findDuplicate(int arr[], int n){
    createArr(arr, n);
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i]==arr[j]){
                cout<<arr[i];
                break;
            }
        }
        break;
    }
    
}


int main() {
    // Your code goes here
    int n=6;
    int arr[n];
    findDuplicate(arr, n);
    return 0;
}
