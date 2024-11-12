public class garbageCollect {
    public static void main(String[] args) {
        garbageCollect obj1 = new garbageCollect();
        garbageCollect obj2 = new garbageCollect();
        
        // Assign obj1 to obj2, now obj1 is eligible for garbage collection
        obj1 = null;
        
        // Suggesting JVM to run Garbage Collector
        System.gc();
        
        System.out.println("Garbage Collection demo completed.");
    }
    @Override
    protected void finalize() throws Throwable {
        try {
            System.out.println("Garbage collector called");
            System.out.println("Object garbage collected: " + this);
        } finally {
            super.finalize();
        }
    }
}