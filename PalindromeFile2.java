
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
public class PalindromeFile2{
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
        PalindromeFile2 p=new PalindromeFile2();

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

        try(BufferedReader reader=new BufferedReader(new FileReader("Second.txt"))){
            String line;
            while((line=reader.readLine())!=null){
                int[] freq=new int[26];

                for(int i=0;i<line.length();i++){
                    char c=Character.toLowerCase(line.charAt(i));
                    if(c>='a' && c<='z'){
                        freq[c-'a']++;
                    }
                }

                for(int i=0;i<26;i++){
                    if(freq[i]>0){
                        System.out.println((char)(i+'a')+" Repeated "+freq[i]+" times.");
                    }
                }
            System.out.println();
          }
        }
        catch(IOException e){
            System.out.println("error: "+e.getMessage());
        }
    }
}
//o,p
