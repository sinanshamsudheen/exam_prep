// // #include<stdio.h>
// // void main(){
// //     int a=10;
// //     int *ptr = &a;
// //     printf("%d",ptr);
// // }
// // #include <stdio.h>
// // #include <string.h>
// // void main()
// // {
// //     char line[150];
// //     int v, c, s, i;
// //     v = c = s = 0;
// //     printf("enter the line of string");
// //     fgets(line,150,stdin);
// //     for (i = 0; line[i] != '\0'; i++)
// //     {
// //         if (line[i] == 'a' || line[i] == 'A' || line[i] == 'e' || line[i] == 'E' || line[i] == 'i' || line[i] == 'I' || line[i] == 'o' || line[i] == 'O' || line[i] == 'u' || line[i] == 'U')
// //         {
// //             v++;
// //         }
// //         else if (line[i] == ' ')
// //         {
// //             s++;
// //         }
// //         else
// //         {
// //             c++;
// //         }
// //     }
// //     printf("vowels : %d", v);
// //     printf("consonants : %d", c);
// //     printf("space :%d", s);
// // }
// #include<stdio.h>
// #include<string.h>
// void main()
// {
//     char str1[20],str2[20],str3[100];
//     int i=0,j=0;
//     printf("enter the first string: ");
//     scanf("%s",str1);
//     printf("enter the second string: ");
//     scanf("%s",str2);

//     while (str1[i] != '\0') {
//         str3[j] = str1[i];
//         i++;
//         j++;
//     }
//     i = 0;
//     while (str2[i] != '\0') {
//         str3[j] = str2[i];
//         i++;
//         j++;
//     }
//     str3[j] = '\0';
//     printf("The concatenated string is: %s",str3);
// }
// C program to illustrate situation 
// where flush(stdin) is required only 
// in certain compilers. 
#include <stdio.h> 
#include<stdlib.h> 
int main() 
{ 
	char str[20]; 
	int i; 
	for (i=0; i<2; i++) 
	{ 
		scanf("%s", &str); 
		printf("%s\n", str); 
		// fflush(stdin); 
	} 
	return 0; 
} 

helehelel

#include<stdio.h> 
int main(){
  int a,b,sum=0,pdt=0;
  printf("Enter the values of a and b :\n");
  scanf("%d%d",&a,&b);
  sum=a+b;
  pdt=a*b;
  printf("The sum is: %d\n",sum);
  printf("The product is: %d",pdt);
}

//   area of a circle
#include<stdio.h> 
int main(){
    float area;
    int r;
    printf("enter the radius : ");
    scanf("%d",&r);
    area=3.14*r*r;
    printf("the area is : %f",area);
}
// int 1,2,3
// float 2.3, 4.5
// char s,i,n,a,n
// string sinan
