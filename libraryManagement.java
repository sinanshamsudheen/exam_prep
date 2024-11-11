import java.util.Scanner;
class Book {
     int bookNo;
     String bookName;
     String publisher;
     int numCopiesIssued;

    public Book(int bookNo, String bookName, String publisher, int numCopiesIssued) {
        this.bookNo = bookNo;
        this.bookName = bookName;
        this.publisher = publisher;
        this.numCopiesIssued = numCopiesIssued;
    }

    public void issueBook() {
        if (numCopiesIssued > 0) {
            numCopiesIssued--;
            System.out.println("Book issued successfully.");
        } else {
            System.out.println("Book not available.");
        }
    }

    public void returnBook(boolean isDueDateOver) throws DueDateOverException {
        if (isDueDateOver) {
            throw new DueDateOverException("Due date is over. Cannot return the book.");
        } else {
            numCopiesIssued++;
            System.out.println("Book returned successfully.");
        }
    }

    @Override
    public String toString() {
        return "Book Number: " + bookNo + "\nBook Name: " + bookName + "\nPublisher: " + publisher + "\nNumber of Copies Issued: " + numCopiesIssued;
    }
}

class DueDateOverException extends Exception {
    public DueDateOverException(String message) {
        super(message);
    }
}

public class libraryManagement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of books: ");
        int n = scanner.nextInt();
        Book[] books = new Book[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter book number: ");
            while (!scanner.hasNextInt()) {
                System.out.println("Invalid input. Please enter a valid book number.");
                scanner.next(); // consume invalid input
            }
            int bookNo = scanner.nextInt();
            scanner.nextLine(); // consume newline

            System.out.print("Enter book name: ");
            String bookName = scanner.nextLine();

            System.out.print("Enter publisher: ");
            String publisher = scanner.nextLine();

            System.out.print("Enter number of copies issued: ");
            while (!scanner.hasNextInt()) {
                System.out.println("Invalid input. Please enter a valid number of copies issued.");
                scanner.next(); // consume invalid input
            }
            int numCopiesIssued = scanner.nextInt();
            scanner.nextLine(); // consume newline

            books[i] = new Book(bookNo, bookName, publisher, numCopiesIssued);
        }

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Issue Book");
            System.out.println("2. Return Book");
            System.out.println("3. Display Book Details");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1 -> {
                    System.out.print("Enter book number to issue: ");
                    int bookNo = scanner.nextInt();
                    boolean found = false;
                    for (Book book : books) {
                        if (bookNo == book.bookNo) {
                            book.issueBook();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("Book not found.");
                    }
                }
                case 2 -> {
                    System.out.print("Enter book number to return: ");
                    int bookNo = scanner.nextInt();
                    System.out.print("Is the due date over? (true/false): ");
                    boolean isDueDateOver = scanner.nextBoolean();
                    boolean found = false;
                    for (Book book : books) {
                        if (bookNo == book.bookNo) {
                            try {
                                book.returnBook(isDueDateOver);
                            } catch (DueDateOverException e) {
                                System.out.println(e.getMessage());
                            }
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("Book not found.");
                    }
                }
                case 3 -> {
                    System.out.print("Enter book number to display details: ");
                    int bookNo = scanner.nextInt();
                    boolean found = false;
                    for (Book book : books) {
                        if (bookNo == book.bookNo) {
                            System.out.println(book);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("Book not found.");
                    }
                }
                case 4 -> {
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                }
                default -> System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
// Enter the number of books: 2
// Enter book number: 101
// Enter book name: Java Programming
// Enter publisher: Pearson
// Enter number of copies issued: 5
// Enter book number: 102
// Enter book name: Data Structures
// Enter publisher: McGraw-Hill
// Enter number of copies issued: 3
// Menu:
// 1. Issue Book
// 2. Return Book
// 3. Display Book Details
// 4. Exit
// Enter your choice: 1
// Enter book number to issue: 101
// Book issued successfully.
// Menu:
// 1. Issue Book
// 2. Return Book
// 3. Display Book Details
// 4. Exit
// Enter your choice: 3
// Enter book number to display details: 101
// Book Number: 101
// Book Name: Java Programming
// Publisher: Pearson
// Number of Copies Issued: 4
// Menu:
// 1. Issue Book
// 2. Return Book
// 3. Display Book Details
// 4. Exit
// Enter your choice: 2
// Enter book number to return: 101
// Is the due date over? (true/false): false
// Book returned successfully.
// Menu:
// 1. Issue Book
// 2. Return Book
// 3. Display Book Details
// 4. Exit
// Enter your choice: 4
// Exiting...