import java.util.*;
public class quickSort{
    public void swap(int[] arr,int i,int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    public int partition(int arr[],int low,int high){
        int p=arr[low];
        int i=low;
        int j=high;

       while(i<j){
            while(arr[i]<=p && i<high){
                i++;
            }
            while(arr[j]>p && j>low){
                j--;
            }
            if(i<j){
                swap(arr,i,j);
            }
       }
        swap(arr,low,j);
        return j;
    }
    public void Sort(int arr[],int low, int high){
        if(low<high){
            int pi=partition(arr, low, high);
            Sort(arr, low, pi-1);
            Sort(arr, pi+1, high);
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        quickSort qs=new quickSort();
        int n=4;
        int[] arr=new int[100];
        for(int i=0;i<n;i++){
            int a=sc.nextInt();
            arr[i]=a;
        }
        qs.Sort(arr,0,n-1);
        for(int i=0;i<n;i++){
            System.out.print(arr[i]);
        }
    }
}