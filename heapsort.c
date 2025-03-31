#include<stdio.h>
void heapify(int arr[],int n,int i){
    int root=i;
    int right=2*i+2;
    int left=2*i+1;
    if(left<n && arr[root]<arr[left]){
        root=left;
    }
    if(right<n && arr[root]<arr[right]){
        root=right;
    }
    if(root!=i){
        swap(&arr[root],&arr[i]);
        heapify(arr,n,root);
    }
}
void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}