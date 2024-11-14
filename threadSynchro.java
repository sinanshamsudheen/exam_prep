class Counter {
    private int count = 0; // A private variable to keep track of the count

    public synchronized void increment() { // Synchronized method to ensure thread safety
        count++; // Increment the count by 1
    }

    public int getCount() { // Method to get the current count value
        return count; // Return the current count
    }
}

class CounterThread extends Thread { // Define a class CounterThread that extends the Thread class
    private Counter counter; // Declare a private Counter object

    public CounterThread(Counter counter) { // Constructor that takes a Counter object as a parameter
        this.counter = counter; // Initialize the counter field with the provided Counter object
    }

    @Override
    public void run() { // Override the run method of the Thread class
        for (int i = 0; i < 1000; i++) { // Loop 1000 times
            counter.increment(); // Call the increment method on the Counter object
        }
    }
}

public class threadSynchro { // Define the main class
    public static void main(String[] args) { // Main method, entry point of the program
        Counter counter = new Counter(); // Create a new Counter object
        CounterThread thread1 = new CounterThread(counter); // Create a new CounterThread object, passing the Counter object
        CounterThread thread2 = new CounterThread(counter); // Create another CounterThread object, passing the same Counter object

        thread1.start(); // Start the first thread
        thread2.start(); // Start the second thread
        thread1.join();
        thread2.join();
        // try {
        //     thread1.join(); // Wait for the first thread to finish
        //     thread2.join(); // Wait for the second thread to finish
        // } catch (InterruptedException e) { // Catch any InterruptedException that might occur
        //     e.printStackTrace(); // Print the stack trace if an exception occurs
        // }

        System.out.println("Final count: " + counter.getCount()); // Print the final count from the Counter object
    }
}
// op,
// Final count: 2000