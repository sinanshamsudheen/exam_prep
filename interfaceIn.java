interface array{
    void sort(int arr[]);
    void insert(int arr[],int data);
    void delete(int arr[],int key);
    void binaryS(int arr[],int key);
}
class singlearray implements array{
    @Override
    public void sort(int arr[]){
        int n=arr.length;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }
    @Override
    public void insert(int arr[],int data){
        int n=arr.length;
        arr[n]=data;
    }
    @Override
    public void delete(int arr[],int key){
        int n=arr.length;
        int i=0,j;
        while(arr[i]!=key && i<n){
            i++;
        }
        if(i==n){
            System.out.println("not found");
            return;
        }
        for(j=i;j<n-1;j++){
            arr[j]=arr[j+1];
        }
    }
    @Override
    public void binaryS(int arr[],int key){
        
        int low=0;
        int n=arr.length;
        int high=n-1;
        
        while(low<high){
            int mid=(high-low)/2;
            if(key<arr[mid]){
                high=mid;
            }else if(key>arr[mid]){
                low=mid;
            }
            else{
                System.out.println("key found at position: "+mid);
                break;
            }
        }
    }
    public void display(int arr[]){
        int n=arr.length;
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
public class interfaceIn{
    public static void main(String[] args) {
        singlearray a=new singlearray();
        
        int[] arr={8,2,1,5,6,3};
        a.sort(arr);
        a.display(arr);
        a.insert(arr,7);
        a.display(arr);
        a.delete(arr,1);
        a.display(arr);
        a.binaryS(arr,6);
    }
}