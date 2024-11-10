
import java.util.Scanner;
//r1-number of rows in first matrix
//c1-number of columns in first matrix
//r2-number of columns in second matrix
//c2-number of columns in second matrix
public class matrixMult{
    public void result(int a1[][],int a2[][],int r1,int r2,int c2){
        int[][] res=new int[100][100];
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                res[i][j]=0;
                for(int k=0;k<r2;k++){
                    res[i][j]+=a1[i][k]*a2[k][j];
                }
                System.out.print(res[i][j]+" ");
            }
            System.out.println();
        }
        // for(int i=0;i<r1;i++){
        //     for(int j=0;j<c1;j++){
        //     }
        //     System.out.println();
        // }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of rows and columns of the first matrix: ");
        int r1=sc.nextInt();
        int c1=sc.nextInt();
        int[][] a1=new int[100][100];
        int[][] a2=new int[100][100];
        System.out.println("enter the elements for first matrix:");
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                a1[i][j]=sc.nextInt();
            }
        }
        System.out.println("Enter the number of rows and columns of the second matrix: ");
        int r2=sc.nextInt();
        int c2=sc.nextInt();
        System.out.println("enter the elements for second matrix:");
        for(int i=0;i<r2;i++){
            for(int j=0;j<c2;j++){
                a2[i][j]=sc.nextInt();
            }
        }
        matrixMult obj=new matrixMult();
        if(c1!=r2){
            System.out.println("Matrix multiplication is not possible");
        }else{
            obj.result(a1, a2, r1, r2, c2);
        }

    }
}
