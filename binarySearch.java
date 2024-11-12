public class binarySearch {
    public binarySearch(int arr[],int key){
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
    public static void main(String[] args) {
        int[] arr={1,2,3,4,5,6,7,8,9};
        binarySearch bs=new binarySearch(arr, 3);
    }
}
