//  if a ball is dropped from height h then after how many tips the ball will stops 

#include <iostream>
using namespace std;

void noOFTips(float speed ){
    int count=0;
    while(speed>0.001){
        count++;
        speed=speed/2;
    }
    cout<<"No. of tips after ball will stop: "<<count<<endl;

}

int main() {
    noOFTips(30);
    return 0;
}
