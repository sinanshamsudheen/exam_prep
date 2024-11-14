import java.util.*;

public class stringtokenizer{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n;
        int sum=0;
        System.out.println("enter numbers separated by a gap: ");
        String text=sc.nextLine();
        StringTokenizer st=new StringTokenizer(text);
        while(st.hasMoreTokens()){
            String temp=st.nextToken();
            n=Integer.parseInt(temp);
            System.out.println(n);
            sum+=n;
        }
        System.out.println("the sum of elements is : "+sum);
        sc.close();
    }
}
// enter numbers separated by a gap: 
// 30 40 60
// 30
// 40
// 60
// the sum of elements is : 130