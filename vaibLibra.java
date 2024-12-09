import java.io.*;
import java.util.*;
class bookmanager
{
    private static final String FILE_NAME="Books.txt";
    private static final String TEMP_NAME="temp_books.txt";
    public void addBook(String isbn,String title,String author,double price,int pages, String pubdate)
    {
        try
        {
            FileWriter f=new FileWriter(FILE_NAME,true);
            String data=isbn + " " + title +" " +author + " " + price+" "+pages+" "+pubdate;
            f.write(data+"\n");
            System.out.println("Book Added successfully.");
            f.close();  
        }
        catch(IOException e)
        {
            System.out.println("Error adding book:"+e.getMessage());
        }
    }
    public void search(String isbn)
    {
        try{
            FileReader f= new FileReader(FILE_NAME);
            Scanner sc=new Scanner(f);
            boolean found=false;
            while(sc.hasNextLine())
            {
                String[] bookdata=sc.nextLine().split(" ");
                if(bookdata[0].equals(isbn))
                {
                    System.out.println("Book found:");
                    display(bookdata);
                    found=true;
                    break;
                }
            }
            if(found==false)
            {
                System.out.println("Book not found.");
            }
            sc.close();
        }
        catch(IOException e){
            System.out.println("Error searching book:"+e.getMessage());}
    }
    public void update(String isbn)
    {
        try
        {
            Scanner sc=new Scanner(System.in);
            Scanner fr=new Scanner(FILE_NAME);
            FileWriter fw=new FileWriter(TEMP_NAME);
            boolean found=false;
            while(sc.hasNextLine())
            {
                String[] bookdata=fr.nextLine().split(" ");
                if(bookdata[0].equals(isbn))
                {
                    System.out.println("Enter new title:");
                    bookdata[1]=sc.nextLine();
                    System.out.println("Enter new author:");
                    bookdata[2]=sc.nextLine();
                    System.out.println("Enter new price:");
                    bookdata[3]=sc.nextLine();
                    System.out.println("Enter new pages:");
                    bookdata[4]=sc.nextLine();
                    System.out.println("Enter new publish date:");
                    bookdata[5]=sc.nextLine();
                    found=true;
                }
                fw.write(String.join(" ",bookdata)+"\n");
            }
            if(found)
            {
                System.out.println("Book Updated Successfully.");
            }
            else{System.out.println("Book Not Found.");}
            sc.close();
            fr.close();
            fw.close();
        }
        catch(IOException e){
            System.out.println("Error updating book:"+e.getMessage());
        }
        new File(TEMP_NAME).renameTo(new File(FILE_NAME));
    }
    public void delete(String isbn)
    {
        try{
            FileReader fr=new FileReader(FILE_NAME);
            Scanner sc=new Scanner(fr);
            FileWriter fw=new FileWriter(TEMP_NAME);
            boolean found=false;
            while(sc.hasNextLine())
            {
                String[] bookdata=sc.nextLine().split(" ");
                if(!bookdata[0].equals(isbn))
                {
                    fw.write(String.join(" ",bookdata)+"\n");
                }
                else{found=true;}
            }
        if(found){System.out.println("Book deleted Successfully.");}
        else{System.out.println("Book not found.");}
        sc.close();
        fw.close();
        }
        catch(IOException e)
        {
            System.out.println("Error deleting book:"+e.getMessage());
        }
        new File(TEMP_NAME).renameTo(new File(FILE_NAME));
        
    }
    public void displayAllbooks()
    {
        try
        {
            FileReader f=new FileReader(FILE_NAME);
            Scanner sc=new Scanner(f);
            while(sc.hasNextLine())
            {
                String[] bookdata=sc.nextLine().split(" ");
                display(bookdata);
            }
            sc.close();
        }
        catch(IOException e)
        {
            System.out.println("Error displaying books:"+e.getMessage());
        }
    }
    public void display(String[] bookdata)
    {
        System.out.println("ISBN: "+bookdata[0]);
        System.out.println("Title: "+bookdata[1]);
        System.out.println("Author: "+bookdata[2]);
        System.out.println("Price: $"+bookdata[3]);
        System.out.println("Pages: "+bookdata[4]);
        System.out.println("Publish Date: "+bookdata[5]);
        System.out.println();
    }
}
public class vaibLibra{
    public static void main(String[] args) {
        bookmanager manager=new bookmanager();
        Scanner sc=new Scanner(System.in);
        while(true)
        {
            System.out.println("\nLibrary Menu:");
            System.out.println("1.Add book 2.Search Book 3.Update book 4.Delete Book 5.DisplayAllBooks 6.Exit");
            int ch=sc.nextInt();
            sc.nextLine();
            switch(ch)
            {
                case 1:
                        System.out.println("Enter ISBN: ");
                        String isbn=sc.nextLine();
                        System.out.println("Enter title: ");
                        String title=sc.nextLine();
                        System.out.println("Enter author: ");
                        String author=sc.nextLine();
                        System.out.println("Enter Price: ");
                        double price=sc.nextDouble();
                        System.out.println("Enter pages: ");
                        int page=sc.nextInt();
                        sc.nextLine();
                        System.out.println("Enter publish date: ");
                        String pubdate=sc.nextLine();
                        manager.addBook(isbn, title, author, price, page, pubdate);
                        break;
                case 2: 
                        System.out.println("Enter ISBN to search:");
                        isbn=sc.nextLine();
                        manager.search(isbn);
                        break;
                case 3:
                        System.out.println("Enter ISBN to update:");
                        isbn=sc.nextLine();
                        manager.update(isbn);
                        break;
                case 4:
                        System.out.println("Enter ISBN to delete: ");
                        isbn=sc.nextLine();
                        manager.delete(isbn);
                        break;
                case 5: 
                        System.out.println("Displaying All books:");
                        manager.displayAllbooks();
                        break;
                case 6: 
                        System.out.println("Exiting...");
                        sc.close();
                        System.exit(0);
                        break;
                default: System.out.println("INVALID CHOICE");
            }
        }
    }
}