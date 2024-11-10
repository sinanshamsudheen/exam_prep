import java.io.*;
import java.util.Scanner;

public class encryption {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string to encrypt:");
        String input = scanner.nextLine();
        String encryptedString = encrypt(input);

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("sample.txt"))) {
            writer.write(encryptedString);
        } catch (IOException e) {
            e.printStackTrace();
        }

        String decryptedString = "";
        try (BufferedReader reader = new BufferedReader(new FileReader("sample.txt"))) {
            decryptedString = decrypt(reader.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Decrypted string: " + decryptedString);
    }

    private static String encrypt(String input) {
        StringBuilder encrypted = new StringBuilder();
        for (char c : input.toCharArray()) {
            encrypted.append((char) (c + 2));
        }
        return encrypted.toString();
    }

    private static String decrypt(String input) {
        StringBuilder decrypted = new StringBuilder();
        for (char c : input.toCharArray()) {
            decrypted.append((char) (c - 2));
        }
        return decrypted.toString();
    }
}
//o,p
string

