#include <stdio.h>
#include <math.h>
int first4(int x){
   return x/10000;
}
int last4(int x){
   return x%10000;
}
int first8(int x){
   return x/100000000;
}
int last8(int x){
   return x%100000000;
}
int shift4(int x){
   return x*10000;
}
//suppose that input = x = 12345678
//then a = 1234 , b = 5678
int main(void){
    int x;
    int a, b;
    int c1, c2, c3;
    scanf("%8d",&x); 
    a = first4(x);
    b = last4(x);
    c3 = last4(b*b);
    c2 = shift4(last4(a*a))+2*a*b+first4(b*b);
    c1 = first4(a*a) + (c2/pow(10,8));
    printf("%4d%08d%04d",c1,last8(c2),c3);
    return 0;
}