#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// int main(void){
//     int x;
//     printf("Please enter a number:");
//     scanf("%d",&x);
//     if(x%2>0){
//         printf("Odd.");
//     }
//     else{
//         printf("Even.");
//     }
//     return 0;
// }


// int print();
// int square(int);

// int main(){
//     print();
//     return 0;
// }
// int print(){
//     printf("%d",square(5));
//     return 0;
// }
// int square(int x){
//     return x*x;
// }


// int main(){
//     int a = 10;
//     int count = 0;
//     while(a > 5 && a < 9){
//         a = a-2;
//         count--;
//     }
//     printf("%d\n",a);
//     printf("%d",count);
//     return 0;
// }

// int main(){
// //a1x+b1y=c1 r+s=N
// //a2x+b2y=c2 5r+7s=M
//     int a1 = 1,a2 = 5,b1 = 1,b2 = 7,c1,c2;
//     scanf("%d %d",&c1,&c2);
//     int x=(b2*c1-b1*c2)/(a1*b2-b1*a2);
//     int y=(a1*c2-a2*c1)/(a1*b2-b1*a2);
//     printf("%d %d\n",x,y);
// // }

// int main(){
//     long int a;
//     float g, b, s, pg;
//     scanf("%f %f %f",&g,&b,&s);
//     pg = g / s;
//     a = g * b;
//     printf("%ld\n%.2f\n",a,pg);

// }

// int main(){
//     float f;
//     float c;
//     scanf("%f",&c);
//     f = (9*c)/5 + 32;
//     printf("%0.1f\n",f);
// }


// int main(){
//     char c;
//     printf("please enter the character you want to convert:");
//     scanf("%c",&c);
//     int a = c;
//     int n;
//     scanf("%d",&n);
//     printf("the ascii code of %c is %d\n",c,c);
//     printf("the %dth number after %c is %c.",n,c,a+n);
// }

// int main(){
//     int x;
//     scanf("%d",&x);
//     printf("%d",x%26);
// }


// int main(){

// char str[30];

// scanf("%[0-9]", str);

// printf("%s\n", str);

// return 0;

// }


// int main(){
//     char c[3];
//     int x;
//     scanf("%c%c%c %d", &c[0], &c[1], &c[2], &x);
//     for(int i=0;c[i]!='\0';i++){
//         if(c[i]+x>='A'&&c[i]+x<='Z'){
//             c[i] = c[i]+x;
//         }
//         else if(c[i]+x<'A'){
//             c[i] = c[i]+x+26;
//         }
//         else if(c[i]+x>'Z'){
//             c[i] = c[i]+x-26;
//         }
//     }
//     printf("%c%c%c\n",c[0],c[1],c[2]);
// }


// int main(){
//     char a[5];
//     scanf("%s",a);
//     int len = sizeof(a)/sizeof(a[0]);
//     for(int i=0;i<strlen(a);i++){
//         printf("%c",a[i]);
//     }
//     printf("%d",len);
// }


// int main(){
//     char a[150];
//     scanf("%[0-9]",a);
//     for(int i=0;i<strlen(a);i++){
//         printf("%c",a[i]);
//     }
// }


// int main(){
//     char a[3]={'0'}, b[3]={'0'};
//     int sum[3]={0};
//     int carry, i;
//     scanf("%s",a);
//     scanf("%s",b);
//     for(carry=0,i=2;i>=0;i--){
//         sum[i] = a[i] + b[i] + carry;
//         carry = sum[i]/10;
//         sum[i]%=10;
//     }
//     for(i=0;i<3;i++){
//         printf("%d",sum[i]);
//     }
// }





// int main(){
//     char A[10][10];
//     scanf("%s",A[0]);
//     scanf("%s",A[1]);

    // for(int i=0;i<9;i++){
    //     printf("%c",A[0][i]);
    // }
    // printf("%c\n",A[0][9]);
    // for(int i=0;i<9;i++){
    //     printf("%c",A[1][i]);
    // }
    // printf("%c\n",A[1][9]);
    // char temp;
    // temp = A[0][2];
    // A[0][2] = ',';
    // A[0][3] = temp;
//     printf("%s",A[0]);
// }

// int main(){
//     int dir[10][10] = {{1,0},{0,1},{-1,1},{1,1}};
//     for(int i=0;i<4;i++){
//         printf("%d %d\n",dir[i][0],dir[i][1]);
//     }
// }

// int a = 0;

// void mul(){
//     extern int a; // 會去global找變數
//     printf("%d",a*2);
//     return;
// }

// int main(){
//     int a = 2;
//     mul();
//     printf("%d",a);
// }


// #define ADD(X, Y) (X+Y)
// #define ADD(X, Y) X+Y

// int main(void) {
//     int result;
//     result = 2 * ADD(1, 2) * 4;
//     printf("%d\n", result);
//     return 0;
// }

int main(){
    char A = 'A';
    printf("%d\n", A);
}