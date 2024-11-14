public class dLL {
    class Node{
        int data;
        Node left;
        Node right;

        Node(int data){
            this.data=data;
        }
    }
    private Node head;

    public void add(int data){
        Node New=new Node(data);
        if(head==null){
            head=New;
            return;
        }
        Node temp=head;
        while(temp.right!=null){
            temp=temp.right;
        }
        temp.right=New;
        New.left=temp;
    }
    public void delete(int data){
        Node temp=head;
        Node prev=head;
        if(temp.data==data){
            head=temp.right;
        }
        while(temp!=null && temp.data!=data){
            prev=temp;
            temp=temp.right;
        }
        if(temp==null){
            System.out.println("not found");
            return;
        }
        Node ptr=temp.right;
        prev.right=ptr;
        ptr.left=prev;
    }
    public void traverse(){
        Node temp=head;
        while(temp!=null){
            System.out.print(temp.data+"-> ");
            temp=temp.right;
        }
        System.out.print("NULL\n");
    }
    public static void main(String[] args) {
        dLL l=new dLL();
        l.add(3);
        l.add(5);
        l.add(7);
        l.add(9);
        l.add(0);

        l.traverse();
        l.delete(7);
        l.traverse();
    }
}
// o/p,
// 3-> 5-> 7-> 9-> 0-> NULL
// 3-> 5-> 9-> 0-> NULL