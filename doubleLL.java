public class doubleLL {
    class Node {
        int data;
        Node prev;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    private Node head;

    // Method to add a node at the end of the list
    public void add(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        newNode.prev = temp;
    }

    // Method to delete a node with a given value
    public void delete(int data) {
        if (head == null) {
            return;
        }
        Node temp = head;
        while (temp != null && temp.data != data) {
            temp = temp.next;
        }
        if (temp == null) {
            return; // Element not found
        }
        if (temp.prev != null) {
            temp.prev.next = temp.next;
        } else {
            head = temp.next; // Deleting the head node
        }
        if (temp.next != null) {
            temp.next.prev = temp.prev;
        }
    }

    // Method to display the contents of the list
    public void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        doubleLL dll = new doubleLL();
        dll.add(1);
        dll.add(2);
        dll.add(3);
        dll.add(4);
        dll.add(5);

        System.out.println("Original List:");
        dll.display();

        dll.delete(3);

        System.out.println("List after deleting element 3:");
        dll.display();
    }
}
// Original List:
// 1 2 3 4 5 
// List after deleting element 3:
// 1 2 4 5