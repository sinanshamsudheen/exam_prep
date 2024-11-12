// class ItemList {
//     int itemNumber;
//     String name;
//     float price;
//     int quantity;
//     public ItemList(int itemNumber,String nm,float pr,int qty){
//         this.itemNumber=itemNumber;
//         this.name=nm;
//         this.price=pr;
//         this.quantity=qty;
//     }
//     public float getStockValue(){
//         return price*quantity;
//     }
//     @Override
//     public String toString(){
//         return "Item Number: "+itemNumber+"\nName: "+name+"\nPrice: "+price+"\nQuantity: "+quantity;
//     }
// }
// class itemStock{
    
// }
// public class itemList{
//     public static void main(String[] args) {
        
//     }
// }
import java.util.Scanner;

class ItemList {
    int itemNumber;
    String name;
    float price;
    int quantity;

    public ItemList(int itemNumber, String name, float price, int quantity) {
        this.itemNumber = itemNumber;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public float getStockValue() {
        return price * quantity;
    }

    // @Override
    // public String toString() {
    //     return "ItemNumber: " + itemNumber + ", Name: " + name + ", Price: " + price + ", Quantity: " + quantity;
    // }
}

class ItemStock {
    ItemList[] items;
    int itemCount;

    public ItemStock(int size) {
        items = new ItemList[size];
        itemCount = 0;
    }

    public void addItem(ItemList item) {
        if (itemCount < items.length) {
            items[itemCount++] = item;
        } else {
            System.out.println("Stock is full. Cannot add more items.");
        }
    }

    public void deleteItem(int itemNumber) {
        for (int i = 0; i < itemCount; i++) {
            if (items[i].itemNumber == itemNumber) {
                for (int j = i; j < itemCount - 1; j++) {
                    items[j] = items[j + 1];
                }
                items[--itemCount] = null;
                return;
            }
        }
        System.out.println("Item not found.");
    }

    public float calculateStockValue() {
        float totalValue = 0;
        for (int i = 0; i < itemCount; i++) {
            totalValue += items[i].getStockValue();
        }
        return totalValue;
    }

    public void displayItemsDescendingOrder() {
        for (int i = 0; i < itemCount - 1; i++) {
            for (int j = 0; j < itemCount - i - 1; j++) {
                if (items[j].price < items[j + 1].price) {
                    ItemList temp = items[j];
                    items[j] = items[j + 1];
                    items[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < itemCount; i++) {
            System.out.println(items[i]);
        }
    }
}
public class MainList {
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
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter item number: ");
                    int itemNumber = scanner.nextInt();
                    scanner.nextLine(); // consume newline
                    System.out.print("Enter item name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter item price: ");
                    float price = scanner.nextFloat();
                    System.out.print("Enter item quantity: ");
                    int quantity = scanner.nextInt();
                    itemStock.addItem(new ItemList(itemNumber, name, price, quantity));
                    break;
                case 2:
                    System.out.print("Enter item number to delete: ");
                    int deleteItemNumber = scanner.nextInt();
                    itemStock.deleteItem(deleteItemNumber);
                    break;
                case 3:
                    System.out.println("Total Stock Value: " + itemStock.calculateStockValue());
                    break;
                case 4:
                    itemStock.displayItemsDescendingOrder();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);

        scanner.close();
    }
}