#include<iostream>
#include<cmath>
using namespace std;

int facto(int n){
    int factorial=1;
    for(int i=2;i<=n;i++){
        factorial*=i;
    }return factorial;
}
int main()
{
    int n,r;
    cin>>n>>r;

    int ans=facto(n)/(facto(r)*facto(n-r));
    cout<<ans;
 return 0;
}


// #include<iostream>
// #include<cmath>
// using namespace std;
// int n,r;
// int facto1(int n){
//         int factorial=1;
//     for(int i=2;i<=n;i++){
//         factorial *=i;
//     }
//     return factorial;
// }
// int facto2(int r){
//     int factorial2=1;
//     for(int j=2;j<=r;j++){
//         factorial2 *=j;
//     }return factorial2;
// }
// int facto3(int n,int r){
//     int factorial3=1;
//     for(int k=2;k<=(n-r);k++){
//         factorial3 *= k;
//     }return factorial3;
// }

// int main()
// {
//     int n,r;
//     cin>>n>>r;

//     int comb;
//     comb = facto1(n)/(facto2(r)*facto3(n,r));
//     cout<<comb<<endl;
//  return 0;
// }