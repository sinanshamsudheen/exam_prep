#include <iostream>
using namespace std;
int main(){
    int Pocketmoney=3000;
    for(int date=1;date<=30;date++){
        if(date%2==0){
            continue;
        }
        if(Pocketmoney==0){
            break;
        }
        cout<<"I can go out today"<<endl;
        Pocketmoney=Pocketmoney-300;
    }
}