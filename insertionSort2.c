#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insertion(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(arr[j] >= temp && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int partition(int arr[],int low,int high){
    int pi=arr[low];
    int i=low,j=high;
    while(i<j){
        while(arr[i] <= pi && i<high){
            i++;
        }
        while(arr[j] > pi && j>low){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
void heapify(int arr[],int n,int i){
    int root=i;
    int right=2*i + 2;
    int left=2*i + 1;
    if(left<n && arr[left]>arr[root]){
        root=left;
    }
    if(right<n && arr[right]>arr[root]){
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
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void main(){
    int arr[]={3,1,8,7,10,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    display(arr,n);
}