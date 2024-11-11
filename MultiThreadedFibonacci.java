public class MultiThreadedFibonacci {

    public static void main(String[] args) {
        Thread perfectNumberThread = new Thread(new PerfectNumberGenerator());
        Thread fibonacciThread = new Thread(new FibonacciGenerator());
        Thread primeNumberThread = new Thread(new PrimeNumberGenerator());

        perfectNumberThread.start();
        fibonacciThread.start();
        primeNumberThread.start();
    }
}

class PerfectNumberGenerator implements Runnable {
    @Override
    public void run() {
        System.out.println("Perfect numbers:");
        for (int i = 1; i <= 100; i++) {
            if (isPerfect(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    private boolean isPerfect(int number) {
        int sum = 1;
        for (int i = 2; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum == number && number != 1;
    }
}

class FibonacciGenerator implements Runnable {
    @Override
    public void run() {
        System.out.println("Fibonacci series:");
        int n1 = 0, n2 = 1, n3;
        System.out.print(n1 + " " + n2);
        for (int i = 2; i < 100; ++i) {
            n3 = n1 + n2;
            System.out.print(" " + n3);
            n1 = n2;
            n2 = n3;
        }
        System.out.println();
    }
}

class PrimeNumberGenerator implements Runnable {
    @Override
    public void run() {
        System.out.println("Prime numbers:");
        for (int i = 2; i <= 100; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    private boolean isPrime(int number) {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
}
// Perfect numbers:
// Fibonacci series:
// Prime numbers:
// 2 3 5 6 7 11 28 0 113 
// 17 19  123  229 31  337  541 43 47  853  1359 61  2167  34 55 8971  14473  23379  37783 89 97  610 987 1597 2584 4181 6765 10946
//  17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 165580141 267914296 433494437 701408733 1134903170 1836311903 -1323752223 512559680 -811192543 -298632863 
//  -1109825406 -1408458269 1776683621 368225352 2144908973 -1781832971 363076002 -1418756969 -1055680967 1820529360 764848393