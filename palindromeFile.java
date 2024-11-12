
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
public class palindromeFile{
    public boolean  palindromeChk(String s){
        int len=s.length();
        int j=len-1,i=0;

        while(i<j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public static void main(String[] args) throws IOException{
        Scanner sc=new Scanner(System.in);
        palindromeFile p=new palindromeFile();

        System.out.println("enter ur string: ");
        String s=sc.nextLine();
        String[] words=s.split("\\s+");

        try(FileWriter fwPal=new FileWriter("First.txt",true);
        FileWriter fwNonPal=new FileWriter("Second.txt",true)){

            for(String word : words){
                boolean isPalindrome=p.palindromeChk(word);
                if(isPalindrome){
                    fwPal.write(word+"\n");
                }
                else{
                    fwNonPal.write(word+"\n");
                }
            }
        }catch(IOException e){
            System.out.println("error: "+e.getMessage());
        }

        BufferedReader reader=new BufferedReader(new FileReader("Second.txt"));
        String line;
        while((line=reader.readLine())!=null){
            for(String word:line.split("\\s+")){
                for(int i=0;i<word.length();i++){
                    int count=0;
                    for(int j=0;j<word.length();j++){
                        if(word.charAt(i)==word.charAt(j)){
                            count++;
                        }
                    }
                    System.out.println(word.charAt(i)+" Repeated "+count+" times.");
                }
            }
            System.out.println();
        }
    }
}
//o,p
// enter ur string: 
// sinan wataw rotor food
// s Repeated 1 times.
// i Repeated 1 times.
// n Repeated 2 times.
// a Repeated 1 times.
// n Repeated 2 times.

// f Repeated 1 times.
// o Repeated 2 times.
// o Repeated 2 times.
// d Repeated 1 times.
