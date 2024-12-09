#include<stdio.h>
void merge(int arr[],int temp[],int start1,int end1,int start2,int end2){
    int i=start1;
    int j=start2;
    int k=start1;
    while(i<=end1 && j<=end2){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=end1){
        temp[k++]=arr[i++];
    }
    while(j<=end2){
        temp[k++]=arr[j++];
    }
    for(i=start1;i<=end2;i++){
        arr[i]=temp[i];
    }
}
void mergeSort(int arr[],int temp[],int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        mergeSort(arr,temp,start,mid);
        mergeSort(arr,temp,mid+1,end);
        merge(arr,temp,start,mid,mid+1,end);
    }
}
void main(){
    int arr[]={2,6,1,9,8,7};
    int temp[100];
    mergeSort(arr,temp,0,6);
    for(int i=0;i<6;i++){
        printf("%d",temp[i]);
    }
}