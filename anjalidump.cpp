#include <iostream>
using namespace std;

void swap(int a,int b){
                int temp=a;
                a=b;
                b=temp;
}
int main()
{
    int arr[100];
    int n, fq[100]={0}, freq;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        freq = 0;
        for (int j = 0; j < n; j++)
        {
             if (arr[i] == arr[j])
                {
                    freq++;
                }
        }
            fq[i] = freq;
    
    }
    for (int i = 0; i < n-1; i++)
    {
            if(fq[i]>fq[i+1]){
                int tmp = fq[i];
                while(tmp!=0){
                    cout<<arr[i];
                    tmp--;
                }
            }
        // for(int j=0;j<n-i-1;j++){

        // }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << fq[i];
    // }
}
// input,
// 6
// 1 1 2 2 2 3
// output,
// 3,1,1,2,2,2