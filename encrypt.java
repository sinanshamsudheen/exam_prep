import java.io.*;
import java.util.*;

class convert{
    public convert(String line){
        try(BufferedWriter writer=new BufferedWriter(new FileWriter("First.txt"));
        BufferedReader reader=new BufferedReader(new FileReader("First.txt"))){
            
            System.out.println("intial text: "+line);
            System.out.println("after encryption: "+toEncrypt(line));
            writer.write((toEncrypt(line)));
            System.out.println("successfully add to the file");

            String input=reader.readLine();
            System.out.println((toDecrypt(input)));

        }catch(IOException e){
            e.printStackTrace();
        }


    }
    public String toEncrypt(String line){
        StringBuilder s=new StringBuilder();
        int i=0;
        for(char c: line.toCharArray()){
            s.append((char)(c+2));
        }
        return s.toString();
    }
    public String toDecrypt(String text){
        StringBuilder s=new StringBuilder();
        for(char c:text.toCharArray()){
            s.append((char)(c-2));
        }
        return s.toString();
    }
}
public class encrypt {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter ur string: ");
        String s=sc.nextLine();
        convert c=new convert(s);
    }
}
