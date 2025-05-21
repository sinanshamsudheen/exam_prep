// Pascal Triangle

#include<iostream>
using namespace std;
int facto(int n){
    int factorial=1;
    for(int i=2;i<=n;i++){
        factorial *=i;
    }return factorial;
}
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<facto(i)/(facto(j)*facto(i-j))<<" ";
        }
        cout<<endl;
    }
 return 0;
}


// #include<iostream>
// using namespace std;

// int PT(int n){
//     int num=1;
//     for(int k=1;k<=n;k++){
//         cout<<num;
//         num=num+1;
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             cout<<PT(n)<<endl;
//         }
//     }
//  return 0;
// }
