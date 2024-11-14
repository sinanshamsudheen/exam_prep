import java.util.Arrays;

interface ArrayInterface {
    void sort();
    void insert(int element);
    void delete(int element);
    int binarySearch(int element);
}

class SingleArray implements ArrayInterface {
    private int[] array;
    private int size;
    private static final int INITIAL_CAPACITY = 10;

    public SingleArray() {
        array = new int[INITIAL_CAPACITY];
        size = 0;
    }

    @Override
    public void sort() {
        Arrays.sort(array, 0, size);
    }

    @Override
    public void insert(int element) {
        if (size == array.length) {
            resize();
        }
        array[size++] = element;
    }

    @Override
    public void delete(int element) {
        int index = binarySearch(element);
        if (index == -1) {
            System.out.println("Element not found.");
            return;
        }
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

    @Override
    public int binarySearch(int element) {
        sort();
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (array[mid] == element) {
                return mid;
            }
            if (array[mid] < element) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    private void resize() {
        array = Arrays.copyOf(array, array.length * 2);
    }

    public void display() {
        System.out.print("Array elements: ");
        for(int i=0;i<size;i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    // Example usage
    public static void main(String[] args) {
        SingleArray sa = new SingleArray();
        sa.insert(5);
        sa.insert(3);
        sa.insert(8);
        sa.insert(1);
        sa.display();

        sa.sort();
        sa.display();

        sa.delete(3);
        sa.display();

        int index = sa.binarySearch(8);
        if(index != -1){
            System.out.println("Element found at index: " + index);
        } else {
            System.out.println("Element not found.");
        }
    }
}
