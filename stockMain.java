import java.util.Scanner;

class ItemList{
    int Itemno;
    String name;
    float price;
    int quantity;
    public ItemList(int itemNumber,String nm,float pr,int qty){
        this.Itemno=itemNumber;
        this.name=nm;
        this.price=pr;
        this.quantity=qty;
    }
    public float getStockValue(){
        return price*quantity;
    }
    @Override
    public String toString(){
        return "Item number: "+Itemno+"\nItem Name: "+name+"\nItem price: "+price+"\nQuantity: "+quantity;
    }
}
class ItemStock{
    ItemList[] items;
    int itemCount;
    public ItemStock(int size){
        items=new ItemList[size];
        itemCount=0;
    }
    public void addItem(ItemList item){
        if(itemCount<items.length){
            items[itemCount++]=item;
        }
        else{
            System.out.println("List is full\n");
        }
    }
    public void deleteItem(int ItemNumber){
        for(int i=0;i<itemCount;i++){
            if(items[i].Itemno==ItemNumber){
                for(int j=i;j<itemCount-1;j++){
                    items[j]=items[j+1];
                }
                items[--itemCount]=null;
                System.out.println("deleted the item!");
                return;
            }
        }
        System.out.println("item not found!\n");
    }
    public float calculateStockValue(){
        float totalValue=0;
        for(int i=0;i<itemCount;i++){
            totalValue+=items[i].getStockValue();
        }
        return totalValue;
    }

    public void displayDescendingOrder(){
        for(int i=0;i<itemCount-1;i++){
            for(int j=i+1;j<itemCount;j++){
                if(items[i].price<items[j].price){
                    ItemList temp=items[i];
                    items[i]=items[j];
                    items[j]=temp;
                }
            }
        }
        for (int i = 0; i < itemCount; i++) {
            System.out.println(items[i]);
        }
    }

}

public class stockMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of items: ");
        int n = scanner.nextInt();
        ItemStock itemStock = new ItemStock(n);
        int choice;

        do {
            System.out.println("Menu:");
            System.out.println("1. Add Item");
            System.out.println("2. Delete Item");
            System.out.println("3. Calculate Stock Value");
            System.out.println("4. Display Items in Descending Order of Price");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            switch(choice){
                case 1 : {
                    System.out.println("enter itemNumber: ");
                    int itemno=scanner.nextInt();
                    scanner.nextLine();
                    System.out.println("enter name: ");
                    String name=scanner.nextLine();
                    System.out.println("enter price: ");
                    float price=scanner.nextFloat();
                    System.out.println("enter quantity: ");
                    int quantity=scanner.nextInt();
                    itemStock.addItem(new ItemList(itemno,name,price,quantity));
                    break;
                }
                case 2:{
                    System.out.println("enter itemnumber to delete: ");
                    int in=scanner.nextInt();
                    itemStock.deleteItem(in);
                    break;
                }
                case 3:{
                    System.out.println("the total stock value is: "+itemStock.calculateStockValue());
                    break;
                }
                case 4:{
                    System.out.println("Displaying the items in price high to low:");
                    itemStock.displayDescendingOrder();
                    break;
                }
                case 0:{
                    break;
                }
            }
    }while(choice!=0);
    scanner.close();
    }
}
// Enter the number of items: 3
// Menu:
// 1. Add Item
// 2. Delete Item
// 3. Calculate Stock Value
// 4. Display Items in Descending Order of Price
// 0. Exit
// Enter your choice: 1
// enter itemNumber: 
// 1    
// enter name: 
// sinan
// enter price: 
// 50
// enter quantity: 
// 2
// Menu:
// 1. Add Item
// 2. Delete Item
// 3. Calculate Stock Value
// 4. Display Items in Descending Order of Price
// 0. Exit
// Enter your choice: 1
// enter itemNumber: 
// 2
// enter name: 
// nas
// enter price: 
// 80
// enter quantity: 
// 4
// Menu:
// 1. Add Item
// 2. Delete Item
// 3. Calculate Stock Value
// 4. Display Items in Descending Order of Price
// 0. Exit
// Enter your choice: 1
// enter itemNumber: 
// 3
// enter name: 
// aadil
// enter price: 
// 99
// enter quantity: 
// 5
// Menu:
// 1. Add Item
// 2. Delete Item
// 3. Calculate Stock Value
// 4. Display Items in Descending Order of Price
// 0. Exit
// Enter your choice: 4
// Displaying the items in price high to low:
// Item number: 3
// Item Name: aadil
// Item price: 99.0
// Quantity: 5
// Item number: 2
// Item Name: nas
// Item price: 80.0
// Quantity: 4
// Item number: 1
// Item Name: sinan
// Item price: 50.0
// Quantity: 2
// Menu:
// 1. Add Item
// 2. Delete Item
// 3. Calculate Stock Value
// 4. Display Items in Descending Order of Price
// 0. Exit
// Enter your choice: 2
// enter itemnumber to delete: 
// 2
// deleted the item!
// Menu:
// 1. Add Item
// 2. Delete Item
// 3. Calculate Stock Value
// 4. Display Items in Descending Order of Price
// 0. Exit
// Enter your choice: 4
// Displaying the items in price high to low:
// Item number: 3
// Item Name: aadil
// Item price: 99.0
// Quantity: 5
// Item number: 1
// Item Name: sinan
// Item price: 50.0
// Quantity: 2