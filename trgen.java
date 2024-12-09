
import java.util.Random;

class trgenene extends Thread{
        Random rand=new Random();
        public void run(){
            while(true){
                int n=rand.nextInt(100)+1;
                System.out.println("num:" + n);
                if(n%2==0){
                    evenThr e1=new evenThr(n);
                    e1.start();
                }
                else if(n%2!=0){
                    oddThr o1=new oddThr(n);
                    o1.start();
                }
                try{
                    Thread.sleep(1000);
                }catch (Exception e) {
                    e.printStackTrace();
                }
            }
            }
}

class oddThr extends Thread{
    private int num;
    oddThr(int num){
        this.num=num;
    }
    public void run(){
        for(int i=1;i<=num;i+=2){
            System.out.println(i);
        }
    }
}
class evenThr extends Thread{
    private int num;
    evenThr(int num){
        this.num=num;
    }
    public void run(){
        for(int i=0;i<=num;i+=2){
            System.out.println(i);
        }
    }
}
public class trgen{
    public static void main(String[] args) {
        trgenene t = new trgenene();
        t.start();
    }
}