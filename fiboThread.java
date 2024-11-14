
class mainThread extends Thread{
    public void run(){
        for(int i=0;i<100;i++){
            if(isPerfect(i)){
                System.out.println(i+ "is a perfect no.");
            }
            if(i%2==0){
                System.out.println(fibo(i));
            }
            else{
                System.out.println("square is: "+i*i);
            }
        }
    }
    public boolean isPerfect(int n){
        int temp=n;
        int sum=0;
        while(n!=0){
            int rem=n%10;
            sum+=rem;
            n=n/10;
        }
        if(sum==temp){
            return true;
        }
        else{
            return false;
        }
    }
    public int fibo(int n){
        if(n<=1){
            return n;
        }
        return fibo(n-1)+fibo(n-2);
    }
}
public class fiboThread {
    public static void main(String[] args) {
        mainThread t1=new mainThread();
        t1.start();
    }
}
