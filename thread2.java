
import java.util.Random;
class randTr extends Thread{
    public void run(){
        Random rand=new Random();
    while(true){
        int n=rand.nextInt(100);
        if(n%2==0){
            squaretr s=new squaretr(n);
            s.start();
        }else{
            cubetr c=new cubetr(n);
            c.start();
        }try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
    }
}
class squaretr extends Thread{
    int num;
    public squaretr(int num){
        this.num=num;
    }
    public void run(){
        System.out.println("square: "+num*num);
    }
}
class cubetr extends Thread{
    int num;
    public cubetr(int num){
        this.num=num;
    }
    public void run(){
        System.out.println("cube: "+num*num*num);
    }
}

public class thread2 {
    public static void main(String[] args) {
        randTr r=new randTr();
        r.start();
    }
}
