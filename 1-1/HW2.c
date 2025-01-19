#include <stdio.h>
int time(){
    int t;
    scanf("%d",&t);
    if(t < 1200){
        printf("%02d:%02d a.m.",t/100,t%100);
    }
    if(t >= 1200){
        int tp = t-1200;
        printf("%02d:%02d p.m.",tp/100,tp%100);
    }
}
int math(){
    float n1,n2;
    char o;
    scanf("%f %c %f",&n1,&o,&n2);
    if(o == '+'){
        printf("%.3f\n",n1+n2);
    }
    if(o == '-'){
        printf("%.3f\n",n1-n2);
    }
    if(o == '*'){
        printf("%.3f\n",n1*n2);
    }
    if(o == '/'){
        printf("%.3f\n",n1/n2);
    }
}
int main(){
    math();
    return 0;
}