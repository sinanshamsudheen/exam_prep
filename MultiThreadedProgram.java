import java.util.Random;

class NumberGenerator extends Thread {
    public void run() {
        Random rand = new Random();
        while (true) {
            int num = rand.nextInt(100);
            System.out.println("Generated Number: " + num);
            if (num % 2 == 0) {
                new Square(num).start();
            }
            else {
                new Cube(num).start();
            }
            try { Thread.sleep(1000); } catch (InterruptedException e) { e.printStackTrace(); }
        }
    }
}

class Square extends Thread {
    int num;
    Square(int num) { this.num = num; }
    public void run() { System.out.println("Square of " + num + " = " + (num * num)); }
}

class Cube extends Thread {
    int num;
    Cube(int num) { this.num = num; }
    public void run() { System.out.println("Cube of " + num + " = " + (num * num * num)); }
}

public class MultiThreadedProgram {
    public static void main(String[] args) {
        new NumberGenerator().start();
    }
}
